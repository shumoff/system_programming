#include <gtest/gtest.h>
#include <task_6/schur_transform.cpp>
#include <complex>

TEST(polynomial, schur) {
    Polynomial<int> polynomial = Polynomial<int>(1, 2, 3);

    Polynomial<int> schur_polynomial = schur_transform(polynomial);

    EXPECT_EQ(schur_polynomial.get_coeff(0), 0);
    EXPECT_EQ(schur_polynomial.get_coeff(1), 4);
    EXPECT_EQ(schur_polynomial.get_coeff(2), 8);
}

TEST(polynomial, schur_2_complex) {
    std::complex<double> first = std::complex<double>(1, 1);
    std::complex<double> second = std::complex<double>(2, 2);

    Polynomial<std::complex<double>> polynomial = Polynomial<std::complex<double>>(first, second);

    Polynomial<std::complex<double>> schur_polynomial = schur_transform(polynomial);

    EXPECT_EQ(std::real(schur_polynomial.get_coeff(0)), 0);
    EXPECT_EQ(std::imag(schur_polynomial.get_coeff(0)), 0);
    EXPECT_EQ(std::real(schur_polynomial.get_coeff(1)), 6);
    EXPECT_EQ(std::imag(schur_polynomial.get_coeff(1)), 0);
}

TEST(polynomial, schur_3_complex) {
    std::complex<double> first = std::complex<double>(1, 1);
    std::complex<double> second = std::complex<double>(2, 2);
    std::complex<double> third = std::complex<double>(3, 3);

    Polynomial<std::complex<double>> p = Polynomial<std::complex<double>>(first, second, third);

    Polynomial<std::complex<double>> schur_polynomial = schur_transform(p);

    EXPECT_EQ(std::real(schur_polynomial.get_coeff(0)), 0);
    EXPECT_EQ(std::imag(schur_polynomial.get_coeff(0)), 0);
    EXPECT_EQ(std::real(schur_polynomial.get_coeff(1)), 8);
    EXPECT_EQ(std::imag(schur_polynomial.get_coeff(1)), 0);
    EXPECT_EQ(std::real(schur_polynomial.get_coeff(2)), 16);
    EXPECT_EQ(std::imag(schur_polynomial.get_coeff(2)), 0);
}