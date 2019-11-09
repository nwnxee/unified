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

    time_t now = std::time(nullptr);
    tm* timeinfo = std::localtime(&now);

    // Get filename without the full path.
    const char* filename = file;
    const char* filenameTemp = filename;
    while ((filenameTemp = std::strstr(filename, "/")))
    {
        filename = filenameTemp + 1;
    }

    std::ostringstream stream;
    tfm::format(stream, "%s [%02d:%02d:%02d] [%s] [%s:%d] ",
            SEVERITY_NAMES[static_cast<size_t>(channel)],
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
            plugin, filename, line);

    tfm::format(stream, format, std::forward<Args>(args)...);

    InternalTrace(channel, allowedChannel, stream.str().c_str());
}

