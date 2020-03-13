cmake_minimum_required(VERSION 3.16)
project(tinyrenderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(tinyrenderer
        src/main.cpp
)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(PNG REQUIRED libpng)
#target_link_libraries(tinyrenderer
#        ${PNG_LIBRARIES}
#)