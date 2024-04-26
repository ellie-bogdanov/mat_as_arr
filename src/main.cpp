#include "matrix.hpp"
#include <iostream>

int main() {
    mat_as_arr::matrix<int> mtx(4, 5);
    for (int i = 0; i < mtx.rows; ++i) {
        for (int j = 0; j < mtx.columns; ++j) {
            mtx.at(i, j) = 0;
        }
    }

    mtx.at(2, 3) = 502;
    mtx.at(0, 0) = 2;
    mtx.at(1, 4) = 283;

    std::cout << mtx;
    return 0;
}