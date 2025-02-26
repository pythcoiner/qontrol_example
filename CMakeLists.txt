cmake_minimum_required(VERSION 3.22)
set(BIN QontrolExample)
project(${BIN} VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)

# include qontrol from git repo
include(FetchContent)
FetchContent_Declare(qontrol
    GIT_REPOSITORY https://github.com/pythcoiner/qontrol.git
    GIT_TAG c3fcb91
)
FetchContent_MakeAvailable(qontrol)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES
    src/main.cpp
    src/Controller.cpp
    src/MainWindow.cpp
    src/screens/Home.cpp
    src/screens/Next.cpp
)

qt_add_executable(${BIN}
    ${SOURCES}
)

add_dependencies(${BIN} 
    qontrol
)

target_include_directories(${BIN}
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
)

target_link_libraries(${BIN} 
    PRIVATE 
    Qt6::Gui 
    Qt6::Core 
    Qt6::Widgets 
    qontrol
)

set_target_properties(${BIN} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

