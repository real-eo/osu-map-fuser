#include "../core/toolbar.h"
#include "../core/Application.h"
#include "../audio/songs.h"
#include "../audio/sfx.h"
#include <iostream>

/*
    void play();
    void pause();
    void stop();
    void togglePause();
*/


inline void handleSongDebug(int commandId, Application* app) {
    switch (commandId) {
        case MenuID::DEBUG::Song::PLAY:
            
            DEBUG_LOG("AUDIO: play");    
            app->audio()->play();

            break;

        case MenuID::DEBUG::Song::PAUSE:

            DEBUG_LOG("AUDIO: pause");
            app->audio()->pause();

            break;

        case MenuID::DEBUG::Song::STOP:

            DEBUG_LOG("AUDIO: stop");
            app->audio()->stop();

            break;

        case MenuID::DEBUG::Song::TOGGLE_PAUSE:

            DEBUG_LOG("AUDIO: toggle pause");
            app->audio()->togglePause();
        
            break;

        case MenuID::DEBUG::Song::LOG_STATE:
            
            DEBUG_LOG("AUDIO: log state");
            app->audio()->logState();

            break;

        default:
            TOOLBAR_LOG("Unknown debug command: " << commandId);
            break;
    }
}

inline void handleSfxDebug(int commandId, Application* app) {
    switch (commandId) {
        case MenuID::DEBUG::Sfx::PLAY_SAMPLE_1:

            DEBUG_LOG("SFX: play sample 1 (drum-hitclap)");
            app->sfx()->play("drum-hitclap");

            break;

        default:
            TOOLBAR_LOG("Unknown SFX debug command: " << commandId);
            break;
    }
}

// ! DEBUG MENU CREATION. ONLY USED WHEN `DEBUG::enabled` IS `true`.
void Toolbar::createDebugMenu(HMENU& hMenuBar) {
    HMENU hDebugMenu = CreatePopupMenu();

    // Song control commands
    AppendMenuA(hDebugMenu, MF_STRING, MenuID::DEBUG::Song::PLAY, "Play Loaded Song");
    AppendMenuA(hDebugMenu, MF_STRING, MenuID::DEBUG::Song::PAUSE, "Pause Loaded Song");
    AppendMenuA(hDebugMenu, MF_STRING, MenuID::DEBUG::Song::STOP, "Stop Loaded Song");
    AppendMenuA(hDebugMenu, MF_STRING, MenuID::DEBUG::Song::TOGGLE_PAUSE, "Toggle Pause Loaded Song");
    AppendMenuA(hDebugMenu, MF_STRING, MenuID::DEBUG::Song::LOG_STATE, "Log Audio State");
    AppendMenuA(hDebugMenu, MF_SEPARATOR, 0, NULL);

    // SFX control commands
    AppendMenuA(hDebugMenu, MF_STRING, MenuID::DEBUG::Sfx::PLAY_SAMPLE_1, "Play SFX: drum-hitclap");
    
    AppendMenuA(hMenuBar, MF_POPUP, (UINT_PTR)hDebugMenu, "DEBUG");
}


// TODO: Use preprocessor directives to include/exclude debug commands based on debug/release builds
// ! DEBUG SPECIFIC COMMAND HANDLING. ONLY USED WHEN `DEBUG::enabled` IS `true`.
void Toolbar::handleDebugCommand(int commandId) {
    // Determine which command to execute based on section
    int section = (
        commandId - MenuID::DEBUG::_OFFSET                                              // ? Get offset within DEBUG menu
    ) / MenuID::DEBUG::_MAX_BUTTONS_PER_SECTION;                                        // ? Determine section index

    // Handle command based on section
    switch (section) {
        case MenuID::DEBUG::Song::_SECTION_ID:                                          // Song controls
            handleSongDebug(commandId, app);
            break;

        case MenuID::DEBUG::Sfx::_SECTION_ID:                                           // SFX controls
            handleSfxDebug(commandId, app);
            break;

        default:
            TOOLBAR_LOG("Unknown debug command section: " << section);
            break;
    }

}


