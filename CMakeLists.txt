cmake_minimum_required(VERSION 3.15)
project(tiny_renderer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

#file(GLOB LIB_SRC include/*)
file(GLOB SRC src/*)

#MESSAGE("lib ${LIB_SRC}")
MESSAGE("src ${SRC}")

#add_library(lib ${LIB_SRC})
#set_target_properties(lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(tiny_renderer ${SRC})
target_link_libraries(tiny_renderer)

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(PNG REQUIRED libpng)
#target_link_libraries(tinyrenderer
#        ${PNG_LIBRARIES}
#)

enable_testing()
find_package(GTest REQUIRED)
file(GLOB TEST_SRC test/*)

add_executable(all_test ${TEST_SRC})
target_include_directories(all_test PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(all_test
        #lib
        ${GTEST_BOTH_LIBRARIES})

gtest_discover_tests(all_test)