//
// Created by shumoff on 13.02.2020.
//
#include <array>

#ifndef TASK_3_TIE_H
#define TASK_3_TIE_H

template <class T, int N, int M>
struct Tie {
public:
    explicit Tie(std::array<T*, M> & array) {
        arrays_ = array;
    }
    void operator=(const std::array<T, N * M> & rhs) {
        for (size_t i = 0; i != M; ++i) {
            for (size_t j = 0; j != N; ++j)
                arrays_[i][j] = *(rhs.begin() + i * N + j);
        }
    }
    size_t size() {
        return arrays_.size();
    }
    
private:
    std::array<T*, M> arrays_;
};

#endif //TASK_3_TIE_H
