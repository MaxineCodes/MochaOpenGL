#version 330

in vec4 vertexColour;
in vec2 texCoord;

out vec4 colour;

uniform sampler2D textureSampler;

vec3 checker(in float u, in float v)
{
    float checkSize = 2;
    float fmodResult = mod(floor(checkSize * u) + floor(checkSize * v), 2.0);
    float fin = max(sign(fmodResult), 0.3f);
    return vec3(fin, fin, fin) - vec3(0.0f, 1.0f, 0.0f);
}

void main()
{
    vec3 check = checker(texCoord.x * 5, texCoord.y * 5);

    colour = vec4(check, 1.0f);
}