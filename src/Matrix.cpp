//
// Created by giow on 07/06/19.
//

#include "Matrix.h"

void Matrix::print() {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << matrix[i * cols_ + j] << " ";
        }
        std::cout << std::endl;
    }
}