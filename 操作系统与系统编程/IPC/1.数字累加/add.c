/*************************************************************************
	> File Name: add.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月04日 星期六 16时11分54秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/file.h>

char num_file[] = "./.num";
char lock_file[] = "./.lock";

struct Num{
    int now;
    int sum;
};

size_t get_num(struct Num *num) {
    size_t read;
    FILE *f = fopen(num_file, "r");
    if(f == NULL) {
        perror(num_file);
        return -1;
    }
    if((read = fread(num,sizeof(struct Num),1, f)) < 0) {
        return -1;
    }
    fclose(f);
    return read;
}

size_t set_num(struct Num *num) {
    FILE *f = fopen(num_file, "w");
    size_t write = fwrite(num, sizeof(struct Num), 1, f);
    fclose(f);
    printf("          write %ld \n", write);
    return write;
}

void do_add(int max, int x) {
    struct Num num;
    while(1) {
        FILE *lock = fopen(lock_file, "w");
        flock(lock->_fileno, LOCK_EX);
        if(get_num(&num) < 0) {
            fclose(lock);
            continue;
        }
        printf("<%d> : %d   %d \n", x, num.now, num.sum);
        if(num.now > max) {
            break;
        }
        num.sum += num.now;
        num.now ++;
        set_num(&num);
        flock(lock->_fileno, LOCK_UN);
        fclose(lock);
    }
}

int main(int argc, char **argv) {
    if(argc != 3) {
        fprintf(stderr, "Usage:%s max ins\n", argv[0]);
        return 1;
    }
    int x = 0;
    pid_t pid;
    struct Num num;
    num.now = 0;
    num.sum = 0;
    set_num(&num);
    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    for(int i = 0; i < ins; i++) {
        if((pid = fork()) < 0) {
            perror("fork");
            return 1;
        }
        if(pid == 0) {
            x = i;
            break;
        }
    }
    if(pid == 0) {
        do_add(max, x);
        printf("<%d> exit\n", x);
        exit(0);
    }
    while(ins) {
        wait(NULL);
        ins--;
    }
    get_num(&num);
    printf("Ans = %d", num.sum);
    return 0;
}
