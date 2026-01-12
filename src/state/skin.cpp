#include "skin.h"

#include <iostream>

namespace fs = std::filesystem;


SkinManager::SkinManager(SDL_Window* window) : Manager(window) {}
SkinManager::~SkinManager() = default;
