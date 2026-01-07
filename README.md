osu! Map Fuser — SDL2 + OpenGL starter

This workspace contains a minimal prototype that opens an SDL2 OpenGL window and draws two side-by-side views. It's a starting point for a tool to compare multiple osu! maps that share the same audio.

Quick notes:
- The renderer currently uses OpenGL compatibility (legacy) calls for a minimal example.
- For production you should migrate to modern OpenGL (GLAD/GL3) or Vulkan and implement per-view FBOs.

# Running
Run `../run` in the MSYS2 MinGW shell from within `build/` folder to compile and run
