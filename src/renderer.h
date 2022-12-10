
#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"

class Renderer {
 public:
  Renderer();
  ~Renderer();

  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif