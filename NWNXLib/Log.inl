void InternalTrace(Channel::Enum channel, Channel::Enum allowedChannel, const char* message);

template <typename ... Args>
void Trace(Channel::Enum channel, const char* plugin, const char* file, int line, const char* format, Args&& ... args)
{
    Channel::Enum allowedChannel = GetLogLevel(plugin);

    if (channel > allowedChannel)
    {
        // No need to do anything. Our log level is lower.
        return;
    }

    static constexpr const char * SEVERITY_NAMES[] = { "", "", "F", "E", "W", "N", "I", "D" };

    // Get filename without the full path.
    const char* filename = file;
    const char* filenameTemp = filename;
    while ((filenameTemp = std::strstr(filename, "/")))
    {
        filename = filenameTemp + 1;
    }

    std::ostringstream stream;
    stream << SEVERITY_NAMES[static_cast<size_t>(channel)] << " ";
    if (GetPrintTimestamp())
    {
        time_t now = std::time(nullptr);
        tm* timeinfo = std::localtime(&now);

        if (GetPrintDate())
            tfm::format(stream, "[%04d-%02d-%02d %02d:%02d:%02d] ", 1900 + timeinfo->tm_year,  1 + timeinfo->tm_mon,
                    timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        else
            tfm::format(stream, "[%02d:%02d:%02d] ", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    }
    if (GetPrintPlugin())
    {
        tfm::format(stream, "[%s] ", plugin);
    }
    if (GetPrintSource())
    {
        tfm::format(stream, "[%s:%d] ", filename, line);
    }
    tfm::format(stream, format, std::forward<Args>(args)...);

    InternalTrace(channel, allowedChannel, stream.str().c_str());
}

