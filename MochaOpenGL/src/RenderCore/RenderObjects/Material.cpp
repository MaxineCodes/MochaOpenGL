#include "Material.h"
#include "../../Logging/Logger.h"

Mocha::Material::Material()
{
	m_shader = nullptr;
}

Mocha::Material::~Material()
{

}

void Mocha::Material::useMaterial()
{
	// Check for nullptr
	if (m_shader == nullptr)
	{
		Logger::Log("Shader is NULLPTR", Logger::logLevel::WARNING);
		return;
	}



	// Bind textures
	for (int i = 0; i < m_textures.size(); i++)
	{
		if (m_textures[i] != nullptr)
		{
			m_textures[i]->useTexture();
		}

		else
		{
			Logger::Log("Texture is NULLPTR", Logger::logLevel::WARNING);
		}
	}

	// Set the shader to be active for the next drawcall
	m_shader->useShader();
}

void Mocha::Material::setShader(Shader* shader)
{
	m_shader = shader;
}

void Mocha::Material::addTexture(Texture* texture)
{
	m_textures.push_back(texture);
}
