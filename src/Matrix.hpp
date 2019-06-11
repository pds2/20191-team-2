//
// Created by giow on 07/06/19.
//

#ifndef BOMBERMANC__MATRIX_H_
#define BOMBERMANC__MATRIX_H_
#include<vector>
#include <iostream>

/*Space locality Matrix*/
class Matrix {

 public:
    int rows_, cols_;
    /*Initiate 2d matrix_*/
    Matrix(int rows, int cols): rows_{rows}, cols_{cols}, matrix_(rows_ * cols_, 0){}

    int& at(int x, int y)
    {
      return matrix_[y * cols_ + x];
    }
    int& operator()(int x, int y)
    {
        return matrix_[y * cols_ + x];
    }

    void print();
 private:
    std::vector<int> matrix_;

};
#endif //BOMBERMANC__MATRIX_H_
