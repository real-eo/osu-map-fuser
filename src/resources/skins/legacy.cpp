#include "legacy.h"

// // #define LEGACY_SKIN_BASE "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/"

// // #define EMBED_FILE(varname, relpath)                    \
// //     const unsigned char varname[] = {                   \
// //         #embed LEGACY_SKIN_BASE relpath                 \
// //     };                                                  \
// //     const std::size_t varname##_size = sizeof(varname)

#define EMBED_LVALUE(varname) const unsigned char varname[] = { 
#define RVALUE_SIZE(varname) }; const std::size_t varname##_size = sizeof(varname);

namespace legacy {
// * ==== [AUDIO] ==========================================================
namespace samples {
// * ALL

// * MENU SAMPLES
namespace menu {
} // namespace menu

// * GAMEPLAY
// MP3 samples
EMBED_LVALUE(applause)
#embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/applause.mp3"
RVALUE_SIZE(applause)

EMBED_LVALUE(combobreak)
#embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/combobreak.mp3"
RVALUE_SIZE(combobreak)

EMBED_LVALUE(failsound)
#embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/failsound.mp3"
RVALUE_SIZE(failsound)

namespace section {
    EMBED_LVALUE(fail)
    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sectionfail.mp3"
    RVALUE_SIZE(fail)

    EMBED_LVALUE(pass)
    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sectionpass.mp3"
    RVALUE_SIZE(pass)
} // namespace section


// WAV samples
EMBED_LVALUE(count)
#embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/count.wav" 
RVALUE_SIZE(count)


// * osu!standard
namespace osu {
    // Drum 
    namespace drum {
        namespace hit {
            EMBED_LVALUE(clap)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/drum-hitclap.wav"
            RVALUE_SIZE(clap)
            
            EMBED_LVALUE(finish)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/drum-hitfinish.wav"
            RVALUE_SIZE(finish)
            
            EMBED_LVALUE(normal)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/drum-hitnormal.wav"
            RVALUE_SIZE(normal)
            
            EMBED_LVALUE(whistle)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/drum-hitwhistle.wav"
            RVALUE_SIZE(whistle)
        } // namespace hit

        namespace slider {
            EMBED_LVALUE(slide)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/drum-sliderslide.wav"
            RVALUE_SIZE(slide)

            EMBED_LVALUE(tick)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/drum-slidertick.wav"
            RVALUE_SIZE(tick)

            EMBED_LVALUE(whistle)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/drum-sliderwhistle.wav"
            RVALUE_SIZE(whistle)
        } // namespace slider
    } // namespace drum


    // Nightcore
    namespace nightcore {
        EMBED_LVALUE(clap)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/nightcore-clap.wav"
        RVALUE_SIZE(clap)

        EMBED_LVALUE(finish)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/nightcore-finish.wav"
        RVALUE_SIZE(finish)
        
        EMBED_LVALUE(hat)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/nightcore-hat.wav"
        RVALUE_SIZE(hat)
        
        EMBED_LVALUE(kick)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/nightcore-kick.wav"
        RVALUE_SIZE(kick)
    } // namespace nightcore


    // Normal
    namespace normal {
        namespace hit {
            EMBED_LVALUE(clap)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/normal-hitclap.wav"
            RVALUE_SIZE(clap)

            EMBED_LVALUE(finish)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/normal-hitfinish.wav"
            RVALUE_SIZE(finish)
            
            EMBED_LVALUE(normal)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/normal-hitnormal.wav"
            RVALUE_SIZE(normal)
            
            EMBED_LVALUE(whistle)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/normal-hitwhistle.wav"
            RVALUE_SIZE(whistle)
        } // namespace hit

        namespace slider {
            EMBED_LVALUE(slide)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/normal-sliderslide.wav"
            RVALUE_SIZE(slide)

            EMBED_LVALUE(tick)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/normal-slidertick.wav"
            RVALUE_SIZE(tick)
            
            EMBED_LVALUE(whistle)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/normal-sliderwhistle.wav"
            RVALUE_SIZE(whistle)
        } // namespace slider
    } // namespace normal


    // Soft
    namespace soft {
        namespace hit {
            EMBED_LVALUE(clap)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/soft-hitclap.wav"
            RVALUE_SIZE(clap)
            
            EMBED_LVALUE(finish)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/soft-hitfinish.wav"
            RVALUE_SIZE(finish)
            
            EMBED_LVALUE(normal)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/soft-hitnormal.wav"
            RVALUE_SIZE(normal)
            
            EMBED_LVALUE(whistle)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/soft-hitwhistle.wav"
            RVALUE_SIZE(whistle)
        } // namespace hit

        namespace slider {
            EMBED_LVALUE(slide)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/soft-sliderslide.wav"
            RVALUE_SIZE(slide)

            EMBED_LVALUE(tick)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/soft-slidertick.wav"
            RVALUE_SIZE(tick)

            EMBED_LVALUE(whistle)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/soft-sliderwhistle.wav"
            RVALUE_SIZE(whistle)
        } // namespace slider
    } // namespace soft


    // Spinner
    namespace spinner {
        EMBED_LVALUE(bonus)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinnerbonus.wav"
        RVALUE_SIZE(bonus)

        EMBED_LVALUE(spin)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinnerspin.wav"
        RVALUE_SIZE(spin)
    } // namespace spinner
} // namespace osu


// * osu!taiko
namespace taiko {
    // Drum
    namespace drum {
        namespace hit {
            EMBED_LVALUE(clap)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-drum-hitclap.wav"
            RVALUE_SIZE(clap)
            
            EMBED_LVALUE(finish)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-drum-hitfinish.wav"
            RVALUE_SIZE(finish)
            
            EMBED_LVALUE(normal)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-drum-hitnormal.wav"
            RVALUE_SIZE(normal)

            EMBED_LVALUE(whistle)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-drum-hitwhistle.wav"
            RVALUE_SIZE(whistle);
        } // namespace hit
    } // namespace drum


    // Normal
    namespace normal {
        namespace hit {
            EMBED_LVALUE(clap)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-normal-hitclap.wav"
            RVALUE_SIZE(clap)

            EMBED_LVALUE(finish)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-normal-hitfinish.wav"
            RVALUE_SIZE(finish)
            
            EMBED_LVALUE(normal)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-normal-hitnormal.wav"
            RVALUE_SIZE(normal)

            EMBED_LVALUE(whistle)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-normal-hitwhistle.wav"
            RVALUE_SIZE(whistle);
        } // namespace hit
    } // namespace normal


    // Soft
    namespace soft {
        namespace hit {
            EMBED_LVALUE(clap)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-soft-hitclap.wav"
            RVALUE_SIZE(clap)
            
            EMBED_LVALUE(finish)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-soft-hitfinish.wav"
            RVALUE_SIZE(finish)
            
            EMBED_LVALUE(normal)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-soft-hitnormal.wav"
            RVALUE_SIZE(normal)

            EMBED_LVALUE(whistle)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-soft-hitwhistle.wav"
            RVALUE_SIZE(whistle)
        } // namespace hit
    } // namespace soft
} // namespace taiko
} // namespace samples


// * ==== [IMAGES] =========================================================
namespace sprites {
} // namespace sprites


// * ==== [CONFIGURATION] ==================================================
namespace config {
    // skin.ini
    EMBED_LVALUE(skin_ini)
    #embed "../../../res/skins/Legacy/skin.ini"
    RVALUE_SIZE(skin_ini)
} // namespace config
} // namespace legacy