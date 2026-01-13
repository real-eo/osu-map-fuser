#pragma once

#include "../utils.h"                                                                   // ? Resource utilities 

// * Macro to declare external embedded files
#define EXTERN_FILE(varname)                    \
    extern const unsigned char varname[];       \
    extern const std::size_t varname##_size

// * Audio macros
#define EXTERN_SAMPLE_SECTION(ns)               \
    namespace ns {                              \
    namespace hit {                             \
        EXTERN_FILE(clap);                      \
        EXTERN_FILE(finish);                    \
        EXTERN_FILE(normal);                    \
        EXTERN_FILE(whistle);                   \
    }                                           \
                                                \
    namespace slider {                          \
        EXTERN_FILE(slide);                     \
        EXTERN_FILE(tick);                      \
        EXTERN_FILE(whistle);                   \
    } /* namespace slider */                    \
    } // namespace ns

#define EXTERN_SAMPLE_SECTION_TAIKO(ns)         \
    namespace ns {                              \
    namespace hit {                             \
        EXTERN_FILE(clap);                      \
        EXTERN_FILE(finish);                    \
        EXTERN_FILE(normal);                    \
        EXTERN_FILE(whistle);                   \
    } /* namespace hit */                       \
    } // namespace ns

// * Sprite macros
#define EXTERN_SPRITE(varname,definition)       \
    namespace varname {                         \
        EXTERN_FILE(definition);                \
    } // namespace varname    

#define EXTERN_ANIMATED(varname,definition)             \
    namespace varname {                                 \
        extern const frame definition[];                \
        extern const std::size_t definition##_frames;   \
    } /* namespace varname */                   

// * Embed legacy skin resources
namespace legacy { 

namespace samples {

// MP3 samples
EXTERN_FILE(applause);
EXTERN_FILE(combobreak);
EXTERN_FILE(failsound);

namespace section {
    EXTERN_FILE(fail);
    EXTERN_FILE(pass);
} // namespace section


// WAV samples
EXTERN_FILE(count);

// * osu!standard
namespace osu {

// Sample sections
EXTERN_SAMPLE_SECTION(drum);
namespace nightcore {
    EXTERN_FILE(clap);
    EXTERN_FILE(finish);
    EXTERN_FILE(hat);
    EXTERN_FILE(kick);
} // namespace nightcore
EXTERN_SAMPLE_SECTION(normal);
EXTERN_SAMPLE_SECTION(soft);

// Spinner
namespace spinner {
    EXTERN_FILE(bonus);
    EXTERN_FILE(spin);
} // namespace spinner
} // namespace osu


// * osu!taiko
namespace taiko {
EXTERN_SAMPLE_SECTION_TAIKO(drum);
EXTERN_SAMPLE_SECTION_TAIKO(normal);
EXTERN_SAMPLE_SECTION_TAIKO(soft);
} // namespace taiko
} // namespace samples





// * IMAGES
namespace sprites {
// * MENU
namespace UI {
    EXTERN_SPRITE(star, HD);
    EXTERN_SPRITE(star2, HD);
    EXTERN_SPRITE(star3, HD);
} // namespace UI

// * GAMEPLAY
// Multiple modes
EXTERN_SPRITE(comboburst, HD);

EXTERN_SPRITE(ready, HD);
EXTERN_SPRITE(count::ONE, HD);
EXTERN_SPRITE(count::TWO, HD);
EXTERN_SPRITE(count::THREE, HD);
EXTERN_SPRITE(go, HD);

EXTERN_SPRITE(cursor, HD);
EXTERN_SPRITE(cursor::trail, HD);
EXTERN_SPRITE(cursor::middle, HD);
EXTERN_SPRITE(cursor::smoke, HD);

EXTERN_SPRITE(inputoverlay::background, HD);
EXTERN_SPRITE(inputoverlay::key, HD);

EXTERN_SPRITE(ranking::XH, HD);
EXTERN_SPRITE(ranking::X, HD);

EXTERN_SPRITE(ranking::SH, HD);
EXTERN_SPRITE(ranking::S, HD);
EXTERN_SPRITE(ranking::A, HD);
EXTERN_SPRITE(ranking::B, HD);
EXTERN_SPRITE(ranking::C, HD);
EXTERN_SPRITE(ranking::D, HD);

EXTERN_SPRITE(score::ZERO, HD);
EXTERN_SPRITE(score::ONE, HD);
EXTERN_SPRITE(score::TWO, HD);
EXTERN_SPRITE(score::THREE, HD);
EXTERN_SPRITE(score::FOUR, HD);
EXTERN_SPRITE(score::FIVE, HD);
EXTERN_SPRITE(score::SIX, HD);
EXTERN_SPRITE(score::SEVEN, HD);
EXTERN_SPRITE(score::EIGHT, HD);
EXTERN_SPRITE(score::NINE, HD);
EXTERN_SPRITE(score::comma, HD);
EXTERN_SPRITE(score::dot, HD);
EXTERN_SPRITE(score::percent, HD);
EXTERN_SPRITE(score::pp, HD);
EXTERN_SPRITE(score::x, HD);

EXTERN_SPRITE(scorebar::bg, HD);
EXTERN_SPRITE(scorebar::colour, HD);
EXTERN_SPRITE(scorebar::marker, HD);

EXTERN_SPRITE(scoreboard::explosion::ONE, HD);
EXTERN_SPRITE(scoreboard::explosion::TWO, HD);


// * osu!standard
namespace osu {
    EXTERN_SPRITE(approachcircle, HD);

