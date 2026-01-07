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
// * MENU SAMPLES
// ! UNUSED in the osu!lazer client, same goes for the osu!map fuser
// // namespace UI {
// // } // namespace UI

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
// ! Note: All images in legacy skin are in @2x (HD) resolution, and no animations, but  
// !       I'll treat the implementation as if both SD, HD and frames exist for future-proofing.
namespace sprites {
// * MENU
namespace UI {
    namespace star {
        // Star texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/star@2x.png"
        RVALUE_SIZE(HD)
    } // namespace star
    namespace star2 {
        // Star2 texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/star2@2x.png"
        RVALUE_SIZE(HD)
    } // namespace star2
    namespace star3 {                                                                   // ? I honestly don't even know what this is for
        // Star3 texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/star3@2x.png"
        RVALUE_SIZE(HD)
    } // namespace star3
} // namespace UI

// * GAMEPLAY
// Multiple modes
namespace comboburst {
    // // EMBED_LVALUE(SD)
    // // #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/comboburst.png"
    // // RVALUE_SIZE(SD)

    EMBED_LVALUE(HD)
    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/comboburst@2x.png"
    RVALUE_SIZE(HD)
} // namespace comboburst
namespace count {
    namespace ONE {                                                                         // ? Spelling "1" to avoid invalid namespace names
        // // EMBED_LVALUE(SD)
        // // #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/count1.png"
        // // RVALUE_SIZE(SD)

        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/count1@2x.png"
        RVALUE_SIZE(HD)
    } // namespace ONE
    namespace TWO {                                                                         // ? Spelling "2" to avoid invalid namespace names
        // // EMBED_LVALUE(SD)
        // // #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/count2.png"
        // // RVALUE_SIZE(SD)

        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/count2@2x.png"
        RVALUE_SIZE(HD)
    } // namespace TWO
    namespace THREE {                                                                       // ? Spelling "3" to avoid invalid namespace names
        // // EMBED_LVALUE(SD)
        // // #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/count3.png"
        // // RVALUE_SIZE(SD)

        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/count3@2x.png"
        RVALUE_SIZE(HD)
    } // namespace THREE
} // namespace count
namespace cursor {
    // Cursor texture
    EMBED_LVALUE(HD)
    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/cursor@2x.png"
    RVALUE_SIZE(HD)

