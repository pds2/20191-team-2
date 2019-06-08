//
// Created by giow on 07/06/19.
//

#ifndef BOMBERMANC__MATRIX_H_
#define BOMBERMANC__MATRIX_H_
#include<vector>
#include <iostream>

/*Space locality Matrix*/
class Matrix {
    int rows_, cols_;
    std::vector<int> matrix;
 public:
    /*Initiate 2d matrix*/
    Matrix(int rows, int cols): rows_{rows}, cols_{cols}, matrix(rows_ * cols_, 0){}

    int& operator()(int x, int y)
    {
        return matrix[y * cols_ + x];
    }

    void print();
};
#endif //BOMBERMANC__MATRIX_H_
