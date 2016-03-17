#!/bin/sh

# CPU architecture
CPU_ARCH="arm64-v8a"
# Toolchain
TOOLCHAIN="aarch64-linux-android-clang3.5"
# STL
STL="c++_shared"
# cmake path
CMAKE=/Applications/CMake.app/Contents/bin/cmake

# NDK location
export ANDROID_NDK=~/Documents/adt-bundle-mac-x86_64-20130219/android-ndk-r10e

# script location
DIR=`dirname "$0"`
# user location
# make build dir
BUILD_DIR=$DIR/../build-android
mkdir -p $BUILD_DIR
cd $BUILD_DIR
# cmake step
$CMAKE  -DCMAKE_TOOLCHAIN_FILE=../scripts/android.toolchain.cmake -DANDROID_ABI=$CPU_ARCH -DANDROID_TOOLCHAIN_NAME=$TOOLCHAIN -DANDROID_STL=$STL ..
# make step
make
# back to initial directory
