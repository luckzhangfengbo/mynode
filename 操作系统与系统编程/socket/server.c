/*************************************************************************
	> File Name: server.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时04分46秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/wait.h>
int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s powrt\n", argv[0]);
        exit(1);
    }

    int port, server_listen;
    port = atoi(argv[1]);
    if((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) { //完成两个应用程序之间的数据传输, 应用程序可以通过它发送或接收数据,网络套接字是IP地址与端口的组合;temet（AF_INET）、XeroxNS（AF_NS）等。而Dos和Windows仅支持AF_INET。type参数指定所需的通信类型。包括数据流（SOCK_STREAM）、数据报（SOCK-DGRAM）和原始类型（S0CK_RAW）。参数protocol说明该套接字使用的协议族中的特定协议。如果调用者不希望特别指定使用的协议，则置为0，使用默认的连接模式。
        perror("socket");
        exit(1);
    }
    /*
     server_listen: 标识一未捆绑套接口的描述字。
     server: 赋予套接口的地址
     struct sockaddr_in 
     {
     short sin_family;//Address family一般来说AF_INET（地址族）PF_INET（协议族）
     unsigned short sin_port; // Port number(必须要采用网络数据格式,普通数字可以用htons()函数转换成网络数据格式的数字)
     struct in_addr sin_addr;//IP address in network byte order（Internet address）;
     }

int bind( int sockfd , const struct sockaddr * my_addr, socklen_t addrlen);
参数列表中，sockfd 表示已经建立的socket编号（描述符）；
my_addr 是一个指向sockaddr结构体类型的指针；
参数addrlen表示my_addr结构的长度，可以用sizeof操作符获得。
    */
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) { //将一本地地址与一套接口捆绑
        perror("bind");
        exit(1);
    }
    /*
    #include <sys/socket.h>
    int listen( int sockfd, int backlog);
    sockfd：用于标识一个已捆绑未连接套接口的描述字。
    backlog：等待连接队列的最大长度。
    */
    if(listen(server_listen, 20) < 0) { // 创建一个套接口并监听申请的连接
        perror("server");
        exit(1);
    }

    /*
     accept()是在一个套接口接受的一个连接
     SOCKET accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
     sockfd：套接字描述符，该套接口在listen()后监听连接。
    */

    /* fork系统调用用于创建一个新进程，称为子进程，它与进程（称为系统调用fork的进程）同时运行，此进程称为父进程。创建新的子进程后，两个进程将执行fork（）系统调用之后的下一条指令。子进程使用相同的pc（程序计数器），相同的CPU寄存器，在父进程中使用的相同打开文件。
    */
    int *status;
    while(1) {
        int sockfd;
        if((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }
        pid_t pid;
        if((pid = fork()) < 0) {
            perror("fork");
            continue;
        }
        if(pid == 0) { // 子进程
        close(server_listen);
        char name[20] = {0};
        if(recv(sockfd, name, sizeof(name), 0) <= 0) {
           perror("recv");
            close(sockfd);
         // continue;
        }
        printf("name: %s\n", name);
        close(sockfd);
            exit(0);
        } else {
        wait(status);
        }
    }
    close(server_listen);
    return 0;
}
