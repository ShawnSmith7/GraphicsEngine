cmake_minimum_required(VERSION 4.1)
project(GraphicsEngine LANGUAGES C CXX)

add_library(glad STATIC dependencies/glad/src/glad.c)

target_include_directories(glad PUBLIC dependencies/glad/include)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.2
)

FetchContent_MakeAvailable(glfw glm)

add_executable(GraphicsEngine src/main.cpp src/ShaderProgram.cpp)

target_link_libraries(GraphicsEngine PUBLIC opengl32 glad glfw glm)

target_compile_definitions(GraphicsEngine PRIVATE
    SRC_DIR="${CMAKE_SOURCE_DIR}/src/"
)