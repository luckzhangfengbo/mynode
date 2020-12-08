/*************************************************************************
	> File Name: test.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年01月14日 星期二 18时17分13秒
 ************************************************************************/

/*
#include<iostream>
using namespace std;
#include<stdio.h>
#define ABS(x) _Generic((x), int : abs, double : fabs)(x)


int main() {
    int a = -123;
    double b = -12.3;
    printf("%d\n", ABS(a));
    printf("%lf\n", ABS(b));

    return 0;
}
*/


#include<iostream>
#include<cstdio>
using namespace std;

#define COLOR(str, code) "\033[" #code "m" str "\033[0m"
#define YELLOW(str) COLOR(str, 33)
//#define YELLOW(str) "\033[33m" str"\033[0m"

int main() {
    printf(YELLOW("ping攻击中...\n"));
    printf("\033[5;33;46m警告！！！\033[0m");
}
