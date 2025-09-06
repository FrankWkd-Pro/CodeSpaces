//服务端
#include <winsock2.h>
#include <iostream>
#include <list>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

// 线程处理函数
DWORD WINAPI ThreadFun (LPVOID lpThreadParameter);

void init_app();
void Send_All (list<SOCKET> Client_List_Now, char *msg, SOCKET This_Socket);
char* GetName (int num);

WSADATA wd;
SOCKET Socket;
list<SOCKET> Client_List;
sockaddr_in addrClient;
int len = sizeof (sockaddr_in);


int main() {
	init_app();
	//主线程循环接收客户端的连接
	while (true) {
		// 接受成功返回与client通讯的Socket
		SOCKET Client = accept (Socket, (SOCKADDR *) &addrClient, &len);
		if (Client != INVALID_SOCKET) {
			// 创建线程，并且传入与client通讯的套接字
			HANDLE hThread = CreateThread (NULL, 0, ThreadFun, (LPVOID) Client, 0, NULL);
			CloseHandle (hThread); // 关闭对线程的引用
		}
	}
	//关闭监听套接字
	closesocket (Socket);
	//清理winsock2的环境
	WSACleanup();
	return 0;
}

DWORD WINAPI ThreadFun (LPVOID lpThreadParameter) {
	// 接受数据
	SOCKET This_Socket = (SOCKET) lpThreadParameter;

	// 发送欢迎
	char buf[100] = {0};
	sprintf (buf, "******** %s Get to Room*******\n", GetName (This_Socket));
	cout << This_Socket << " Is Already in room\n";
	Send_All (Client_List, buf, This_Socket);
	Client_List.push_back (This_Socket);
	// 循环接收客户端数据
	int ret = 0;
	do {
		char buf2[100] = {0};
		ret = recv (This_Socket, buf2, 100, 0);
		cout << This_Socket << " Sent:" << buf2 << endl;
		char str3[200];
		strcpy (str3, GetName (This_Socket));
		strcat (str3, " Sent:");
		strcat (str3, buf2);
		Send_All (Client_List, str3, This_Socket);
	} while (ret != SOCKET_ERROR && ret != 0);
	Client_List.remove (This_Socket);
	cout << This_Socket << " Leave This Room\n";
	return 0;
}

void Send_All (list<SOCKET> Client_List_Now, char *msg, SOCKET This_Socket) {
	Client_List_Now.remove (This_Socket);
	for (auto iter :  Client_List_Now) {
		send (iter, msg, strlen (msg), 0);
	}
}

void init_app() {
	cout << "===========Server============" << endl;
	char falg;
	char *ip;
	if (WSAStartup (MAKEWORD (2, 2), &wd) != 0) {
		cout << "WSAStartup Error:" << WSAGetLastError() << endl;
		return;
	}
	// 创建流式套接字
	Socket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (Socket == INVALID_SOCKET) {
		cout << "socket error:" << WSAGetLastError() << endl;
		return;
	}
	cout << "是否自定义当前服务器IP(y/n):";
	cin >> falg;
	switch (falg) {
		case 'n': {
			ip = "127.0.0.1";
			break;
		}
		case 'y': {
			cout << "请输入IP:";
			cin >> ip;
			break;
		}
	}

	//绑定端口和ip
	sockaddr_in addr;
	memset (&addr, 0, sizeof (sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons (8000);
	addr.sin_addr.s_addr = inet_addr (ip);
	cout << "Server IP:" << ip << "\n";

	//服务端bind绑定
	if (bind (Socket, (SOCKADDR *) &addr, len) == SOCKET_ERROR) {
		cout << "bind Error:" << WSAGetLastError() << endl;
		return;
	}
	// 监听20个以下设备
	listen (Socket, 20);
}
char* GetName (int num) {
	num = (num % 19) + 1;
	switch (num) {
		case (1) : {
			return "Client 1";
		}
		case (2) : {
			return "Client 2";
		}
		case (3) : {
			return "Client 3";
		}
		case (4) : {
			return "Client 4";
		}
		case (5) : {
			return "Client 5";
		}
		case (6) : {
			return "Client 6";
		}
		case (7) : {
			return "Client 7";
		}
		case (8) : {
			return "Client 8";
		}
		case (9) : {
			return "Client 9";
		}
		case (10): {
			return "Client 10";
		}
		case (11): {
			return "Client 11";
		}
		case (12): {
			return "Client 12";
		}
		case (13): {
			return "Client 13";
		}
		case (14): {
			return "Client 14";
		}
		case (15): {
			return "Client 15";
		}
		case (16): {
			return "Client 16";
		}
		case (17): {
			return "Client 17";
		}
		case (18): {
			return "Client 18";
		}
		case (19): {
			return "Client 19";
		}
	}
}
