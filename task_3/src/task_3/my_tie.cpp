//
// Created by shumoff on 13.02.2020.
//
#include "my_tie.h"


template <class T, size_t N, class ...Arrays>
auto my_tie(std::array<T, N> & first_array, Arrays & ...arrays) -> Tie<T, N, 1 + sizeof...(arrays)> {
    std::array<T*, 1 + sizeof...(arrays) + 1> array {first_array.begin(), arrays.begin()...};
    return Tie<T, N, 1 + sizeof...(arrays)>(array);
}
