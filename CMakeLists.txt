cmake_minimum_required(VERSION 3.10)
project(ArtiApp_Template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#################################
#          Add library          #
#################################
add_subdirectory(deps/ArtiApp)

#################################
#    Application Executable     #
#################################
set(SOURCES
    main.cpp

    include/Main.hpp

    src/Main.cpp
)

set(COMPILE_DEFINITIONS
    -DNDEBUG=1
    -DARTI_MEASURE_FPS=1
)

if ((${CMAKE_SYSTEM_NAME} MATCHES "Windows") AND NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    add_executable(
        ArtiAppTemplate WIN32
            ${SOURCES}
    )

    set(COMPILE_DEFINITIONS
        -DARTI_MEASURE_FPS=1
        -DARTI_DISABLE_LOGGER=1
    )
else()
    add_executable(
        ArtiAppTemplate
            ${SOURCES}
    )
endif()

#################################
#     Compile definitions       #
#################################
target_compile_definitions(
    ArtiApp PUBLIC
        ${COMPILE_DEFINITIONS}
)

target_include_directories(
    ArtiAppTemplate PUBLIC
        "include"
)

target_link_libraries(
    ArtiAppTemplate PUBLIC
        ArtiApp
)

#################################
#    Copy DLLS to out folder    #
#################################
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/)

set_target_properties(
    ArtiAppTemplate PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

set_property(
    TARGET ArtiAppTemplate
    APPEND
    PROPERTY ADDITIONAL_CLEAN_FILES ${CMAKE_CURRENT_SOURCE_DIR}/bin/
)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_custom_command(TARGET ArtiAppTemplate POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:ArtiAppTemplate> ${CMAKE_CURRENT_SOURCE_DIR}/bin/
        COMMAND_EXPAND_LISTS
    )
endif()

#################################
#   Copy assets to out folder   #
#################################
add_custom_command(TARGET ArtiAppTemplate POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets/ ${CMAKE_CURRENT_SOURCE_DIR}/bin/assets/
    COMMAND_EXPAND_LISTS
)
