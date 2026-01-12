#pragma once

#include "manager.h"
#include "../data/skin.h"


// * SkinManager: Manages loading, storing, and accessing skins
class SkinManager : public Manager {
private:
    // State
    Skin currentSkin;

    // Persistence
    Skin&& loadSkinConfig();                                                            // Only called on initialization 
    void saveSkinConfig();                                                              // Only called when changing skin
    
    [[nodiscard]] bool loadFromFile(const std::string& path);

public:
    SkinManager(SDL_Window* window);
    ~SkinManager();

    // Event handlers
    void changeSkin();

    // Getters
    // TODO: FUCNTION TO RETURN ALL SAMPLES FROM THE LOADED SKIN

};