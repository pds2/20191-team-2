//
// Created by giow on 10/06/19.
//

#ifndef BOMBERMANC_SRC_GAMECONTROLLER_H_
#define BOMBERMANC_SRC_GAMECONTROLLER_H_
#include "Game.hpp"

class KeyboardController
{
 public:
    int pressed_key()
    {
        if(Game::event.type == SDL_KEYDOWN)
        {
          std::cout << "can\n";

          switch (Game::event.key.keysym.sym)
            {
              std::cout << "can\n";

              case SDLK_UP:
                  return SDLK_UP;
                    break;
                case SDLK_DOWN:
                  return SDLK_DOWN;
                    break;
                case SDLK_LEFT:
                  return SDLK_LEFT;
                    break;
                case SDLK_RIGHT:
                  return SDLK_RIGHT;
                    break;
            }
        }
        if(Game::event.type == SDL_KEYUP)
        {
            //Reset Velocity (IF I'm going to implement accel)
        }
    }
};

#endif //BOMBERMANC_SRC_GAMECONTROLLER_H_
