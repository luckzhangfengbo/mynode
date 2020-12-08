/*************************************************************************
	> File Name: select1.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月16日 星期四 19时16分58秒
 ************************************************************************/

#include"../common/head.h"
#include"../common/color.h"

#include"../common/common.h"
#include"../common/tcp_server.h"

#define MAX_N 512
#define BUFFSIZE 4096

struct Buffer{
    int fd;
    char buff[BUFFSIZE];
    int flag;
    int sendindex;
    int recvindex;
};

struct Buffer *AllocBuffer() {
    struct Buffer *buffer =(struct Buffer *)malloc(sizeof(struct Buffer));
    if(buffer == NULL) return NULL;
    buffer->fd = -1;
    buffer->flag = buffer->recvindex = buffer->sendindex = 0;
    memset(buffer->buff, 0, BUFFSIZE);

    return buffer;

}

void FreeBuffer(struct Buffer *buffer) {
    free(buffer);
}

char ch_char(char c) {
    if(c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

int RecvToBuffer(int fd, struct Buffer *buffer) {
    char buff[BUFFSIZE];
    int recv_num;
    while(1) {
        recv_num =recv(fd, buff, sizeof(buff), 0);
        if(recv_num <= 0)break;
        for(int i = 0; i < recv_num; i++) {
            if(buffer->recvindex < sizeof(buffer->buff))
                buffer->buff[buffer->recvindex++] = ch_char(buff[i]);
         /*   if(buff[i] == '\n' && buff[i + 1] == '\n')
                buffer->flag = 1;*/
           /* if(buffer->recvindex > 1 && buffer->buff[buffer->recvindex - 1] == '\n' && buffer->buff[buffer->recvindex - 2] == '\n') {
                buffer->flag = 1;
            }*/
                                printf("recvindex - 1 :%d recvindex-2: %d\n",buffer->buff[buffer->recvindex - 1], buffer->buff[buffer->recvindex-2]);

            if(buffer->recvindex > 1 && buffer->buff[buffer->recvindex - 1] == '\r' && buffer->buff[buffer->recvindex - 2] == '\n') {
                buffer->flag = 1;
            }

        }
    }

    if(recv_num < 0) {
        if(errno == EAGAIN)
            return 0;
        return -1;
    } else if(recv_num == 0){
        return 1;
    }
}

int SendFromBuffer(int fd, struct Buffer *buffer) {
    int send_num;
    while(buffer->sendindex < buffer->recvindex) {
        send_num = send(fd, buffer->buff + buffer->sendindex, buffer->recvindex - buffer->sendindex, 0);
        if(send_num < 0) {
            if(errno == EAGAIN) {
                return 0;
            }
            buffer->fd = -1;
            return -1;
        }
        buffer->sendindex += send_num;
    }
    if(buffer->sendindex == buffer->recvindex)
        buffer->sendindex = buffer->recvindex = 0;
    buffer->flag = 0;
    return 0;
}



int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s port!\n", argv[0]);
        exit(1);
    }
    int server_listen, fd;

    if((server_listen = socket_create(atoi(argv[1]))) < 0) {
        perror("socket_create");
        exit(1);
    }
    struct Buffer *buffer[MAX_N];

    for(int i = 0; i < MAX_N;i ++) {
        buffer[i] = AllocBuffer();
    }

    make_nonblock(server_listen);
    int maxfd = server_listen;//开始server_listen最大
    fd_set rfds, wfds, efds;


    while(1) {
        FD_ZERO(&rfds);
        FD_ZERO(&wfds);
        FD_ZERO(&efds);
        FD_SET(server_listen, &rfds);
        for(int i = 0; i < MAX_N; i++) {
            if(buffer[i]->fd == server_listen)continue;
            if(buffer[i]->fd > 0) {
                if(maxfd < buffer[i]->fd)maxfd = buffer[i]->fd;
                FD_SET(buffer[i]->fd, &rfds);
                if(buffer[i]->flag == 1) {
                    FD_SET(buffer[i]->fd, &wfds);
                }
            }
        }
        if(select(maxfd + 1, &rfds, &wfds, NULL, NULL) < 0) {
            perror("select");
            return 1;
        }
        if(FD_ISSET(server_listen, &rfds)) {
            printf("Connect ready on serverlisten!\n");
            if((fd = accept(server_listen, NULL, NULL))< 0) {
                perror("accept");
                return 1;
            }
            if(fd > MAX_N) {
                printf("Too many clients!\n");
                close(fd);
            } else {
                printf("Login!\n");
                make_nonblock(fd);
                if(buffer[fd]->fd == -1) {
                    buffer[fd]->fd = fd;
                }
            }
        }
        for(int i = 0; i < MAX_N; i++) {
            int retval;
            if(i == server_listen)continue;
            if(FD_ISSET(i, &rfds)) {
                retval = RecvToBuffer(i, buffer[i]);
            }
            if(retval == 0 && FD_ISSET(i, &wfds)) {
                retval = SendFromBuffer(i, buffer[i]);
            }
            if(retval) {
                printf("Login!\n");
                make_nonblock(fd);
                buffer[i]->fd = -1;
                close(i);
            }
        }
    }
    return 0;
}

