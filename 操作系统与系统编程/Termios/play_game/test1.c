/*************************************************************************
	> File Name: text1.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月30日 星期六 19时30分43秒
 ************************************************************************/

#include<stdio.h>
#include<ncurses.h>
int main() {
    initscr();
    clear();
    move(10, 20);
    addstr("hello");
    refresh();
    getchar();
    //gcc -lncurses test1.c
    endwin();
    return 0;
}
