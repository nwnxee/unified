inline uint64_t GetFastTimestamp()
{
    unsigned int out;
    return __rdtscp(&out);
}
