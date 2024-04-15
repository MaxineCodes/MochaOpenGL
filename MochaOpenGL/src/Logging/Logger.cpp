#include "Logger.h"

#include <iostream>


void Mocha::Logger::Log(const char* message)
{
	Log(message, INFO);
}

void Mocha::Logger::Log(const char* message, logLevel level)
{
	const char* prefix = getLogPrefix(level);

	std::cout << prefix << message << std::endl;
}

const char* Mocha::Logger::getLogPrefix(logLevel level)
{
	const char* prefix;

	switch (level)
	{
	case INFO:
		prefix = "[Info] ";
		break;

	case WARNING:
		prefix = "[!Warning!] ";
		break;

	case ERROR:
		prefix = "[!!!ERROR!!!] ";
		break;

	default:
		prefix = "[ ] ";
		break;
	}

	return prefix;
}