    EXTERN_SPRITE(default_::ZERO, HD);
    EXTERN_SPRITE(default_::ONE, HD);
    EXTERN_SPRITE(default_::TWO, HD);
    EXTERN_SPRITE(default_::THREE, HD);
    EXTERN_SPRITE(default_::FOUR, HD);
    EXTERN_SPRITE(default_::FIVE, HD);
    EXTERN_SPRITE(default_::SIX, HD);
    EXTERN_SPRITE(default_::SEVEN, HD);
    EXTERN_SPRITE(default_::EIGHT, HD);
    EXTERN_SPRITE(default_::NINE, HD);

    EXTERN_SPRITE(followpoint, HD);

    EXTERN_SPRITE(hit::miss, HD);
    EXTERN_SPRITE(hit::meh, HD);
    EXTERN_SPRITE(hit::ok, HD);
    EXTERN_SPRITE(hit::ok::katsu, HD);
    EXTERN_SPRITE(hit::great, HD);
    EXTERN_SPRITE(hit::great::geki, HD);
    EXTERN_SPRITE(hit::great::katsu, HD);

    EXTERN_SPRITE(hitcircle, HD);
    EXTERN_SPRITE(hitcircle::overlay, HD);
    EXTERN_SPRITE(hitcircle::select, HD);

    EXTERN_SPRITE(particle::meh, HD);
    EXTERN_SPRITE(particle::ok, HD);
    EXTERN_SPRITE(particle::great, HD);

    EXTERN_SPRITE(reversearrow, HD);
    EXTERN_ANIMATED(slider::b, HD);
    EXTERN_SPRITE(slider::b::nd, HD);
    EXTERN_SPRITE(slider::b::spec, HD);
    EXTERN_SPRITE(slider::endmiss, HD);
    EXTERN_SPRITE(slider::followcircle, HD);
    EXTERN_SPRITE(slider::scorepoint, HD);
    EXTERN_SPRITE(slider::tickmiss, HD);

    EXTERN_SPRITE(spinner::approachcircle, HD);
    EXTERN_SPRITE(spinner::bottom, HD);
    EXTERN_SPRITE(spinner::circle, HD);
    EXTERN_SPRITE(spinner::clear, HD);
    EXTERN_SPRITE(spinner::glow, HD);
    EXTERN_SPRITE(spinner::middle, HD);
    EXTERN_SPRITE(spinner::middle2, HD);
    EXTERN_SPRITE(spinner::rpm, HD);
    EXTERN_SPRITE(spinner::spin, HD);
    EXTERN_SPRITE(spinner::top, HD);
    EXTERN_SPRITE(spinner::warning, HD);
} // namespace osu



// * osu!taiko
namespace taiko {
    EXTERN_ANIMATED(pippidon::clear, SD);
    EXTERN_ANIMATED(pippidon::fail, SD);
    EXTERN_ANIMATED(pippidon::idle, SD);
    EXTERN_ANIMATED(pippidon::kiai, SD);

