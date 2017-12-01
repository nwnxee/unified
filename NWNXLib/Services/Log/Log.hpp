#pragma once

#include "Services/Log/Types.hpp"
#include "Services/Services.hpp"

#include <cassert>
#include <cstdio>
#include <mutex>
#include <string>
#include <set>

namespace NWNXLib {

namespace Services {

class Log : public ServiceBase
{
public: // Structures

public:
    Log();
    ~Log();

    template <typename ... Params>
    void Debug(const std::string& pluginName, const LogSeverity configuredSev,
        const char* format, Params ... args);

    template <typename ... Params>
    void Info(const std::string& pluginName, const LogSeverity configuredSev,
        const char* format, Params ... args);

    template <typename ... Params>
    void Notice(const std::string& pluginName, const LogSeverity configuredSev,
        const char* format, Params ... args);

    template <typename ... Params>
    void Warning(const std::string& pluginName, const LogSeverity configuredSev,
        const char* format, Params ... args);

    template <typename ... Params>
    void Error(const std::string& pluginName, const LogSeverity configuredSev,
        const char* format, Params ... args);

    template <typename ... Params>
    void Fatal(const std::string& pluginName, const LogSeverity configuredSev,
        const char* format, Params ... args);

private:
    std::mutex m_lock;
    std::string m_logFilePath;
    std::set<LogTarget> m_configuredLogTargets;

    // Outputs a log message to all configured log targets.
    template <typename ... Params>
    void Write(const LogSeverity sev, const LogSeverity configuredSev,
        const std::string& pluginName,const char* format, Params ... args);

    void WriteFormatted(const LogSeverity sev, const std::string& pluginName,
        const std::string& formatted);

    void WriteToFileWithoutLock(const std::string& path, const LogSeverity sev,
        const std::string& pluginName, const std::string& message);

    void OutputToFileDescriptor(FILE* fd, const LogSeverity sev,
        const std::string& pluginName, const std::string& message);

    template <typename ... Args>
    static std::string FormatString(const char* format, Args ... args);
};

class LogProxy : public ServiceProxy<Log>
{
public:
    LogProxy(Log& log, const std::string& pluginName, const LogSeverity sev);
    ~LogProxy();

    void SetLogLevel(const LogSeverity LogSeverity);

    template <typename ... Params>
    void Debug(const char* format, Params ... args);

    template <typename ... Params>
    void Info(const char* format, Params ... args);

    template <typename ... Params>
    void Notice(const char* format, Params ... args);

    template <typename ... Params>
    void Warning(const char* format, Params ... args);

    template <typename ... Params>
    void Error(const char* format, Params ... args);

    template <typename ... Params>
    void Fatal(const char* format, Params ... args);

private:
    std::string m_pluginName;
    LogSeverity m_configuredSeverity;
};

#include "Services/Log/Log.inl"

}

}
