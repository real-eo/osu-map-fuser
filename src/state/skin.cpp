#include "skin.h"

#include <iostream>

namespace fs = std::filesystem;


SkinManager::SkinManager(SDL_Window* window) : Manager(window) {}
SkinManager::~SkinManager() = default;


// * Persistence
// TODO: Skin&& SkinManager::loadSkinConfig()
// TODO: void SkinManager::saveSkinConfig()

// * Loading
// TODO: bool SkinManager::loadSkin(const std::string& path)

// * Event handlers
// TODO: void SkinManager::changeSkin(const std::string& path)