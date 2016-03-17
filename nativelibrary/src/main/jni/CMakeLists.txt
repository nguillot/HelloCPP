cmake_minimum_required(VERSION 2.8)
project(HelloLib)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(LIB_CPP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cpp")
set(LIB_JNI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/jni")

message(STATUS "LIB_CPP_DIR: ${LIB_CPP_DIR}")

file(GLOB PUBLIC_HEADERS
    "${LIB_CPP_DIR}/public/Hellolib.h"
)

file(GLOB SRCS
    "${LIB_CPP_DIR}/impl/Hellolib.cpp"
)

if(ANDROID)
    list(APPEND PUBLIC_HEADERS
      "${LIB_JNI_DIR}/public/NativeHolder.h"
      "${LIB_JNI_DIR}/public/Helper.h"
      "${LIB_JNI_DIR}/public/HellolibJNI.h"
      )
    list(APPEND SRCS
      "${LIB_JNI_DIR}/impl/Helper.cpp"
      "${LIB_JNI_DIR}/impl/HellolibJNI.cpp"
    )
endif(ANDROID)

add_library(HelloLib SHARED
  ${PUBLIC_HEADERS}
  ${SRCS}
)

if(ANDROID)
    set_target_properties(HelloLib PROPERTIES LINK_FLAGS "-llog -landroid -atomic")
endif(ANDROID)
