#pragma once

#include "Utils.hpp"
#include <cstdio>

namespace NWNXLib::Assert {

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

    #define ASSERT_OR_THROW(condition) \
        do \
        { \
            if(!(condition)) throw std::runtime_error("ASSERTION FAILURE: (" + std::string(#condition) + ") in NWScript: " + NWNXLib::Utils::GetCurrentScript()); \
        } while (0)
    #define ASSERT_OR_RETURN(condition, retval) \
        do \
        { \
            if (!(condition)) { ASSERT_FAIL_MSG("ASSERTION FAILURE: %s", #condition); return retval; } \
        } while (0)

void Fail(const char* condition, const char* file, int line, const char* message);

void SetCrashOnFailure(bool crash);

template <typename ... Args>
void Fail(const char* condition, const char* file, int line, const char* format, Args ... args)
{
    char buffer[1536];
    std::sprintf(buffer, format, args ...);
    Fail(condition, file, line, buffer);
}

}
