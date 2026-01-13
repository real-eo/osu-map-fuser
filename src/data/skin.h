#pragma once

#include <filesystem>
#include <variant>
#include <string>
// #include <span>                                                                      // In case we go with span approach for SkinElement::all() 
#include <vector>

#include "../resources/utils.h"
#include "../resources/skins/legacy.h"



// Enumeration for audio format types.
enum class AudioFormat {
    WAV,
    MP3,
    OGG,
    UNKNOWN
};

// Enumeration for sprite definition types.
enum class Definition { 
    SD,                                                                                 // SD = Standard Definition (1x)
    HD                                                                                  // HD = High Definition     (2x)
};



// Struct to hold extra skin data
struct SkinExData {
    // Metadata
    std::filesystem::path path;
    std::string name = "Default";

}; // struct SkinExData



// Structs to hold skin resource entries
struct SkinElement {
    std::variant<resource, const frame*> data;                                          // Resource data (ptr + size) or array of frames (typedef)
    const std::string name;                                                             // Const name identifier for the element
    bool isEmbedded;                                                                    // If true, then data.data is a pointer to an embedded 
};                                                                                      // resource, else, it's a filepath to an external resource

struct SkinSample : public SkinElement {
    AudioFormat format;                                                                 // E.g., "wav", "mp3"
};

struct SkinSprite : public SkinElement {
    Definition definition;                                                              // SD or HD     (1 or 2)
    std::size_t frames;                                                                 // Number of frames if animated; NULL if static
    bool isAnimated;
};

// TODO: Maybe add a separate SkinAnimated struct if it can't be
//     : implemented cleanly into the normal SkinSprite struct 

struct SkinConfig : public SkinElement {};



// * Skin data structs
namespace SkinData {
// * RESOURCES
// // #include "../resources/skins/legacy.h"                                                  // Import legacy skin resources within the  
// //                                                                                         // SkinData namespace to prevent name pollution

// * GENERAL
#define EMBEDDED true
#define EXTERNAL false

#define ANIMATED true
#define STATIC false


// * AUDIO
#define LS legacy::samples                                                              // ? legacy::samples macro for brevity; (Legacy Samples)

#define EMBEDDED_WAV(path, name) {resource{path, path##_size}, name, EMBEDDED, AudioFormat::WAV}
#define EMBEDDED_MP3(path, name) {resource{path, path##_size}, name, EMBEDDED, AudioFormat::MP3}

struct Samples {
    // * GAMEPLAY
    // Multiple modes
    SkinSample applause         = EMBEDDED_MP3(LS::applause, "applause");
    SkinSample combobreak       = EMBEDDED_MP3(LS::combobreak, "combobreak");
    SkinSample count            = EMBEDDED_WAV(LS::count, "count");
    SkinSample failsound        = EMBEDDED_MP3(LS::failsound, "failsound");

    struct section {
        SkinSample fail             = EMBEDDED_MP3(LS::section::fail, "sectionfail");
        SkinSample pass             = EMBEDDED_MP3(LS::section::pass, "sectionpass");
    } section;


    // * osu!standard
    struct osu {
        struct drum {                       
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::drum::hit::clap, "drum-hitclap");
                SkinSample finish       = EMBEDDED_WAV(LS::osu::drum::hit::finish, "drum-hitfinish");
                SkinSample normal       = EMBEDDED_WAV(LS::osu::drum::hit::normal, "drum-hitnormal");                    
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::hit::whistle, "drum-hitwhistle");                   
            } hit;                                      
                                                        
