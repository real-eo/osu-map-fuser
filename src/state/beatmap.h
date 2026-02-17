#pragma once

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <filesystem>

// // #include <SDL.h>
#include "manager.h"
#include "../models/beatmap.h"


// * BeatmapManager: Manages loading, storing, and accessing beatmaps
class BeatmapManager : public Manager {    
private:
    // // Non-owning pointer to SDL window, only used for dialogs
    // // SDL_Window* window;

    // State
    // | std::vector<std::unique_ptr<OsuParser::Beatmap::Beatmap>> maps;
    std::vector<std::unique_ptr<Beatmap>> maps;                                         // | TEST
    // // size_t activeIndex = 0;                                                             // We implement such that this can be a different value than 0, but it shouldn't be anything else than 0 for now
    // | BeatmapExData activeBeatmap;                                                   // This struct should follow the lifecycle of the entire 
    // |                                                                                // manager. This variable should always be valid if there
    // |                                                                                // is at least one map loaded. Only it's members change. 

    BeatmapExData activeBeatmap;                                                             
    
    // Helpers
    // | OsuParser::Beatmap::Beatmap* activeBeatmapPtr() const;
    Beatmap* activeBeatmapPtr() const;                                                  // | TEST
    // | bool isAlreadyLoaded(const OsuParser::Beatmap::Beatmap& beatmap) const;
    bool isAlreadyLoaded(const Beatmap& beatmap) const;                                 // | TEST
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
    // | const std::vector<std::unique_ptr<OsuParser::Beatmap::Beatmap>>& all() const { return maps; }
    const std::vector<std::unique_ptr<Beatmap>>& all() const { return maps; }           // | TEST
    // | const BeatmapExData& active() const { return activeBeatmap; }
    const BeatmapExData& active() const { return activeBeatmap; }
    const bool hasActive() const { return !maps.empty(); }

    // Setters
    // // void setActive(size_t index);
};