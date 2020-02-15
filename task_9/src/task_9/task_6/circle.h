//
// Created by shumoff on 14.02.2020.
//

#ifndef TASK_6_CIRCLE_H
#define TASK_6_CIRCLE_H

#include <cmath>

template <class T>
struct Circle {
public:
    explicit Circle(T radius) : radius_(radius) {}

    void set_radius(T radius) {
        radius_ = radius;
    }

    T get_radius() const {
        return radius_;
    }

    T square() const {
        return M_PI * pow(radius_, 2);
    }

private:
    T radius_;
};

#endif //TASK_6_CIRCLE_H