    EXTERN_SPRITE(bar::left, HD);
    EXTERN_SPRITE(bar::line, HD);
    EXTERN_SPRITE(bar::right, HD);
    EXTERN_SPRITE(bar::right::glow, HD);

    EXTERN_SPRITE(bigcircle, HD);
    EXTERN_SPRITE(bigcircle::overlay, HD);

    EXTERN_SPRITE(drum::inner, HD);
    EXTERN_SPRITE(drum::outer, HD);

    EXTERN_SPRITE(glow, HD);
    
    EXTERN_SPRITE(hit::miss, HD);
    EXTERN_SPRITE(hit::ok, HD);
    EXTERN_SPRITE(hit::ok::katsu, HD);
    EXTERN_SPRITE(hit::great, HD);
    EXTERN_SPRITE(hit::great::geki, HD);
    EXTERN_SPRITE(hit::great::katsu, HD);

    EXTERN_SPRITE(hitcircle, HD);
    EXTERN_SPRITE(hitcircle::overlay, HD);

    EXTERN_SPRITE(roll::end, HD);
    EXTERN_SPRITE(roll::middle, HD);

    EXTERN_SPRITE(slider, HD);
    EXTERN_SPRITE(slider::fail, HD);
} // namespace taiko



// * osu!catch
namespace catchthebeat {
    EXTERN_SPRITE(apple, HD);
    EXTERN_SPRITE(apple::overlay, HD);

    EXTERN_SPRITE(bananas, HD);
    EXTERN_SPRITE(bananas::overlay, HD);

    EXTERN_SPRITE(catcher::fail, HD);
    EXTERN_SPRITE(catcher::idle, HD);
    EXTERN_SPRITE(catcher::kiai, HD);

    EXTERN_SPRITE(drop, HD);

    EXTERN_SPRITE(grapes, HD);
    EXTERN_SPRITE(grapes::overlay, HD);

    EXTERN_SPRITE(orange, HD);
    EXTERN_SPRITE(orange::overlay, HD);

    EXTERN_SPRITE(pear, HD);
    EXTERN_SPRITE(pear::overlay, HD);
} // namespace catchthebeat



// * osu!mania
namespace mania {
    EXTERN_SPRITE(lighting, HD);
    EXTERN_ANIMATED(lighting::L, HD);
    EXTERN_SPRITE(lighting::N, HD);

    EXTERN_SPRITE(hit::miss, HD);
    EXTERN_SPRITE(hit::meh, HD);
    EXTERN_SPRITE(hit::ok, HD);
    EXTERN_SPRITE(hit::good, HD);
    EXTERN_SPRITE(hit::great, HD);
    EXTERN_ANIMATED(hit::perfect, HD);

    EXTERN_SPRITE(key::ONE, HD);
    EXTERN_SPRITE(key::ONE::D, HD);
    EXTERN_SPRITE(key::TWO, HD);
    EXTERN_SPRITE(key::TWO::D, HD);
    EXTERN_SPRITE(key::S, HD);
    EXTERN_SPRITE(key::S::D, HD);

    EXTERN_SPRITE(note::ONE, HD);
    EXTERN_SPRITE(note::ONE::H, HD);
    EXTERN_ANIMATED(note::ONE::L, HD);
    EXTERN_SPRITE(note::TWO, HD);
    EXTERN_SPRITE(note::TWO::H, HD);
    EXTERN_ANIMATED(note::TWO::L, HD);
    EXTERN_SPRITE(note::S, HD);
    EXTERN_SPRITE(note::S::H, HD);
    EXTERN_ANIMATED(note::S::L, HD);

    EXTERN_SPRITE(stage::hint, HD);
    EXTERN_SPRITE(stage::left, HD);
    EXTERN_SPRITE(stage::light, HD);
    EXTERN_SPRITE(stage::right, HD);
} // namespace mania
} // namespace sprites





// * CONFIGURATION
namespace config {
    // skin.ini
    EXTERN_FILE(skin_ini);
} // namespace config
} // namespace legacy

