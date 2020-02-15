//
// Created by shumoff on 13.02.2020.
//
#include <array>

#ifndef TASK_3_CAT_H
#define TASK_3_CAT_H

template <class T, std::size_t firstSize, std::size_t secondSize>
std::array<T, firstSize + secondSize> cat(std::array<T, firstSize> first_array, std::array<T, secondSize> second_array);

template <class firstType, class ... Types>
auto cat(firstType first_array, Types ... arrays);

#endif //TASK_3_CAT_H
