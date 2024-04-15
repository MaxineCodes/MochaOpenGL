#pragma once

namespace Mocha
{
	namespace Logger
	{
		enum logLevel
		{
			INFO = 0,
			WARNING = 1,
			ERROR = 2
		};

		void Log(const char* message);
		void Log(const char* message, logLevel);

		const char* getLogPrefix(logLevel level);

	}
}