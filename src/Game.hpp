//
// Created by giow on 08/06/19.
//

#ifndef BOMBERMANC_SRC_GAME_HPP_
#define BOMBERMANC_SRC_GAME_HPP_
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.hpp"
#include "GameObjectSDL.h"

const int INDEX_FLAG = 0;
const int NO_RENDER_FLAG = 0;
const int NO_ERROR = 0;

class Game {
  bool is_running_ = false;
  SDL_Window *window_;

 public:
  static SDL_Renderer *renderer_;
  static SDL_Event event;
  Game();
  ~Game();
  /*Initialize SDL Objects*/
  void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
  /*Handle SDL events*/
  void handle_events();
  /*Update game objects*/
  void update();
  /*Render game objects*/
  void render();
  /*Clean/Destruct SDL objects used*/
  void clean();
  /*Check if the SDL framework is running*/
  bool running();
  /*Create SDL Window*/
  void create_window(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
  /*Create SDL Renderer*/
  void create_renderer();

  /*Function to terminate program*/
  void escape();
};

#endif //BOMBERMANC_SRC_GAME_HPP_
