#pragma once

#include <cstdio>

namespace NWNXLib::Assert {

    #define ASSERT_IMPL(condition) \
        do \
        { \
            if (!(condition)) ::NWNXLib::Assert::Fail((#condition), __FILE__, __LINE__, ""); \
        } while (0)

    #define ASSERT_MSG_IMPL(condition, format, ...) \
        do \
        { \
            if (!(condition)) ::NWNXLib::Assert::Fail((#condition), __FILE__, __LINE__, (format), ##__VA_ARGS__); \
        } while (0)

    #define ASSERT_FAIL_IMPL() \
        ::NWNXLib::Assert::Fail(nullptr, __FILE__, __LINE__, "")

    #define ASSERT_FAIL_MSG_IMPL(format, ...) \
        ::NWNXLib::Assert::Fail(nullptr, __FILE__, __LINE__, (format), ##__VA_ARGS__)

    #define ASSERT_OR_THROW_IMPL(condition) \
        do \
        { \
            if(!(condition)) throw std::runtime_error("ASSERTION FAILURE: (" + std::string(#condition) + ") in NWScript: " + NWNXLib::Utils::GetCurrentScript()); \
        } while (0)
    #define ASSERT_OR_RETURN_IMPL(condition, retval) \
        do \
        { \
            if (!(condition)) { ASSERT_FAIL_MSG("ASSERTION FAILURE: %s", #condition); return retval; } \
        } while (0)

    void FailInternal(const char* condition, const char* file, int line, const char* message);

    template <typename ... Args>
    void Fail(const char* condition, const char* file, int line, const char* format, Args ... args)
    {
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wformat-security"
        char buffer[1536];
        std::sprintf(buffer, format, args ...);
        FailInternal(condition, file, line, buffer);
    #pragma GCC diagnostic pop
    }

}
