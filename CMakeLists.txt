cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(
  StopWatch
  VERSION 0.1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_BUILD_TYPE)
  if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(DIR_NAME "deb")
  elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(DIR_NAME "rel")
  else()
    message(FATAL_ERROR "変数CMAKE_BUILD_TYPEにはDebugかReleaseを指定してください")
  endif()
else()
  message(FATAL_ERROR "変数CMAKE_BUILD_TYPEが定義されていません")
endif()

set(CMAKE_CXX_FLAGS "-Wall -fmessage-length=0")
set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3")

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

add_library(
  stopwatch
  SHARED
  ${PROJECT_SOURCE_DIR}/src/StopWatch.cpp
)

target_include_directories(
  stopwatch
  PUBLIC 
  ${PROJECT_SOURCE_DIR}/include
)

add_executable(
  demo
  ${PROJECT_SOURCE_DIR}/src/demo.cpp
)

target_link_libraries(
  demo
  stopwatch
)