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

    char formatBuffer[1536];
    std::sprintf(formatBuffer, format, args ...);

    InternalTrace(channel, allowedChannel, plugin, file, line, formatBuffer);
}

