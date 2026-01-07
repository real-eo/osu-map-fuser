#pragma once
#include <string>
#include <unordered_map>
#include <bass.h>


class SfxPlayer {
private:
    struct Sample { 
        HSAMPLE sample; 
        float volume; 
    };

    std::unordered_map<std::string, Sample> samples;

public:
    bool init() {
        // audioengine::init already called BASS_Init; if not, call it here.
        // TODO: Ensure BASS audio engine is initialized
        return true;
    }

    bool loadSampleMemory(const std::string& name, const void* data, std::size_t size, float volume = 1.0f) {
        HSAMPLE s = BASS_SampleLoad(
            TRUE, 
            const_cast<void*>(data),
            0,
            static_cast<DWORD>(size),
            8, 
            BASS_SAMPLE_OVER_POS
        );
        
        if (!s) return false;
        
        samples[name] = {s, volume};
        return true;
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
        
        samples[name] = {s, volume};

        return true;
    }

    void play(const std::string& name) {
        auto it = samples.find(name);
        
        if (it == samples.end()) return;
        
        HCHANNEL ch = BASS_SampleGetChannel(it->second.sample, FALSE);
        
        if (!ch) return;
        
        BASS_ChannelSetAttribute(ch, BASS_ATTRIB_VOL, it->second.volume);
        BASS_ChannelPlay(ch, TRUE);
    }
};