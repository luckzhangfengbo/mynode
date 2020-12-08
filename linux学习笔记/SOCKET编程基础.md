

# SOCKET编程基础

![](SOCKET%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80.assets/2020-03-22%2022-47-53%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](SOCKET%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80.assets/2020-03-22%2022-48-59%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](SOCKET%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80.assets/2020-03-22%2022-49-42%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](SOCKET%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80.assets/2020-03-22%2022-50-11%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### socket()创建socket

```
 完成两个应用程序之间的数据传输, 应用程序可以通过它发送或接收数据,网络套接字是IP地址与端口的组合;
```

socket()函数调用的格式

>SOCKET PASCAL FAR socket（int af，int type，int protocol）；

参数af指定套接字使用的协议族, 

type参数指定所需的通信类型。包括数据流（SOCK_STREAM）、数据报（SOCK-DGRAM）和原始类型（S0CK_RAW）。

参数protocol说明该套接字使用的协议族中的特定协议。如果调用者不希望特别指定使用的协议，则置为0，使用默认的连接模式。

![](SOCKET%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80.assets/2020-03-22%2022-56-22%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```c
int port, server_listen;
    port = atoi(argv[1]);
if((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) { // 完成两个应用程序之间的数据传输, 应用程序可以通过它发送或接收数据,网络套接字是IP地址与端口的组合;
        perror("socket");
        exit(1);
    }
```

### bind()绑定IP地址及端口

bind()函数通过给一个[未命名](https://baike.baidu.com/item/未命名/278232)套接口分配一个本地名字来为套接口建立本地捆绑（[主机地址](https://baike.baidu.com/item/主机地址/9765500)/[端口号](https://baike.baidu.com/item/端口号/10883658)）。

```c
`#include ``#include ``/****``* sockfd：标识一未捆绑套接口的描述字。``* my_addr：赋予套接口的地址。sockaddr结构定义如下：``* struct sockaddr{``*  u_short sa_family;``*  char sa_data[14];``* };``* addrlen：name名字的长度。``* 返回值：成功返回0，失败返回-1.``****/``int` `bind( ``int` `sockfd , ``const` `struct` `sockaddr * my_addr, socklen_t addrlen);`
```

参数列表中，server_listen 表示已经建立的socket编号（描述符）；

server 是一个指向sockaddr结构体类型的指针；

参数sizeof(server)表示server结构的长度，可以用sizeof操作符获得。

```c
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) { //将一本地地址与一套接口捆绑
        perror("bind");
        exit(1);
    }
```

### listen()监听socket

```
创建一个套接口并监听申请的连接.
#include <sys/socket.h>
int listen( int sockfd, int backlog);
sockfd：用于标识一个已捆绑未连接套接口的描述字。
backlog：等待连接队列的最大长度。
```

```c
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
```

![](SOCKET%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80.assets/2020-03-22%2023-07-04%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



### connect()建立连接

![](SOCKET%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80.assets/2020-03-22%2023-53-13%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```
connect()用于建立与指定socket的连接。
头文件: #include <sys/socket.h>
函数原型: int connect(SOCKET s, const struct sockaddr * name, int namelen);
参数:
s：标识一个未连接socket
name：指向要连接套接字的sockaddr结构体的指针
namelen：sockaddr结构体的字节长度
```

```c
    printf("Socket create.\n");
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }
```



### accept()接收连接

\#include <sys/socket.h>

```
accept()是在一个套接口接受的一个连接
     SOCKET accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
     sockfd：套接字描述符，该套接口在listen()后监听连接。
```

```c
 int sockfd;
        if((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }

```

![](SOCKET%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80.assets/2020-03-22%2023-48-17%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)







### send()发送数据

  send（）是一个计算机函数，功能是向一个已经连接的socket发送数据
     int send( SOCKET s, const char FAR *buf, int len, int flags );
     不论是客户还是服务器应用程序都用send函数来向TCP连接的另一端发送数据。
    客户程序一般用send函数向服务器发送请求，而服务器则通常用send函数来向客户程序发送应答。
（1）第一个参数指定发送端套接字描述符；
（2）第二个参数指明一个存放应用程序要发送数据的缓冲区；
（3）第三个参数指明实际要发送的数据的字节数；
（4）第四个参数一般置0。

```c
    if(send(sockfd, "fangsong", sizeof("fangsong"), 0) < 0) {
        perror("send");
        exit(1);
    }
```

### recv()接收数据

![](SOCKET%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80.assets/2020-03-22%2023-50-55%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```c
    if(recv(sockfd, name, sizeof(name), 0) <= 0) {
           perror("recv");
            close(sockfd);
         // continue;
        }    if(recv(sockfd, name, sizeof(name), 0) <= 0) {
           perror("recv");
            close(sockfd);
         // continue;
        }
```



# 实现一个socket程序

### server.c

```c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s powrt\n", argv[0]);
        exit(1);
    }

    int port, server_listen;
    port = atoi(argv[1]);
    if((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) { // 完成两个应用程序之间的数据传输, 应用程序可以通过它发送或接收数据,网络套接字是IP地址与端口的组合;
        perror("socket");
        exit(1);
    }
    /*
     server_listen: 标识一未捆绑套接口的描述字。
     server: 赋予套接口的地址
     struct sockaddr_in {
     short sin_family;//Address family一般来说AF_INET（地址族）PF_INET（协议族）
     unsigned short sin_port; // Port number(必须要采用网络数据格式,普通数字可以用htons()函数转换成网络数据格式的数字)
     struct in_addr sin_addr;//IP address in network byte order（Internet address）;
     }
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
        if(pid == 0) {
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
        }
    }
    close(server_listen);
    return 0;
}
```

### client.c

```c
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
```

