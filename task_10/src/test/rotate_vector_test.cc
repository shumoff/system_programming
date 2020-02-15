#include <gtest/gtest.h>
#include <vector>
#include <task_10/rotate_vector.cpp>

TEST(rotate_vector, wrong_size){
    std::vector<int> vector = {1, 2, 3};
    EXPECT_EQ(rotate_vector(vector, 90), 1);
}

TEST(rotate_vector, non_multiple_degrees){
    std::vector<int> vector = {1, 2};
    EXPECT_EQ(rotate_vector(vector, 100), 1);
}

TEST(rotate_vector, rotate_clockwise){
    std::vector<int> vector = {1, 2};
    rotate_vector(vector, 90);
    EXPECT_EQ(2, vector[0]);
    EXPECT_EQ(-1, vector[1]);
}

TEST(rotate_vector, rotate_counter_clockwise) {
    std::vector<int> vector = {1, 2};
    rotate_vector(vector, -90);
    EXPECT_EQ(-2, vector[0]);
    EXPECT_EQ(1, vector[1]);
}