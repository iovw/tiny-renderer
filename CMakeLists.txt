cmake_minimum_required(VERSION 3.16)
project(tinyrenderer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB SRC
        "include/*.{inc,hpp,h}"
        "src/*.cpp")

add_executable(tinyrenderer ${SRC})

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(PNG REQUIRED libpng)
#target_link_libraries(tinyrenderer
#        ${PNG_LIBRARIES}
#)

enable_testing()
find_package(GTest REQUIRED)
file(GLOB TEST_SRC test/*.{cpp})
add_executable(my_test ${TEST_SRC} test/VectorTest.cpp)
target_include_directories(my_test PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(my_test ${GTEST_BOTH_LIBRARIES})
gtest_discover_tests(my_test)