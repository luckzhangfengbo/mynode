/*************************************************************************
	> File Name: pthread.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月26日 星期四 19时50分34秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
struct Msg{
    int age;
    char name[20];
};
int retval;
void *print(void *arg) {
    struct Msg * tmp;
    tmp = (struct Msg *)arg;
    printf("name = %s, age = %d\n", tmp->name, tmp->age);
    retval = 3;
    //exit(3);
    pthread_exit((void *)&retval);
}

/*
 *线程退出：exit, 主函数return, 只要有一个线程exit,所有结束
 *Created创建
 *join等待
 *exit自杀
 */

int main() {
    void *status;
    pthread_t tid;
    struct Msg msg;
    msg.age = 18;
    strcpy(msg.name, "fangsong");
    pthread_create(&tid, NULL, print, (void *)&msg);
    pthread_join(tid,&status);
    printf("%d\n",*(int *)status);
    sleep(1);
    return 0;
}
