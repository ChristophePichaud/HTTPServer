#pragma once
class Logger
{
public:
	Logger();
	~Logger();

public:
	void WriteLog(std::wstring message);
};

