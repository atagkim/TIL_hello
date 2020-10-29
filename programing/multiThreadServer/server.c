// TCP echo concurrent server using multithread
// TCP echo concurrent server using multithread
#include <winsock.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BUFSIZE 512

int servicerTable[200];
SOCKET servicerSocketTable[200];
SOCKADDR_IN servicerServeraddrTable[200];

SOCKET userSocketTable[200];
SOCKADDR_IN userAddrTable[200];

int userIDTop;

// socket errof display and quit
void err_quit(char* msg)
{
	printf("socket function error [%s] (error code: %d)... program terminated \n", msg, WSAGetLastError());
	exit(-1);
}

// socket errof display and quit
void err_display(char* msg, int code)
{
	printf("%s (error code: %d)\n", msg, code);
}


// Thread function to communicate with a client
DWORD WINAPI ProcessClient(LPVOID arg)
{

	SOCKET				client_sock = (SOCKET)arg;
	SOCKET				servicer = (SOCKET)arg;
	
	unsigned char				buf[BUFSIZE + 1];
	SOCKADDR_IN			clientaddr;
	int					addrlen;
	int					retval;


	int servicerRetval;
	SOCKET servicerSock;
	SOCKADDR_IN servicerServeraddr;
	unsigned char servicerBuf[BUFSIZE + 1];

	WSADATA servicerWsa;

	int servicerID;
	int commandID;
	int userID;
	int dataLen;
	char dataPart[500];

	int myUserID = userIDTop++;
	

	
	// obtain the client's information
	addrlen = sizeof(clientaddr);
	getpeername(client_sock, (SOCKADDR*)&clientaddr, &addrlen);

	userSocketTable[myUserID] = client_sock;
	userAddrTable[myUserID] = clientaddr;
	
	while (1) {
		
		printf("\n\tclient %d is running...\n\n", myUserID);

		// receive data from the client
		retval  = recv(userSocketTable[myUserID], buf, BUFSIZE, 0);
		if (retval == SOCKET_ERROR) {
			err_display("socket error: recv()", WSAGetLastError());
			break;
		}
		else if (retval == 0) {
			break;
		}

		// parsing the received data
		buf[retval] = '\0';

		servicerID = 0;
		servicerID = buf[0] >> 5;
		commandID = 0;
		commandID = buf[0] & 0x1f;
		userID = 0;
		userID = myUserID;
		
		if (commandID != 3) {
			dataLen = 0;
			dataLen = buf[2];
			dataLen = dataLen << 8;
			dataLen = dataLen | buf[3];

			dataPart[500];
			for (int i = 0; i < dataLen; i++) {
				dataPart[i] = buf[4 + i];
			}
			dataPart[dataLen] = 0;
		}

		printf("\tMessage from client (%s:%d):\n\n", inet_ntoa(userAddrTable[myUserID].sin_addr), ntohs(userAddrTable[myUserID].sin_port));
		printf("\t\tserviceID: %d\n\t\tcommandID: %d\n\t\tuserID: %d\n", servicerID, commandID, userID);
		if (commandID == 3) {
			printf("\t\tdataLen: 0\n\n");
		}
		else {
			printf("\t\tdataLen: %d\n\t\tdataPart: %s\n\n", dataLen, dataPart);
		}
		

		//connecting to servicer
		if (servicerTable[servicerID] == 0) {

			// winsock init
			if (WSAStartup(MAKEWORD(2, 2), &servicerWsa) != 0)
				return -1;

			printf("\n\tconnecting servicer(servicerID: %d)...\n\n", servicerID);
			
			// socket()
			servicerSock = socket(AF_INET, SOCK_STREAM, 0);
			if (servicerSock == INVALID_SOCKET) err_quit("socket()");

			// server address
			ZeroMemory(&servicerServeraddr, sizeof(servicerServeraddr));
			servicerServeraddr.sin_family = AF_INET;
			servicerServeraddr.sin_port = htons(9000);
			servicerServeraddr.sin_addr.s_addr = inet_addr("13.125.18.38");

			// connect()
			servicerRetval = connect(servicerSock, (SOCKADDR*)&servicerServeraddr, sizeof(servicerServeraddr));
			if (servicerRetval == SOCKET_ERROR) {
				err_quit("connect()");
			}
			servicerSocketTable[servicerID] = servicerSock;
			servicerServeraddrTable[servicerID] = servicerServeraddr;
			servicerTable[servicerID] = 1;

			printf("\tconnect success\n\n");
		}
		else {
			servicerSock = servicerSocketTable[servicerID];
			servicerServeraddr = servicerServeraddrTable[servicerID];

			printf("\n\talready connected\n\n");
		}

		// echo the received data to servicer
		servicerRetval = send(servicerSock, buf, retval, 0);
		if (servicerRetval == SOCKET_ERROR) {
			err_display("socket error: send()", WSAGetLastError());
			break;
		}

		printf("\n\tsending to servicer success\n\n");


		// receive data from the servicer
		servicerRetval = recv(servicerSock, servicerBuf, BUFSIZE, 0);
		if (servicerRetval == SOCKET_ERROR) {
			err_display("socket error: recv()", WSAGetLastError());
			break;
		}
		else if (servicerRetval == 0) {
			break;
		}


		// parsing the received data
		servicerBuf[servicerRetval] = '\0';

		servicerID = 0;
		servicerID = servicerBuf[0] >> 5;
		commandID = 0;
		commandID = servicerBuf[0] & 0x1f;
		userID = 0;
		userID = servicerBuf[1];


		if (commandID != 3) {
			
			dataLen = 0;
			dataLen = servicerBuf[2];
			dataLen = dataLen << 8;
			dataLen = dataLen | servicerBuf[3];
			
			dataPart[500];
			for (int i = 0; i < dataLen; i++) {
				dataPart[i] = servicerBuf[4 + i];
			}
			dataPart[dataLen] = 0;
		}

		
		printf("\tMessage from servicer (%s:%d):\n\n", inet_ntoa(userAddrTable[myUserID].sin_addr), ntohs(userAddrTable[myUserID].sin_port));
		printf("\t\tserviceID: %d\n\t\tcommandID: %d\n\t\tuserID: %d\n", servicerID, commandID, userID);
		printf("\t\tdataLen: %d\n\t\tdataPart:\n\n%s\n\n", dataLen, dataPart);
		

		// echo the received data to client
		retval = send(userSocketTable[myUserID], servicerBuf, servicerRetval, 0);
		if (retval == SOCKET_ERROR) {
			err_display("socket error: send()", WSAGetLastError());
			break;
		}

		printf("\tsending to client success\n\n");

	}

	// closesocket()
	closesocket(userSocketTable[myUserID]);
	printf("\n\t[TCP Server] connection terminated: client (%s:%d)\n\n",
		inet_ntoa(userAddrTable[myUserID].sin_addr), ntohs(userAddrTable[myUserID].sin_port));

	// closesocket()
	closesocket(servicerSock);
	printf("\t[TCP Server] connection terminated: client (%s:%d)\n\n",
		inet_ntoa(servicerServeraddr.sin_addr), ntohs(servicerServeraddr.sin_port));


	servicerTable[servicerID] = 0;


	printf("\tclient and servicer terminate\n\n");
	return 0;
}

