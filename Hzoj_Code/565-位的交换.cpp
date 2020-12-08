/*************************************************************************
	> File Name: 565-位的交换.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月24日 星期五 17时42分23秒
 ************************************************************************/

#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int ans = ((n << 16) & 0xffff0000) | ((n >> 16) & 0x0000ffff);
    printf("%d\n",ans);
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << ((n << 16) & 0xffff0000 | (n >> 16) & 0x0000ffff) << endl;
    return 0;
}

