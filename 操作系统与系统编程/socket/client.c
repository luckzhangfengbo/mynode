/*************************************************************************
	> File Name: client.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时22分39秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(int argc, char **argv) {
    int sockfd, port;
    struct sockaddr_in server;
    if(argc != 3) {
        fprintf(stderr, "Usage: %s ip port\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[2]);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    /*
     connect()用于建立与指定socket的连接。
     头文件: #include <sys/socket.h>
     函数原型: int connect(SOCKET s, const struct sockaddr * name, int namelen);
    参数:
    s：标识一个未连接socket
    name：指向要连接套接字的sockaddr结构体的指针
    namelen：sockaddr结构体的字节长度
     */
    printf("Socket create.\n");
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }
    /*
     send（）是一个计算机函数，功能是向一个已经连接的socket发送数据
     int send( SOCKET s, const char FAR *buf, int len, int flags );
     不论是客户还是服务器应用程序都用send函数来向TCP连接的另一端发送数据。
    客户程序一般用send函数向服务器发送请求，而服务器则通常用send函数来向客户程序发送应答。
（1）第一个参数指定发送端套接字描述符；
（2）第二个参数指明一个存放应用程序要发送数据的缓冲区；
（3）第三个参数指明实际要发送的数据的字节数；
（4）第四个参数一般置0。
    */
    if(send(sockfd, "fangsong", sizeof("fangsong"), 0) < 0) {
        perror("send");
        exit(1);
    }
    close(sockfd);
    return 0;
}
