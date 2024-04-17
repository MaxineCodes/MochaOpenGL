#pragma once

#include <GL/glew.h>

namespace Mocha
{
	class Texture
	{
	public:
		Texture();
		Texture(const char* textureFileLocation);
		~Texture();

		void loadTexture();
		void useTexture();
		void clearTexture();

	private:
		GLuint m_textureID;

		int m_width, m_height, m_bitDepth;

		const char* m_fileLocation;

	};
}


