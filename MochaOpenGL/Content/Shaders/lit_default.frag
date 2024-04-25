#version 330

in vec4 vertexColour;
in vec2 texCoord;

out vec4 colour;

struct DirectionalLight 
{
    vec3 colour; 
    float ambientIntensity;

};

uniform sampler2D textureSampler;
uniform DirectionalLight directionalLight;

void main()
{
    vec4 ambientColour = vec4(directionalLight.colour, 1.0f) * directionalLight.ambientIntensity;
    vec4 positionColour = vec4(vertexColour) * 0.5f;

    //colour = vertexColour;
    colour = (texture(textureSampler, texCoord * 2) * ambientColour) + positionColour;
}