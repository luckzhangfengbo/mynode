/*************************************************************************
	> File Name: 1.fork.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月24日 星期二 19时14分14秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
    int pid;
    printf("before fork()...");
    fflush(stdout);
    if((pid = fork()) < 0) { // fork对输出缓冲区进行复制
        perror("fork");
    }
    if(pid == 0) {
        printf("In Child\n");
    } else {
        sleep(1);
        printf("In father\n");
    }
    printf("END FORK!\n");
    return 0;
}
