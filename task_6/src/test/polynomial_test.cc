#include <gtest/gtest.h>
#include <task_6/polynomial.h>
#include <complex>

TEST(polynomial, real_coeffs) {
    auto polynomial = Polynomial<float>(1.7f, 2.5f);

    EXPECT_EQ( polynomial.get_coeff(0), 1.7f);
    EXPECT_EQ(polynomial.get_coeff(1), 2.5f);

    polynomial.multiply(2.0f);

    EXPECT_EQ(polynomial.get_coeff(0), 3.4f);
    EXPECT_EQ( polynomial.get_coeff(1), 5.0f);
}

TEST(polynomial, complex_coeffs) {
    std::complex<double> first = std::complex<double>(1.7, -0.7);
    std::complex<double> second = std::complex<double>(2.5, -3.5);
    std::complex<double> multiplier = std::complex<double>(5.8, -7.2);

    auto polynomial = Polynomial<std::complex<double>>(first, second);

    EXPECT_EQ( polynomial.get_coeff(0), first);
    EXPECT_EQ(polynomial.get_coeff(1), second);

    polynomial.multiply(multiplier);

    EXPECT_EQ(polynomial.get_coeff(0), first * multiplier);
    EXPECT_EQ( polynomial.get_coeff(1), second * multiplier);
}