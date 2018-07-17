#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <sstream>


// °Ñ¦Ò https://stackoverflow.com/questions/6168107/how-to-implement-a-good-debug-logging-feature-in-a-project

/* consider adding boost thread id since we'll want to know whose writting and
* won't want to repeat it for every single call */

/* consider adding policy class to allow users to redirect logging to specific
* files via the command line
*/

namespace Util {

	enum class LogLevel
	{
		LogERROR, LogWARNING, LogINFO, LogDEBUG, LogDEBUG1, LogDEBUG2, LogDEBUG3, LogDEBUG4
	};

	class LogIt
	{
	public:
		LogIt(LogLevel _loglevel = LogLevel::LogERROR) {
			_buffer << static_cast<int>(_loglevel) << " :"
				<< std::string(
					_loglevel > LogLevel::LogDEBUG
					? (static_cast<int>(_loglevel) - static_cast<int>(LogLevel::LogDEBUG)) * 4
					: 1
					, ' ');
		}

		template <typename T>
		LogIt & operator<<(T const & value)
		{
			_buffer << value;
			return *this;
		}

		~LogIt()
		{
			_buffer << std::endl;
			// This is atomic according to the POSIX standard
			// http://www.gnu.org/s/libc/manual/html_node/Streams-and-Threads.html
			std::cerr << _buffer.str();
		}

	private:
		std::ostringstream _buffer;
	};

	extern LogLevel logLevel;

#define Log(level) \
if (level > logLevel) ; \
else LogIt(level)

}



#endif