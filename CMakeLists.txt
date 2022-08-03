cmake_minimum_required(VERSION 3.10)
project(ArtiApp_Template)

set(CMAKE_CXX_STANDARD 17)

#################################
#          Add library          #
#################################
add_subdirectory(deps/ArtiApp)

#################################
#      Enable measure FPS       #
#################################
target_compile_definitions(
    ArtiApp PUBLIC
        -DNDEBUG=1
        -DARTI_MEASURE_FPS=1
)

#################################
#    Application Executable     #
#################################
set(SOURCES
    main.cpp

    include/Main.hpp

    src/Main.cpp
)

if ((${CMAKE_SYSTEM_NAME} MATCHES "Windows") AND NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    add_executable(
        ArtiAppTemplate WIN32
            ${SOURCES}
    )
else()
    add_executable(
        ArtiAppTemplate
            ${SOURCES}
    )
endif()

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