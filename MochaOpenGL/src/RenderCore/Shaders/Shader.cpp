#include "Shader.h"
#include <fstream>

Mocha::Shader::Shader(const char* vertexShaderSourceLocation, const char* fragmentShaderSourceLocation)
{
	m_shaderID = 0;
	m_uniformModelMatrix = 0;
	m_uniformProjectionMatrix = 0;
	m_uniformViewMatrix = 0;

	createFromFiles(vertexShaderSourceLocation, fragmentShaderSourceLocation);
}

Mocha::Shader::Shader()
{
	m_shaderID = 0;
	m_uniformModelMatrix = 0;
	m_uniformProjectionMatrix = 0;
	m_uniformViewMatrix = 0;

	const char* defaultVertShaderLocation = "./Content/Shaders/default.vert";
	const char* defaultFragShaderLocation = "./Content/Shaders/default.frag";

	createFromFiles(defaultVertShaderLocation, defaultFragShaderLocation);
}

Mocha::Shader::~Shader()
{
	clearShader();
}

void Mocha::Shader::createFromString(const char* vertexShaderSource, const char* fragmentShaderSource)
{
}

void Mocha::Shader::createFromFiles(const char* vertexShaderSourceLocation, const char* fragmentShaderSourceLocation)
{
	//const char* vertexShaderSource = readFile(vertexShaderSourceLocation).c_str();
	//const char* fragmentShaderSource = readFile(fragmentShaderSourceLocation).c_str();

	std::string strVertexShaderSource = readFile(vertexShaderSourceLocation);
	std::string strFragmentShaderSource = readFile(fragmentShaderSourceLocation);

	const char* vertexShaderSource = strVertexShaderSource.c_str();
	const char* fragmentShaderSource = strFragmentShaderSource.c_str();

	compileShader(vertexShaderSource, fragmentShaderSource);
}

void Mocha::Shader::useShader()
{
	glUseProgram(m_shaderID);
}

void Mocha::Shader::clearShader()
{
	if (m_shaderID != 0)
	{
		glDeleteProgram(m_shaderID);
		m_shaderID = 0;
	}

	m_uniformModelMatrix = 0;
	m_uniformProjectionMatrix = 0;
}

std::string Mocha::Shader::readFile(const char* fileLocation)
{
	std::string fileSource;
	std::ifstream fileStream(fileLocation, std::ios::in);

	if (!fileStream.is_open())
	{
		printf("Failed to read %s! file.", fileLocation);
		return "";
	}

	std::string line = "";

	while (!fileStream.eof())
	{
		std::getline(fileStream, line);
		fileSource.append(line + "\n");
	}

	fileStream.close();

	return fileSource;
}

void Mocha::Shader::compileShader(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	m_shaderID = glCreateProgram();

	if (!m_shaderID)
	{
		printf("Failed to create shader\n");
		return;
	}

	addShader(m_shaderID, vertexShaderSource, GL_VERTEX_SHADER);
	addShader(m_shaderID, fragmentShaderSource, GL_FRAGMENT_SHADER);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glLinkProgram(m_shaderID);
	glGetProgramiv(m_shaderID, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(m_shaderID, sizeof(eLog), NULL, eLog);
		printf("Error linking program: '%s'\n", eLog);
		return;
	}

	glValidateProgram(m_shaderID);
	glGetProgramiv(m_shaderID, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(m_shaderID, sizeof(eLog), NULL, eLog);
		printf("Error validating program: '%s'\n", eLog);
		return;
	}

	m_uniformModelMatrix = glGetUniformLocation(m_shaderID, "model");
	m_uniformProjectionMatrix = glGetUniformLocation(m_shaderID, "projection");
	m_uniformViewMatrix = glGetUniformLocation(m_shaderID, "view");
}

void Mocha::Shader::addShader(GLuint shaderProgramID, const char* shaderSource, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	const GLchar* theCode[1];
	theCode[0] = shaderSource;

	GLint codeLength[1];
	codeLength[0] = strlen(shaderSource);

	glShaderSource(shader, 1, theCode, codeLength);
	glCompileShader(shader);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(shader, 1024, NULL, eLog);
		fprintf(stderr, "Error compiling the %d shader: '%s'\n", shaderType, eLog);
		return;
	}

	glAttachShader(shaderProgramID, shader);
}