            struct slider {                          
                SkinSample slide        = EMBEDDED_WAV(LS::osu::drum::slider::slide, "drum-sliderslide");
                SkinSample tick         = EMBEDDED_WAV(LS::osu::drum::slider::tick, "drum-slidertick");
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::slider::whistle, "drum-sliderwhistle");
            } slider;                   
        } drum;

        struct nightcore {
            SkinSample clap             = EMBEDDED_WAV(LS::osu::nightcore::clap, "nightcore-clap");
            SkinSample finish           = EMBEDDED_WAV(LS::osu::nightcore::finish, "nightcore-finish");
            SkinSample hat              = EMBEDDED_WAV(LS::osu::nightcore::hat, "nightcore-hat");
            SkinSample kick             = EMBEDDED_WAV(LS::osu::nightcore::kick, "nightcore-kick");
        } nightcore;    

        struct normal {                       
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::normal::hit::clap, "normal-hitclap");
                SkinSample finish       = EMBEDDED_WAV(LS::osu::normal::hit::finish, "normal-hitfinish");
                SkinSample normal       = EMBEDDED_WAV(LS::osu::normal::hit::normal, "normal-hitnormal");
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::normal::hit::whistle, "normal-hitwhistle");
            } hit;                                          
                                                        
            struct slider {                          
                SkinSample slide        = EMBEDDED_WAV(LS::osu::normal::slider::slide, "normal-sliderslide");
                SkinSample tick         = EMBEDDED_WAV(LS::osu::normal::slider::tick, "normal-slidertick");                      
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::normal::slider::whistle, "normal-sliderwhistle");
            } slider;                   
        } normal;

        struct soft {                       
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::soft::hit::clap, "soft-hitclap");
                SkinSample finish       = EMBEDDED_WAV(LS::osu::soft::hit::finish, "soft-hitfinish");
                SkinSample normal       = EMBEDDED_WAV(LS::osu::soft::hit::normal, "soft-hitnormal");
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::soft::hit::whistle, "soft-hitwhistle");
            } hit;                                          
                                                        
            struct slider {                          
                SkinSample slide        = EMBEDDED_WAV(LS::osu::soft::slider::slide, "soft-sliderslide");
                SkinSample tick         = EMBEDDED_WAV(LS::osu::soft::slider::tick, "soft-slidertick");                      
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::soft::slider::whistle, "soft-sliderwhistle");
            } slider;                   
        } soft;

        struct spinner {
            SkinSample bonus            = EMBEDDED_WAV(LS::osu::spinner::bonus, "spinnerbonus");
            SkinSample spin             = EMBEDDED_WAV(LS::osu::spinner::spin, "spinnerspin");
        } spinner;
    } osu;

    // * Taiko
    struct taiko {
        struct drum {                              
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::drum::hit::clap, "taiko-drum-hitclap");
                SkinSample finish       = EMBEDDED_WAV(LS::osu::drum::hit::finish, "taiko-drum-hitfinish");
                SkinSample normal       = EMBEDDED_WAV(LS::osu::drum::hit::normal, "taiko-drum-hitnormal");
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::hit::whistle, "taiko-drum-hitwhistle");                   
            } hit;                    
        } drum;

        struct normal {                              
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::drum::hit::clap, "taiko-normal-hitclap");
                SkinSample finish       = EMBEDDED_WAV(LS::osu::drum::hit::finish, "taiko-normal-hitfinish");
                SkinSample normal       = EMBEDDED_WAV(LS::osu::drum::hit::normal, "taiko-normal-hitnormal");
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::hit::whistle, "taiko-normal-hitwhistle");                   
            } hit;                    
        } normal;

        struct soft {                              
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::drum::hit::clap, "taiko-soft-hitclap");
                SkinSample finish       = EMBEDDED_WAV(LS::osu::drum::hit::finish, "taiko-soft-hitfinish");
                SkinSample normal       = EMBEDDED_WAV(LS::osu::drum::hit::normal, "taiko-soft-hitnormal");
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::hit::whistle, "taiko-soft-hitwhistle");                   
            } hit;                    
        } soft;
    } taiko;

    // * All samples 
    // TODO: See if we can implement this solution without the vector allocation overhead
    // [[nodiscard]] std::span<const SkinSample* const> all() const {
        // static const std::array sample_ptrs = { ... };
        // return sample_ptrs; 
        // ? What happens:
        // ?    First call: Array is initialized once with pointers to this object's members
        // ?    Subsequent calls: Returns a span over the already-initialized array
        // ?    Zero overhead: No re-initialization, just returns the existing array
        // ? Important caveat: 
        // ?    The static array is initialized per Samples object address. If you have multiple 
        // ?    Skin objects, the first one to call all() "wins" and the array will always point 
        // ?    to that first object's members - even when called on other instances.
    // }
        
    // But since that solution isn't yet determined to be viable, so for now, we just go with the vector approach
    [[nodiscard]] std::vector<const SkinSample*> all() const {
        return {
            &applause, &combobreak, &count, &failsound, &section.fail, &section.pass,                                   // multiple modes
            &osu.drum.hit.clap, &osu.drum.hit.finish, &osu.drum.hit.normal, &osu.drum.hit.whistle,                      // osu! drum-hit
            &osu.drum.slider.slide, &osu.drum.slider.tick, &osu.drum.slider.whistle,                                    // osu! drum-slider
            &osu.nightcore.clap, &osu.nightcore.finish, &osu.nightcore.hat, &osu.nightcore.kick,                        // osu! nightcore  
            &osu.normal.hit.clap, &osu.normal.hit.finish, &osu.normal.hit.normal, &osu.normal.hit.whistle,              // osu! normal-hit
            &osu.normal.slider.slide, &osu.normal.slider.tick, &osu.normal.slider.whistle,                              // osu! normal-slider
            &osu.soft.hit.clap, &osu.soft.hit.finish, &osu.soft.hit.normal, &osu.soft.hit.whistle,                      // osu! soft-hit
            &osu.soft.slider.slide, &osu.soft.slider.tick, &osu.soft.slider.whistle,                                    // osu! soft-slider
            &osu.spinner.bonus, &osu.spinner.spin,                                                                      // osu! spinner
            &taiko.drum.hit.clap, &taiko.drum.hit.finish, &taiko.drum.hit.normal, &taiko.drum.hit.whistle,              // taiko drum-hit
            &taiko.normal.hit.clap, &taiko.normal.hit.finish, &taiko.normal.hit.normal, &taiko.normal.hit.whistle,      // taiko normal-hit
            &taiko.soft.hit.clap, &taiko.soft.hit.finish, &taiko.soft.hit.normal, &taiko.soft.hit.whistle,              // taiko soft-hit
        };
    }
};

