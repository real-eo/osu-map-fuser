#pragma once

#include <filesystem>
#include <variant>
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
    std::string name;

}; // struct SkinExData



// Structs to hold skin resource entries
struct SkinElement {
    std::variant<resource, const frame*> data;                                          // Resource data (ptr + size) or array of frames (typedef)
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

#define EMBEDDED_WAV(path) {resource{path, path##_size}, EMBEDDED, AudioFormat::WAV}
#define EMBEDDED_MP3(path) {resource{path, path##_size}, EMBEDDED, AudioFormat::MP3}

struct Samples {
    // * GAMEPLAY
    // Multiple modes
    SkinSample applause         = EMBEDDED_MP3(LS::applause);
    SkinSample combobreak       = EMBEDDED_MP3(LS::combobreak);
    SkinSample count            = EMBEDDED_WAV(LS::count);
    SkinSample failsound        = EMBEDDED_MP3(LS::failsound);

    struct section {
        SkinSample fail             = EMBEDDED_MP3(LS::section::fail);
        SkinSample pass             = EMBEDDED_MP3(LS::section::pass);
    } section;


    // * osu!standard
    struct osu {
        struct drum {                       
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::drum::hit::clap);
                SkinSample finish       = EMBEDDED_WAV(LS::osu::drum::hit::finish);
                SkinSample normal       = EMBEDDED_WAV(LS::osu::drum::hit::normal);                    
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::hit::whistle);                   
            } hit;                                      
                                                        
            struct slider {                          
                SkinSample slide        = EMBEDDED_WAV(LS::osu::drum::slider::slide);
                SkinSample tick         = EMBEDDED_WAV(LS::osu::drum::slider::tick);
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::slider::whistle);
            } slider;                   
        } drum;

        struct nightcore {
            SkinSample clap             = EMBEDDED_WAV(LS::osu::nightcore::clap);
            SkinSample finish           = EMBEDDED_WAV(LS::osu::nightcore::finish);
            SkinSample hat              = EMBEDDED_WAV(LS::osu::nightcore::hat);
            SkinSample kick             = EMBEDDED_WAV(LS::osu::nightcore::kick);
        } nightcore;    

        struct normal {                       
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::normal::hit::clap);
                SkinSample finish       = EMBEDDED_WAV(LS::osu::normal::hit::finish);
                SkinSample normal       = EMBEDDED_WAV(LS::osu::normal::hit::normal);
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::normal::hit::whistle);
            } hit;                                          
                                                        
            struct slider {                          
                SkinSample slide        = EMBEDDED_WAV(LS::osu::normal::slider::slide);
                SkinSample tick         = EMBEDDED_WAV(LS::osu::normal::slider::tick);                      
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::normal::slider::whistle);
            } slider;                   
        } normal;

        struct soft {                       
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::soft::hit::clap);
                SkinSample finish       = EMBEDDED_WAV(LS::osu::soft::hit::finish);
                SkinSample normal       = EMBEDDED_WAV(LS::osu::soft::hit::normal);
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::soft::hit::whistle);
            } hit;                                          
                                                        
            struct slider {                          
                SkinSample slide        = EMBEDDED_WAV(LS::osu::soft::slider::slide);
                SkinSample tick         = EMBEDDED_WAV(LS::osu::soft::slider::tick);                      
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::soft::slider::whistle);
            } slider;                   
        } soft;

        struct spinner {
            SkinSample bonus            = EMBEDDED_WAV(LS::osu::spinner::bonus);
            SkinSample spin             = EMBEDDED_WAV(LS::osu::spinner::spin);
        } spinner;
    } osu;

    // * Taiko
    struct taiko {
        struct drum {                              
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::drum::hit::clap);
                SkinSample finish       = EMBEDDED_WAV(LS::osu::drum::hit::finish);
                SkinSample normal       = EMBEDDED_WAV(LS::osu::drum::hit::normal);
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::hit::whistle);                   
            } hit;                    
        } drum;

        struct normal {                              
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::drum::hit::clap);
                SkinSample finish       = EMBEDDED_WAV(LS::osu::drum::hit::finish);
                SkinSample normal       = EMBEDDED_WAV(LS::osu::drum::hit::normal);
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::hit::whistle);                   
            } hit;                    
        } normal;

        struct soft {                              
            struct hit {                             
                SkinSample clap         = EMBEDDED_WAV(LS::osu::drum::hit::clap);
                SkinSample finish       = EMBEDDED_WAV(LS::osu::drum::hit::finish);
                SkinSample normal       = EMBEDDED_WAV(LS::osu::drum::hit::normal);
                SkinSample whistle      = EMBEDDED_WAV(LS::osu::drum::hit::whistle);                   
            } hit;                    
        } soft;
    } taiko;
};

