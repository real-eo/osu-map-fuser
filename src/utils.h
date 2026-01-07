#pragma once

// // Windows
// #define NOMINMAX
// #define WIN32_LEAN_AND_MEAN
#include <windows.h>

// // Standard
// // #include <iostream>
// #include <string>
// #include <vector>
// #include <memory>
// #include <filesystem>
// #include <algorithm>
#include <cstdint>
#include <string>

// WORKAROUND AS TO NOT INCLUDE <windows.h>
// #define CP_UTF8                   65001       // UTF-8 translation
// typedef unsigned long       DWORD;

// Type aliases
using I64 = int64_t;
using U64 = uint64_t;
using SongTime_t = int;

// Utility
// Convert std::string (UTF-8) to std::wstring (UTF-16)
static inline std::wstring stows(const std::string &s) {
    constexpr DWORD flags = 0;
    const int len = MultiByteToWideChar(CP_UTF8, flags, s.c_str(), -1, nullptr, 0);
    if (len <= 0) return std::wstring();
    std::wstring ret(len, 'X');
    MultiByteToWideChar(CP_UTF8, flags, s.c_str(), -1, &ret[0], static_cast<int>(ret.size()));
    return ret;
}