// ? Undefined macros to prevent pollution
#undef LS

#undef EMBEDDED_WAV                                                                     
#undef EMBEDDED_MP3


// * IMAGES
#define LT legacy::sprites                                                              // ? legacy::sprites macro for brevity; (Legacy Textures)

#define STATIC_SPRITE(path, def, name) {resource{path::def, path::def##_size}, name, EMBEDDED, Definition::def, 1, STATIC}
#define ANIMATED_SPRITE(path, def, name) {path::def, name, EMBEDDED, Definition::def, path::def##_frames, ANIMATED}

struct Sprites {
    // * MENU
    struct UI {
        SkinSprite star         = STATIC_SPRITE(LT::UI::star, HD, "star");
        SkinSprite star2        = STATIC_SPRITE(LT::UI::star2, HD, "star2");
        SkinSprite star3        = STATIC_SPRITE(LT::UI::star3, HD, "star3");
    } UI;

    // * GAMEPLAY
    // Multiple modes
    SkinSprite comboburst       = STATIC_SPRITE(LT::comboburst, HD, "comboburst");
    SkinSprite ready            = STATIC_SPRITE(LT::ready, HD, "ready");
    struct count {
        SkinSprite ONE          = STATIC_SPRITE(LT::count::ONE, HD, "count1");
        SkinSprite TWO          = STATIC_SPRITE(LT::count::TWO, HD, "count2");
        SkinSprite THREE        = STATIC_SPRITE(LT::count::THREE, HD, "count3");
    } count;
    SkinSprite go               = STATIC_SPRITE(LT::go, HD, "go");

