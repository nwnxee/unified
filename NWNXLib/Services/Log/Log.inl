template <typename ... Params>
void Log::Debug(const std::string& pluginName, const LogSeverity configuredSev,
    const char* format, Params ... args)
{
    Write(LogSeverity::SEV_DEBUG, configuredSev, pluginName, format, args ...);
}

template <typename ... Params>
void Log::Info(const std::string& pluginName, const LogSeverity configuredSev,
    const char* format, Params ... args)
{
    Write(LogSeverity::SEV_INFO, configuredSev, pluginName, format, args ...);
}

template <typename ... Params>
void Log::Notice(const std::string& pluginName, const LogSeverity configuredSev,
    const char* format, Params ... args)
{
    Write(LogSeverity::SEV_NOTICE, configuredSev, pluginName, format, args ...);
}

template <typename ... Params>
void Log::Warning(const std::string& pluginName, const LogSeverity configuredSev,
    const char* format, Params ... args)
{
    Write(LogSeverity::SEV_WARNING, configuredSev, pluginName, format, args ...);
}

template <typename ... Params>
void Log::Error(const std::string& pluginName, const LogSeverity configuredSev,
    const char* format, Params ... args)
{
    Write(LogSeverity::SEV_ERROR, configuredSev, pluginName, format, args ...);
}

template <typename ... Params>
void Log::Fatal(const std::string& pluginName, const LogSeverity configuredSev,
    const char* format, Params ... args)
{
    // Always emit fatal messages on console. We're not worried about clobbering
    // the configured param since we will abort immediately after.
    m_configuredLogTargets.insert(LogTarget::CONSOLE);
    Write(LogSeverity::SEV_FATAL, configuredSev, pluginName, format, args ...);
    std::terminate();
}

template <typename ... Params>
void Log::Write(const LogSeverity sev, const LogSeverity configuredSev,
    const std::string& pluginName, const char* format, Params ... args)
{
    if (static_cast<uint8_t>(sev) <= static_cast<uint8_t>(configuredSev))
    {
        WriteFormatted(sev, pluginName, FormatString(format, args ...));
    }
}

template <typename ... Args>
std::string Log::FormatString(const char* format, Args ... args)
{
    // Lots of allocations, and slow ... :(
    const int ret = std::snprintf(nullptr, 0, format, args ...);
    assert(ret >= 0);
    const size_t len = static_cast<size_t>(ret);
    std::unique_ptr<char[]> buffer(new char[len + 1]);
    std::snprintf(buffer.get(), len + 1, format, args ...);
    return std::string(buffer.get(), buffer.get() + len);
}

template <typename ... Params>
void LogProxy::Debug(const char* format, Params ... args)
{
    m_proxyBase.Debug(m_pluginName, m_configuredSeverity, format, args ...);
}

template <typename ... Params>
void LogProxy::Info(const char* format, Params ... args)
{
    m_proxyBase.Info(m_pluginName, m_configuredSeverity, format, args ...);
}

template <typename ... Params>
void LogProxy::Notice(const char* format, Params ... args)
{
    m_proxyBase.Notice(m_pluginName, m_configuredSeverity, format, args ...);
}

template <typename ... Params>
void LogProxy::Warning(const char* format, Params ... args)
{
    m_proxyBase.Warning(m_pluginName, m_configuredSeverity, format, args ...);
}

template <typename ... Params>
void LogProxy::Error(const char* format, Params ... args)
{
    m_proxyBase.Error(m_pluginName, m_configuredSeverity, format, args ...);
}

template <typename ... Params>
void LogProxy::Fatal(const char* format, Params ... args)
{
    m_proxyBase.Fatal(m_pluginName, m_configuredSeverity, format, args ...);
}
