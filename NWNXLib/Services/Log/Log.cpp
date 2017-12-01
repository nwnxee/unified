#include "Services/Log/Log.hpp"

#include "Platform/FileSystem.hpp"
#include "Platform/Time.hpp"
#include "Platform/Syslog.hpp"

#include <cassert>
#include <cstdio>

namespace NWNXLib {

namespace Services {

Log::Log() :
    ServiceBase(nullptr),
    //TODO: make log directory configurable (we probably need to retrieve -userdir)
    m_logFilePath(Platform::FileSystem::CombinePaths(
                      Platform::FileSystem::CombinePaths(
                          Platform::FileSystem::GetCurExecutablePath(),
                          std::string("logs.0")),
                      "nwnx.txt")),

    // TODO: make log targets configurable
    m_configuredLogTargets( { LogTarget::CONSOLE, LogTarget::LOCALFILE })
{
}

Log::~Log()
{
}

void Log::WriteFormatted(const LogSeverity sev, const std::string& pluginName, const std::string& formatted)
{
    std::lock_guard<std::mutex> lock(m_lock);

    if (m_configuredLogTargets.find(LogTarget::CONSOLE) != m_configuredLogTargets.end())
    {
        OutputToFileDescriptor(stdout, sev, pluginName, formatted);
    }

    if (m_configuredLogTargets.find(LogTarget::SYSLOG) != m_configuredLogTargets.end())
    {
        Platform::Syslog::Emit(sev, "nwnx-" + pluginName, formatted);
    }

    if (m_configuredLogTargets.find(LogTarget::LOCALFILE) != m_configuredLogTargets.end())
    {
        // TODO: do we even want one-file-per-plugin? Usually it's enough
        //       to grep the big file.
        // TODO: this will hang when the log file grows > INT32 bytes. Need
        //       to support truncating.
        WriteToFileWithoutLock(m_logFilePath, sev, pluginName, formatted);
    }
}

void Log::WriteToFileWithoutLock(const std::string& path, const LogSeverity sev,
    const std::string& pluginName, const std::string& message)
{
    FILE* file = std::fopen(path.c_str(), "a+");

    if (file)
    {
        OutputToFileDescriptor(file, sev, pluginName, message);
        std::fclose(file);
    }
}

void Log::OutputToFileDescriptor(FILE* fd, const LogSeverity sev,
    const std::string& pluginName, const std::string& message)
{
    static constexpr const char * SEVERITY_NAMES[] = { "", "", "F", "E", "W", "N", "I", "D" };

    assert(fd);
    Platform::Time::Date date = Platform::Time::ConstructDateFromSystemTime();
    std::fprintf(fd, "%s [%02d:%02d:%02d] %s: %s\n",
        SEVERITY_NAMES[static_cast<size_t>(sev)],
        date.m_hour,
        date.m_minute,
        date.m_second,
        pluginName.c_str(),
        message.c_str());
}

LogProxy::LogProxy(Log& log, const std::string& pluginName, const LogSeverity sev)
    : ServiceProxy<Log>(log), m_pluginName(pluginName), m_configuredSeverity(sev)
{
}

LogProxy::~LogProxy()
{
}

void LogProxy::SetLogLevel(const LogSeverity severity)
{
    m_configuredSeverity = severity;
}

}

}
