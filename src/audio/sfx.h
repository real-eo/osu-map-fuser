#pragma once
#include <string>
#include <unordered_map>
#include <bass.h>

#include "../resources/utils.h"

class SfxPlayer {
private:
    // // // Sample struct - currently just a wrapper for HSAMPLE, but implemented such that it can be extended later
    // // struct Sample { 
    // //     HSAMPLE sample;  
    // // };

    // // std::unordered_map<std::string, Sample> samples;
    std::unordered_map<std::string, HSAMPLE> samples;

public:
    bool init() {
        // audioengine::init already called BASS_Init; if not, call it here.
        // TODO: Ensure BASS audio engine is initialized
        return true;
    }

    bool loadSampleMemory(const std::string& name, const void* data, std::size_t size) {
        HSAMPLE s = BASS_SampleLoad(
            TRUE, 
            const_cast<void*>(data),
            0,
            static_cast<DWORD>(size),
            8, 
            BASS_SAMPLE_OVER_POS
        );
        
        if (!s) return false;
        
        // // samples[name] = {s};
        samples[name] = s;
        return true;
    }

    // Overload for resource struct
    bool loadSampleMemory(const std::string& name, const resource& res) {
        return loadSampleMemory(name, res.data, res.size);
    }

    bool loadSampleFile(const std::string& name, const std::string& path, float volume = 1.0f) {
        HSAMPLE s = BASS_SampleLoad(
            FALSE, 
            path.c_str(), 
            0, 
            0, 
            8, 
            BASS_SAMPLE_OVER_POS
        );
        
        if (!s) return false;
        
        // // samples[name] = {s};
        samples[name] = s;
        return true;
    }

    void play(const std::string& name, float volume = 1.0f) {
        auto it = samples.find(name);
        
        if (it == samples.end()) return;
        
        // // HCHANNEL ch = BASS_SampleGetChannel(it->second.sample, FALSE);
        HCHANNEL ch = BASS_SampleGetChannel(it->second, FALSE);
        
        if (!ch) return;
        
        BASS_ChannelSetAttribute(ch, BASS_ATTRIB_VOL, volume);
        BASS_ChannelPlay(ch, TRUE);
    }
};