
find_package(JNI)
find_package(Java)

if (JAVA_FOUND AND JNI_FOUND)
  include_directories(${JNI_INCLUDE_DIRS})

  add_plugin(JVM
    JVM.cpp
    Internal.cpp
    Config.cpp
    NWScript.cpp
    SCORCO.cpp
  )

  # We disable this here because this particular plugin has a ton of these harmless warnings
  # and I don't really have the patience to fix them right now.
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter -Wno-header-hygiene -Wno-cast-qual")

  # target_link_libraries(JVM ${JAVA_JVM_LIBRARY})
  target_link_libraries(JVM /usr/lib/jvm/java-8-openjdk-i386/jre/lib/i386/server/libjvm.so)

elseif (JAVA_FOUND AND JNI_FOUND)
  message(WARNING "Not compiling JVM plugin, no JDK&JNI found")
endif()
