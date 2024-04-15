#include "RenderObject.h"
#include "../Logging/Logger.h"

Mocha::RenderObject::RenderObject(Material mat, Mesh mesh)
{

}

Mocha::RenderObject::RenderObject()
{
	//m_mesh GenerateDefaultMesh();

	Mocha::Logger::Log("default obj constructor");
}

Mocha::RenderObject::~RenderObject()
{

}

void Mocha::RenderObject::draw()
{
	// Assign shader program

	//Mesh mesh = GenerateDefaultMesh();
	//mesh.drawMesh();

	// Draw mesh
	m_mesh.drawMesh();


}
