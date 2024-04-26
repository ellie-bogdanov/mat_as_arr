#pragma once

#include <array>
#include <iostream>
#include <memory>
#include <stdint.h>
#include <vector>
namespace mat_as_arr {

    template <typename T>
    struct matrix {
    private:
        std::vector<T> mat;

    public:
        const uint64_t rows;
        const uint64_t columns;

        matrix(uint64_t rows, uint64_t columns) : rows(rows), columns(columns) {
            mat.resize(rows * columns);
        }

        void operator=(const std::vector<std::vector<T>> &copy_mat) {
            mat.clear();
            rows = copy_mat.size();
            columns = copy_mat[0].size();
            mat = new T[rows * columns];

            for (unsigned long i = 0; i < rows; ++i) {
                for (unsigned long j = 0; j < columns; ++j) {
                    mat[i * columns + j] = copy_mat[i][j];
                }
            }
        }

        T &at(uint64_t i, uint64_t j) {
            if (i < rows && j < columns)
                return mat[i * columns + j];
            std::cerr << "out of bounds \n";
            throw(1);
        }
    };

    template <typename T>
    std::ostream &operator<<(std::ostream &os, matrix<T> mtx) {
        os << "[\n ";
        for (uint64_t i = 0; i < mtx.rows; ++i) {
            os << '[';
            for (uint64_t j = 0; j < mtx.columns - 1; ++j) {
                os << mtx.at(i, j) << ", ";
            }
            os << mtx.at(i, mtx.columns - 1) << "]\n ";
        }
        os << "\b]\n";
        return os;
    }
}
