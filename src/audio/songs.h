#pragma once

#include <filesystem>
#include <string>

namespace fs = std::filesystem;


class AudioPlayer {
private:
    bool initialized = false;
    // std::string currentAudioFile;

public:
    AudioPlayer();
    ~AudioPlayer();

    // Initialization
    bool init();
    
    // Loading
    bool load(const fs::path& audioPath);
    
    // Playback control
    void play();
    void pause();
    void stop();
    void togglePause();
    
    // Seeking
    void jumpTo(int ms);
    void relativeJump(int ms);
    
    // Volume & speed
    float getVolume() const;
    float getPlaybackSpeed() const;
    
    void setVolume(float vol);
    void setPlaybackSpeed(float speed);
    
    // Playback state
    int getCurrentTime() const;
    bool isPlaying() const;
    bool isPaused() const;
    bool isStopped() const;

    // DEBUG
    void logState() const;
};
