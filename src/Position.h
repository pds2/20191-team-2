//
// Created by giow on 07/06/19.
//

#ifndef BOMBERMANC_SRC_POSITION_H_
#define BOMBERMANC_SRC_POSITION_H_

/*Position class to be used by other classes*/
class Pos {
    int x_, y_;
 public:

    int get_x() const {
        return x_;
    }
    void set_x(int x) {
        x_ = x;
    }
    int get_y() const {
        return y_;
    }
    void set_y(int y) {
        y_ = y;
    }

    explicit Pos(int x = 0, int y = 0):x_{x},y_{y}{}

    int& operator()(int x, int y)
    {
        x_ = x;
        y_ = y;
    }
};

#endif //BOMBERMANC_SRC_POSITION_H_
