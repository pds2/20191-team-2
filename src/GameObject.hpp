//
// Created by giow on 07/06/19.
//

#ifndef BOMBERMANC_SRC_GAMEOBJECT_HPP_
#define BOMBERMANC_SRC_GAMEOBJECT_HPP_
#include "Position.hpp"
class GameObject {
 protected:
    Pos pos_;
    bool blockable;
    bool visible;

 public:
    virtual void show() = 0;
    virtual void create() = 0;
    virtual void destroy() = 0;

};

#endif //BOMBERMANC_SRC_GAMEOBJECT_HPP_