    namespace trail {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/cursortrail@2x.png"
        RVALUE_SIZE(HD)
    } // namespace trail
    namespace middle {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/cursormiddle@2x.png"
        RVALUE_SIZE(HD)
    } // namespace middle
    namespace smoke {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/cursor-smoke@2x.png"
        RVALUE_SIZE(HD)
    } // namespace smoke
} // namespace cursor
namespace go {
    // Go texture
    EMBED_LVALUE(HD)
    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/go@2x.png"
    RVALUE_SIZE(HD)
} // namespace go
namespace inputoverlay {
    namespace background {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/inputoverlay-background@2x.png"
        RVALUE_SIZE(HD)
    } // namespace background
    namespace key {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/inputoverlay-key@2x.png"
        RVALUE_SIZE(HD)
    } // namespace key
} // namespace inputoverlay
namespace ranking {
    namespace XH {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/ranking-XH-small@2x.png"
        RVALUE_SIZE(HD)
    }
    namespace X {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/ranking-X-small@2x.png"
        RVALUE_SIZE(HD)
    } // namespace X
    namespace SH {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/ranking-SH-small@2x.png"
        RVALUE_SIZE(HD)
    } // namespace SH
    namespace S {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/ranking-S-small@2x.png"
        RVALUE_SIZE(HD)
    } // namespace S
    namespace A {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/ranking-A-small@2x.png"
        RVALUE_SIZE(HD)
    } // namespace A
    namespace B {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/ranking-B-small@2x.png"
        RVALUE_SIZE(HD)
    } // namespace B
    namespace C {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/ranking-C-small@2x.png"
        RVALUE_SIZE(HD)
    } // namespace C
    namespace D {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/ranking-D-small@2x.png"
        RVALUE_SIZE(HD)
    } // namespace D
} // namespace ranking
namespace ready {
    // Ready texture
    EMBED_LVALUE(HD)
    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/ready@2x.png"
    RVALUE_SIZE(HD)
} // namespace ready
namespace score {
    namespace ZERO {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-0@2x.png"
        RVALUE_SIZE(HD)
    } // namespace ZERO
    namespace ONE {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-1@2x.png"
        RVALUE_SIZE(HD)
    } // namespace ONE
    namespace TWO {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-2@2x.png"
        RVALUE_SIZE(HD)
    } // namespace TWO
    namespace THREE {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-3@2x.png"
        RVALUE_SIZE(HD)
    } // namespace THREE
    namespace FOUR {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-4@2x.png"
        RVALUE_SIZE(HD)
    } // namespace FOUR
    namespace FIVE {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-5@2x.png"
        RVALUE_SIZE(HD)
    } // namespace FIVE
    namespace SIX {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-6@2x.png"
        RVALUE_SIZE(HD)
    } // namespace SIX
    namespace SEVEN {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-7@2x.png"
        RVALUE_SIZE(HD)
    } // namespace SEVEN
    namespace EIGHT {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-8@2x.png"
        RVALUE_SIZE(HD)
    } // namespace EIGHT
    namespace NINE {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-9@2x.png"
        RVALUE_SIZE(HD)
    } // namespace NINE
    namespace comma {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-comma@2x.png"
        RVALUE_SIZE(HD)
    } // namespace comma
    namespace dot {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-dot@2x.png"
        RVALUE_SIZE(HD)
    } // namespace dot
    namespace percent {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-percent@2x.png"
        RVALUE_SIZE(HD)
    } // namespace percent
    namespace pp {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-pp@2x.png"
        RVALUE_SIZE(HD)
    } // namespace pp
    namespace x {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/score-x@2x.png"
        RVALUE_SIZE(HD)
    } // namespace x
} // namespace score
namespace scorebar {
    namespace bg {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/scorebar-bg@2x.png"
        RVALUE_SIZE(HD)
    } // namespace bg
    namespace colour {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/scorebar-colour@2x.png"
        RVALUE_SIZE(HD)
    } // namespace colour
    namespace marker {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/scorebar-marker@2x.png"
        RVALUE_SIZE(HD)
    } // namespace marker
} // namespace scorebar
namespace scoreboard {
    namespace explosion {
        namespace ONE {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/scoreboard-explosion-1@2x.png"
            RVALUE_SIZE(HD)
        } // namespace ONE
        namespace TWO {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/scoreboard-explosion-2@2x.png"
            RVALUE_SIZE(HD)
        } // namespace TWO
} // namespace scoreboard


// * osu!standard
namespace osu {
    namespace approachcircle {
        // // EMBED_LVALUE(SD)
        // // #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/approachcircle.png"
        // // RVALUE_SIZE(SD)

        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/approachcircle@2x.png"
        RVALUE_SIZE(HD)
    } // namespace approachcircle
    namespace default {                                                                     // ? Combo numbers; "default" is a reserved keyword
        namespace ZERO {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-0@2x.png"
            RVALUE_SIZE(HD)
        } // namespace ZERO
        namespace ONE {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-1@2x.png"
            RVALUE_SIZE(HD)
        } // namespace ONE
        namespace TWO {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-2@2x.png"
            RVALUE_SIZE(HD)
        } // namespace TWO
        namespace THREE {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-3@2x.png"
            RVALUE_SIZE(HD)
        } // namespace THREE
        namespace FOUR {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-4@2x.png"
            RVALUE_SIZE(HD)
        } // namespace FOUR
        namespace FIVE {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-5@2x.png"
            RVALUE_SIZE(HD)
        } // namespace FIVE
        namespace SIX {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-6@2x.png"
            RVALUE_SIZE(HD)
        } // namespace SIX
        namespace SEVEN {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-7@2x.png"
            RVALUE_SIZE(HD)
        } // namespace SEVEN
        namespace EIGHT {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-8@2x.png"
            RVALUE_SIZE(HD)
        } // namespace EIGHT
        namespace NINE {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/default-9@2x.png"
        RVALUE_SIZE(HD)
    } // namespace NINE
    } // namespace default
    namespace followpoint {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/followpoint@2x.png"
        RVALUE_SIZE(HD)
    } // namespace followpoint
    namespace hit {
        // ? Using game terminology to avoid invalid namespace names. See: https://github.com/ppy/osu/wiki/Scoring
        namespace miss {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hit0@2x.png"
            RVALUE_SIZE(HD)
        } // namespace miss
        namespace meh {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hit50@2x.png"
            RVALUE_SIZE(HD)
        } // namespace meh
        namespace ok {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hit100@2x.png"
            RVALUE_SIZE(HD)

