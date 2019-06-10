//
// Created by giow on 07/06/19.
//

#ifndef BOMBERMANC_SRC_POSITION_HPP_
#define BOMBERMANC_SRC_POSITION_HPP_

/*Position class to be used by other classes*/
class Pos {
 public:
    int x_, y_;

    explicit Pos(int x = 0, int y = 0):x_{x},y_{y}{}

    int& operator()(int x, int y)
    {
        x_ = x;
        y_ = y;
    }
};

#endif //BOMBERMANC_SRC_POSITION_HPP_
