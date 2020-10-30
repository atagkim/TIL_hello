// COechoClnt.c
// TCP echo client
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1500

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

int main(int argc, char* argv[])
{
	int retval;
	SOCKET sock;
	SOCKADDR_IN serveraddr;
	char buf[BUFSIZE+1];
	int len;

	// 윈속 초기화
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2), &wsa) != 0)
		return -1;

	printf("# TCP echo CLIENT\n");
	printf("# Network SW Design Course by Ajou University \n\n");

	// socket()
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == INVALID_SOCKET) err_quit("socket()");	
	
	// server address
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9000);
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// connect()
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if(retval == SOCKET_ERROR) err_quit("connect()");
		
	// communication with the server
	while(1){
		// input data to be sent to the server
		ZeroMemory(buf, sizeof(buf));
		printf("\n[Input Data] ");
		if(fgets(buf, BUFSIZE+1, stdin) == NULL)
			break;

		// make input string message
		len = strlen(buf);
		if(buf[len-1] == '\n')
			buf[len-1] = '\0';
		if(strlen(buf) == 0)
			break;

		// send message
		retval = send(sock, buf, strlen(buf), 0);
		if(retval == SOCKET_ERROR){
			err_display("socket error: send()", WSAGetLastError());
			break;
		}
		printf("[TCP Clinet: send] message %d bytes sent ... \n\n", retval);

		// receive echo message from the server
		retval = recv(sock, buf, BUFSIZE, 0);
		if(retval == SOCKET_ERROR){
			err_display("socket error: recv()", WSAGetLastError());
			break;
		}
		else if(retval == 0)
			break;
		
		// display the echoed data
		buf[retval] = '\0';
		printf("[TCP Client: recv] message %d bytes received.\n", retval);
		printf("[Received message] %s\n\n", buf);
	}

	// closesocket()
	closesocket(sock);

	// 윈속 종료
	WSACleanup();
	return 0;
}