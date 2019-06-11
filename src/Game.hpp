//
// Created by giow on 08/06/19.
//

#ifndef BOMBERMANC_SRC_GAME_HPP_
#define BOMBERMANC_SRC_GAME_HPP_
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "TextureManager.hpp"

const int INDEX_FLAG = 0;
const int NO_RENDER_FLAG = 0;
const int NO_ERROR = 0;

class Game {
    int counter_ = 0;
    bool is_running_ = false;
    SDL_Window *window_;

 public:
    Game();
    ~Game();
    void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
    void handle_events();
    void update();
    void render();
    void clean();
    bool running();
    void create_window(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
    void create_renderer();

    static  SDL_Renderer *renderer_;
    static SDL_Event event;
};

#endif //BOMBERMANC_SRC_GAME_HPP_