            namespace katsu {
                // 100k texture
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hit100k@2x.png"
                RVALUE_SIZE(HD)
            } // namespace katsu
        } // namespace ok
        namespace great {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hit300@2x.png"
            RVALUE_SIZE(HD)

            namespace geki {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hit300g@2x.png"
                RVALUE_SIZE(HD)
            } // namespace geki
            namespace katsu {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hit300k@2x.png"
                RVALUE_SIZE(HD)
            } // namespace katsu
        } // namespace great
    } // namespace hit
    namespace hitcircle {
        // Hit circle texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hitcircle@2x.png"
        RVALUE_SIZE(HD)

        namespace overlay {
            // Hit circle overlay texture
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hitcircleoverlay@2x.png"
            RVALUE_SIZE(HD)
        } // namespace overlay
        namespace select {
            // Hit circle select texture
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/hitcircleselect@2x.png"
            RVALUE_SIZE(HD)
        } // namespace select
    } // namespace hitcircle
    namespace particle {
        // ? Using game terminology to avoid invalid namespace names. See: https://github.com/ppy/osu/wiki/Scoring
        namespace meh {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/particle50@2x.png"
            RVALUE_SIZE(HD)
        } // namespace meh
        namespace ok {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/particle100@2x.png"
            RVALUE_SIZE(HD)
        } // namespace ok
        namespace great {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/particle300@2x.png"
            RVALUE_SIZE(HD)
        } // namespace great
    } // namespace particle
    namespace reversearrow {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/reversearrow@2x.png"
        RVALUE_SIZE(HD)
    } // namespace reversearrow
    namespace slider {
        namespace b {
            namespace _frames {
                // When externing, use byte-matricies, and implement 
                // each frame as a byte array in their correct order.
                namespace ZERO {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb0@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace ZERO
                namespace ONE {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb1@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace ONE
                namespace TWO {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb2@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace TWO
                namespace THREE {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb3@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace THREE
                namespace FOUR {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb4@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace FOUR
                namespace FIVE {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb5@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace FIVE
                namespace SIX {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb6@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace SIX
                namespace SEVEN {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb7@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace SEVEN
                namespace EIGHT {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb8@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace EIGHT
                namespace NINE {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb9@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace NINE
            } // namespace _frames
            namespace nd {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb-nd@2x.png"
                RVALUE_SIZE(HD)
            } // namespace nd
            namespace spec {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderb-spec@2x.png"
                RVALUE_SIZE(HD)
            } // namespace spec
        } // namespace b
        namespace endmiss {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderendmiss@2x.png"
            RVALUE_SIZE(HD)
        } // namespace endmiss
        namespace followcircle {
            // Slider follow circle texture
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderfollowcircle@2x.png"
            RVALUE_SIZE(HD)
        } // namespace followcircle
        namespace scorepoint {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/sliderpoint@2x.png"
            RVALUE_SIZE(HD)
        }
        namespace tickmiss {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/slidertickmiss@2x.png"
            RVALUE_SIZE(HD)
        } // namespace tickmiss
    } // namespace slider
    namespace spinner {
        namespace approachcircle {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-approachcircle@2x.png"
            RVALUE_SIZE(HD)
        } // namespace approachcircle
        namespace bottom {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-bottom@2x.png"
            RVALUE_SIZE(HD)
        } // namespace bottom
        namespace circle {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-circle@2x.png"
            RVALUE_SIZE(HD)
        } // namespace circle
        namespace clear {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-clear@2x.png"
            RVALUE_SIZE(HD)
        } // namespace clear
        namespace glow {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-glow@2x.png"
            RVALUE_SIZE(HD)
        } // namespace glow
        namespace middle {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-middle@2x.png"
            RVALUE_SIZE(HD)
        } // namespace middle
        namespace middle2 {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-middle2@2x.png"
            RVALUE_SIZE(HD)
        } // namespace middle2
        namespace rpm {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-rpm@2x.png"
            RVALUE_SIZE(HD)
        } // namespace rpm
        namespace spin {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-spin@2x.png"
            RVALUE_SIZE(HD)
        } // namespace spin
        namespace top {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-top@2x.png"
            RVALUE_SIZE(HD)
        } // namespace top
        namespace warning {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/spinner-warning@2x.png"
            RVALUE_SIZE(HD)
        } // namespace warning
    } // namespace spinner
} // namespace osu

// * osu!taiko
namespace taiko {
    namespace pippidon {
        namespace clear {
            namespace _frames {
                // When externing, use byte-matricies, and implement 
                // each frame as a byte array in their correct order.
                namespace ZERO {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonclear0.png"
                    RVALUE_SIZE(SD)
                } // namespace ZERO
                namespace ONE {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonclear1.png"
                    RVALUE_SIZE(SD)
                } // namespace ONE
                namespace TWO {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonclear2.png"
                    RVALUE_SIZE(SD)
                } // namespace TWO
                namespace THREE {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonclear3.png"
                    RVALUE_SIZE(SD)
                } // namespace THREE
                namespace FOUR {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonclear4.png"
                    RVALUE_SIZE(SD)
                } // namespace FOUR
                namespace FIVE {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonclear5.png"
                    RVALUE_SIZE(SD)
                } // namespace FIVE
                namespace SIX {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonclear6.png"
                    RVALUE_SIZE(SD)
                } // namespace SIX
                namespace SEVEN {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonclear7.png"
                    RVALUE_SIZE(SD)
                } // namespace SEVEN
                namespace EIGHT {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonclear8.png"
                    RVALUE_SIZE(SD)
                } // namespace EIGHT
            } // namespace _frames
        } // namespace clear

