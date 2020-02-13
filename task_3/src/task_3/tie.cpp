//
// Created by shumoff on 13.02.2020.
//
#include "tie.h"

template <class T, size_t N, class ...Arrays>
auto tie(std::array<T, N> & first_array, Arrays & ...arrays) {
    std::array<T*, 1 + sizeof...(arrays)> array {first_array.begin(), arrays.begin()...};
    return Tie<T, N, 1 + sizeof...(arrays)>(array);
}
