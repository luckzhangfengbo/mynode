/*************************************************************************
	> File Name: 1.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月31日 星期日 14时11分05秒
 ************************************************************************/

#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
int main() {
    initscr();
    for(int i = 0; i < LINES; i++) {
        move(i, i + 1);
        //if(i % 2 == 0) standout();//高亮
        addstr("Hello  HaiZei!");
        //if(i % 2 == 0) standend();
        sleep(1);
        move(LINES, COLS);
        refresh();
        move(i - 1, i);
        addstr("              ");
        move(LINES - 2, COLS - 2);
        refresh();
    }
    getchar();
    endwin();
    return 0;
}
