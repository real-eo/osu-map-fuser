#include "beatmap.h"

// // #include <osu!parser/Parser/Beatmap.hpp>


#define NOT_SET 0                                                                       // ! Can't be negative as it's unsigned



// * Constructors & destructor
Beatmap::Beatmap(const std::string& path) : OsuParser::Beatmap::Beatmap(path) {
    // Program metadata
    data.location = std::filesystem::path(path).parent_path();                          // Directory of the beatmap
    data.audioFilename = General.AudioFilename;                                         // Filename of the beatmap's audio file (extracted from the beatmap file, not the path)
    data.index = NOT_SET;                                                               // ? Index is set by the BeatmapManager     
}

Beatmap::~Beatmap() = default;



// * BeatmapExData function definitions
// ? I kept this definition here, and not in "src/data/beatmap.h" to avoid including the parser in that file
std::filesystem::path BeatmapExData::audioPath() const {
    // | if (!beatmap) { return {}; }                                                        // No active beatmap
    // | return data.location / General.AudioFilename;
    return location / audioFilename;
}
