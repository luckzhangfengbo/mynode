/*************************************************************************
	> File Name: client.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月26日 星期二 22时20分09秒
 ************************************************************************/
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