    struct cursor {
        SkinSprite _            = STATIC_SPRITE(LT::cursor, HD, "cursor");
        SkinSprite trail        = STATIC_SPRITE(LT::cursor::trail, HD, "cursortrail");
        SkinSprite middle       = STATIC_SPRITE(LT::cursor::middle, HD, "cursormiddle");
        SkinSprite smoke        = STATIC_SPRITE(LT::cursor::smoke, HD, "cursor-smoke");

        operator const SkinSprite&() const { return _; }
        operator SkinSprite&() { return _; }
    } cursor;

    struct inputoverlay {
        SkinSprite background   = STATIC_SPRITE(LT::inputoverlay::background, HD, "inputoverlay-background");
        SkinSprite key          = STATIC_SPRITE(LT::inputoverlay::key, HD, "inputoverlay-key");
    } inputoverlay;

    struct ranking {
        SkinSprite XH           = STATIC_SPRITE(LT::ranking::XH, HD, "ranking-XH-small");
        SkinSprite X            = STATIC_SPRITE(LT::ranking::X, HD, "ranking-X-small");
        SkinSprite SH           = STATIC_SPRITE(LT::ranking::SH, HD, "ranking-SH-small");
        SkinSprite S            = STATIC_SPRITE(LT::ranking::S, HD, "ranking-S-small");
        SkinSprite A            = STATIC_SPRITE(LT::ranking::A, HD, "ranking-A-small");
        SkinSprite B            = STATIC_SPRITE(LT::ranking::B, HD, "ranking-B-small");
        SkinSprite C            = STATIC_SPRITE(LT::ranking::C, HD, "ranking-C-small");
        SkinSprite D            = STATIC_SPRITE(LT::ranking::D, HD, "ranking-D-small");
    } ranking;

    struct score {
        SkinSprite ZERO         = STATIC_SPRITE(LT::score::ZERO, HD, "score-0");
        SkinSprite ONE          = STATIC_SPRITE(LT::score::ONE, HD, "score-1");
        SkinSprite TWO          = STATIC_SPRITE(LT::score::TWO, HD, "score-2");
        SkinSprite THREE        = STATIC_SPRITE(LT::score::THREE, HD, "score-3");
        SkinSprite FOUR         = STATIC_SPRITE(LT::score::FOUR, HD, "score-4");
        SkinSprite FIVE         = STATIC_SPRITE(LT::score::FIVE, HD, "score-5");
        SkinSprite SIX          = STATIC_SPRITE(LT::score::SIX, HD, "score-6");
        SkinSprite SEVEN        = STATIC_SPRITE(LT::score::SEVEN, HD, "score-7");
        SkinSprite EIGHT        = STATIC_SPRITE(LT::score::EIGHT, HD, "score-8");
        SkinSprite NINE         = STATIC_SPRITE(LT::score::NINE, HD, "score-9");
        SkinSprite comma        = STATIC_SPRITE(LT::score::comma, HD, "score-comma");
        SkinSprite dot          = STATIC_SPRITE(LT::score::dot, HD, "score-dot");
        SkinSprite percent      = STATIC_SPRITE(LT::score::percent, HD, "score-percent");
        SkinSprite pp           = STATIC_SPRITE(LT::score::pp, HD, "score-pp");
        SkinSprite x            = STATIC_SPRITE(LT::score::x, HD, "score-x");
    } score;

    struct scorebar {
        SkinSprite bg           = STATIC_SPRITE(LT::scorebar::bg, HD, "scorebar-bg");
        SkinSprite marker       = STATIC_SPRITE(LT::scorebar::marker, HD, "scorebar-marker");
        SkinSprite colour       = STATIC_SPRITE(LT::scorebar::colour, HD, "scorebar-colour");
    } scorebar;

