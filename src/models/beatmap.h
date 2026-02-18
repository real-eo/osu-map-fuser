// * NOTICE
//  This file contains the Beatmap datamodel, which is an instance of a beatmap. This class is accessed by
//  the beatmap manager in `state/beatmap.h` and is responsible for managing the lifecycle of a beatmap 
//  instance. The actual data structs and containers for a beatmap's data is defined in `data/beatmap.h`

#pragma once

#include <cmath>
#include <memory>
#include <osu!parser/Parser/Beatmap.hpp>

#include "../data/beatmap.h"

// ? NOTE TO SELF: Ensure the beatmap manager interacts with this model, and not directly with the parser's beatmap struct


// * Beatmap model 
class Beatmap : public OsuParser::Beatmap::Beatmap {
private:
    // * Program metadata
    BeatmapExData data;

public:
    // * Constructors & destructor
    Beatmap(const std::string& path);
    ~Beatmap();

    // * Actual beatmap data
    /*// (Members inherited from: `OsuParser::Beatmap::Beatmap`)
    // ? Version
        std::int32_t Version = 14;
    // ? Sections
        Sections::General::GeneralSection General;
        Sections::Metadata::MetadataSection Metadata;
        Sections::Editor::EditorSection Editor;
        Sections::Difficulty::DifficultySection Difficulty;
        Sections::Colour::ColourSection Colours;
        Sections::Variable::VariableSection Variables;
    // ? Objects
        Objects::TimingPoint::TimingPoints TimingPoints;
        Objects::HitObject::HitObjects HitObjects;
        Objects::Event::Events Events;
    */

    // * Performance critial
    void load();

    // * Getters
    // std::filesystem::path audioPath() const;                                         // ? Stored in `BeatmapExData`
    const BeatmapExData& ExData() const { return data; }
};
