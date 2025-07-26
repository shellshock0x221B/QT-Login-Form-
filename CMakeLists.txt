cmake_minimum_required(VERSION 3.16)
project(QtLoginApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt modules
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

# Source files in src/
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.h"
    "src/*.ui"
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include path
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Link Qt
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Sql)

# Copy database after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/databases"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/databases"
)
