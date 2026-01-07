#pragma once    

#include <filesystem>


// Forward declarations instead of including the full parser
namespace OsuParser::Beatmap {
    class Beatmap;
}


// * Struct to hold extra beatmap info
struct BeatmapExData {
    // Data
    OsuParser::Beatmap::Beatmap* beatmap;
    std::filesystem::path location;                                                     // Directory of the beatmap file                                  
    size_t index;

    // Getters
    std::filesystem::path audioPath() const;
    
}; // BeatmapExData   