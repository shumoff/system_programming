#include <gtest/gtest.h>
#include "task_9/task_3/cat.cpp"

TEST(cat, cat_1_array) {
    std::array<float, 3> array_1 = {1.0f, 2.0f, 3.0f};
    size_t size = 3;
    auto res_array = cat(array_1);
    EXPECT_EQ(res_array[0], 1);
    EXPECT_EQ(res_array[1], 2);
    EXPECT_EQ(res_array[2], 3);
    EXPECT_EQ(res_array.size(), size);
}

TEST(cat, cat_2_arrays) {
    std::array<float, 3> array_1 = {1.0f, 2.0f, 3.0f};
    std::array<float, 2> array_2 = {4.0f, 5.0f};
    size_t size = 5;
    auto res_array = cat(array_1, array_2);
    EXPECT_EQ(res_array[0], 1.0f);
    EXPECT_EQ(res_array[1], 2.0f);
    EXPECT_EQ(res_array[2], 3.0f);
    EXPECT_EQ(res_array[3], 4.0f);
    EXPECT_EQ(res_array[4], 5.0f);
    EXPECT_EQ(res_array.size(), size);
}

TEST(cat, cat_3_arrays) {
    std::array<float, 3> array_1 = {1.0f, 2.0f, 3.0f};
    std::array<float, 2> array_2 = {4.0f, 5.0f};
    std::array<float, 4> array_3 = {6.0f, 7.0f, 8.0f, 9.0f};
    size_t size = 9;
    auto res_array = cat(array_1, array_2, array_3);
    EXPECT_EQ(res_array[0], 1.0f);
    EXPECT_EQ(res_array[1], 2.0f);
    EXPECT_EQ(res_array[2], 3.0f);
    EXPECT_EQ(res_array[3], 4.0f);
    EXPECT_EQ(res_array[4], 5.0f);
    EXPECT_EQ(res_array[5], 6.0f);
    EXPECT_EQ(res_array[6], 7.0f);
    EXPECT_EQ(res_array[7], 8.0f);
    EXPECT_EQ(res_array[8], 9.0f);
    EXPECT_EQ(res_array.size(), size);
}