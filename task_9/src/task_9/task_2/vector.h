//
// Created by shumoff on 09.02.2020.
//
#include <cstddef>
#include <algorithm>

#ifndef SYSTEM_PROGRAMMING_VECTOR_H
#define SYSTEM_PROGRAMMING_VECTOR_H

template <typename T>
struct Vector
{
public:
    Vector() = default;
    explicit Vector(size_t size): size_(size), data_(new T[size]) {};
    Vector(Vector<T> const & other): size_(other.size_), data_(new T[other.size_]) {
        for (size_t i = 0; i != size_; ++i)
            data_[i] = other.data_[i];
    };

    Vector(Vector<T> && other): size_(std::move(other.size_)), data_(std::move(other.data_)) {};

    Vector & operator=(Vector<T> const & other) {
        this->~Vector();
        Vector<T> tmp(other);
        this->swap(tmp);
        return *this;
    }

    Vector & operator=(Vector<T> && other) {
        this->swap(other);
        return *this;
    }

    T & operator[](size_t index) {
        return data_[index];
    }

    void swap(Vector<T> & other) {
        size_t tmp_size = size_;
        size_ = other.size_;
        other.size_ = tmp_size;
        T * tmp_data = this->data_;
        data_ = other.data_;
        other.data_ = tmp_data;
    }

    T * begin() {
        return data_;
    }

    T * end() {
        return data_ + size_;
    }

    size_t size() {
        return size_;
    }

    T & push_back(T const & value) {
        T * tmp_data = data_;
        size_ += 1;
        data_ = new T[size_];
        for (size_t i = 0; i != size_ - 1; ++i)
            data_[i] = tmp_data[i];
        data_[size_ - 1] = value;
        delete[] tmp_data;
        tmp_data = nullptr;
        return value;
    }

    T & push_back(T && value) {
        T * tmp_data = data_;
        size_ += 1;
        data_ = new T[size_];
        for (size_t i = 0; i != size_ - 1; ++i)
            data_[i] = std::move(tmp_data[i]);
        data_[size_ - 1] = std::move(value);
        delete[] tmp_data;
        tmp_data = nullptr;
        return value;
    }

    T pop_back() {
        T * tmp_data = data_;
        size_ -= 1;
        data_ = new T[size_];
        for (size_t i = 0; i != size_; ++i)
            data_[i] = tmp_data[i];
        T popped_value(tmp_data[size_]);
        if (size_ == 0)
            this->~Vector();
        delete[] tmp_data;
        tmp_data = nullptr;
        return popped_value;
    }

    T * erase(T * index) {
        size_t num_er_els = 1;
        T * erased = new T[num_er_els];
        T * tmp_data = data_;
        size_t tmp_data_offset = 0;
        size_ -= 1;
        data_ = new T[size_];
        for (size_t i = 0; i != size_ + 1; ++i) {
            if (tmp_data + i != index)
                data_[i - tmp_data_offset] = tmp_data[i];
            else {
                erased[tmp_data_offset] = tmp_data[i];
                tmp_data_offset += 1;
            }
        }
        if (size_ == 0)
            this->~Vector();
        delete tmp_data;
        tmp_data = nullptr;
        return erased;
    }

    T * erase(T * first, T * last) {
        size_t num_er_els = last - first;
        T * erased = new T[num_er_els];
        T * tmp_data = data_;
        size_t tmp_data_offset = 0;
        size_ -= num_er_els;
        data_ = new T[size_];
        for (size_t i = 0; i != size_ + num_er_els; ++i) {
            if (tmp_data + i < first || tmp_data + i >= last)
                data_[i - tmp_data_offset] = tmp_data[i];
            else {
                erased[tmp_data_offset] = tmp_data[i];
                tmp_data_offset += 1;
            }
        }
        if (size_ == 0)
            this->~Vector();
        delete tmp_data;
        tmp_data = nullptr;
        return erased;
    }

    ~Vector() {
        size_ = 0;
        delete[] data_;
        data_ = nullptr;
    }

private:
    size_t size_ = 0;
    T * data_ = nullptr;

};

template<typename T>
void swap(Vector<T> & a, Vector<T> & b) {
    a.swap(b);
}
#endif //SYSTEM_PROGRAMMING_VECTOR_H
