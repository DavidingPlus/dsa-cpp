cmake_minimum_required (VERSION 3.12)

set (CMAKE_CXX_STANDARD 11)

project ("dsa-cpp")

# configuring compiler cross platform
if (CMAKE_HOST_WIN32)
    include (config-win32.cmake)

elseif (CMAKE_HOST_UNIX)
    include (config-unix.cmake)

else ()
    message (FATAL_ERROR "Unknown platform.")

endif ()

add_subdirectory (src)
