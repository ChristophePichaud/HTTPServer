#pragma once
class ServerHelper
{
public:
	ServerHelper();
	~ServerHelper();

public:
	static std::wstring GetIP();
	static std::vector<std::wstring> GetIPs();
	static std::wstring GetHostName();
	static std::wstring BuildURL(std::wstring server, std::wstring port);
	static std::wstring FindParameterInQuery(std::map<std::wstring, std::wstring>query, std::wstring var);
	static std::wstring FindParameter(http_request message, std::wstring var);
};

