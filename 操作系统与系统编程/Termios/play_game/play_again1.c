/*************************************************************************
	> File Name: play_again1.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月28日 星期四 20时02分38秒
 ************************************************************************/

#include<stdio.h>
#define Q "Do you want another try?"

int getresponse();

int main() {
    int response;
    response = getresponse();
    return response;
}

int getresponse() {
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
