# 使用UDP编程

## 基本信息

由于UDP通信不需要事先建立连接，因此不需要TCP中的connect函数。

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1gf8byl9q7qj30k30ii0wc.jpg)
![图片](https://static.dingtalk.com/media/lALPDgtYtcpsexvNAyLNA3E_881_802.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22627064533%3A627064533%22%2C%22msgId%22%3A%224001648499702%22%7D&bizType=im&open_id=627064533)

**服务器端的步骤如下：**

**1. socket**：    建立一个socket

**2. bind**：      将这个socket绑定在某个端口上（AF_INET）

**3. recvfrom**：  如果没有客户端发起请求，则会阻塞在这个函数里

**4. close**：     通信完成后关闭socket

**客户端的步骤如下：**

**1. socket**：    建立一个socket

**2. sendto**：   相服务器的某个端口发起请求（AF_INET）

**3. close**：     通信完成后关闭socket

可以看到，和TCP相比，步骤少了一些。

## sendto

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1gf8c4q8y6nj319x06j44f.jpg)

**socket：**socket套接字

**buf：**要发送的数据的起始地址

**flags：**一般情况下为0

**dest_addr：**发送到的目的地址

**addrlen：**地址长度



## recvfrom

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1gf8c5j7o4tj31bl073jx9.jpg)

**socket：**socket套接字

**buf：**接收到的数据的存放位置

**flags：**一般情况下为0

**src_addr：**接收的源地址

**addrlen：**地址长度



### client.c

```cpp
#include <stdio.h>   
#include <string.h>   
#include <errno.h>   
#include <stdlib.h>   
#include <unistd.h>   
#include <sys/types.h>   
#include <sys/socket.h>   
#include <netinet/in.h>   
#include <arpa/inet.h>   

int main(int argc, char **argv) {
    int sockfd, port;
    struct sockaddr_in addr_serv;
    if(argc != 3) {
        fprintf(stderr, "Usage: %s ip port\n", argv[0]);
        exit(1);
    }
    memset(&addr_serv, 0, sizeof(addr_serv));  
    port = atoi(argv[2]);
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = htons(port);
    addr_serv.sin_addr.s_addr = inet_addr(argv[1]);

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    int len = sizeof(addr_serv);
    int send_num;
    int recv_num;
    char send_buf[20] = "666666666666";
    char recv_buf[20];
    printf("client send: %s\n", send_buf);
    send_num = sendto(sockfd, send_buf, strlen(send_buf), 0, (struct sockaddr *)&addr_serv, len);     
    if(send_num < 0) {
        perror("sendto");
        exit(1);
    }
    sleep(5);
    recv_num = recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr_serv, (socklen_t *)&len);     
    if(recv_num < 0) {  
        perror("recvfrom");  
        exit(1);  
    }
    recv_buf[recv_num] = '\0';  
    printf("client receive %d bytes: %s\n", recv_num, recv_buf);  
    close(sockfd);  
  return 0;  
}
```



### server.c

```cpp
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
    int port, sockfd;
    port = atoi(argv[1]);
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in addr_serv;
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = htons(port);
    addr_serv.sin_addr.s_addr = INADDR_ANY;
    if(bind(sockfd, (struct sockaddr *)&addr_serv, sizeof(addr_serv)) < 0) {
        perror("bind");
        exit(1);
    }
    int recv_num;
    int send_num, len;
    char send_buf[20] = "iamserver";
    char recv_buf[20];
    struct sockaddr_in addr_client;
     len = sizeof(addr_serv);
    while(1) {
        printf("server wait:\n");
        recv_num = recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *) &addr_client, (socklen_t *)&len);
        if(recv_num < 0) {
            perror("recvfrom");
            exit(1);
        }
        recv_buf[recv_num] = '\0';
        printf("server receive %d bytes:%s \n", recv_num, recv_buf);
        send_num = sendto(sockfd, send_buf, recv_num, 0, (struct sockaddr *)&addr_client, len);  
       // send_num = sendto(sockfd, send_buf, recv_num, 0, (struct sockaddr *)&addr_client,len);
        if(send_num < 0) {
            perror("sendto ");
            exit(1);
        }
    }
    close(sockfd);
    return 1;
}
```

