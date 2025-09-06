#include<winsock2.h>//winsock2的头文件
#include<iostream>
#include <pthread.h>

using namespace std;

void init_app();

void *GetMsg (void *socket);

void SendMsg();

#pragma comment(lib, "ws2_32.lib")


WSADATA wd;
SOCKET Socket;
//客户端
int main() {
	init_app();
	//接收服务端的消息
	pthread_t tids;
	pthread_create (&tids, NULL, GetMsg, &Socket);
	//随时给服务端发消息
	SendMsg();
	//关闭监听套接字
	closesocket (Socket);
	//清理winsock2的环境
	WSACleanup();
	return 0;
}

void SendMsg() {
	int ret = 0;
	do {
		char buf[100] = {0};
		cin >> buf;
		cout << "You Sent: > " << buf << " <\n";
		ret = send (Socket, buf, 100, 0);
	} while (ret != SOCKET_ERROR && ret != 0);
}

void *GetMsg (void *socket) {
	do {
		int ret = 0;
		do {
			char buf2[100] = {0};
			ret = recv (Socket, buf2, 100, 0);
			cout << buf2 << endl;

		} while (ret != SOCKET_ERROR && ret != 0);
	} while (true);
}


void init_app() {
	cout << "--->>>Client Site<<<---" << endl;
	//加载winsock2的环境
	if (WSAStartup (MAKEWORD (2, 2), &wd) != 0) {
		cout << "WSAStartup  error：" << GetLastError() << endl;
		return;
	}
	//创建流式套接字
	Socket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (Socket == INVALID_SOCKET) {
		cout << "socket  error：" << GetLastError() << endl;
		return;
	}
	char falg;
	cout << "是否输入服务器IP(y/n):";
	cin >> falg;
	char *ip;
	switch (falg) {
		case 'n': {
			ip = "127.0.0.1";
			break;
		}
		case 'y': {
			cout << "Read-in IP:";
			cin >> ip;
			break;
		}
	}

	//链接服务器
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons (8000);
	addr.sin_addr.s_addr = inet_addr (ip);
	cout << "Your IP:" << ip << "\n";
	int len = sizeof (sockaddr_in);
	if (connect (Socket, (SOCKADDR *) &addr, len) == SOCKET_ERROR) {
		cout << "connect  error：" << GetLastError() << endl;
		return;
	}
}
