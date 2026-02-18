// // #include "manager.h"
#include "beatmap.h"

#include <iostream>

// // #ifdef _WIN32
// // #include <SDL_syswm.h>
// // #include <windows.h>
// // #include <commdlg.h>
// // #endif

// #include "../debug/debug.h"
#ifndef BEATMAP_MANAGER_LOG
#define BEATMAP_MANAGER_LOG(...) do { } while(0)
#endif
#ifndef BEATMAP_MANAGER_ERROR
#define BEATMAP_MANAGER_ERROR(...) do { } while(0)
#endif

#include <osu!parser/Parser/Beatmap.hpp>

namespace fs = std::filesystem;


// // BeatmapManager::BeatmapManager(SDL_Window* window) : window(window) {}
BeatmapManager::BeatmapManager(SDL_Window* window) : Manager(window) {}

BeatmapManager::~BeatmapManager() {
    BEATMAP_MANAGER_LOG("Unloading all beatmaps from manager...");
    
    unloadAll();

    BEATMAP_MANAGER_LOG("BeatmapManager destroyed");
}

// // #ifdef _WIN32
// // std::string BeatmapManager::openFileDialog() {
// //     SDL_SysWMinfo wmInfo;
// //     SDL_VERSION(&wmInfo.version);
// //     if (!SDL_GetWindowWMInfo(window, &wmInfo)) {
// //         return "";
// //     }
// //     HWND hWnd = wmInfo.info.win.window;

// //     // File filter: .osu files
// //     const char filter[] = "osu! Beatmaps (*.osu)\0*.osu\0All Files (*.*)\0*.*\0";

// //     char filename[MAX_PATH] = {0};

// //     OPENFILENAMEA ofn = {};
// //     ofn.lStructSize = sizeof(ofn);
// //     ofn.hwndOwner = hWnd;
// //     ofn.lpstrFilter = filter;
// //     ofn.lpstrFile = filename;
// //     ofn.nMaxFile = MAX_PATH;
// //     ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
// //     ofn.lpstrTitle = "Open Beatmap";

// //     if (GetOpenFileNameA(&ofn)) {
// //         return std::string(filename);
// //     }

// //     return "";
// // }
// // #endif

void BeatmapManager::loadBeatmap() {
    // Get file path via dialog
    //// #ifdef _WIN32
    //// std::string path = openFileDialog();

    //// #else
    //// std::cout << "Load beatmap dialog is only implemented on Windows.\n";
    //// return;

    //// #endif
    std::string path = openFile("osu! Beatmaps (*.osu)\0*.osu\0All Files (*.*)\0*.*\0", "Open Beatmap");

    if (path.empty()) { return; }

    // Unload all currently loaded beatmaps
    unloadAll();

    // Load the selected beatmap
    BEATMAP_MANAGER_LOG("Loading beatmap: " << path);

    // Ensure we don't assume beatmap loaded successfully to avoid  
    // nullptr dereference when accessing beatmap data after loading
    if (!loadFromFile(path)) [[unlikely]] {
        BEATMAP_MANAGER_ERROR("Failed to load beatmap from file: " << path);
        return;
    }

    BEATMAP_MANAGER_LOG("Beatmap loaded successfully");
    

    // Update activeBeatmap struct         
    activeBeatmap = (maps.front())->ExData();                                           


    // todo ?
    // Notify application of new beatmap loaded
    BEATMAP_MANAGER_LOG("Notifying application of loaded beatmap (TODO)");

}

