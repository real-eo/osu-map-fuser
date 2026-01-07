#include "toolbar.h"
#include "application.h"

#ifdef _WIN32
#include <SDL_syswm.h>
#include <windows.h>

#endif


// * Constructors & Destructor
Toolbar::Toolbar(Application* app)
    : app(app), window(nullptr) {
    #ifdef _WIN32
    hwnd = nullptr;
    menuBar = nullptr;
    oldWndProc = nullptr;
    #endif
}

Toolbar::~Toolbar() { shutdown(); }



// * Initialization & shutdown
bool Toolbar::init(SDL_Window* window_) {
    this->window = window_;

    #ifdef _WIN32
    createMenuBar();
    std::cout << "Toolbar (menu bar) created\n";
    #else
    std::cout << "Toolbar creation skipped (Windows only)\n";
    #endif

    return true;
}

void Toolbar::shutdown() {
    std::cout << "Shutting down toolbar...\n";

    #ifdef _WIN32
    // Restore original window procedure
    if (hwnd && oldWndProc) {
        SetWindowLongPtr((HWND)hwnd, GWLP_WNDPROC, (LONG_PTR)oldWndProc);
        oldWndProc = nullptr;
    }

    if (menuBar) {
        DestroyMenu((HMENU)menuBar);
        menuBar = nullptr;
    }
    #endif

    std::cout << "Toolbar shut down\n";
}



// * Windows-specific implementations
#ifdef _WIN32

