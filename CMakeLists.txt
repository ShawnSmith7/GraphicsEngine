cmake_minimum_required(VERSION 4.1)
project(GraphicsEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options("/Zc:__cplusplus")

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

add_library(GraphicsEngineLib 
    src/Window.cpp 
    src/ShaderProgram.cpp 
    src/VertexArray.cpp 
    src/Layout.cpp
    src/Buffer.cpp 
    src/VertexBuffer.cpp 
    src/IndexBuffer.cpp 
    src/Drawable.cpp 
    src/Transformer.cpp
    src/Rect.cpp 
    src/Line.cpp
    src/Circle.cpp)
target_include_directories(GraphicsEngineLib PUBLIC src)
target_link_libraries(GraphicsEngineLib PUBLIC opengl32 glad glfw glm)

add_executable(GraphicsEngineApp src/main.cpp)
target_link_libraries(GraphicsEngineApp PRIVATE GraphicsEngineLib)

target_compile_definitions(GraphicsEngineLib PRIVATE
    SRC_DIR="${CMAKE_SOURCE_DIR}/src/"
)