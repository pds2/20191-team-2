//
// Created by giow on 08/06/19.
//

#ifndef BOMBERMANC_SRC_GAME_H_
#define BOMBERMANC_SRC_GAME_H_
#include <SDL.h>
#include <iostream>
const int INDEX_FLAG = 0;
const int NO_RENDER_FLAG = 0;
const int NO_ERROR = 0;
class Game {
    bool is_running;
    SDL_Window *window_;
    SDL_Renderer *renderer_;

 public:
    Game();
    ~Game();
    void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
    void handle_events();
    void update();
    void render();
    void clean();
    bool running();
    bool is_window_created();
    bool is_renderer_created();
    void create_window(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen);
    void create_renderer();

};

#endif //BOMBERMANC_SRC_GAME_H_