void BeatmapManager::addBeatmap() {
    // Check if there's at least one beatmap loaded
    if (maps.empty()) {
        BEATMAP_MANAGER_LOG("No beatmaps currently loaded. Defaulting to load instead.");
        
        loadBeatmap();
        
        return;
    }

    // Get file path via dialog
    // // #ifdef _WIN32
    // // std::string path = openFileDialog();
    
    // // #else
    // // std::cout << "Add beatmap dialog is only implemented on Windows.\n";
    // // return;
    
    // // #endif
    std::string path = openFile("osu! Beatmaps (*.osu)\0*.osu\0All Files (*.*)\0*.*\0", "Add Beatmap");

    if (path.empty()) { return; }                                                       // User cancelled

    // Load the selected beatmap
    BEATMAP_MANAGER_LOG("Adding beatmap: " << path);

    if (loadFromFile(path, true)) {                                                     // Discard the map if it's already loaded
        BEATMAP_MANAGER_LOG("Beatmap added successfully");
    } 

    // todo
    // Notify application of new beatmap added
    BEATMAP_MANAGER_LOG("Notifying application of added beatmap (TODO)");

    // DEBUG: List all loaded beatmaps
    BEATMAP_MANAGER_LOG("Currently loaded beatmaps:");
    for (size_t i = 0; i < maps.size(); ++i) {
        const auto& beatmap = maps[i];
        
        BEATMAP_MANAGER_LOG(" [" << i << "] MapID: " << beatmap->Metadata.BeatmapID << ", by " << beatmap->Metadata.Creator);
    }
}

// ? This function is used by both loadBeatmap and addBeatmap, which have different behaviors
// TODO: Resolve error where valid maps (such as: "C:\Users\reale\AppData\Local\osu!\Songs\beatmap829e679ddda54795b61c4eb76bba4578\3D - KOEDDNTRY & KOEDD PAA 057 ([ Real ]) [PRANKSTER].osu") causes "stoi" exceptions.
//     : Example of map that doesn't cause issues: "C:\Users\reale\AppData\Local\osu!\Songs\beatmap-639029096208267409-koeddntry\3D - KOEDDNTRY & KOEDD PAA 057 ([ Real ]) [TIMED].osu"
[[nodiscard]] bool BeatmapManager::loadFromFile(const std::string& path, bool discardIfDuplicate) {
    try {
        // Parse beatmap
        auto beatmap = std::make_unique<Beatmap>(path);                                 
        
        // Check for duplicates if requested
        if (discardIfDuplicate) {
            if (isAlreadyLoaded(*beatmap)) {
                throw std::runtime_error("Beatmap is already loaded!");                 // ? Unsure if we really should throw here...
            }
        }

        // Store beatmap
        maps.push_back(std::move(beatmap));
        return true;
    } 
    
    catch (const std::exception& e) {
        // Log error
        BEATMAP_MANAGER_ERROR("Failed to load beatmap from file: " << e.what());
        return false;
    }
}


void BeatmapManager::unloadAll() {
    maps.clear();
}

bool BeatmapManager::isAlreadyLoaded(const Beatmap& beatmap) const {
    // ? Check 1: If it has a BeatmapID, check by ID (submitted maps)
    if (beatmap.Metadata.BeatmapID != "0") {
        return std::any_of(maps.begin(), maps.end(),
            [&beatmap](const auto& existing) {
                return existing->Metadata.BeatmapID == beatmap.Metadata.BeatmapID;
            }
        );
    }

    // ? Check 2: Check by metadata combination (Artist + Title + Creator + Difficulty)
    return std::any_of(maps.begin(), maps.end(),
        [&beatmap](const auto& existing) {
            return existing->Metadata.Artist == beatmap.Metadata.Artist &&
                   existing->Metadata.Title == beatmap.Metadata.Title &&
                   existing->Metadata.Creator == beatmap.Metadata.Creator &&
                   existing->Metadata.Version == beatmap.Metadata.Version;
        }
    );

    // TODO:
    // ? Alternative Check 3: Somehow compare the entire file contents (only timing points + hit objects) quickly
}


// TODO: FIX THIS FUNCTION TO ACTUALLY GET THE ACTIVE BEATMAP POINTER BASED ON THE CURRENTLY SELECTED ACTIVE INDEX (see loadBeatmap and addBeatmap for function requirements)
// Internal helper to get the active beatmap pointer
Beatmap* BeatmapManager::activeBeatmapPtr() const {
    return maps.empty() ? nullptr : maps.front().get();
}

// ? DEPRECATED.
// // void BeatmapManager::setActive(size_t index) {
// //     if (index < maps.size() && index != 0) {
// //         std::swap(maps[0], maps[index]);
// //     }
// // }


