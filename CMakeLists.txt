cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(TOY VERSION 0.0.1 LANGUAGES CXX)

file(GLOB TOY_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc")

add_library(toy SHARED ${TOY_SRCS})
target_include_directories(toy PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
if(MSVC)
  target_compile_definitions(toy PRIVATE -DTOY_EXPORTS)
endif()
set_target_properties(toy PROPERTIES POSITION_INDEPENDENT_CODE ON
                                     CXX_STANDARD 17)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/pybind11" EXCLUDE_FROM_ALL)
file(GLOB TOY_PY_API_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/python/csrc/*.cc")
pybind11_add_module(pytoy_capi MODULE "${TOY_PY_API_SRCS}")
target_include_directories(pytoy_capi PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
                                              "${CMAKE_CURRENT_SOURCE_DIR}/python/csrc")
target_link_libraries(pytoy_capi PRIVATE toy)
add_dependencies(pytoy_capi toy)
target_compile_definitions(pytoy_capi PRIVATE VERSION_INFO=${CMAKE_PROJECT_VERSION})
