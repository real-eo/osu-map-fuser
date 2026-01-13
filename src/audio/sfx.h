#pragma once

#include <string>
#include <unordered_map>

#include <bass.h>


// * Forward declarations
struct resource;                                                                        // From src/resources/utils.h
namespace SkinData { struct Samples; } // namespace SkinData



class SfxPlayer {
private:
    // // // Sample struct - currently just a wrapper for HSAMPLE, but implemented such that it can be extended later
    // // struct Sample { 
    // //     HSAMPLE sample;  
    // // };

    // // std::unordered_map<std::string, Sample> samples;
    std::unordered_map<std::string, HSAMPLE> samples;

public:
    // * Initialization & deinitialization
    ~SfxPlayer();
    bool init();
    void clearSample(const std::string& name);
    void clearAll();


    // * Sample loading
    // Loads sample from file path                                                              - used when loading external samples
    bool loadSampleFile(const std::string& name, const std::string& path);
    
    // Loads sample from memory buffer                                                          - used when loading embedded samples
    bool loadSampleMemory(const std::string& name, const void* data, std::size_t size);

    // Overload for resource struct                                                             - used when loading embedded samples
    bool loadSampleMemory(const std::string& name, const resource& res);

    // Load all samples from a skin
    void loadSkinSamples(const SkinData::Samples& samples);


    // * Playback
    void play(const std::string& name, float volume = 1.0f);


    // * DEBUG
    void logState() const;
};