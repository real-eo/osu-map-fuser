#pragma once

#include <cstddef>

// * Frame struct for animated sprites to group textures along with their sizes
struct resource {
    const unsigned char* data;
    std::size_t size;
};

// Typedef frame as resource such that frame can be interpreted as an array of textures with sizes
using frame = resource;
