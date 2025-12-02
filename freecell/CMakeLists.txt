# CMakeLists.txt for FreeCell game project
cmake_minimum_required(VERSION 3.10)

project(FreeCell VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Windows-specific settings
if(WIN32)
    add_definitions(-DUNICODE -D_UNICODE)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-DNOMINMAX)
endif()

# Source files
set(SOURCES
    winmain.cpp
    InitializeEngine.cpp
    EngineHandler.cpp
    DialogHelper.cpp
    FreeCellGame.cpp
    globals.cpp
)

# Header files
set(HEADERS
    types.h
    IEngineInterface.h
    InitializeEngine.h
    EngineHandler.h
    DialogHelper.h
    FreeCellGame.h
)

# Create executable (WIN32 for Windows GUI application)
add_executable(FreeCell WIN32 ${SOURCES} ${HEADERS})

# Link Windows libraries
if(WIN32)
    target_link_libraries(FreeCell
        user32
        gdi32
        shell32
        comctl32
        ole32
        comdlg32
        advapi32
    )
endif()

# Set output directory
set_target_properties(FreeCell PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Install target
install(TARGETS FreeCell RUNTIME DESTINATION bin)
