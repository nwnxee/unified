template<> std::vector<MetricData> Resamplers::Sum<std::chrono::nanoseconds>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Sum<int64_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Sum<uint64_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Sum<double>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Sum<int32_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Sum<uint32_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Sum<float>(std::vector<MetricData>&&);

template<> std::vector<MetricData> Resamplers::Mean<std::chrono::nanoseconds>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Mean<int64_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Mean<uint64_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Mean<double>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Mean<int32_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Mean<uint32_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Mean<float>(std::vector<MetricData>&&);

template<> std::vector<MetricData> Resamplers::Min<std::chrono::nanoseconds>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Min<int64_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Min<uint64_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Min<double>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Min<int32_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Min<uint32_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Min<float>(std::vector<MetricData>&&);

template<> std::vector<MetricData> Resamplers::Max<std::chrono::nanoseconds>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Max<int64_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Max<uint64_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Max<double>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Max<int32_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Max<uint32_t>(std::vector<MetricData>&&);
template<> std::vector<MetricData> Resamplers::Max<float>(std::vector<MetricData>&&);

template <typename T>
std::vector<MetricData> Resamplers::Sum(std::vector<MetricData>&& data,
    std::function<T(const std::string&)>&& fromString,
    std::function<std::string(const T&)>&& toString,
    T startingVal)
{
    return Resample(std::forward<std::vector<MetricData>>(data),
        [&](std::vector<std::string>&& existing) -> std::string
        {
            T val = std::forward<T>(startingVal);

            for (auto& entry : existing)
            {
                val += fromString(entry);
            }

            return toString(std::move(val));
        }
    );
}

template <typename T>
std::vector<MetricData> Resamplers::Mean(std::vector<MetricData>&& data,
    std::function<T(const std::string&)>&& fromString,
    std::function<std::string(const T&)>&& toString)
{
    return Resample(std::forward<std::vector<MetricData>>(data),
        [&](std::vector<std::string>&& existing) -> std::string
        {
            T val = fromString(existing[0]);

            for (size_t i = 1; i < existing.size(); ++i)
            {
                val += fromString(existing[i]);
            }

            return toString(val / static_cast<T>(existing.size()));
        }
    );
}

template <typename T>
std::vector<MetricData> Resamplers::Min(std::vector<MetricData>&& data,
    std::function<T(const std::string&)>&& fromString,
    std::function<std::string(const T&)>&& toString)
{
    return Resample(std::forward<std::vector<MetricData>>(data),
        [&](std::vector<std::string>&& existing) -> std::string
        {
            T val = fromString(existing[0]);

            for (size_t i = 1; i < existing.size(); ++i)
            {
                T val2 = fromString(existing[i]);

                if (val2 < val)
                {
                    std::swap(val, val2);
                }
            }

            return toString(val);
        }
    );
}

template <typename T>
std::vector<MetricData> Resamplers::Max(std::vector<MetricData>&& data,
    std::function<T(const std::string&)>&& fromString,
    std::function<std::string(const T&)>&& toString)
{
    return Resample(std::forward<std::vector<MetricData>>(data),
        [&](std::vector<std::string>&& existing) -> std::string
        {
            T val = fromString(existing[0]);

            for (size_t i = 1; i < existing.size(); ++i)
            {
                T val2 = fromString(existing[i]);

                if (val2 > val)
                {
                    std::swap(val, val2);
                }
            }

            return toString(val);
        }
    );
}
