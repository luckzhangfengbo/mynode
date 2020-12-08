/*************************************************************************
	> File Name: 2.fork.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月24日 星期二 19时49分36秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
    int pid, x = 0;
    for(int i = 1; i <= 3; i++) {
        if((pid = fork()) < 0) {
            perror("fork()");
            continue;
        }
        if(pid == 0) {
            x = i;
        }
    }
    printf("I/m %dth child.\n", x);
    sleep(60);
   // printf("father%d\n", x);
    return 0;
}
