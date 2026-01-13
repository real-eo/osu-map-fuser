#pragma once

#include "../debug/debug.h"

#include <SDL.h>
#include <memory>
#include <string>



// Forward declarations
class Renderer;
class Toolbar;
class ImGuiManager;
class BeatmapManager;
class SkinManager;
class AudioPlayer;
class SfxPlayer;
// // class Timeline;


// * Main application class orchestrating subsystems
class Application {
private:
    // App state
    std::string title;
    int windowWidth;
    int windowHeight;
    bool running;
    double elapsedTime;
    int playbackPosition = 0;                                                           // Current audio playback position in milliseconds

    // Window & graphics
    SDL_Window* window;
    SDL_GLContext glContext;
    std::unique_ptr<Renderer> renderer;
    // // std::unique_ptr<ImGuiManager> ui;
    std::unique_ptr<Toolbar> toolbar;

    // Program state
    std::unique_ptr<BeatmapManager> beatmapManager;
    std::unique_ptr<SkinManager> skinManager;
    std::unique_ptr<AudioPlayer> audioPlayer;
    std::unique_ptr<SfxPlayer> sfxPlayer;                                               // Must come after AudioPlayer (to ensure audio engine initialized first)
    // // std::unique_ptr<Timeline> timeline;                                                 // Must come after audioPlayer (to access playback position)

    void handleEvents();
    void update(double deltaTime);
    void render();
    
    void shutdown();

public:
    Application(const std::string& title, int width, int height);
    ~Application();

    // Disable copy/move
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    // Initialization & main loop
    bool init();
    int run();

    // Getters
    bool isRunning() const { return running; }
    AudioPlayer* audio() { return audioPlayer.get(); }
    SfxPlayer* sfx() { return sfxPlayer.get(); }                                        // ? DEBUG ONLY PER NOW
    // // BeatmapManager* iWantToSpeakToYourManager() { return beatmapManager.get(); }        // You don't know how funny this is at 2 am

    // Setters
    void requestShutdown() { running = false; }

    // * Delegations
    // Management
    void loadBeatmap();
    void addBeatmap();
    // // void loadSkin();
};