void Toolbar::createMenuBar() {                                                         // ? Create menu bar and attach to window
    // Get the native Windows HWND from SDL
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);

    if (!SDL_GetWindowWMInfo(window, &wmInfo)) {
        std::cerr << "Failed to get window info: " << SDL_GetError() << "\n";
        return;
    }

    hwnd = wmInfo.info.win.window;
    HWND hWnd = (HWND)hwnd;

    // Subclass the window to intercept messages
    oldWndProc = (void*)SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)WindowProc);
    SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)this);

    // Create menu bar
    HMENU hMenuBar = CreateMenu();

    // File menu
    HMENU hFileMenu = CreatePopupMenu();
    AppendMenuA(hFileMenu, MF_STRING, MenuID::FILE::OPEN, "Open Beatmap...\tCtrl+O");
    AppendMenuA(hFileMenu, MF_STRING, MenuID::FILE::ADD, "Add Beatmap...\tCtrl+A");
    AppendMenuA(hFileMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuA(hFileMenu, MF_STRING, MenuID::FILE::EXIT, "Exit\tAlt+F4");
    AppendMenuA(hMenuBar, MF_POPUP, (UINT_PTR)hFileMenu, "File");

    // Edit menu
    HMENU hEditMenu = CreatePopupMenu();
    AppendMenuA(hEditMenu, MF_STRING, MenuID::EDIT::SETTINGS, "Settings...");
    AppendMenuA(hMenuBar, MF_POPUP, (UINT_PTR)hEditMenu, "Edit");

    // View menu
    HMENU hViewMenu = CreatePopupMenu();
    AppendMenuA(hViewMenu, MF_STRING, MenuID::VIEW::FULLSCREEN, "Toggle Fullscreen\tF11");
    AppendMenuA(hMenuBar, MF_POPUP, (UINT_PTR)hViewMenu, "View");

    // Help menu
    HMENU hHelpMenu = CreatePopupMenu();
    AppendMenuA(hHelpMenu, MF_STRING, MenuID::HELP::ABOUT, "About");
    AppendMenuA(hMenuBar, MF_POPUP, (UINT_PTR)hHelpMenu, "Help");

    // DEBUG menu
    if (DEBUG::enabled) {                                                               // TODO: Use preprocessor directives to include/exclude debug commands based on debug/release builds
        createDebugMenu(hMenuBar);                                                      // ? Defined in src/debug/toolbar.cpp
    }

    // Attach menu to window
    SetMenu(hWnd, hMenuBar);
    menuBar = hMenuBar;

    // Force window to redraw with new menu
    SetWindowPos(hWnd, NULL, 0, 0, 0, 0,
                 SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

LRESULT CALLBACK Toolbar::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {   // ? Static window procedure that will intercept all window messages
    // Retrieve pointer to Toolbar instance from window user data
    Toolbar* pThis = nullptr;
    
    if (msg == WM_CREATE) {
        CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
        pThis = reinterpret_cast<Toolbar*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);
    } else {
        pThis = reinterpret_cast<Toolbar*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    }

    // Log when menu is opened
    if (msg == WM_INITMENUPOPUP) {
        HMENU hMenu = (HMENU)wParam;
        int menuPos = (int)lParam;
        
        if (pThis) {
            pThis->onMenuOpen(hMenu, menuPos);
        }
        
        return 0;
    }

    // Handle menu commands
    if (msg == WM_COMMAND) {
        int commandId = LOWORD(wParam);
        
        if (pThis) {
            std::cout << "[Menu] Command ID: " << commandId << "\n";
            pThis->handleMenuCommand(commandId);
        }
        
        return 0;                                                                       // Message handled
    }

    // Call the original window procedure for other messages
    if (pThis && pThis->oldWndProc) {
        return CallWindowProc((WNDPROC)pThis->oldWndProc, hwnd, msg, wParam, lParam);
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}


// * Handling
// TODO: Notify application when a menu is open, so that it can pause updates/rendering/playback
void Toolbar::onMenuOpen(HMENU hMenu, int menuPos) {
    switch (menuPos) {                                                                  // Determine which menu was opened based on position
        case 0:                                                                         // First menu   = File
            TOOLBAR_LOG("File menu opened");
            break;

        case 1:                                                                         // Second menu  = Edit
            TOOLBAR_LOG("Edit menu opened");
            break;

        case 2:                                                                         // Third menu   = View
            TOOLBAR_LOG("View menu opened");
            break;

        case 3:                                                                         // Fourth menu  = Help
            TOOLBAR_LOG("Help menu opened");
            break;

        case 4:                                                                         // Fifth menu   = DEBUG (if enabled)
            TOOLBAR_LOG("DEBUG menu opened");
            break;

        default:
            TOOLBAR_LOG("Unknown menu opened at position " << menuPos);
            break;
    }
}

void Toolbar::handleMenuCommand(int commandId) {
    // TODO: Use preprocessor directives to include/exclude debug commands based on debug/release builds
    // Handle debug commands first
    if (commandId > MenuID::DEBUG::_OFFSET) {
        DEBUG_LOG("Debug command triggered: " << commandId);
        handleDebugCommand(commandId);
        return;
    }

    // Handle regular commands
    switch (commandId) {
        case MenuID::FILE::OPEN:
            TOOLBAR_LOG(" -> Open Beatmap selected");
            app->loadBeatmap();
            break;

        case MenuID::FILE::ADD:
            TOOLBAR_LOG(" -> Add Beatmap selected");
            app->addBeatmap();
            break;

        case MenuID::FILE::EXIT:
            TOOLBAR_LOG(" -> Exit selected");
            app->requestShutdown();
            break;

        case MenuID::EDIT::SETTINGS:
            TOOLBAR_LOG(" -> Settings selected");
            // TODO: Show settings dialog
            break;

        case MenuID::VIEW::FULLSCREEN:
            TOOLBAR_LOG(" -> Toggle fullscreen selected");
            // TODO: Toggle fullscreen on app
            break;

        case MenuID::HELP::ABOUT:
            TOOLBAR_LOG(" -> About selected");
            MessageBoxA((HWND)hwnd,
                      "osu! Map Fuser v0.1\nA tool for splicing osu! beatmaps",
                      "About", MB_OK | MB_ICONINFORMATION);
            break;
            
        default:
            std::cout << "Unknown menu command: " << commandId << std::endl;
            break;
    }
}


#else
// Non-Windows stubs
void Toolbar::handleMenuCommand(int commandId) {
    (void)commandId;  // Unused on non-Windows
}
#endif
