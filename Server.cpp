#include "pch.h"
#include "Server.h"
#include "ServerHelper.h"


std::wstring Server::_server;
std::wstring Server::_port;
std::wstring Server::_name;


Server::Server(std::wstring url) : m_listener(url)
{
	std::function<void(http_request)> fnGet = &Server::handle_get;
	m_listener.support(methods::GET, fnGet);
	this->_url = url;
}

Server::~Server()
{
}


void Server::Init()
{
	this->_http = std::make_unique<Server>(this->_url);
	this->_http->open().wait();
}

void Server::Close()
{
	this->_http->close().wait();
}

void Server::handle_get(http_request message)
{
	try
	{
		g_Logger.WriteLog(_T("handle_get"));

		PrintRequest(message);

		//http://192.168.137.148:7001.MyServer/?request=ping

		std::wstring request = ServerHelper::FindParameter(message, _T("request"));

		if (request == _T("ping"))
		{
			message.reply(status_codes::OK, _T("PING OK..."));
			return;
		}
		else if (request == _T("getdata"))
		{
			message.reply(status_codes::OK, _T("{.........................................}"));
			return;
		}
	}
	catch (...)
	{
		// an internal problem occured
		g_Logger.WriteLog(_T("handle_get exception..."));
	}

	message.reply(status_codes::OK);
}

void Server::PrintRequest(http_request message)
{
	g_Logger.WriteLog(message.to_string());
	g_Logger.WriteLog(message.relative_uri().to_string());

	auto paths = uri::split_path(uri::decode(message.relative_uri().path()));
	for (auto it1 = paths.begin(); it1 != paths.end(); it1++)
	{
		std::wstring path = *it1;
		g_Logger.WriteLog(path);
	}

	auto query = uri::split_query(uri::decode(message.relative_uri().query()));
	for (auto it2 = query.begin(); it2 != query.end(); it2++)
	{
		std::wostringstream buf;
		buf << _T("Query ") << it2->first << _T(" ") << it2->second;
		g_Logger.WriteLog(buf.str());
	}
}