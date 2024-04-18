#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"
#include "../../Logging/Logger.h"
#include <stb_image.h>

Mocha::Texture::Texture()
{
	m_textureID = 0;
	m_width = 0;
	m_height = 0;
	m_bitDepth = 0;
	m_fileLocation = "";
}

Mocha::Texture::Texture(const char* textureFileLocation)
{
	m_textureID = 0;
	m_width = 0;
	m_height = 0;
	m_bitDepth = 0;
	m_fileLocation = textureFileLocation;
}

Mocha::Texture::~Texture()
{
	Texture::clearTexture();
}

void Mocha::Texture::loadTexture()
{
	unsigned char* texData = stbi_load(m_fileLocation, &m_width, &m_height, &m_bitDepth, 0);

	if (!texData)
	{
		Logger::Log("Invalid texture data", Logger::WARNING);
		return;
	}

	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(texData);
}

void Mocha::Texture::useTexture()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
}

void Mocha::Texture::clearTexture()
{
	glDeleteTextures(1, &m_textureID);
	m_textureID = 0;
	m_width = 0;
	m_height = 0;
	m_bitDepth = 0;
	m_fileLocation = "";
}
