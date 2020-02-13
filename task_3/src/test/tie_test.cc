#include <gtest/gtest.h>
#include "task_3/tie.cpp"

TEST(tie, tie_1_array) {
    std::array<float, 3> r = {1.0f, 2.0f, 3.0f};
    std::array<float, 3> array_1{};
    auto res_tie = tie(array_1);
    res_tie = r;
    size_t size = 1;
    EXPECT_EQ(array_1[0], 1.0f);
    EXPECT_EQ(array_1[1], 2.0f);
    EXPECT_EQ(array_1[2], 3.0f);
    EXPECT_EQ(res_tie.size(), size);
}

TEST(tie, tie_2_arrays) {
    std::array<float, 6> r = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    std::array<float, 3> array_1{}, array_2{};
    auto res_tie = tie(array_1, array_2);
    res_tie = r;
    size_t size = 2;
    EXPECT_EQ(array_1[0], 1.0f);
    EXPECT_EQ(array_1[1], 2.0f);
    EXPECT_EQ(array_1[2], 3.0f);
    EXPECT_EQ(array_2[0], 4.0f);
    EXPECT_EQ(array_2[1], 5.0f);
    EXPECT_EQ(array_2[2], 6.0f);
    EXPECT_EQ(res_tie.size(), size);
}

TEST(tie, tie_3_arrays) {
    std::array<float, 6> r = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    std::array<float, 2> array_1{}, array_2{}, array_3{};
    auto res_tie = tie(array_1, array_2, array_3);
    res_tie = r;
    size_t size = 3;
    EXPECT_EQ(array_1[0], 1.0f);
    EXPECT_EQ(array_1[1], 2.0f);
    EXPECT_EQ(array_2[0], 3.0f);
    EXPECT_EQ(array_2[1], 4.0f);
    EXPECT_EQ(array_3[0], 5.0f);
    EXPECT_EQ(array_3[1], 6.0f);
    EXPECT_EQ(res_tie.size(), size);
}
