#include <gtest/gtest.h>
#include <task_6/trait.h>

TEST(trait, circle) {
    float float_radius = 3.14;
    double double_radius = 2.718281828;
    auto float_circle = Circle<float>(float_radius);
    auto double_circle = Circle<double>(double_radius);

    EXPECT_EQ(Trait<Circle<float>>::size(float_circle), sizeof(float_radius));
    EXPECT_EQ(Trait<Circle<double>>::size(double_circle), sizeof(double_radius));
}

TEST(trait, rectangle) {
    float float_width = 1.5;
    float float_height = 2.5;
    auto float_rectangle = Rectangle<float>(float_width, float_height);
    double double_width = 4.3333;
    double double_height = 5.4444;
    auto double_rectangle = Rectangle<double>(double_width, double_height);

    EXPECT_EQ(Trait<Rectangle<float>>::size(float_rectangle), sizeof(float_width) + sizeof(float_height));
    EXPECT_EQ(Trait<Rectangle<double>>::size(double_rectangle), sizeof(double_width) + sizeof(double_height));
}