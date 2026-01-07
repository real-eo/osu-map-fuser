#pragma once

#include <SDL.h>

#include "../debug/debug.h"

#ifdef _WIN32
#include <windows.h>
#endif

// Forward declaration
class Application;


// * Manages the application toolbar/menu
class Toolbar {
private:
    Application* app;
    SDL_Window* window;

    #ifdef _WIN32

    void* hwnd;
    void* menuBar;
    void* oldWndProc;                                                                   // Store original window procedure

    void createMenuBar();
    void handleMenuCommand(int commandId);
    void onMenuOpen(HMENU hMenu, int menuPos);
    
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    void createDebugMenu(HMENU& hMenuBar);                                              // ? Defined in src/debug/toolbar.cpp
    void handleDebugCommand(int commandId);                                             // ? Debug-specific command handling                 
    #endif

public:
    Toolbar(Application* app);
    ~Toolbar();

    bool init(SDL_Window* window);
    void shutdown();

};


// * Menu item IDs
namespace MenuID {
    // (1xxx)   File menu
    namespace FILE {
        constexpr int OPEN = 1001;
        constexpr int ADD = 1002;
        constexpr int EXIT = 1003;
    } // namespace FILE


    // (2xxx)   Edit menu
    namespace EDIT {
        constexpr int SETTINGS = 2001;
    } // namespace EDIT
    

    // (3xxx)   View menu
    namespace VIEW {
        constexpr int FULLSCREEN = 3001;
    } // namespace VIEW


    // (4xxx)   Help menu
    namespace HELP {
        constexpr int ABOUT = 4001;
    } // namespace HELP


    // (9xxx)   DEBUG menu
    namespace DEBUG {
        constexpr int _OFFSET = 9000;
        constexpr int _MAX_BUTTONS_PER_SECTION = 16;

        namespace Song {
            constexpr int _SECTION_ID = 0;
            constexpr int _SECTION_OFFSET = _OFFSET + (_MAX_BUTTONS_PER_SECTION * _SECTION_ID);

            constexpr int PLAY          = 1     + _SECTION_OFFSET;
            constexpr int PAUSE         = 2     + _SECTION_OFFSET;
            constexpr int STOP          = 3     + _SECTION_OFFSET;
            constexpr int TOGGLE_PAUSE  = 4     + _SECTION_OFFSET;
            constexpr int LOG_STATE     = 5     + _SECTION_OFFSET;
        } // namespace Song

        namespace Sfx {
            constexpr int _SECTION_ID = 1;
            constexpr int _SECTION_OFFSET = _OFFSET + (_MAX_BUTTONS_PER_SECTION * _SECTION_ID);

            constexpr int PLAY_SAMPLE_1 = 1     + _SECTION_OFFSET;
            constexpr int PLAY_SAMPLE_2 = 2     + _SECTION_OFFSET;
            constexpr int PLAY_SAMPLE_3 = 3     + _SECTION_OFFSET;
            constexpr int PLAY_SAMPLE_4 = 4     + _SECTION_OFFSET;
            constexpr int PLAY_SAMPLE_5 = 5     + _SECTION_OFFSET;
        } // namespace Sfx
    } // namespace DEBUG
} // namespace MenuID
