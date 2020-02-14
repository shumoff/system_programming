//
// Created by shumoff on 14.02.2020.
//

#ifndef TASK_6_POLYNOMIAL_H
#define TASK_6_POLYNOMIAL_H

#include <complex>

template<class T>
struct Polynomial {
public:
    template<class ... Coeffs>
    explicit Polynomial(T first_coef, Coeffs ... coeffs) {
        size_ = sizeof...(coeffs) + 1;
        coeffs_ = new T[size_];
        set_coeffs(0, first_coef, coeffs...);
    }

    explicit Polynomial(T* coeffs, size_t size) : size_(size) {
        coeffs_ = new T[size_];
        for (size_t i = 0; i != size_; ++i)
            coeffs_[i] = coeffs[i];
    }

    Polynomial operator-(Polynomial<T> const & other) {
        size_t res_size = this->get_size();
        T* res_coeffs = new T[res_size];
        for (size_t i = 0; i != res_size; ++i)
            res_coeffs[i] = this->get_coeff(i) - other.get_coeff(i);
        return Polynomial<T>(res_coeffs, res_size);
    }

    size_t get_size() const {
        return size_;
    }

    T* get_coeffs() const {
        return coeffs_;
    }

    T get_coeff(size_t index) const {
        return coeffs_[index];
    }

    void set_coeff(size_t index, T value) {
        coeffs_[index] = value;
    }

    void multiply(T c) {
        for (size_t i = 0; i != size_; i++) {
            coeffs_[i] = coeffs_[i] * c;
        }
    }

    ~Polynomial() {
        delete[] coeffs_;
    }

private:
    T* coeffs_;
    size_t size_;

    template<class firstCoeff, class ... Coeffs>
    void set_coeffs(size_t index, firstCoeff first_coeff, Coeffs ... coeffs) {
        coeffs_[index] = first_coeff;
        if constexpr (sizeof...(coeffs) > 0)
            set_coeffs(index + 1, coeffs...);
    }
};

#endif //TASK_6_POLYNOMIAL_H
