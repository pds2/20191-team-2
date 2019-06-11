//
// Created by giow on 09/06/19.
//

#ifndef BOMBERMANC_SRC_GAMEOBJECTSDL_H_
#define BOMBERMANC_SRC_GAMEOBJECTSDL_H_

#include "Game.hpp"
#include "Position.hpp"
#include "TextureManager.hpp"

class GameObjectSDL
{
 private:
  bool blockable_ = false;
    bool visible_ = false;

 protected:
    /*Texture Object*/
    SDL_Texture* obj_texture_;

    /*From Where to where to Draw*/
    SDL_Rect src_rect_;
    SDL_Rect dest_rect_;
 public:

    /*Base Constructor*/
    GameObjectSDL(const char* texture_sheet, const Pos& pos);
     virtual ~GameObjectSDL();

    /*Same for render fucntion*/
    virtual void render() = 0;
    /* This is here if the game obj is destructible*/
    virtual void destroy() = 0;
    /*Derived classes should implement their update function (if it is needed)*/
    virtual void update() = 0;

    /*Getters and Setters*/
    bool is_blockable() const;
    void set_blockable(bool blockable);
    bool is_visible() const;
    void set_visible(bool visible);
  Pos pos_;
};
#endif //BOMBERMANC_SRC_GAMEOBJECTSDL_H_
