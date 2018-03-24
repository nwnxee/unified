#pragma once

#include <cstdio>

namespace NWNXLib {

namespace Assert {

#if TAR_DEBUG
    #define ASSERT(condition) \
        do \
        { \
            if (!(condition)) ::NWNXLib::Assert::Fail((#condition), __FILE__, __LINE__, nullptr); \
        } while (0)

    #define ASSERT_MSG(condition, format, ...) \
        do \
        { \
            if (!(condition)) ::NWNXLib::Assert::Fail((#condition), __FILE__, __LINE__, (format), ##__VA_ARGS__); \
        } while (0)

    #define ASSERT_FAIL() \
        ::NWNXLib::Assert::Fail(nullptr, __FILE__, __LINE__, nullptr)

    #define ASSERT_FAIL_MSG(format, ...) \
        ::NWNXLib::Assert::Fail(nullptr, __FILE__, __LINE__, (format), ##__VA_ARGS__)
#else
    #define ASSERT(condition) (void)0
    #define ASSERT_MSG(condition, format, ...) (void)0
    #define ASSERT_FAIL() (void)0
    #define ASSERT_FAIL_MSG(format, ...) (void)0
#endif

void Fail(const char* condition, const char* file, int line, const char* message);

template <typename ... Args>
void Fail(const char* condition, const char* file, int line, const char* format, Args ... args);

void SetCrashOnFailure(bool crash);

#include "Assert.inl"

}

}
