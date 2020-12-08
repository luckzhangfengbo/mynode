/*************************************************************************
	> File Name: sleep.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月31日 星期日 15时04分14秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void print() {
    printf("It's time to get up\n");
}
int main() {
    signal(14, print);
    alarm(3);
    pause();
    return 0;
}
