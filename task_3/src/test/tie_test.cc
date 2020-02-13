#include <gtest/gtest.h>
//#include <array>
#include "task_3/my_tie.cpp"

TEST(tie, tie_1_array) {
    std::array<float, 6> r = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    std::array<float, 3> vec1, vec2;

    my_tie(vec1, vec2) = r;
//    size_t size = 5;
    EXPECT_EQ(vec1[0], 1.0f);
    EXPECT_EQ(vec1[1], 2.0f);
    EXPECT_EQ(vec1[2], 3.0f);
    EXPECT_EQ(vec2[0], 4.0f);
    EXPECT_EQ(vec2[1], 5.0f);
    EXPECT_EQ(vec2[2], 6.0f);


//    EXPECT_EQ(res_array.size(), size);

}

//TEST(cat, cat_2_arrays) {
//    std::array<float, 3> array_1 = {1.0f, 2.0f, 3.0f};
//    std::array<float, 2> array_2 = {4.0f, 5.0f};
//    size_t size = 5;
//    auto res_array = cat(array_1, array_2);
//    EXPECT_EQ(res_array[0], 1.0f);
//    EXPECT_EQ(res_array[1], 2.0f);
//    EXPECT_EQ(res_array[2], 3.0f);
//    EXPECT_EQ(res_array[3], 4.0f);
//    EXPECT_EQ(res_array[4], 5.0f);
//    EXPECT_EQ(res_array.size(), size);
//}
//
//TEST(cat, cat_3_arrays) {
//    std::array<float, 3> array_1 = {1.0f, 2.0f, 3.0f};
//    std::array<float, 2> array_2 = {4.0f, 5.0f};
//    std::array<float, 4> array_3 = {6.0f, 7.0f, 8.0f, 9.0f};
//    size_t size = 9;
//    auto res_array = cat(array_1, array_2, array_3);
//    EXPECT_EQ(res_array[0], 1.0f);
//    EXPECT_EQ(res_array[1], 2.0f);
//    EXPECT_EQ(res_array[2], 3.0f);
//    EXPECT_EQ(res_array[3], 4.0f);
//    EXPECT_EQ(res_array[4], 5.0f);
//    EXPECT_EQ(res_array[5], 6.0f);
//    EXPECT_EQ(res_array[6], 7.0f);
//    EXPECT_EQ(res_array[7], 8.0f);
//    EXPECT_EQ(res_array[8], 9.0f);
//    EXPECT_EQ(res_array.size(), size);
//
//}