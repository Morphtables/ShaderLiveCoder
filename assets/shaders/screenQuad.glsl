#shader vertex
#version 330 core

layout (location = 0) in vec4 vertex;
uniform mat4 projection;
uniform mat4 model;

out vec2 texCoords;

void main() {
    gl_Position = projection * vec4(vertex.xy, 0.0, 1.0 );
    texCoords = vertex.zw;
}

#shader fragment
#version 330 core

in vec2 texCoords;

uniform vec3 quadColor;
uniform sampler2D fontTexture;
uniform vec2 iResolution;
uniform float iTime;

out vec4 color;

void main() {
    vec2 uv=(texCoords-0.5*iResolution.xy)/iResolution.y;
    float circle = length(uv);
    circle-=0.5;
    circle = abs(circle);
    color = vec4(circle,0.2, 0.29, 1.0);
}