// ? Undefined macros to prevent pollution
#undef LS

#undef EMBEDDED_WAV                                                                     
#undef EMBEDDED_MP3


// * IMAGES
#define LT legacy::sprites                                                              // ? legacy::sprites macro for brevity; (Legacy Textures)

#define STATIC_SPRITE(path, def) {resource{path::def, path::def##_size}, EMBEDDED, Definition::def, 1, STATIC}
#define ANIMATED_SPRITE(path, def) {path::def, EMBEDDED, Definition::def, path::def##_frames, ANIMATED}

struct Sprites {
    // * MENU
    struct UI {
        SkinSprite star         = STATIC_SPRITE(LT::UI::star, HD);
        SkinSprite star2        = STATIC_SPRITE(LT::UI::star2, HD);
        SkinSprite star3        = STATIC_SPRITE(LT::UI::star3, HD);
    } UI;

    // * GAMEPLAY
    // Multiple modes
    SkinSprite comboburst       = STATIC_SPRITE(LT::comboburst, HD);
    SkinSprite ready            = STATIC_SPRITE(LT::ready, HD);
    struct count {
        SkinSprite ONE          = STATIC_SPRITE(LT::count::ONE, HD);
        SkinSprite TWO          = STATIC_SPRITE(LT::count::TWO, HD);
        SkinSprite THREE        = STATIC_SPRITE(LT::count::THREE, HD);
    } count;
    SkinSprite go               = STATIC_SPRITE(LT::go, HD);

    struct cursor {
        SkinSprite _            = STATIC_SPRITE(LT::cursor, HD);
        SkinSprite trail        = STATIC_SPRITE(LT::cursor::trail, HD);
        SkinSprite middle       = STATIC_SPRITE(LT::cursor::middle, HD);
        SkinSprite smoke        = STATIC_SPRITE(LT::cursor::smoke, HD);

        operator const SkinSprite&() const { return _; }
        operator SkinSprite&() { return _; }
    } cursor;

    struct inputoverlay {
        SkinSprite background   = STATIC_SPRITE(LT::inputoverlay::background, HD);
        SkinSprite key          = STATIC_SPRITE(LT::inputoverlay::key, HD);
    } inputoverlay;

    struct ranking {
        SkinSprite XH           = STATIC_SPRITE(LT::ranking::XH, HD);
        SkinSprite X            = STATIC_SPRITE(LT::ranking::X, HD);
        SkinSprite SH           = STATIC_SPRITE(LT::ranking::SH, HD);
        SkinSprite S            = STATIC_SPRITE(LT::ranking::S, HD);
        SkinSprite A            = STATIC_SPRITE(LT::ranking::A, HD);
        SkinSprite B            = STATIC_SPRITE(LT::ranking::B, HD);
        SkinSprite C            = STATIC_SPRITE(LT::ranking::C, HD);
        SkinSprite D            = STATIC_SPRITE(LT::ranking::D, HD);
    } ranking;

    struct score {
        SkinSprite ZERO         = STATIC_SPRITE(LT::score::ZERO, HD);
        SkinSprite ONE          = STATIC_SPRITE(LT::score::ONE, HD);
        SkinSprite TWO          = STATIC_SPRITE(LT::score::TWO, HD);
        SkinSprite THREE        = STATIC_SPRITE(LT::score::THREE, HD);
        SkinSprite FOUR         = STATIC_SPRITE(LT::score::FOUR, HD);
        SkinSprite FIVE         = STATIC_SPRITE(LT::score::FIVE, HD);
        SkinSprite SIX          = STATIC_SPRITE(LT::score::SIX, HD);
        SkinSprite SEVEN        = STATIC_SPRITE(LT::score::SEVEN, HD);
        SkinSprite EIGHT        = STATIC_SPRITE(LT::score::EIGHT, HD);
        SkinSprite NINE         = STATIC_SPRITE(LT::score::NINE, HD);
        SkinSprite comma        = STATIC_SPRITE(LT::score::comma, HD);
        SkinSprite dot          = STATIC_SPRITE(LT::score::dot, HD);
        SkinSprite percent      = STATIC_SPRITE(LT::score::percent, HD);
        SkinSprite pp           = STATIC_SPRITE(LT::score::pp, HD);
        SkinSprite x            = STATIC_SPRITE(LT::score::x, HD);
    } score;

