//
// Created by giow on 07/06/19.
//

#include "Matrix.hpp"

void Matrix::print() {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << matrix_[i * cols_ + j] << " ";
        }
        std::cout << std::endl;
    }
}