cmake_minimum_required(VERSION 2.6.4 FATAL_ERROR)

project(
  StopWatch
  CXX
)

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
  ${CMAKE_SOURCE_DIR}/include
)

add_custom_target(
  check_crlf
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMAND ./scripts/check_crlf.sh
)

add_custom_target(
  mkdir_build
  COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/bin/${DIR_NAME}
)


add_library(
  stopwatch
  SHARED
  ${CMAKE_SOURCE_DIR}/src/StopWatch.cpp
)

add_dependencies(
  stopwatch
  check_crlf
)

add_executable(
  demo
  ${CMAKE_SOURCE_DIR}/src/demo.cpp
)

target_link_libraries(
  demo
  stopwatch
  rt
)