        namespace fail {
            namespace _frames {
                // When externing, use byte-matricies, and implement 
                // each frame as a byte array in their correct order.
                namespace ZERO {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonfail0.png"
                    RVALUE_SIZE(SD)
                } // namespace ZERO
                namespace ONE {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonfail1.png"
                    RVALUE_SIZE(SD)
                } // namespace ONE
                namespace TWO {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonfail2.png"
                    RVALUE_SIZE(SD)
                } // namespace TWO
            } // namespace _frames
        } // namespace fail

        namespace idle {
            namespace _frames {
                // When externing, use byte-matricies, and implement 
                // each frame as a byte array in their correct order.
                namespace ZERO {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonidle0.png"
                    RVALUE_SIZE(SD)
                } // namespace ZERO
                namespace ONE {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonidle1.png"
                    RVALUE_SIZE(SD)
                } // namespace ONE
            } // namespace _frames
        } // namespace idle

        namespace kiai {
            namespace _frames {
                // When externing, use byte-matricies, and implement 
                // each frame as a byte array in their correct order.
                namespace ZERO {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonkiai0.png"
                    RVALUE_SIZE(SD)
                } // namespace ZERO
                namespace ONE {
                    EMBED_LVALUE(SD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/pippidonkiai1.png"
                    RVALUE_SIZE(SD)
                } // namespace ONE
            } // namespace _frames
        } // namespace kiai
    } // namespace pippidon
    namespace bar {
        namespace left {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-bar-left@2x.png"
            RVALUE_SIZE(HD)
        } // namespace left
        namespace line {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-barline@2x.png"
            RVALUE_SIZE(HD)
        } // namespace line
        namespace right {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-bar-right@2x.png"
            RVALUE_SIZE(HD)

            namespace glow {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-bar-right-glow@2x.png"
                RVALUE_SIZE(HD)
            } // namespace glow
        } // namespace right
    } // namespace bar
    namespace bigcircle {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taikobigcircle@2x.png"
        RVALUE_SIZE(HD)

        namespace overlay {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taikobigcircleoverlay@2x.png"
            RVALUE_SIZE(HD)
        } // namespace overlay
    } // namespace bigcircle
    namespace drum {
        namespace inner {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-drum-inner@2x.png"
            RVALUE_SIZE(HD)
        } // namespace inner
        namespace outer {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-drum-outer@2x.png"
            RVALUE_SIZE(HD)
        } // namespace outer
    } // namespace drum
    namespace glow {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-glow@2x.png"
        RVALUE_SIZE(HD)
    }
    namespace hit {
        // ? Using game terminology to avoid invalid namespace names. See: https://github.com/ppy/osu/wiki/Scoring
        namespace miss {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-hit0@2x.png"
            RVALUE_SIZE(HD)
        } // namespace miss
        namespace ok {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-hit100@2x.png"
            RVALUE_SIZE(HD)

            namespace katsu {
                // 100k texture
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-hit100k@2x.png"
                RVALUE_SIZE(HD)
            } // namespace katsu
        } // namespace ok
        namespace great {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-hit300@2x.png"
            RVALUE_SIZE(HD)

            namespace geki {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-hit300g@2x.png"
                RVALUE_SIZE(HD)
            } // namespace geki
            namespace katsu {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-hit300k@2x.png"
                RVALUE_SIZE(HD)
            } // namespace katsu
        } // namespace great
    } // namespace hit
    namespace hitcircle {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taikohitcircle@2x.png"
        RVALUE_SIZE(HD)

