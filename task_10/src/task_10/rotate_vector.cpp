//
// Created by shumoff on 15.02.2020.
//
#include <vector>

template <typename T>
int rotate_vector(std::vector<T>& vector, int degrees) {
    if (vector.size() > 2)
        return 1;

    if (degrees % 90 > 0)
        return 1;

    int rotations = degrees / 90;
    if (rotations > 0)
        for(int i = 0; i != rotations; ++i) {
            T tmp = vector[1];
            vector[1] = -vector[0];
            vector[0] = tmp;
        }
    else
        for(int i = 0; i != -rotations; ++i) {
            T tmp = vector[0];
            vector[0] = -vector[1];
            vector[1] = tmp;
        }

    return 0;
}

