#include "sfx.h"

#include "../resources/utils.h"
#include "../state/skin.h"
#include "../debug/debug.h"


// * Initialization & deinitialization
// Deconstructor
SfxPlayer::~SfxPlayer() {
    // Free all loaded samples and clear map
    clearAll();
}

// Initialize SfxPlayer
bool SfxPlayer::init() {
    // audioengine::init already called BASS_Init; if not, call it here.
    // TODO: Ensure BASS audio engine is initialized
    return true;
}

// Free a sample by name
void SfxPlayer::clearSample(const std::string& name) {
    auto it = samples.find(name);
    
    if (it != samples.end()) {
        BASS_SampleFree(it->second);
        samples.erase(it);
    }
}

// Free all loaded samples
void SfxPlayer::clearAll() {
    for (const auto& [name, sample] : samples) {
        BASS_SampleFree(sample);
    }

    samples.clear();
}



// * Sample loading
// Loads sample from file path
bool SfxPlayer::loadSampleFile(const std::string& name, const std::string& path) {
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

// Loads sample from memory buffer
bool SfxPlayer::loadSampleMemory(const std::string& name, const void* data, std::size_t size) {
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
bool SfxPlayer::loadSampleMemory(const std::string& name, const resource& res) {
    return loadSampleMemory(name, res.data, res.size);
}


// Load all samples from a skin
void SfxPlayer::loadSkinSamples(const SkinData::Samples& samples) {
    for (const auto* sample : samples.all()) {
        // * Embedded samples
        if (sample->isEmbedded) {
            if (std::holds_alternative<resource>(sample->data)) [[likely]] {                // Mark as likely; samples should only be resources  
                loadSampleMemory(sample->name, std::get<resource>(sample->data));
            }
        } 
        
        // * External samples
        else {
            if (std::holds_alternative<resource>(sample->data)) [[likely]] {                // Mark as likely; samples should only be resources                    
                const auto& res = std::get<resource>(sample->data);

                // Reinterpret the data back to a string
                // ? This solution is a bit hacky, as it requires `data` (in this   
                // ? case a std::string which stores the external resources filepath) 
                // ? to be first be reinterpreted to const unsigned char*, and then
                // ? back to string. The reason we do this is so that we can store 
                // ? external files using the `resource` struct for consistency/ 
                // ? simplicity with embedded resources, and to avoid adding 2 more
                // ? std::variant types to accommodate external resources. 
                std::string path(reinterpret_cast<const char*>(res.data), res.size);
                
                loadSampleFile(sample->name, path);
            }
        }
    }
}


// * Playback
void SfxPlayer::play(const std::string& name, float volume) {
    auto it = samples.find(name);
    
    if (it == samples.end()) return;
    
    // // HCHANNEL ch = BASS_SampleGetChannel(it->second.sample, FALSE);
    HCHANNEL ch = BASS_SampleGetChannel(it->second, FALSE);
    
    if (!ch) return;
    
    BASS_ChannelSetAttribute(ch, BASS_ATTRIB_VOL, volume);
    BASS_ChannelPlay(ch, TRUE);
}


// * DEBUG
void SfxPlayer::logState() const {
    SFX_LOG("SfxPlayer State:");
    SFX_LOG("  Loaded Samples: " << samples.size());
    for (const auto& [name, sample] : samples) {
        SFX_LOG("    Sample: \"" << name << "\"");
    }
}