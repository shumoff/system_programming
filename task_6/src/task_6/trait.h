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
static unsigned size(const Circle<T>& c) {
    return sizeof(c.get_radius());
    }
};

template<class T>
struct Trait<Rectangle<T>> {
static unsigned size(const Rectangle<T>& r) {
    return sizeof(r.get_a()) + sizeof(r.get_b());
    }
};

#endif //TASK_6_TRAIT_H
