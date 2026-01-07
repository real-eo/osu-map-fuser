#pragma once

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <filesystem>

// // #include <SDL.h>
#include "manager.h"
#include "../data/beatmap.h"


// * BeatmapManager: Manages loading, storing, and accessing beatmaps
class BeatmapManager : public Manager {    
private:
    // // Non-owning pointer to SDL window, only used for dialogs
    // // SDL_Window* window;

    // State
    std::vector<std::unique_ptr<OsuParser::Beatmap::Beatmap>> maps;
    // // size_t activeIndex = 0;                                                             // We implement such that this can be a different value than 0, but it shouldn't be anything else than 0 for now
    BeatmapExData activeBeatmap;                                                        // This struct should follow the lifecycle of the entire  
                                                                                        // manager. This variable should always be valid if there
                                                                                        // is at least one map loaded. Only it's members change.                   

    // Helpers
    OsuParser::Beatmap::Beatmap* activeBeatmapPtr() const;
    bool isAlreadyLoaded(const OsuParser::Beatmap::Beatmap& beatmap) const;
    [[nodiscard]] bool loadFromFile(const std::string& path, bool discardIfDuplicate = false);                                         

    // // #ifdef _WIN32
    // // std::string openFileDialog();
    // // #endif

public:
    BeatmapManager(SDL_Window* window);
    ~BeatmapManager();


    // Event handlers
    void loadBeatmap();
    void addBeatmap();
    void unloadAll();

    // Getters
    const std::vector<std::unique_ptr<OsuParser::Beatmap::Beatmap>>& all() const { return maps; }
    const BeatmapExData& active() const { return activeBeatmap; }
    const bool hasActive() const { return !maps.empty(); }

    // Setters
    // // void setActive(size_t index);
};