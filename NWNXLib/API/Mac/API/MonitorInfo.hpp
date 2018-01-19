#pragma once

#include <cstdint>

#include "DetailedTiming.hpp"
#include "Timing.hpp"
#include "unknown_TLS_2CBA9030A62635964B64D4E478EE5B4E.hpp"

namespace NWNXLib {

namespace API {

struct MonitorInfo
{
    int32_t checksum;
    char manufacturer_code[4];
    int32_t product_code;
    uint32_t serial_number;
    int32_t production_week;
    int32_t production_year;
    int32_t model_year;
    int32_t major_version;
    int32_t minor_version;
    int32_t is_digital;
    TLS_2CBA9030A62635964B64D4E478EE5B4E _anon_0;
    int32_t width_mm;
    int32_t height_mm;
    double aspect_ratio;
    double gamma;
    int32_t standby;
    int32_t suspend;
    int32_t active_off;
    int32_t srgb_is_standard;
    int32_t preferred_timing_includes_native;
    int32_t continuous_frequency;
    double red_x;
    double red_y;
    double green_x;
    double green_y;
    double blue_x;
    double blue_y;
    double white_x;
    double white_y;
    Timing established[24];
    Timing standard[8];
    int32_t n_detailed_timings;
    DetailedTiming detailed_timings[4];
    char dsc_serial_number[14];
    char dsc_product_name[14];
    char dsc_string[14];
};

}

}
