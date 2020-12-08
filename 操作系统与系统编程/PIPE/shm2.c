/*************************************************************************
	> File Name: shm2.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月04日 星期六 19时09分11秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<signal.h>
#include<string.h>
int main() {
    pid_t pid;
    int pipefd[2];
    pipe(pipefd);
    char buff[1024] = {0};
    if((pid = fork()) < 0) {
        perror("fork");
        return 1;
    }
    if(pid == 0) {
        while(1) {
            close(pipefd[0]);
            scanf("%[^\n]s", buff);
            getchar();
            write(pipefd[1],buff, 1024);
        }
    } else {
        while(1) {  
            close(pipefd[1]);
            read(pipefd[0], buff, 1024);
            printf("server : %s\n", buff);
            //memset(buff, 0, sizeof(buff));
        }
    }
    return 0;
}

