#pragma once

#include <iostream>
#include <string>                                                       


namespace DEBUG {
    // Global debug enable/disable          - off by default
    inline bool enabled = false;
    
    // Subsystem-specific logging toggles   - on by default
    inline bool logAudioPlayer = true;
    inline bool logSfxPlayer = true;
    inline bool logBeatmapManager = true;
    inline bool logSkinManager = true;
    inline bool logRendering = true;
    inline bool logToolbar = true;

    inline int verbosityLevel = 0;  
} // namespace Debug


// Helper macros for clean logging
#define DEBUG_LOG(msg) if (DEBUG::enabled) { std::cout << "[DEBUG] " << msg << "\n"; }

#define AUDIO_LOG(msg) if (DEBUG::logAudioPlayer) { std::cout << "[Audio] " << msg << "\n"; }
#define SFX_LOG(msg) if (DEBUG::logSfxPlayer) { std::cout << "[SFX] " << msg << "\n"; }
#define BEATMAP_LOG(msg) if (DEBUG::logBeatmapManager) { std::cout << "[Beatmap] " << msg << "\n"; }
#define SKIN_LOG(msg) if (DEBUG::logSkinManager) { std::cout << "[Skin] " << msg << "\n"; }
#define RENDER_LOG(msg) if (DEBUG::logRendering) { std::cout << "[Render] " << msg << "\n"; }
#define TOOLBAR_LOG(msg) if (DEBUG::logToolbar) { std::cout << "[Toolbar] " << msg << "\n"; }

// Error macros
#define DEBUG_ERROR(msg) std::cerr << "[ERROR] " << msg << "\n";

#define AUDIO_ERROR(msg) std::cerr << "[ERROR] [Audio] " << msg << "\n";
#define SFX_ERROR(msg) std::cerr << "[ERROR] [SFX] " << msg << "\n";
#define BEATMAP_ERROR(msg) std::cerr << "[ERROR] [Beatmap] " << msg << "\n";
#define SKIN_ERROR(msg) std::cerr << "[ERROR] [Skin] " << msg << "\n";
#define RENDER_ERROR(msg) std::cerr << "[ERROR] [Render] " << msg << "\n";
#define TOOLBAR_ERROR(msg) std::cerr << "[ERROR] [Toolbar] " << msg << "\n";
