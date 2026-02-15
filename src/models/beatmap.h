// * NOTICE
//  This file contains the Beatmap datamodel, which is an instance of a beatmap. This class is accessed by
//  the beatmap manager in `state/beatmap.h` and is responsible for managing the lifecycle of a beatmap 
//  instance. The actual data structs and containers for a beatmap's data is defined in `data/beatmap.h`

#pragma once

#include "../data/beatmap.h"



// * Beatmap model 
class Beatmap {
private:
    // Program metadata
    BeatmapExData data;

    // Actual beatmap data
    // TODO: REFACTOR THIS TO BE THE BEATMAP SECTIONS PARSED BY THE PARSER!
    // TODO: BeatmapData;
    // TODO: BeatmapData;
    // TODO: BeatmapData; 

public:

    // Getters
    const BeatmapExData&           getData()       const { return data;    }
    // TODO: REFACTOR THIS TO RETURN THE BEATMAP SECTIONS PARSED BY THE PARSER!
    // TODO: const SkinData::Samples&    getSamples()    const { return samples; }
    // TODO: const SkinData::Sprites&    getSprites()    const { return sprites; }
    // TODO: const SkinData::Config&     getConfig()     const { return config;  }
};
