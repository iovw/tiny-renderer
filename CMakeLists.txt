cmake_minimum_required(VERSION 3.16)
project(tinyrenderer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB SRC
        "include/*.{inc,hpp,h}"
        "src/*.cpp")

add_executable(tinyrenderer
        ${SRC} include/type.h)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(PNG REQUIRED libpng)
#target_link_libraries(tinyrenderer
#        ${PNG_LIBRARIES}
#)