    struct scoreboard {
        struct explosion {
            SkinSprite ONE      = STATIC_SPRITE(LT::scoreboard::explosion::ONE, HD, "scoreboard-explosion-1");
            SkinSprite TWO      = STATIC_SPRITE(LT::scoreboard::explosion::TWO, HD, "scoreboard-explosion-2");
        } explosion;
    } scoreboard;

    // * osu!standard
    struct osu {
        SkinSprite approachcircle   = STATIC_SPRITE(LT::osu::approachcircle, HD, "approachcircle");

        struct default_ {
            SkinSprite ZERO         = STATIC_SPRITE(LT::osu::default_::ZERO, HD, "default-0");
            SkinSprite ONE          = STATIC_SPRITE(LT::osu::default_::ONE, HD, "default-1");
            SkinSprite TWO          = STATIC_SPRITE(LT::osu::default_::TWO, HD, "default-2");
            SkinSprite THREE        = STATIC_SPRITE(LT::osu::default_::THREE, HD, "default-3");
            SkinSprite FOUR         = STATIC_SPRITE(LT::osu::default_::FOUR, HD, "default-4");
            SkinSprite FIVE         = STATIC_SPRITE(LT::osu::default_::FIVE, HD, "default-5");
            SkinSprite SIX          = STATIC_SPRITE(LT::osu::default_::SIX, HD, "default-6");
            SkinSprite SEVEN        = STATIC_SPRITE(LT::osu::default_::SEVEN, HD, "default-7");
            SkinSprite EIGHT        = STATIC_SPRITE(LT::osu::default_::EIGHT, HD, "default-8");
            SkinSprite NINE         = STATIC_SPRITE(LT::osu::default_::NINE, HD, "default-9");
        } default_;

        SkinSprite followpoint      = STATIC_SPRITE(LT::osu::followpoint, HD, "followpoint");

        struct hit {
            SkinSprite miss         = STATIC_SPRITE(LT::osu::hit::miss, HD, "hit0");
            SkinSprite meh          = STATIC_SPRITE(LT::osu::hit::meh, HD, "hit50");
            struct ok {
                SkinSprite _        = STATIC_SPRITE(LT::osu::hit::ok, HD, "hit100");
                SkinSprite katsu    = STATIC_SPRITE(LT::osu::hit::ok::katsu, HD, "hit100k");
                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } ok;
            struct great {
                SkinSprite _        = STATIC_SPRITE(LT::osu::hit::great, HD, "hit300");
                SkinSprite geki     = STATIC_SPRITE(LT::osu::hit::great::geki, HD, "hit300g");
                SkinSprite katsu    = STATIC_SPRITE(LT::osu::hit::great::katsu, HD, "hit300k");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } great;
        } hit;

        struct hitcircle {
            SkinSprite _            = STATIC_SPRITE(LT::osu::hitcircle, HD, "hitcircle");
            SkinSprite overlay      = STATIC_SPRITE(LT::osu::hitcircle::overlay, HD, "hitcircleoverlay");
            SkinSprite select       = STATIC_SPRITE(LT::osu::hitcircle::select, HD, "hitcircleselect");

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } hitcircle;

        struct particle {
            SkinSprite meh          = STATIC_SPRITE(LT::osu::particle::meh, HD, "particle50");
            SkinSprite ok           = STATIC_SPRITE(LT::osu::particle::ok, HD, "particle100");
            SkinSprite great        = STATIC_SPRITE(LT::osu::particle::great, HD, "particle300");
        } particle;

        SkinSprite reversearrow     = STATIC_SPRITE(LT::osu::reversearrow, HD, "reversearrow");

        struct slider {
            struct b {
                SkinSprite _        = ANIMATED_SPRITE(LT::osu::slider::b, HD, "sliderb");
                SkinSprite nd       = STATIC_SPRITE(LT::osu::slider::b::nd, HD, "sliderb-nd");
                SkinSprite spec     = STATIC_SPRITE(LT::osu::slider::b::spec, HD, "sliderb-spec");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } b;   

