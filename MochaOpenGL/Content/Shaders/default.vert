#version 330

layout (location = 0) in vec3 pos;      // XYZ
layout (location = 1) in vec2 uvCoord;  // UV

out vec4 vertexColour;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
    gl_Position = projection * view * model * vec4(pos, 1.0);
	vertexColour = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);

	texCoord = uvCoord;
}