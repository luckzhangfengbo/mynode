/*************************************************************************
	> File Name: server.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月26日 星期二 21时54分02秒
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
