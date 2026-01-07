// // #include "../managers/win.h"
#include "win.h"                                                                        // Corresponding .h for the windows manager

#ifdef _WIN32
#include <SDL_syswm.h>
#include <windows.h>
#include <commdlg.h>
#endif


std::string WinManager::openFile(const char filter[], const char title[]) {
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    if (!SDL_GetWindowWMInfo(window, &wmInfo)) {
        return "";
    }

    HWND hWnd = wmInfo.info.win.window;

    // // File filter: .osu files
    // // const char filter[] = "osu! Beatmaps (*.osu)\0*.osu\0All Files (*.*)\0*.*\0";
    
    char filename[MAX_PATH] = {0};
    
    OPENFILENAMEA ofn = {};
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFilter = filter;
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    // // ofn.lpstrTitle = "Open Beatmap";
    ofn.lpstrTitle = title;

    if (GetOpenFileNameA(&ofn)) {
        return std::string(filename);
    }

    return "";
}