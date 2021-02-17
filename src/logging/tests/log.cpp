#include "../include/log.hpp"

#include <string>

#include <gtest/gtest.h>

const std::string test_strings[] = {
    "1234567890 the quick brown fox jumps over the lazy dog",
    "!@#$%^&*() THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG",
    "懒狗的棕色狐狸跳得很快", // This may not appear in your editor, but it is chineese,
    "[]\\;',./`"
};

#define TEST_STRING_ITERATION for (auto test_string : test_strings)

TEST(logging, logging_init_succeeds) {
    CatnetUtils::Log::Init();
}

/******************** HEAD LOGGING TESTS ********************/

TEST(logging, trace_head_logging_succeeds) {
    TEST_STRING_ITERATION { HD_TRACE(test_string); }
}

TEST(logging, warn_head_logging_succeeds) {
    TEST_STRING_ITERATION { HD_WARN(test_string); }
}

TEST(logging, info_head_logging_succeeds) {
    TEST_STRING_ITERATION { HD_INFO(test_string); }
}

TEST(logging, error_head_logging_succeeds) {
    TEST_STRING_ITERATION { HD_ERROR(test_string); }
}

TEST(logging, critical_head_logging_succeeds) {
    TEST_STRING_ITERATION { HD_CRITICAL(test_string); }
}

/******************** WHISKER LOGGING TESTS ********************/

TEST(logging, trace_whisker_logging_succeeds) {
    TEST_STRING_ITERATION { WK_TRACE(test_string); }
}

TEST(logging, warn_whisker_logging_succeeds) {
    TEST_STRING_ITERATION { WK_WARN(test_string); }
}

TEST(logging, info_whisker_logging_succeeds) {
    TEST_STRING_ITERATION { WK_INFO(test_string); }
}

TEST(logging, error_whisker_logging_succeeds) {
    TEST_STRING_ITERATION { WK_ERROR(test_string); }
}

TEST(logging, critical_whisker_logging_succeeds) {
    TEST_STRING_ITERATION { WK_CRITICAL(test_string); }
}
