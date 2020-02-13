//
// Created by shumoff on 13.02.2020.
//
#include <array>

template <class T, std::size_t firstSize, std::size_t secondSize>
std::array<T, firstSize + secondSize> cat(std::array<T, firstSize> const first_array, std::array<T, secondSize> const second_array) {
    std::array<T, firstSize + secondSize> res_array{};
    for (size_t i = 0; i != firstSize + secondSize; ++i) {
        if (i < firstSize)
            *(res_array.begin() + i) = *(first_array.begin() + i);
        else
            *(res_array.begin() + i) = *(second_array.begin() + i - firstSize);
    }

    return res_array;
}


template <class firstType, class ... Types>
auto cat(firstType first_array, Types ... arrays) {
    if constexpr (sizeof...(arrays) > 0) {
        auto res_array = cat(first_array, cat(arrays...));
        return res_array;
    }
    else {
        auto res_array = first_array;
        return res_array;
    }
};
