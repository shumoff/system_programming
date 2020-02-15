#include <gtest/gtest.h>
#include <vector>
#include "task_9/task_5/merge_sort.cpp"

TEST(merge_sort, regular_vector) {
    std::vector<int>vector{9, 8, 7, 5, 6, 4, 2, 3, 1, 0};
    merge_sort(vector.begin(),vector.end());

    for(int i = 0; i < 10; i++)
        EXPECT_EQ(vector[i], i);
}

TEST(merge_sort, one_element_vector) {
    std::vector<int>vector{0};
    merge_sort(vector.begin(),vector.end());
    EXPECT_EQ(vector[0], 0);
}