int main(int argc, char* argv[])
{
	SOCKADDR_IN		serveraddr, clientaddr;		// server and client address
	SOCKET			listen_sock, client_sock;	// sockets for listen and client communication
	int				addrlen;
	int				retval;
	HANDLE			hThread;
	DWORD			ThreadId;
	userIDTop++;

	// winsock initialization
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return -1;

	// socket()
	listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_sock == INVALID_SOCKET) err_quit("socket()");

	// server IP address and port number
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9000);
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

	// bind()
	retval = bind(listen_sock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR) err_quit("bind()");

	// listen()
	retval = listen(listen_sock, SOMAXCONN);
	if (retval == SOCKET_ERROR) err_quit("listen()");

	printf("\n< welcome to our platform >\n\n");
	
	while (1) {
		// accept()
		printf("< platform is running... >\n\n");
		addrlen = sizeof(clientaddr);
		client_sock = accept(listen_sock, (SOCKADDR*)&clientaddr, &addrlen);
		if (client_sock == INVALID_SOCKET) {
			err_display("socket error: accept()", WSAGetLastError());
			break;
		}

		printf("\tconnection establisehd to Clinet (IP: %s, port: %d)\n\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

		// thread for client
		hThread = CreateThread(NULL, 0, ProcessClient, (LPVOID)client_sock, 0, &ThreadId);
		if (hThread == NULL)
			err_display("error: failure of thread creation!!!", GetLastError());
		else
			CloseHandle(hThread);
	}

	// closesocket()
	closesocket(listen_sock);

	// winsock terminate
	WSACleanup();
	return 0;
}