// * NOTICE
//  This file contains the Skin datamodel, which is an instance of a skin. This class is accessed 
//  by the skin manager in `state/skin.h` and is responsible for managing the lifecycle of a skin 
//  instance. The actual data structs and containers for a skin's data is defined in `data/skin.h`

#pragma once

#include "../data/skin.h"



// * Skin model 
class Skin {
private:
    // Program metadata
    SkinExData data;

    // Actual skin data
    // ! NOTICE: ALL of these members contains intialized data. THEY ARE NOT NULL!  (see `data/skin.h::SkinData` for details)
    SkinData::Samples samples;                                                          
    SkinData::Sprites sprites;                             
    SkinData::Config config;                  

public:
//     Skin();
//     ~Skin();

//     // Load skin from path
//     bool loadFromPath(const std::filesystem::path& path);

    // Getters
    const SkinExData&           getData()       const { return data;    }
    const SkinData::Samples&    getSamples()    const { return samples; }
    const SkinData::Sprites&    getSprites()    const { return sprites; }
    const SkinData::Config&     getConfig()     const { return config;  }
};
