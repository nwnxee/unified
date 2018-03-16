void InternalTrace(Channel::Enum channel, Channel::Enum allowedChannel, const char* plugin, const char* file, int line, const char* message);

template <typename ... Args>
void Trace(Channel::Enum channel, const char* plugin, const char* file, int line, const char* format, Args ... args)
{
    Channel::Enum allowedChannel = GetLogLevel(plugin);

    if (channel > allowedChannel)
    {
        // No need to do anything. Our log level is lower.
        return;
    }

    // 128k should be the VM boundary, so largest message we'd need to print.
    static char formatBuffer[128*1024];
    std::snprintf(formatBuffer, sizeof(formatBuffer), format, args ...);

    InternalTrace(channel, allowedChannel, plugin, file, line, formatBuffer);
}

