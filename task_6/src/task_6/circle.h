//
// Created by shumoff on 14.02.2020.
//

#ifndef TASK_6_CIRCLE_H
#define TASK_6_CIRCLE_H
#include <cmath>

template <class T>
class Circle {
public:
    Circle(T radius) : radius(R) {}

    void set_radius(T R) {
        this->radius = R;
    }

    T get_radius() const {
        return radius;
    }

    T square() const {
        return M_PI * pow(radius, 2);
    }

private:
    T radius_;
};
#endif //TASK_6_CIRCLE_H
