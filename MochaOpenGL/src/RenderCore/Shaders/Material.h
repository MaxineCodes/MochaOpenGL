/////////////////////////////////////////////////////////////////////////////////////////////
// 
//	Material.h
// 
// 
//  Description:  Material class which holds some data like a shader program and textures. 
//			      Is required to construct a RenderObject class.
//				  
//                Call applyMaterial() to bind this material for the next draw call.
//			      This is already performed by RenderObject.draw()
// 
// 
//  
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <vector>

#include "Shader.h"
#include "Texture.h"


namespace Mocha
{
	class Material
	{
	public:
		Material();
		~Material();

		// Set this material to be active for the next drawcall
		void useMaterial();

		// Set the active shader for the material.
		void setShader(Shader* shader);

		// Add a texture to the material
		void addTexture(Texture* texture);

	private:
		Shader* m_shader;
		std::vector<Texture*> m_textures;
	};
}

