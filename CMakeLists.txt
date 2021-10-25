cmake_minimum_required(VERSION 3.5)

project(QPanda_gui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(QT_DIR)
    set(CMAKE_PREFIX_PATH ${QT_DIR})
endif()

set(CMAKE_BUILD_TYPE Debug)

find_package(QT NAMES Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

file(GLOB TRANS_FILE translation/qpanda_gui_zh_CN.ts)
file(GLOB RESOURCE_FILE resource/resource.qrc)

add_subdirectory(src)