#include "pch.h"
#include "Logger.h"

Logger g_Logger;

Logger::Logger()
{
}


Logger::~Logger()
{
}

void Logger::WriteLog(std::wstring message)
{
	std::wcout << message << std::endl;
}