    struct scorebar {
        SkinSprite bg           = STATIC_SPRITE(LT::scorebar::bg, HD);
        SkinSprite marker       = STATIC_SPRITE(LT::scorebar::marker, HD);
        SkinSprite colour       = STATIC_SPRITE(LT::scorebar::colour, HD);
    } scorebar;

    struct scoreboard {
        struct explosion {
            SkinSprite ONE      = STATIC_SPRITE(LT::scoreboard::explosion::ONE, HD);
            SkinSprite TWO      = STATIC_SPRITE(LT::scoreboard::explosion::TWO, HD);
        } explosion;
    } scoreboard;

    // * osu!standard
    struct osu {
        SkinSprite approachcircle   = STATIC_SPRITE(LT::osu::approachcircle, HD);

        struct default_ {
            SkinSprite ZERO         = STATIC_SPRITE(LT::osu::default_::ZERO, HD);
            SkinSprite ONE          = STATIC_SPRITE(LT::osu::default_::ONE, HD);
            SkinSprite TWO          = STATIC_SPRITE(LT::osu::default_::TWO, HD);
            SkinSprite THREE        = STATIC_SPRITE(LT::osu::default_::THREE, HD);
            SkinSprite FOUR         = STATIC_SPRITE(LT::osu::default_::FOUR, HD);
            SkinSprite FIVE         = STATIC_SPRITE(LT::osu::default_::FIVE, HD);
            SkinSprite SIX          = STATIC_SPRITE(LT::osu::default_::SIX, HD);
            SkinSprite SEVEN        = STATIC_SPRITE(LT::osu::default_::SEVEN, HD);
            SkinSprite EIGHT        = STATIC_SPRITE(LT::osu::default_::EIGHT, HD);
            SkinSprite NINE         = STATIC_SPRITE(LT::osu::default_::NINE, HD);
        } default_;

        SkinSprite followpoint      = STATIC_SPRITE(LT::osu::followpoint, HD);

        struct hit {
            SkinSprite miss         = STATIC_SPRITE(LT::osu::hit::miss, HD);
            SkinSprite meh          = STATIC_SPRITE(LT::osu::hit::meh, HD);
            struct ok {
                SkinSprite _        = STATIC_SPRITE(LT::osu::hit::ok, HD);
                SkinSprite katsu    = STATIC_SPRITE(LT::osu::hit::ok::katsu, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } ok;
            struct great {
                SkinSprite _        = STATIC_SPRITE(LT::osu::hit::great, HD);
                SkinSprite geki     = STATIC_SPRITE(LT::osu::hit::great::geki, HD);
                SkinSprite katsu    = STATIC_SPRITE(LT::osu::hit::great::katsu, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } great;
        } hit;

        struct hitcircle {
            SkinSprite _            = STATIC_SPRITE(LT::osu::hitcircle, HD);
            SkinSprite overlay      = STATIC_SPRITE(LT::osu::hitcircle::overlay, HD);
            SkinSprite select       = STATIC_SPRITE(LT::osu::hitcircle::select, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } hitcircle;

        struct particle {
            SkinSprite meh          = STATIC_SPRITE(LT::osu::particle::meh, HD);
            SkinSprite ok           = STATIC_SPRITE(LT::osu::particle::ok, HD);
            SkinSprite great        = STATIC_SPRITE(LT::osu::particle::great, HD);
        } particle;

        SkinSprite reversearrow     = STATIC_SPRITE(LT::osu::reversearrow, HD);

        struct slider {
            struct b {
                SkinSprite _        = ANIMATED_SPRITE(LT::osu::slider::b, HD);
                SkinSprite nd       = STATIC_SPRITE(LT::osu::slider::b::nd, HD);
                SkinSprite spec     = STATIC_SPRITE(LT::osu::slider::b::spec, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } b;   

            SkinSprite endmiss      = STATIC_SPRITE(LT::osu::slider::endmiss, HD);
            SkinSprite followcircle = STATIC_SPRITE(LT::osu::slider::followcircle, HD);
            SkinSprite scorepoint   = STATIC_SPRITE(LT::osu::slider::scorepoint, HD);
            SkinSprite tickmiss     = STATIC_SPRITE(LT::osu::slider::tickmiss, HD);
        } slider;

