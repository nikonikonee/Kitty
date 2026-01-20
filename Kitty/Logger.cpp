#include "Logger.h"

void Logger::Log(clr color, const char* fmt, ...) {
	char buffer[1024];

	va_list args{};
	va_start(args, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	std::cout << color << buffer << clr::reset << std::endl;
}