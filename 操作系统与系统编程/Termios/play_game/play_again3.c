/*************************************************************************
	> File Name: play_again1.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月28日 星期四 20时02分38秒
 ************************************************************************/

#include<stdio.h>
#include<termios.h>
#include<fcntl.h>
#include<ctype.h>
#include<sys/select.h>
#include<string.h>
#define Q "Do you want another try?"
#define TIMEOUT 5
int get_response();
void set_cr_noecho_mode();
void tty_mode();
void set_nonblock_mode();
int get_ok_char();
int main() {
    int response;
    tty_mode(0);
    set_cr_noecho_mode();
    response = get_response();
    tty_mode(1);
    printf("\n");
    printf("return val = %d\n", response);
    return response;
}
int get_response() {
    printf("%s(y/n)?", Q);
    fflush(stdout);
    
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    fd_set set;
    FD_ZERO(&set);
    FD_SET(0, &set);

    int ret = select(1, &set, NULL, NULL, &tv);
    if(ret == 1) {
        if(FD_ISSET(0, &set)) {
            while(1) {
                int input = tolower(getchar());
                switch(input) {
                    case 'y':
                        return 1;
                    case 'n':
                        return 0;
                }
            }
        }
    }
    return 2;
}
int get_ok_char() {
    int c;
    while((c = getchar())!=EOF && strchr("yUnN", c) == NULL);
    return c;
}

void set_nonblock_mode() {
    int termflags;
    termflags = fcntl(0, F_GETFL);
    termflags |= O_NONBLOCK;
    /*设置为非阻塞只修改需要的属性所以这里用"|"*/
    fcntl(0, F_SETFL);
}

void set_cr_noecho_mode() {
    struct termios ttystate;
    /*取*/
    tcgetattr(0, &ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_lflag &= ~ECHO;
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &ttystate);
}

void tty_mode(int how) {
    //how=1;还原 how=0 保存
    static struct termios orignal_mode;
    if(how == 0) {
        tcgetattr(0, &orignal_mode);
    } else {
        tcsetattr(0, TCSANOW, &orignal_mode);
    }
}
