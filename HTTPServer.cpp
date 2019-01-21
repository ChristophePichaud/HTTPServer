// HTTPServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Server.h"
#include "ServerHelper.h"

void AutomateThread()
{
	try
	{
		std::wstring port = _T("7001");
		std::wstring host = ServerHelper::GetHostName();
		std::wstring ip = ServerHelper::GetIP();
		std::wstring url = ServerHelper::BuildURL(ip, port);
		http::uri uri = http::uri(url);
		std::wstring address = uri.to_string();
		std::wstring name = _T("Master");

		//
		// Create the server instance
		//

		Server server(address);
		server._server = ip;
		server._port = port;
		server._name = name;
		server.Init();

		while (TRUE)
		{
			Sleep(5000);

		} // Main loop

		server.Close();

	}
	catch (...)
	{
		g_Logger.WriteLog(_T("EXCEPTION: Arrêt du service"));
	}
}

int main()
{
	std::thread thread(AutomateThread);
	thread.join();
	g_Logger.WriteLog(_T("OK..."));
}