        namespace overlay {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taikohitcircleoverlay@2x.png"
            RVALUE_SIZE(HD)
        } // namespace overlay
    } // namespace hitcircle
    namespace roll {
        namespace end {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-rollend@2x.png"
            RVALUE_SIZE(HD)
        } // namespace end
        namespace middle {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-rollmiddle@2x.png"
            RVALUE_SIZE(HD)
        } // namespace middle
    } // namespace roll
    namespace slider {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-slider@2x.png"
        RVALUE_SIZE(HD)

        namespace fail {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/taiko-slider-fail@2x.png"
            RVALUE_SIZE(HD)
        } // namespace fail
    } // namespace slider
} // namespace taiko



// * osu!catch
namespace catchthebeat {
    namespace apple {
        // Apple texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-apple@2x.png"
        RVALUE_SIZE(HD)
        
        namespace overlay {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-apple-overlay@2x.png"
            RVALUE_SIZE(HD)
        } // namespace overlay
    } // namespace apple

    namespace bananas {
        // Banana texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-bananas@2x.png"
        RVALUE_SIZE(HD)

        namespace overlay {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-bananas-overlay@2x.png"
            RVALUE_SIZE(HD)
        } // namespace overlay
    } // namespace bananas

    namespace catcher {
        namespace fail {
            // Catcher fail texture
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-catcher-fail@2x.png"
            RVALUE_SIZE(HD)
        } // namespace fail
        namespace idle {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-catcher-idle@2x.png"
            RVALUE_SIZE(HD)
        } // namespace idle
        namespace kiai {
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-catcher-kiai@2x.png"
        RVALUE_SIZE(HD)
    } // namespace kiai
    } // namespace catcher

    namespace drop {
        // Drop texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-drop@2x.png"
        RVALUE_SIZE(HD)
    }

    namespace grapes {
        // Grape texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-grapes@2x.png"
        RVALUE_SIZE(HD)

        namespace overlay {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-grapes-overlay@2x.png"
            RVALUE_SIZE(HD)
        } // namespace overlay
    } // namespace grapes

    namespace orange {
        // Orange texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-orange@2x.png"
        RVALUE_SIZE(HD)

        namespace overlay {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-orange-overlay@2x.png"
            RVALUE_SIZE(HD)
        } // namespace overlay
    } // namespace orange

    namespace pear {
        // Pear texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-pear@2x.png"
        RVALUE_SIZE(HD)

        namespace overlay {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/fruit-pear-overlay@2x.png"
            RVALUE_SIZE(HD)
        } // namespace overlay
    } // namespace pear

} // namespace catchthebeat


// * osu!mania
namespace mania {
    namespace lighting {
        // Lighting texture
        EMBED_LVALUE(HD)
        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/lighting@2x.png"
        RVALUE_SIZE(HD)

        namespace L {
            namespace _frames {
                // When externing, use byte-matricies, and implement 
                // each frame as a byte array in their correct order.
                namespace ZERO {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/lightingL-0@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace ZERO
                namespace ONE {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/lightingL-1@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace ONE
                namespace TWO {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/lightingL-2@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace TWO
                namespace THREE {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/lightingL-3@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace THREE
                namespace FOUR {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/lightingL-4@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace FOUR
                namespace FIVE {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/lightingL-5@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace FIVE
            } // namespace _frames
        } // namespace L

        namespace N {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/lightingN@2x.png"
            RVALUE_SIZE(HD)
        } // namespace N
    } // namespace lighting
    namespace hit {
        // ? Using game terminology to avoid invalid namespace names. See: https://github.com/ppy/osu/wiki/Scoring
        namespace miss {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-hit0@2x.png"
            RVALUE_SIZE(HD)
        } // namespace miss
        namespace meh {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-hit50@2x.png"
            RVALUE_SIZE(HD)
        } // namespace meh
        namespace ok {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-hit100@2x.png"
            RVALUE_SIZE(HD)
        } // namespace ok
        namespace good {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-hit200@2x.png"
            RVALUE_SIZE(HD)
        } // namespace good
        namespace great {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-hit300@2x.png"
            RVALUE_SIZE(HD)
        } // namespace great
        namespace perfect {
            namespace _frames {
                // When externing, use byte-matricies, and implement 
                // each frame as a byte array in their correct order.
                namespace ZERO {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-hit300g-0@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace ZERO
                namespace ONE {
                    EMBED_LVALUE(HD)
                    #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-hit300g-1@2x.png"
                    RVALUE_SIZE(HD)
                } // namespace ONE
            } // namespace _frames
        } // namespace perfect
    } // namespace hit
    namespace key {
        namespace ONE {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-key1@2x.png"
            RVALUE_SIZE(HD)

