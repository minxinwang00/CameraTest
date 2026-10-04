cmake_minimum_required(VERSION 3.10)
project(CameraTest)
set(CMAKE_CXX_STANDARD 17)

find_package(spdlog REQUIRED)

set(GALAXY_SDK_ROOT "/home/mxw/Galaxy_Linux-x86_Gige-U3_32bits-64bits_2.6.2606.9251/Galaxy_Linux-x86_Gige-U3_32bits-64bits_2.6.2606.9251/Galaxy_camera")
include_directories(${GALAXY_SDK_ROOT}/inc)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src/sample)

add_executable(camera_test
    src/sample/GxSingleCamColor.cpp
    src/sample/Common/Common.cpp
)

target_link_libraries(camera_test
    gxiapi
    spdlog::spdlog
    pthread
)
