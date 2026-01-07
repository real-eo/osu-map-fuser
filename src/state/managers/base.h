#pragma once

#include <string>


// * BaseManager: Abstract base class for platform-specific Manager implementations
class BaseManager {
public:
    // // BaseManager() = default;
    virtual ~BaseManager() = default;
    virtual std::string openFile(const char filter[], const char title[]) = 0;
};