            namespace D {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-key1D@2x.png"
                RVALUE_SIZE(HD)
            } // namespace D
        } // namespace ONE
        namespace TWO {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-key2@2x.png"
            RVALUE_SIZE(HD)

            namespace D {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-key2D@2x.png"
                RVALUE_SIZE(HD)
            } // namespace D
        } // namespace TWO
        namespace S {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-keyS@2x.png"
            RVALUE_SIZE(HD)

            namespace D {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-keySD@2x.png"
                RVALUE_SIZE(HD)
            } // namespace D
        } // namespace S
    } // namespace key

    namespace note {
        namespace ONE {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note1@2x.png"
            RVALUE_SIZE(HD)

            namespace H {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note1H@2x.png"
                RVALUE_SIZE(HD)
            } // namespace H
            namespace L {
                namespace _frames {
                    // When externing, use byte-matricies, and implement 
                    // each frame as a byte array in their correct order.
                    namespace ZERO {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note1L-0@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace ZERO
                    namespace ONE {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note1L-1@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace ONE
                    namespace TWO {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note1L-2@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace TWO
                    namespace THREE {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note1L-3@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace THREE
                    namespace FOUR {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note1L-4@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace FOUR
                    namespace FIVE {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note1L-5@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace FIVE
                } // namespace _frames
            } // namespace L
        } // namespace ONE

        namespace TWO {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note2@2x.png"
            RVALUE_SIZE(HD)

            namespace H {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note2H@2x.png"
                RVALUE_SIZE(HD)
            } // namespace H
            namespace L {
                namespace _frames {
                    // When externing, use byte-matricies, and implement 
                    // each frame as a byte array in their correct order.
                    namespace ZERO {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note2L-0@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace ZERO
                    namespace ONE {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note2L-1@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace ONE
                    namespace TWO {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note2L-2@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace TWO
                    namespace THREE {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note2L-3@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace THREE
                    namespace FOUR {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note2L-4@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace FOUR
                    namespace FIVE {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-note2L-5@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace FIVE
                } // namespace _frames
            } // namespace L
        } // namespace TWO

        namespace S {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-noteS@2x.png"
            RVALUE_SIZE(HD)

            namespace H {
                EMBED_LVALUE(HD)
                #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-noteSH@2x.png"
                RVALUE_SIZE(HD)
            } // namespace H
            namespace L {
                namespace _frames {
                    // When externing, use byte-matricies, and implement 
                    // each frame as a byte array in their correct order.
                    namespace ZERO {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-noteSL-0@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace ZERO
                    namespace ONE {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-noteSL-1@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace ONE
                    namespace TWO {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-noteSL-2@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace TWO
                    namespace THREE {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-noteSL-3@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace THREE
                    namespace FOUR {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-noteSL-4@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace FOUR
                    namespace FIVE {
                        EMBED_LVALUE(HD)
                        #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-noteSL-5@2x.png"
                        RVALUE_SIZE(HD)
                    } // namespace FIVE
                } // namespace _frames
            } // namespace L
        } // namespace S
    } // namespace note

    namespace stage {
        namespace hint {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-stage-hint@2x.png"
            RVALUE_SIZE(HD)
        } // namespace hint
        namespace left {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-stage-left@2x.png"
            RVALUE_SIZE(HD)
        } // namespace left
        namespace light {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-stage-light@2x.png"
            RVALUE_SIZE(HD)
        } // namespace light
        namespace right {
            EMBED_LVALUE(HD)
            #embed "../../../osu-resources-2025.1218.0/osu.Game.Resources/Skins/Legacy/mania-stage-right@2x.png"
            RVALUE_SIZE(HD)
        } // namespace right
    } // namespace stage
} // namespace mania




} // namespace sprites


// * ==== [CONFIGURATION] ==================================================
namespace config {
    // skin.ini
    EMBED_LVALUE(skin_ini)
    #embed "../../../res/skins/Legacy/skin.ini"
    RVALUE_SIZE(skin_ini)
} // namespace config
} // namespace legacy