            SkinSprite endmiss      = STATIC_SPRITE(LT::osu::slider::endmiss, HD, "sliderendmiss");
            SkinSprite followcircle = STATIC_SPRITE(LT::osu::slider::followcircle, HD, "sliderfollowcircle");
            SkinSprite scorepoint   = STATIC_SPRITE(LT::osu::slider::scorepoint, HD, "sliderscorepoint");
            SkinSprite tickmiss     = STATIC_SPRITE(LT::osu::slider::tickmiss, HD, "slidertickmiss");
        } slider;

        struct spinner {
            SkinSprite approachcircle   = STATIC_SPRITE(LT::osu::spinner::approachcircle, HD, "spinner-approachcircle");
            SkinSprite bottom           = STATIC_SPRITE(LT::osu::spinner::bottom, HD, "spinner-bottom");
            SkinSprite circle           = STATIC_SPRITE(LT::osu::spinner::circle, HD, "spinner-circle");
            SkinSprite clear            = STATIC_SPRITE(LT::osu::spinner::clear, HD, "spinner-clear");
            SkinSprite glow             = STATIC_SPRITE(LT::osu::spinner::glow, HD, "spinner-glow");
            SkinSprite middle           = STATIC_SPRITE(LT::osu::spinner::middle, HD, "spinner-middle");
            SkinSprite middle2          = STATIC_SPRITE(LT::osu::spinner::middle2, HD, "spinner-middle2");
            SkinSprite rpm              = STATIC_SPRITE(LT::osu::spinner::rpm, HD, "spinner-rpm");
            SkinSprite spin             = STATIC_SPRITE(LT::osu::spinner::spin, HD, "spinner-spin");
            SkinSprite top              = STATIC_SPRITE(LT::osu::spinner::top, HD, "spinner-top");
            SkinSprite warning          = STATIC_SPRITE(LT::osu::spinner::warning, HD, "spinner-warning");
        } spinner;
    } osu;

    // * osu!taiko
    struct taiko {
        struct pippidon {
            SkinSprite clear        = ANIMATED_SPRITE(LT::taiko::pippidon::clear, SD, "pippidonclear");
            SkinSprite fail         = ANIMATED_SPRITE(LT::taiko::pippidon::fail, SD, "pippidonfail");
            SkinSprite idle         = ANIMATED_SPRITE(LT::taiko::pippidon::idle, SD, "pippidonidle");
            SkinSprite kiai         = ANIMATED_SPRITE(LT::taiko::pippidon::kiai, SD, "pippidonkiai");
        } pippidon;

        struct bar {
            SkinSprite left         = STATIC_SPRITE(LT::taiko::bar::left, HD, "taiko-bar-left");
            SkinSprite line         = STATIC_SPRITE(LT::taiko::bar::line, HD, "taiko-barline");
            struct right {
                SkinSprite _        = STATIC_SPRITE(LT::taiko::bar::right, HD, "taiko-bar-right");
                SkinSprite glow     = STATIC_SPRITE(LT::taiko::bar::right::glow, HD, "taiko-bar-right-glow");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } right;
        } bar;

        struct bigcircle {
            SkinSprite _            = STATIC_SPRITE(LT::taiko::bigcircle, HD, "taikobigcircle");
            SkinSprite overlay      = STATIC_SPRITE(LT::taiko::bigcircle::overlay, HD, "taikobigcircleoverlay");

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } bigcircle;

        struct drum {
            SkinSprite inner        = STATIC_SPRITE(LT::taiko::drum::inner, HD, "taiko-drum-inner");
            SkinSprite outer        = STATIC_SPRITE(LT::taiko::drum::outer, HD, "taiko-drum-outer");
        } drum;

