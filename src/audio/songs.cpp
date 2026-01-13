#include "../utils.h"
#include "songs.h"
#include "../../osuReplayEditorV3/ReplayEditor/audioengine.hpp"

#include <iostream>

#include "../debug/debug.h"



AudioPlayer::AudioPlayer() = default;
AudioPlayer::~AudioPlayer() {
    if (audioengine::handle) [[likely]] {
        audioengine::handle->stop();
        AUDIO_LOG("Destructor: Stopped audio");
    }

    // ? Default member destruction happens automatically here
};


bool AudioPlayer::init() {
    if (!audioengine::init()) {
        AUDIO_ERROR("Failed to initialize audio engine");
        return false;
    }
    
    initialized = true;
    AUDIO_LOG("Initialized");
    
    return true;
}


bool AudioPlayer::load(const fs::path& audioPath) {
    // Validate initialization
    if (!initialized) [[unlikely]] {
        AUDIO_ERROR("Audio engine not initialized");
        return false;
    }

    // Check file existence
    if (!fs::exists(audioPath)) [[unlikely]] {
        AUDIO_ERROR("Audio file not found: " << audioPath.string());
        return false;
    }

    // Convert to wide string for Windows audio engine
    std::wstring widePath = stows(audioPath.string());

    // Load with audio engine (fallback to fake engine if file not found)
    audioengine::load_with_fallback(widePath, 0, 0);
    
    //// currentAudioFile = pathStr;
    //// std::cout << "[AudioPlayer] Loaded: " << currentAudioFile << "\n";
    return true;
}

// Playback control - all calls must be made through the handle, as this is the exposed endpoint for the audio engine
void AudioPlayer::play() {
    if (audioengine::handle) [[likely]] {
        audioengine::handle->play();
        AUDIO_LOG("Play");
    }
}

void AudioPlayer::pause() {
    if (audioengine::handle) [[likely]] {
        audioengine::handle->pause();
        AUDIO_LOG("Pause");
    }
}

void AudioPlayer::stop() {
    if (audioengine::handle) [[likely]] {
        audioengine::handle->stop();
        AUDIO_LOG("Stop");
    }
}

void AudioPlayer::togglePause() {
    if (audioengine::handle) [[likely]] {
        audioengine::handle->toggle_pause();
    }
}

void AudioPlayer::jumpTo(int ms) {
    if (audioengine::handle) [[likely]] {
        audioengine::handle->jump_to(ms);
    }
}

void AudioPlayer::relativeJump(int ms) {
    if (audioengine::handle) [[likely]] {
        audioengine::handle->rel_jump(ms);
    }
}

void AudioPlayer::setVolume(float vol) {
    if (audioengine::handle) [[likely]] {
        audioengine::handle->set_volume(vol);
    }
}

float AudioPlayer::getVolume() const {
    if (audioengine::handle) [[likely]] {
        return audioengine::handle->get_volume();
    }
    return 0.0f;
}

void AudioPlayer::setPlaybackSpeed(float speed) {
    if (audioengine::handle) [[likely]] {
        audioengine::handle->set_playback_speed(speed);
    }
}

float AudioPlayer::getPlaybackSpeed() const {
    if (audioengine::handle) [[likely]]{
        return audioengine::handle->get_playback_speed();
    }
    return 1.0f;
}

int AudioPlayer::getCurrentTime() const {
    if (audioengine::handle) [[likely]] {
        return audioengine::handle->get_time();
    }
    return 0;
}

bool AudioPlayer::isPlaying() const {
    if (audioengine::handle) [[likely]] {
        return audioengine::handle->is_playing();
    }
    return false;
}

bool AudioPlayer::isPaused() const {
    if (audioengine::handle) [[likely]] {
        return audioengine::handle->is_paused();
    }
    return false;
}

bool AudioPlayer::isStopped() const {
    if (audioengine::handle) [[likely]] {
        return audioengine::handle->is_stopped();
    }
    return true;
}


// DEBUG
void AudioPlayer::logState() const {
    AUDIO_LOG("AudioPlayer State:");
    AUDIO_LOG("  Volume: " << getVolume());
    AUDIO_LOG("  Playback Speed: " << getPlaybackSpeed());
    AUDIO_LOG("  Current Time: " << getCurrentTime() << " ms");
    AUDIO_LOG("  Is Playing: " << isPlaying());
    AUDIO_LOG("  Is Paused: " << isPaused());
    AUDIO_LOG("  Is Stopped: " << isStopped());
}