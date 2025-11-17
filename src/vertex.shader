#version 330 core
layout (location = 0) in vec2 pos;
layout (location = 1) in vec3 vertColor;

uniform mat4 transform;

out vec3 fragColor;

void main() {
    fragColor = vertColor;
    gl_Position = transform * vec4(pos, 0.0, 1.0);
}