        SkinSprite glow             = STATIC_SPRITE(LT::taiko::glow, HD, "taiko-glow");
        struct hit {
            SkinSprite miss         = STATIC_SPRITE(LT::taiko::hit::miss, HD, "taiko-hit0");
            struct ok {
                SkinSprite _        = STATIC_SPRITE(LT::taiko::hit::ok, HD, "taiko-hit100");
                SkinSprite katsu    = STATIC_SPRITE(LT::taiko::hit::ok::katsu, HD, "taiko-hit100k");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } ok;
            struct great {
                SkinSprite _        = STATIC_SPRITE(LT::taiko::hit::great, HD, "taiko-hit300");
                SkinSprite geki     = STATIC_SPRITE(LT::taiko::hit::great::geki, HD, "taiko-hit300g");
                SkinSprite katsu    = STATIC_SPRITE(LT::taiko::hit::great::katsu, HD, "taiko-hit300k");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } great;
        } hit;

        struct hitcircle {
            SkinSprite _            = STATIC_SPRITE(LT::taiko::hitcircle, HD, "taikohitcircle");
            SkinSprite overlay      = STATIC_SPRITE(LT::taiko::hitcircle::overlay, HD, "taikohitcircleoverlay");

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } hitcircle;

        struct roll {
            SkinSprite end          = STATIC_SPRITE(LT::taiko::roll::end, HD, "taiko-roll-end");
            SkinSprite middle       = STATIC_SPRITE(LT::taiko::roll::middle, HD, "taiko-roll-middle");
        } roll;

        struct slider {
            SkinSprite _            = STATIC_SPRITE(LT::taiko::slider, HD, "taiko-slider");
            SkinSprite fail         = STATIC_SPRITE(LT::taiko::slider::fail, HD, "taiko-slider-fail");

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } slider;
    } taiko;

