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

add_library(GraphicsEngineLib src/ShaderProgram.cpp)
target_include_directories(GraphicsEngineLib PUBLIC src)
target_link_libraries(GraphicsEngineLib PUBLIC opengl32 glad glfw glm)

add_executable(GraphicsEngineApp src/main.cpp)
target_link_libraries(GraphicsEngineApp PRIVATE GraphicsEngineLib)

target_compile_definitions(GraphicsEngineLib PRIVATE
    SRC_DIR="${CMAKE_SOURCE_DIR}/src/"
)