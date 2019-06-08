//
// Created by giow on 07/06/19.
//

#ifndef BOMBERMANC_SRC_BLOCK_H_
#define BOMBERMANC_SRC_BLOCK_H_

#include <iostream>
#include "Position.h"
#include "GameObject.h"

class Block : public GameObject {
 public:
    Block(int x, int y) {
        pos_(x, y);
        blockable = true;
        visible = true;
        std::cout << "I'm a block created at: " << pos_.get_x() << ',' << pos_.get_y() << std::endl;
    }
    void show() override {
        std::cout << "I'm a block with no sprites!" << std::endl;
    }
    void create() override {
        std::cout << "I'm a block created at board: " << pos_.get_x() << ',' << pos_.get_y() << std::endl;
    }

    void destroy() override {
        std::cout << "I'm being destroyed! Oh no! " << std::endl;
    }
};
#endif //BOMBERMANC_SRC_BLOCK_H_