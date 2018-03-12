template <typename ... Args>
void Fail(const char* condition, const char* file, int line, const char* format, Args ... args)
{
    char buffer[1536];
    std::sprintf(buffer, format, args ...);
    Fail(condition, file, line, buffer);
}
