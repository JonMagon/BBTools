cmake_minimum_required(VERSION 3.21)
project(BBScriptEditor VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Widgets)

add_library(script_core STATIC
    src/format.cpp
    src/catalog.cpp
    src/command_fields.cpp
    src/script_validation.cpp
    src/game_resources.cpp
    resources.qrc
)
target_include_directories(script_core PUBLIC src)
target_link_libraries(script_core PUBLIC Qt6::Widgets)

add_library(script_ui STATIC
    src/editor.cpp
    src/editor_files.cpp
    src/editor_history.cpp
    src/editor_checks.cpp
    src/editor_about.cpp
    src/editor_support.cpp
    src/choice.cpp
    src/graph_node.cpp
    src/graph_view.cpp
)
target_link_libraries(script_ui PUBLIC script_core)

add_executable(BBScriptEditor src/main.cpp)
target_link_libraries(BBScriptEditor PRIVATE script_ui)
target_compile_definitions(BBScriptEditor PRIVATE SCRIPTS_EDITOR_VERSION="${PROJECT_VERSION}")
if(WIN32)
    enable_language(RC)
    target_include_directories(BBScriptEditor PRIVATE resources)
    target_sources(BBScriptEditor PRIVATE resources/app.rc)
endif()
if(MSVC)
    target_compile_options(script_core PRIVATE /W4 /utf-8)
    target_compile_options(script_ui PRIVATE /W4 /utf-8)
else()
    target_compile_options(script_core PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(script_ui PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(CTest)
if(BUILD_TESTING)
    find_package(Qt6 6.4 REQUIRED COMPONENTS Test)

    add_executable(editor_tests
        tests/test_editor.cpp
        tests/fixtures.cpp
    )
    target_link_libraries(editor_tests PRIVATE script_ui Qt6::Test)

    add_test(NAME editor_tests COMMAND editor_tests)
    set_tests_properties(editor_tests PROPERTIES
        ENVIRONMENT "QT_QPA_PLATFORM=offscreen"
    )
endif()

# Formatting is optional for building, but can be checked without modifying files.
find_program(CLANG_FORMAT_EXECUTABLE NAMES clang-format clang-format-22 clang-format-21)
if(CLANG_FORMAT_EXECUTABLE)
    file(GLOB_RECURSE FORMAT_SOURCE_FILES CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.h"
        "${PROJECT_SOURCE_DIR}/tests/*.cpp"
        "${PROJECT_SOURCE_DIR}/tests/*.h"
    )
    add_custom_target(format-check
        COMMAND "${CLANG_FORMAT_EXECUTABLE}" --dry-run --Werror ${FORMAT_SOURCE_FILES}
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
        COMMENT "Checking C++ formatting"
        VERBATIM
    )
endif()

install(TARGETS BBScriptEditor RUNTIME DESTINATION bin)
if(UNIX AND NOT APPLE)
    install(FILES resources/bbscripteditor.desktop DESTINATION share/applications)
    foreach(ICON_SIZE 16 24 32 48 64 128 256 512)
        install(FILES resources/icons/bbscripteditor-${ICON_SIZE}.png
            DESTINATION share/icons/hicolor/${ICON_SIZE}x${ICON_SIZE}/apps
            RENAME bbscripteditor.png)
    endforeach()
endif()
