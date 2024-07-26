cmake_minimum_required(VERSION 3.16)
project(CoTree LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
    CoTree.ui
    CoTree.h
    CoTree.cpp
    CoTree.rc

    RandomNumberTool/RandomNumberTool.h
    RandomNumberTool/RandomNumberTool.cpp

    FileIOTool/FileIOTool.h
    FileIOTool/FileIOTool.cpp
)

qt_add_executable(CoTree ${PROJECT_SOURCES})

set_target_properties(CoTree
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(CoTree
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
