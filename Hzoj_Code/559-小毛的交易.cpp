/*************************************************************************
	> File Name: 559-小毛的交易.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月29日 星期三 18时30分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

double f[1005];
struct Node{
    double a, b, c;
}s[1005];
bool cmp(Node a, Node b) {
    return a.c > b.c;
}
int main() {
    int m, n;
    cin >> m >> n;
    double res = 0;
    for(int i = 0; i < n; i++) {
        cin >> s[i].a >>s[i].b;
        s[i].c = s[i].a * 1.0 / s[i].b;
    }
    sort(s, s + n, cmp);
    for(int i = 0; i < n; i++) {
        if(m >= s[i].b) {
            m -= s[i].b;
            res += s[i].a;
        } else {
            res += s[i].a * m / s[i].b;
            break;
        }
    }
    printf("%.3f", res);
    return 0;
}
