/*************************************************************************
	> File Name: itimer.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月31日 星期日 15时54分09秒
 ************************************************************************/

#include<stdio.h>
#include <sys/time.h>
#include<signal.h>
#include<unistd.h>
void print(){
    printf("Recv a signal!\n");
}
int main() {
    struct itimerval itm;
    signal(14, print);
    itm.it_interval.tv_sec = 1;
    itm.it_interval.tv_usec = 0;
    itm.it_value.tv_sec = 3;
    itm.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &itm, NULL);
    while(1) {
        sleep(10);
        printf("After!\n");
    }
    return 0;
}
