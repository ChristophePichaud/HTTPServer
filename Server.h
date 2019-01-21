#pragma once
class Server
{
public:
	Server(std::wstring url);
	~Server();
	
	void Init();
	void Close();

public:
	pplx::task<void> open() { return m_listener.open(); }
	pplx::task<void> close() { return m_listener.close(); }

private:
	static void PrintRequest(http_request request);
	static void handle_get(http_request message); 

private:
	http_listener m_listener; 

public:
	static std::wstring _server;
	static std::wstring _port;
	static std::wstring _name;

public:
	std::unique_ptr<Server> _http;
	std::wstring _url;
};

