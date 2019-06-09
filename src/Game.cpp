//
// Created by giow on 08/06/19.
//

#include "Game.hpp"

SDL_Texture *player_texture;
SDL_Rect src_rect, dest_rect;

Game::Game() {
}

void Game::create_window(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen) {
    int fullscreen_flag = 0;

    // Check if fullscreen
    if (fullscreen) {
        fullscreen_flag = SDL_WINDOW_FULLSCREEN;
    }

    // Create window
    window_ = SDL_CreateWindow(title, x_pos, y_pos, width, height, fullscreen_flag);

    // Check if window was created successfully
    if (window_){
        std::cout << "Window Created!" << std::endl;
    }
    else{
        throw std::runtime_error(SDL_GetError());
    }
}

void Game::create_renderer() {
    renderer_ = SDL_CreateRenderer(window_, INDEX_FLAG, NO_RENDER_FLAG);

    if (renderer_){
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
        std::cout << "Renderer Created!" << std::endl;
    }
    else{
        throw std::runtime_error(SDL_GetError());
    }
}



void Game::init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen) {

    if (SDL_InitSubSystem(SDL_INIT_EVERYTHING) == NO_ERROR) {
        std::cout << "Subsystems Initialiased!" << std::endl;

        //Try to Create Window
        try {
            create_window(title, x_pos, y_pos, width, height, fullscreen);
        }
        catch (std::runtime_error &e) {
            std::cerr << "Failed to create Window, error: " << e.what();
            is_running_ = false;
        }

        // Try to initialize Renderer
        try {
            create_renderer();
        }
        catch (std::runtime_error &e) {
            std::cerr << "Failed to create Renderer, error: " << e.what();
            is_running_ = false;
        }

        is_running_ = true;

    } else {
        is_running_ = false;
    }

    SDL_Surface *tmp_surface = IMG_Load("resources/8bitengineer.png");
    player_texture = SDL_CreateTextureFromSurface(renderer_, tmp_surface);
    SDL_FreeSurface(tmp_surface);
}

void Game::handle_events() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            is_running_ = false;
            break;

        default:
            break;
    }
}

void Game::render() {
    SDL_RenderClear(renderer_);
    // renderer, texture, source rectangle,
    SDL_RenderCopy(renderer_, player_texture, NULL, &dest_rect);
    // This is where we add stuff to render
    SDL_RenderPresent(renderer_);
}
void Game::clean() {
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
    std::cout << "Window and renderer cleaned!" << std::endl << "SDL Subsystem Closed!" << std::endl;
}

bool Game::running() {
    return is_running_;
}

void Game::update() {
    counter_++;
    dest_rect.h = 64;
    dest_rect.w = 64;
    dest_rect.x = counter_;
    //std::cout << counter_ << std::endl;
}