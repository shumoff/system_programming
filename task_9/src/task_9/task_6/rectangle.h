//
// Created by shumoff on 14.02.2020.
//

#ifndef TASK_6_RECTANGLE_H
#define TASK_6_RECTANGLE_H

#include <cmath>

template <class T>
struct Rectangle {
public:
    Rectangle(T length, T width) : length_(length), width_(width) {}

    void set_length(T length) {
        length_ = length;
    }

    void set_width(T width) {
        width_ = width;
    }

    T get_length() const {
        return length_;
    }

    T get_width() const {
        return width_;
    }

    T square(){
        return length_ * width_;
    }

private:
    T length_, width_;
};

#endif //TASK_6_RECTANGLE_H
