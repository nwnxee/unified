if(MSVC)
nwnxlib_add("FunctionsWindows.cpp")
else()
nwnxlib_add("FunctionsLinux.cpp")
endif()

set(NWN_API_INCLUDE "ApiExtensions.hpp")

#set(APIDIR ${CMAKE_CURRENT_SOURCE_DIR}/${APIDIR} PARENT_SCOPE)
