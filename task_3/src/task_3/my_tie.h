//
// Created by shumoff on 13.02.2020.
//
#include <array>

#ifndef TASK_3_TIE_H
#define TASK_3_TIE_H

template <class T, int N, int M>
struct Tie {
    explicit Tie(std::array<T*, N> & array) {
        for (size_t i = 0; i != M; ++i)
            arrays[i] = *(array.begin() + i);
    }
    void operator=(const std::array<T, N * M> & rhs) {
        for (size_t i = 0; i != M; ++i)
            arrays[i] = rhs.cbegin() + i * N;
    }

    std::array<T*, M> arrays;
};

#endif //TASK_3_TIE_H
