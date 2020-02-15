//
// Created by shumoff on 14.02.2020.
//
#include "polynomial.h"

template<class T>
typename std::enable_if<std::is_arithmetic<T>::value, Polynomial<T>>::type
schur_transform(Polynomial<T> polynomial) {
    size_t size = polynomial.get_size();
    Polynomial<T> reciprocal_polynomial = Polynomial<T>(polynomial.get_coeffs(), size);
    for (size_t i = 0; i != size; i++)
        reciprocal_polynomial.set_coeff(i, polynomial.get_coeff(size - 1 - i));

    reciprocal_polynomial.multiply(polynomial.get_coeff(0));
    polynomial.multiply(polynomial.get_coeff(size - 1));

    Polynomial<T> schur_polynomial = polynomial - reciprocal_polynomial;

    return schur_polynomial;
}

template<class T>
typename std::enable_if<!std::is_arithmetic<T>::value, Polynomial<T>>::type
schur_transform(Polynomial<T> polynomial) {
    size_t size = polynomial.get_size();
    Polynomial<T> reciprocal_polynomial = Polynomial<T>(polynomial.get_coeffs(), size);
    for (size_t i = 0; i != size; ++i)
        reciprocal_polynomial.set_coeff(i, std::conj(polynomial.get_coeff(size - 1 - i)));

    reciprocal_polynomial.multiply(polynomial.get_coeff(0));
    polynomial.multiply(std::conj(polynomial.get_coeff(size - 1)));

    Polynomial<T> schur_polynomial = polynomial - reciprocal_polynomial;

    return schur_polynomial;
}