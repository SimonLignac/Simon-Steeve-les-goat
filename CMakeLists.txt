cmake_minimum_required(VERSION 3.16)

project(lesgoat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(lesgoat
    main.cpp
)

target_link_libraries(lesgoat PRIVATE Qt6::Widgets)

include(GNUInstallDirs)
install(TARGETS lesgoat
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