    // * osu!catch
    struct catchthebeat {
        struct apple {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::apple, HD, "fruit-apple");
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::apple::overlay, HD, "fruit-apple-overlay");

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } apple;

        struct bananas {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::bananas, HD, "fruit-bananas");
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::bananas::overlay, HD, "fruit-bananas-overlay");

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } bananas;

        struct catcher {
            SkinSprite fail         = STATIC_SPRITE(LT::catchthebeat::catcher::fail, HD, "fruit-catcher-fail");
            SkinSprite idle         = STATIC_SPRITE(LT::catchthebeat::catcher::idle, HD, "fruit-catcher-idle");
            SkinSprite kiai         = STATIC_SPRITE(LT::catchthebeat::catcher::kiai, HD, "fruit-catcher-kiai");
        } catcher;

        SkinSprite drop             = STATIC_SPRITE(LT::catchthebeat::drop, HD, "fruit-drop");

        struct grapes {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::grapes, HD, "fruit-grapes");
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::grapes::overlay, HD, "fruit-grapes-overlay");
            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } grapes;

        struct orange {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::orange, HD, "fruit-orange");
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::orange::overlay, HD, "fruit-orange-overlay");

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } orange;

        struct pear {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::pear, HD, "fruit-pear");
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::pear::overlay, HD, "fruit-pear-overlay");

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } pear;
    } catchthebeat;

    // * osu!mania
    struct mania {
        struct lighting {
            SkinSprite _            = STATIC_SPRITE(LT::mania::lighting, HD, "lighting");
            SkinSprite L            = ANIMATED_SPRITE(LT::mania::lighting::L, HD, "lightingL");
            SkinSprite N            = STATIC_SPRITE(LT::mania::lighting::N, HD, "lightingN");

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } lighting;

        struct hit {
            SkinSprite miss         = STATIC_SPRITE(LT::mania::hit::miss, HD, "mania-hit0");
            SkinSprite meh          = STATIC_SPRITE(LT::mania::hit::meh, HD, "mania-hit50");
            SkinSprite ok           = STATIC_SPRITE(LT::mania::hit::ok, HD, "mania-hit100");
            SkinSprite good         = STATIC_SPRITE(LT::mania::hit::good, HD, "mania-hit200");
            SkinSprite great        = STATIC_SPRITE(LT::mania::hit::great, HD, "mania-hit300");
            SkinSprite perfect      = ANIMATED_SPRITE(LT::mania::hit::perfect, HD, "mania-hit300g");
        } hit;

        struct key {
            struct ONE {
                SkinSprite _        = STATIC_SPRITE(LT::mania::key::ONE, HD, "mania-key1");
                SkinSprite D        = STATIC_SPRITE(LT::mania::key::ONE::D, HD, "mania-key1D");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } ONE;
            struct TWO {
                SkinSprite _        = STATIC_SPRITE(LT::mania::key::TWO, HD, "mania-key2");
                SkinSprite D        = STATIC_SPRITE(LT::mania::key::TWO::D, HD, "mania-key2D");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } TWO;
            struct S {
                SkinSprite _        = STATIC_SPRITE(LT::mania::key::S, HD, "mania-keyS");
                SkinSprite D        = STATIC_SPRITE(LT::mania::key::S::D, HD, "mania-keySD");
                
                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } S;
        } key;

        struct note {
            struct ONE {
                SkinSprite _        = STATIC_SPRITE(LT::mania::note::ONE, HD, "mania-note1");
                SkinSprite H        = STATIC_SPRITE(LT::mania::note::ONE::H, HD, "mania-note1H");
                SkinSprite L        = ANIMATED_SPRITE(LT::mania::note::ONE::L, HD, "mania-note1L");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } ONE;
            struct TWO {
                SkinSprite _        = STATIC_SPRITE(LT::mania::note::TWO, HD, "mania-note2");
                SkinSprite H        = STATIC_SPRITE(LT::mania::note::TWO::H, HD, "mania-note2H");
                SkinSprite L        = ANIMATED_SPRITE(LT::mania::note::TWO::L, HD, "mania-note2L");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } TWO;
            struct S {
                SkinSprite _        = STATIC_SPRITE(LT::mania::note::S, HD, "mania-noteS");
                SkinSprite H        = STATIC_SPRITE(LT::mania::note::S::H, HD, "mania-noteSH");
                SkinSprite L        = ANIMATED_SPRITE(LT::mania::note::S::L, HD, "mania-noteSL");

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } S;
        } note;

        struct stage {
            SkinSprite hint         = STATIC_SPRITE(LT::mania::stage::hint, HD, "mania-stage-hint");
            SkinSprite left         = STATIC_SPRITE(LT::mania::stage::left, HD, "mania-stage-left");
            SkinSprite light        = STATIC_SPRITE(LT::mania::stage::light, HD, "mania-stage-light");
            SkinSprite right        = STATIC_SPRITE(LT::mania::stage::right, HD, "mania-stage-right");
        } stage;
    } mania;
};

// ? Undefine macros to prevent pollution
#undef LT

#undef STATIC_SPRITE
#undef ANIMATED_SPRITE


// * CONFIGURATION
#define LC legacy::config                                                               // ? legacy::config macro for brevity; (Legacy Config)

#define EMBEDDED_FILE(path, name) {resource{path, path##_size}, name, EMBEDDED}

struct Config {
    SkinConfig skin_ini         = EMBEDDED_FILE(LC::skin_ini, "skin.ini");
};

// ? Undefine macros to prevent pollution
#undef LC

#undef EMBEDDED_FILE

} // namespace SkinData



// * Skin class
class Skin {
private:
    // Program metadata
    SkinExData data;

    // Actual skin data
    SkinData::Samples samples;
    SkinData::Sprites sprites;
    SkinData::Config config; 

public:
//     Skin();
//     ~Skin();

//     // Load skin from path
//     bool loadFromPath(const std::filesystem::path& path);

    // Getters
    const SkinExData&           getData()       const { return data;    }
    const SkinData::Samples&    getSamples()    const { return samples; }
    const SkinData::Sprites&    getSprites()    const { return sprites; }
    const SkinData::Config&     getConfig()     const { return config;  }
};
