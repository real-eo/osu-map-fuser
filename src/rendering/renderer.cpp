#include "renderer.h"

#include <SDL_opengl.h>
#include <iostream>

Renderer::Renderer() {}
Renderer::~Renderer() { shutdown(); }

bool Renderer::init(SDL_Window* window) {
    m_window = window;
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    resize(w, h);
    // Use a simple clear color; more GL setup can go here.
    glClearColor(0.08f, 0.08f, 0.09f, 1.0f);
    glEnable(GL_SCISSOR_TEST);
    return true;
}

void Renderer::resize(int w, int h) {
    m_width = w; m_height = h;
    glViewport(0, 0, m_width, m_height);
}

// Render two side-by-side views using viewports. This avoids FBO complexity
// in the starter while showing how you can render N independent views.
void Renderer::render(double timeSec) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Left view (map A)
    glViewport(0, 0, m_width / 2, m_height);
    glScissor(0, 0, m_width / 2, m_height);
    // Simple animated background for demonstration
    float t = (float)timeSec;
    glClearColor(0.12f + 0.05f * sinf(t), 0.12f, 0.18f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, m_width/2, m_height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw a few placeholder circles/objects
    glColor3f(1.0f, 0.6f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(150, 150);
    for(int i=0;i<=32;i++){
        float a = i/(float)32 * 3.14159f*2.0f;
        glVertex2f(150 + cosf(a)*40, 150 + sinf(a)*40);
    }
    glEnd();

    // Right view (map B)
    glViewport(m_width / 2, 0, m_width / 2, m_height);
    glScissor(m_width / 2, 0, m_width / 2, m_height);
    glClearColor(0.08f, 0.14f + 0.05f * cosf(t*1.2f), 0.10f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, m_width/2, m_height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(0.3f, 0.7f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(150, 200);
    for(int i=0;i<=32;i++){
        float a = i/(float)32 * 3.14159f*2.0f;
        glVertex2f(150 + cosf(a)*60, 200 + sinf(a)*60);
    }
    glEnd();
}

void Renderer::shutdown() {
    // Any GL resource cleanup would go here
}
