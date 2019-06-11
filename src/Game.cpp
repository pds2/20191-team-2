//
// Created by giow on 08/06/19.
//

#include "Game.hpp"

#include "GameBoard.hpp"

GameBoard *game_board;
// nullptr because SDL is not initiated yet
SDL_Renderer *Game::renderer_ = nullptr;
SDL_Event Game::event;

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
  if (window_) {
    std::cout << "Window Created!" << std::endl;
  } else {
    throw std::runtime_error(SDL_GetError());
  }
}

void Game::create_renderer() {
  renderer_ = SDL_CreateRenderer(window_, INDEX_FLAG, NO_RENDER_FLAG);

  if (renderer_) {
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
    std::cout << "Renderer Created!" << std::endl;
  } else {
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
  //player = new GameObjectSDL("resources/player.png", Pos(0,0));
  //enemy = new GameObjectSDL("resources/player.png", Pos(50,50));
  game_board = new GameBoard(GAME_BOARD_SIZE);
  //**/player = new Bomber("resources/Bomberman.png", Pos(0,0), game_board->board_);
}

void Game::handle_events() {

  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:is_running_ = false;
      break;

    default:break;
  }
}

void Game::render() {
  SDL_RenderClear(renderer_);
  // renderer, texture, source rectangle,
  game_board->draw();

  // This is where we add stuff to render
  SDL_RenderPresent(renderer_);
}
void Game::escape() {
  if (Game::event.type == SDL_KEYDOWN && Game::event.key.repeat == 0) {
    if (Game::event.key.keysym.sym == SDLK_ESCAPE)
      is_running_ = false;
  }
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
  escape();
  //game_board->update_obj(game_board->player);

  //player->update();
  /*
   *    std::cout << "P, pos: [" << player->pos_.x_ << "," << player->pos_.y_ << "]" << "T, pos ["
                           << player->to_move_.x_ << "," << player->to_move_.y_ << "]" << std::endl;
   * */

}