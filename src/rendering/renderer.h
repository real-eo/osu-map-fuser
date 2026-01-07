#pragma once

#include <SDL.h>

// Lightweight renderer interface and a placeholder FBO abstraction.
// This starter uses OpenGL compatibility/legacy calls to keep the example minimal.

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool init(SDL_Window* window);
    void resize(int w, int h);
    void render(double timeSec);
    void shutdown();
private:
    SDL_Window* m_window = nullptr;
    int m_width = 800;
    int m_height = 600;
};

// Simple placeholder for an FBO-style abstraction. Implementation can be
// expanded later to use modern OpenGL (glGenFramebuffers, textures, etc.).
struct FBO {
    unsigned int fbo = 0;
    unsigned int texture = 0;
    int width = 0;
    int height = 0;
};
