#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include <task_9/task_5/ostream_iterator.h>

TEST(ostream_iterator, regular_behavior) {
    int N = 2;
    std::stringstream stream;
    OstreamIterator<int> ostream_iterator(stream, " ", N);
    std::vector<int> vector{9, 8, 7, 5, 6, 4, 2, 3, 1, 0};
    auto pointer = vector.begin();

    while(pointer != vector.end()) {
        ostream_iterator = *pointer++;
        }
    EXPECT_EQ(stream.str(), "8 5 4 3 0 ");
}