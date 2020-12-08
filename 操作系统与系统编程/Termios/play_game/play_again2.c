/*************************************************************************
	> File Name: play_again1.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月28日 星期四 20时02分38秒
 ************************************************************************/

#include<stdio.h>
#include<termios.h>
#define Q "Do you want another try?"

int get_response();
void set_cr_mode();
void tty_mode();
int main() {
    int response;
    tty_mode(0);
    set_cr_mode();
    response = get_response();
    tty_mode(1);
    printf("return val = %d\n", response);
    return response;
}

int get_response() {
    printf(Q);
    printf("(y/n): ");
    switch(getchar()){
        case 'y':
        case 'Y': return 1;
        case 'n':
        case 'N': return 0;
        default : return 0;
    }
}

void set_cr_mode() {
    struct termios ttystate;
    /*取*/
    tcgetattr(0, &ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_lflag &=~ECHO;
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
