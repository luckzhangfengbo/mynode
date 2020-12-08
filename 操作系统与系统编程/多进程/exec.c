/*************************************************************************
	> File Name: exec.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月26日 星期四 18时13分21秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(int argc, char **argv) {
    pid_t pid;
    char filename[512] = {0};
    char o_name[512] = {0};
    char f_type[256] = {0};
    char cmd[512] = {0};
    if(argc < 2) {
        fprintf(stderr, "Usage: %s filename arg...\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    //a.c b.cpp
    char *sub;

    sub = strrchr(filename, '.');
    strncpy(o_name, filename, sub - filename);
    strcpy(f_type, sub);

    if(!strcmp(f_type, ".c")) {
        strcpy(cmd, "gcc");
    } else if(!strcmp(f_type, ".cpp")) {
        strcpy(cmd, "g++");
    } else {
        fprintf(stderr, "Not support File Type\n");
        return 2;
    }

    if((pid = fork()) < 0) {
        perror("fork");
        return 3;
    } 
    if(pid == 0) {
        execlp("vim", "vim", filename, NULL);
    }
    wait(NULL);
    if((pid = fork()) < 0) {
        perror("fork");
        return 3;
    }
    if(pid == 0) {
        execlp(cmd, cmd, filename, "-o", o_name, NULL);
    }
    int status; //子进程状态
    wait(&status);
    if(status == 0) {
        printf("OK\n");
        char name[25] = "./";
        strcat(name, o_name);
        execlp(name,name,NULL, NULL);
    } 
    return 0;
}
