#pragma once

#include <filesystem>


// Forward declarations instead of including the full parser
namespace OsuParser::Beatmap {
   class Beatmap;
}


// * Struct to hold extra beatmap info. The only reason this exists is to prevent 
// * passing the entire beatmap class around as it can potentially be very heavy. 
// * This struct should only contain the absolute minimum info needed.
struct BeatmapExData {
    // Data
    // | OsuParser::Beatmap::Beatmap* beatmap;                          
    std::filesystem::path location;                                                     // Directory of the beatmap file
    std::string audioFilename;                                                          // Filename of the beatmap's audio file (extracted from the beatmap file, not the path)
    size_t index;

    // Getters
    std::filesystem::path audioPath() const;
    
}; // BeatmapExData   