#include "Application.h"
#include "../core/toolbar.h"
#include "../rendering/renderer.h"
// // #include "../ui/imguiManager.h"  // Uncomment when you add ImGui
#include "../state/beatmap.h"
#include "../audio/songs.h"
#include "../audio/sfx.h"

#include "../resources/skins/legacy.h"

#include <iostream>
#include <chrono>

// // #ifdef _WIN32
// // #include <windows.h>
// // #include <SDL_syswm.h>
// // #endif


Application::Application(const std::string& title, int width, int height)
    : window(nullptr), glContext(nullptr),
      title(title), windowWidth(width), windowHeight(height),
      running(false), elapsedTime(0.0) { 
}

Application::~Application() {
    shutdown();
}

// * Initialize SDL, create window & GL context, initalize subsystems
bool Application::init() {
    std::cout << "Initializing " << title << "...\n";

    // * Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return false;
    }

    // Enable delivery of WM_COMMAND as SDL_SYSWMEVENT
    SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);

    std::cout << "SDL initialized successfully\n";

    // Request an OpenGL compatibility/profile context
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


    // * Create window
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        windowWidth, windowHeight,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        return false;
    }

    std::cout << "Window created\n";

    // Create OpenGL context and attach to window
    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "SDL_GL_CreateContext Error: " << SDL_GetError() << "\n";
        return false;
    }
    std::cout << "OpenGL context created\n";


    // * Initialize toolbar
    toolbar = std::make_unique<Toolbar>(this);

    if (!toolbar->init(window)) {
        std::cerr << "Toolbar init failed\n";
        return false;
    }

    // * Initialize renderer
    renderer = std::make_unique<Renderer>();

    if (!renderer->init(window)) {
        std::cerr << "Renderer init failed\n";
        return false;
    }

    std::cout << "Renderer initialized\n";


    // * Initialize UI (uncomment when you add ImGui)
    // ui = std::make_unique<ImGuiManager>();
    // if (!ui->init(window, glContext)) {
    //     std::cerr << "ImGui init failed\n";
    //     return false;
    // }


    // * Initialize beatmap manager
    beatmapManager = std::make_unique<BeatmapManager>(window);

    // * Initialize audio player
    audioPlayer = std::make_unique<AudioPlayer>();
    if (!audioPlayer->init()) {
        DEBUG_ERROR("AudioPlayer init failed");
        return false;
    } else {
        // Set default audio settings
        audioPlayer->setVolume(0.5f);                                                    // Max volume
        audioPlayer->setPlaybackSpeed(1.0f);                                             // Normal speed

        // Show current audio settings
        audioPlayer->logState();
    }

    // * Initialize SFX player
    sfxPlayer = std::make_unique<SfxPlayer>();
    if (!sfxPlayer->init()) {
        DEBUG_ERROR("SfxPlayer init failed");
        return false;
    } else {
        // Test loading legacy skin sample and playing it
        sfxPlayer->loadSampleMemory("drum-hitclap", legacy::samples::osu::drum::hit::clap, legacy::samples::osu::drum::hit::clap_size, 1.0f);
        // // sfxPlayer->play("drum-hitclap");
    }

    // * Load skin
    // TODO: Load skin from user-selected location; fallback to default legacy skin

    running = true;
    return running;
}


// * Main loop
int Application::run() {
    // Sanity check
    if (!running) {
        std::cerr << "Application not initialized. Call init() first.\n";
        return -1;
    }

    // Setup
    auto startTime = std::chrono::high_resolution_clock::now();
    auto lastFrame = startTime;

    // Main loop
    while (running) {
        auto now = std::chrono::high_resolution_clock::now();
        double deltaTime = std::chrono::duration<double>(now - lastFrame).count();
        elapsedTime = std::chrono::duration<double>(now - startTime).count();
        lastFrame = now;

        handleEvents();
        update(deltaTime);
        render();

        SDL_Delay(8);                                                   // ~120 FPS cap (adjust or remove for uncapped)
    }

    return 0;
}


void Application::handleEvents() {
    SDL_Event ev;

    while (SDL_PollEvent(&ev)) {
        // Let ImGui process events first (uncomment when you add ImGui)
        // ImGui_ImplSDL2_ProcessEvent(&ev);

        switch (ev.type) {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_WINDOWEVENT:
                if (ev.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                    windowWidth = ev.window.data1;
                    windowHeight = ev.window.data2;
                    renderer->resize(windowWidth, windowHeight);
                }
                break;
                
            case SDL_KEYDOWN:
                if (ev.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                break;
                
            // ? Now handled in toolbar.cpp
            // // Toolbar menu command handling (Windows only) 
            // // ! BLOCKING - ACCESSING THE TOOLBAR WILL BLOCK THE MAIN THREAD
            // // #ifdef _WIN32
            // // case SDL_SYSWMEVENT:
            // //     // Handle Windows menu messages (non-blocking via PeekMessage)
            // //     if (ev.syswm.msg->msg.win.msg == WM_COMMAND) {
            // //         // toolbar->handleMenuCommand(LOWORD(ev.syswm.msg->msg.win.wParam));
            // //     }
            // //     break;
            // // #endif
        }
    }
}


void Application::update(double deltaTime) {
    // Update game logic, audio sync, beatmap state, etc.
    (void)deltaTime;                                                                    // Remove when you add actual update logic
}


void Application::render() {
    // Render UI (uncomment when you add ImGui)
    // ui->beginFrame();
    // ImGui::ShowDemoWindow();                                                         // Example UI
    // ui->endFrame();

    // Render scene
    renderer->render(elapsedTime);

    SDL_GL_SwapWindow(window);
}


void Application::shutdown() {
    if (!running && !window) return;                                                    // Already shut down

    std::cout << "Shutting down...\n";

    // * Cleanup subsystems
    // if (ui) ui->shutdown();
    // if (toolbar) toolbar->shutdown();                                                // ? Gets automatically cleaned up in Toolbar::~Toolbar()
    if (renderer) renderer->shutdown();

    // * Cleanup SDL
    if (glContext) SDL_GL_DeleteContext(glContext);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();

    running = false;
    std::cout << "Shutdown complete\n";
}


// * Delegations
void Application::loadBeatmap() {
    // Load beatmap                                                                     - BeatmapManager
    if (beatmapManager) {
        beatmapManager->loadBeatmap();
    } else {
        BEATMAP_ERROR("BeatmapManager not initialized when attempting to load beatmap");
        return;
    }

    // Load audio                                                                       - AudioPlayer
    if (audioPlayer) {
        audioPlayer->load(beatmapManager->active().audioPath());
    } else {
        AUDIO_ERROR("AudioPlayer not initialized when attempting to load beatmap audio");
        return;
    }
}

void Application::addBeatmap() {
    if (beatmapManager) {
        beatmapManager->addBeatmap();  
    }
}
