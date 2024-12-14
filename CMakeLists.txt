# Specify the minimum version
cmake_minimum_required(VERSION 3.9)

# Specify the project info
project(bird_client VERSION 1.0.0 DESCRIPTION "Client library for BIRD routing daemon")

# Declare the library target.
add_library(${PROJECT_NAME} SHARED
    src/bird_client.c
    src/bird_client.h
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

# Set the public header property to the one with the actual API.
set(ALL_PUBLIC_HEADERS
    "src/bird_client.h"
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    PUBLIC_HEADER "${ALL_PUBLIC_HEADERS}"
)

# For access to standard installation directory variables (CMAKE_INSTALL_xDIR).
include(GNUInstallDirs)

# Set library shared object and API header file to install.
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Create the pkg-config file from the template.
configure_file(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

# Set pkg-config file to install.
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
