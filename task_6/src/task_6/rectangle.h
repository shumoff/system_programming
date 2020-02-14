//
// Created by shumoff on 14.02.2020.
//

#ifndef TASK_6_RECTANGLE_H
#define TASK_6_RECTANGLE_H

#include <cmath>

template <class T>
class Rectangle {
private:
    T a, b;

public:
    Rectangle(T a, T b) : a(a), b(b) {}

    void set_a(T a) {
        this->a = a;
    }

    T get_a() const {
        return a;
    }

    void set_b(T b) {
        this->b = b;
    }

    T get_b() const {
        return b;
    }

    T square(){
        return a * b;
    }
};

#endif //TASK_6_RECTANGLE_H