        struct spinner {
            SkinSprite approachcircle   = STATIC_SPRITE(LT::osu::spinner::approachcircle, HD);
            SkinSprite bottom           = STATIC_SPRITE(LT::osu::spinner::bottom, HD);
            SkinSprite circle           = STATIC_SPRITE(LT::osu::spinner::circle, HD);
            SkinSprite clear            = STATIC_SPRITE(LT::osu::spinner::clear, HD);
            SkinSprite glow             = STATIC_SPRITE(LT::osu::spinner::glow, HD);
            SkinSprite middle           = STATIC_SPRITE(LT::osu::spinner::middle, HD);
            SkinSprite middle2          = STATIC_SPRITE(LT::osu::spinner::middle2, HD);
            SkinSprite rpm              = STATIC_SPRITE(LT::osu::spinner::rpm, HD);
            SkinSprite spin             = STATIC_SPRITE(LT::osu::spinner::spin, HD);
            SkinSprite top              = STATIC_SPRITE(LT::osu::spinner::top, HD);
            SkinSprite warning          = STATIC_SPRITE(LT::osu::spinner::warning, HD);
        } spinner;
    } osu;

    // * osu!taiko
    struct taiko {
        struct pippidon {
            SkinSprite clear        = ANIMATED_SPRITE(LT::taiko::pippidon::clear, SD);
            SkinSprite fail         = ANIMATED_SPRITE(LT::taiko::pippidon::fail, SD);
            SkinSprite idle         = ANIMATED_SPRITE(LT::taiko::pippidon::idle, SD);
            SkinSprite kiai         = ANIMATED_SPRITE(LT::taiko::pippidon::kiai, SD);
        } pippidon;

        struct bar {
            SkinSprite left         = STATIC_SPRITE(LT::taiko::bar::left, HD);
            SkinSprite line         = STATIC_SPRITE(LT::taiko::bar::line, HD);
            struct right {
                SkinSprite _        = STATIC_SPRITE(LT::taiko::bar::right, HD);
                SkinSprite glow     = STATIC_SPRITE(LT::taiko::bar::right::glow, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } right;
        } bar;

        struct bigcircle {
            SkinSprite _            = STATIC_SPRITE(LT::taiko::bigcircle, HD);
            SkinSprite overlay      = STATIC_SPRITE(LT::taiko::bigcircle::overlay, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } bigcircle;

        struct drum {
            SkinSprite inner        = STATIC_SPRITE(LT::taiko::drum::inner, HD);
            SkinSprite outer        = STATIC_SPRITE(LT::taiko::drum::outer, HD);
        } drum;

        SkinSprite glow             = STATIC_SPRITE(LT::taiko::glow, HD);

        struct hit {
            SkinSprite miss         = STATIC_SPRITE(LT::taiko::hit::miss, HD);
            struct ok {
                SkinSprite _        = STATIC_SPRITE(LT::taiko::hit::ok, HD);
                SkinSprite katsu    = STATIC_SPRITE(LT::taiko::hit::ok::katsu, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } ok;
            struct great {
                SkinSprite _        = STATIC_SPRITE(LT::taiko::hit::great, HD);
                SkinSprite geki     = STATIC_SPRITE(LT::taiko::hit::great::geki, HD);
                SkinSprite katsu    = STATIC_SPRITE(LT::taiko::hit::great::katsu, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } great;
        } hit;

        struct hitcircle {
            SkinSprite _            = STATIC_SPRITE(LT::taiko::hitcircle, HD);
            SkinSprite overlay      = STATIC_SPRITE(LT::taiko::hitcircle::overlay, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } hitcircle;

        struct roll {
            SkinSprite end          = STATIC_SPRITE(LT::taiko::roll::end, HD);
            SkinSprite middle       = STATIC_SPRITE(LT::taiko::roll::middle, HD);
        } roll;

        struct slider {
            SkinSprite _            = STATIC_SPRITE(LT::taiko::slider, HD);
            SkinSprite fail         = STATIC_SPRITE(LT::taiko::slider::fail, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } slider;
    } taiko;

    // * osu!catch
    struct catchthebeat {
        struct apple {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::apple, HD);
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::apple::overlay, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } apple;

        struct bananas {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::bananas, HD);
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::bananas::overlay, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } bananas;

