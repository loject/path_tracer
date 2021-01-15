# Dependencies
set(Boost_USE_STATIC_LIBS ON)
cmake_policy(SET CMP0074 NEW)
find_package(Boost 1.75.0 COMPONENTS unit_test_framework REQUIRED)

file(GLOB_RECURSE TEST_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach(FILE ${TEST_FILES})
    string(REGEX REPLACE "[./]" "_" NAME ${FILE})
    add_executable(${NAME} ${FILE})
    target_link_libraries(${NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${PROJECT_NAME}_lib)
    add_test(NAME ${NAME} COMMAND ${NAME})
    set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 17)
endforeach(FILE ${TEST_FILES})

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS} ${PROJECT_NAME}/src)

# Compiler option for files with a lot of tests cases
add_definitions(/bigobj)

include(CTest)