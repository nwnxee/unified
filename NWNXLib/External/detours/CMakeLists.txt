add_library(detours STATIC
        src/creatwth.cpp
        src/detours.cpp
        src/detours.h
        src/detver.h
        src/disasm.cpp
        src/disolarm.cpp
        src/disolarm64.cpp
        src/disolia64.cpp
        src/disolx64.cpp
        src/disolx86.cpp
        src/image.cpp
        src/modules.cpp
        src/uimports.cpp)

set_property (SOURCE src/uimports.cpp APPEND PROPERTY HEADER_FILE_ONLY true)
target_include_directories(detours PUBLIC src)
