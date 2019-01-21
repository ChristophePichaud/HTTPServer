#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <random>
#include <memory>
#include <map>

#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/http_client.h"
#include "cpprest/http_msg.h"

using namespace std;
using namespace web;
using namespace utility;
using namespace http;
using namespace http::client;
using namespace web::http;
using namespace web::http::experimental::listener;

#include <tchar.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")

#ifdef _DEBUG
#pragma comment (lib, "cpprest141d_2_10.lib")
#else
#pragma comment (lib, "cpprest141_2_10.lib")
#endif

#include "Logger.h"
extern Logger g_Logger;

#endif //PCH_H

