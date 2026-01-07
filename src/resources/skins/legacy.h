#pragma once

#include <cstddef>

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
    }                                           \
    } // namespace ns

#define EXTERN_SAMPLE_SECTION_TAIKO(ns)         \
    namespace ns {                              \
    namespace hit {                             \
        EXTERN_FILE(clap);                      \
        EXTERN_FILE(finish);                    \
        EXTERN_FILE(normal);                    \
        EXTERN_FILE(whistle);                   \
    }                                           \
    } // namespace ns



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
} // namespace sprites


// * CONFIGURATION
namespace config {
    // skin.ini
    EXTERN_FILE(skin_ini);
} // namespace config
} // namespace legacy