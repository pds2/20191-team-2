//
// Created by root on 06/06/19.
//

#ifndef BOMBERMANC_TEST_CLASS_H
#define BOMBERMANC_TEST_CLASS_H

class test_class{
public:
    int x;
    int y;
    int getX() const {
        return x;
    }

    void setX(int x) {
        test_class::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        test_class::y = y;
    }


    test_class()
    {
        x = 0;
        y = 0;
    }
};

#endif //BOMBERMANC_TEST_CLASS_H
