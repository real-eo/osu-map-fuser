// // #include <string>
// // // #include "../../osuReplayEditorV3/ReplayEditor/config.hpp"

// // namespace config {
//     // // std::wstring song_path;                         // Empty string - linker will use this instead of config.cpp's definition
//     // std::wstring song_path = L"";                   // Empty string - linker will use this instead of config.cpp's definition
// // }

// namespace config {
//     extern wchar_t const* song_path;                // Empty string - linker will use this instead of config.cpp's definition
// }

// wchar_t const* config::song_path = L"";
#include <string>

namespace config {
    std::wstring song_path;
}