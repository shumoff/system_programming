//
// Created by shumoff on 14.02.2020.
//

#ifndef TASK_6_TRAIT_H
#define TASK_6_TRAIT_H

#include "circle.h"
#include "rectangle.h"

template<class Figure>
struct Trait;

template<class T>
struct Trait<Circle<T>> {
    static size_t size(Circle<T> &circle) {
        return sizeof(circle.get_radius());
    }
};

template<class T>
struct Trait<Rectangle<T>> {
    static size_t size(Rectangle<T> &rectangle) {
        return sizeof(rectangle.get_length()) + sizeof(rectangle.get_width());
    }
};

#endif //TASK_6_TRAIT_H
