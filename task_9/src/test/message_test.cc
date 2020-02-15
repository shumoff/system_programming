#include <gtest/gtest.h>
#include "task_9/task_3/message.cpp"

TEST(message, mismatching_args_and_format_symbols) {
    EXPECT_EQ(1, message(std::cout, "% + % = %", 'a'));
    EXPECT_EQ(1, message(std::cout, "% + % = %", 'a', 1, 2.0, "some_string"));
    EXPECT_EQ(1, message(std::cout, "x + y = z", 'a'));
    EXPECT_EQ(0, message(std::cout, "% + % = %", 'a', 'b', 'c'));
}

TEST(message, expected_output) {
    std::stringstream stream;
    message(stream, "some word, %% + % = % another word", "number", 5.0, 3, "8");
    EXPECT_EQ(stream.str(), "some word, number5 + 3 = 8 another word");
}