        struct catcher {
            SkinSprite fail         = STATIC_SPRITE(LT::catchthebeat::catcher::fail, HD);
            SkinSprite idle         = STATIC_SPRITE(LT::catchthebeat::catcher::idle, HD);
            SkinSprite kiai         = STATIC_SPRITE(LT::catchthebeat::catcher::kiai, HD);
        } catcher;

        SkinSprite drop             = STATIC_SPRITE(LT::catchthebeat::drop, HD);

        struct grapes {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::grapes, HD);
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::grapes::overlay, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } grapes;

        struct orange {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::orange, HD);
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::orange::overlay, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } orange;

        struct pear {
            SkinSprite _            = STATIC_SPRITE(LT::catchthebeat::pear, HD);
            SkinSprite overlay      = STATIC_SPRITE(LT::catchthebeat::pear::overlay, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } pear;
    } catchthebeat;

    // * osu!mania
    struct mania {
        struct lighting {
            SkinSprite _            = STATIC_SPRITE(LT::mania::lighting, HD);
            SkinSprite L            = ANIMATED_SPRITE(LT::mania::lighting::L, HD);
            SkinSprite N            = STATIC_SPRITE(LT::mania::lighting::N, HD);

            operator const SkinSprite&() const { return _; }
            operator SkinSprite&() { return _; }
        } lighting;

        struct hit {
            SkinSprite miss         = STATIC_SPRITE(LT::mania::hit::miss, HD);
            SkinSprite meh          = STATIC_SPRITE(LT::mania::hit::meh, HD);
            SkinSprite ok           = STATIC_SPRITE(LT::mania::hit::ok, HD);
            SkinSprite good         = STATIC_SPRITE(LT::mania::hit::good, HD);
            SkinSprite great        = STATIC_SPRITE(LT::mania::hit::great, HD);
            SkinSprite perfect      = ANIMATED_SPRITE(LT::mania::hit::perfect, HD);
        } hit;

        struct key {
            struct ONE {
                SkinSprite _        = STATIC_SPRITE(LT::mania::key::ONE, HD);
                SkinSprite D        = STATIC_SPRITE(LT::mania::key::ONE::D, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } ONE;
            struct TWO {
                SkinSprite _        = STATIC_SPRITE(LT::mania::key::TWO, HD);
                SkinSprite D        = STATIC_SPRITE(LT::mania::key::TWO::D, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } TWO;
            struct S {
                SkinSprite _        = STATIC_SPRITE(LT::mania::key::S, HD);
                SkinSprite D        = STATIC_SPRITE(LT::mania::key::S::D, HD);
                
                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } S;
        } key;

        struct note {
            struct ONE {
                SkinSprite _        = STATIC_SPRITE(LT::mania::note::ONE, HD);
                SkinSprite H        = STATIC_SPRITE(LT::mania::note::ONE::H, HD);
                SkinSprite L        = ANIMATED_SPRITE(LT::mania::note::ONE::L, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } ONE;
            struct TWO {
                SkinSprite _        = STATIC_SPRITE(LT::mania::note::TWO, HD);
                SkinSprite H        = STATIC_SPRITE(LT::mania::note::TWO::H, HD);
                SkinSprite L        = ANIMATED_SPRITE(LT::mania::note::TWO::L, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } TWO;
            struct S {
                SkinSprite _        = STATIC_SPRITE(LT::mania::note::S, HD);
                SkinSprite H        = STATIC_SPRITE(LT::mania::note::S::H, HD);
                SkinSprite L        = ANIMATED_SPRITE(LT::mania::note::S::L, HD);

                operator const SkinSprite&() const { return _; }
                operator SkinSprite&() { return _; }
            } S;
        } note;

        struct stage {
            SkinSprite hint         = STATIC_SPRITE(LT::mania::stage::hint, HD);
            SkinSprite left         = STATIC_SPRITE(LT::mania::stage::left, HD);
            SkinSprite light        = STATIC_SPRITE(LT::mania::stage::light, HD);
            SkinSprite right        = STATIC_SPRITE(LT::mania::stage::right, HD);
        } stage;
    } mania;
};

// ? Undefine macros to prevent pollution
#undef LT

#undef STATIC_SPRITE
#undef ANIMATED_SPRITE


// * CONFIGURATION
#define LC legacy::config                                                               // ? legacy::config macro for brevity; (Legacy Config)

#define EMBEDDED_FILE(path) {resource{path, path##_size}, EMBEDDED}

struct Config {
    SkinConfig skin_ini         = EMBEDDED_FILE(LC::skin_ini);
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
