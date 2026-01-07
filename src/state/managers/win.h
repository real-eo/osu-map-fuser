#pragma once

// // #include "../managers/base.h"
#include "base.h"

#include <SDL.h>

// * Windows-specific Manager implementation
class WinManager : public BaseManager {
private:
    // Non-owning pointer to SDL window, only used for dialogs
    SDL_Window* window{};

public:
    explicit WinManager(SDL_Window* window) : window(window) {}

    // Common functions for all subclass managers
    virtual std::string openFile(const char filter[], const char title[]) override;
};
