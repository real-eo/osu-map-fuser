#pragma once

#include "manager.h"
#include "../data/skin.h"


// * SkinManager: Manages loading, storing, and accessing skins
class SkinManager : public Manager {
private:
    // State
    Skin currentSkin;

    // TODO: Implement skin persistence system such that users can 
    //     : save/load skins. Always fallback to legacy skin. Ensure SkinData::* 
    //     : structs never get overwritten in a way that they lose the embedded data.
    //     : When instantiating a Skin, use the Skin-class to create a new instance,
    //     : which is pre-populated with the embedded data from the legacy skin, such
    //     : that the embedded data is never lost. AS FOR NOW, WE IGNORE PERSISTENCE.
    //     : AND JUST LOAD THE LEGACY SKIN REGARDLESS. THIS IS TO BE IMPLEMENTED LATER.
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
    const Skin& active() const { return currentSkin; }
    // TODO: FUCNTION TO RETURN ALL SAMPLES FROM THE LOADED SKIN

};