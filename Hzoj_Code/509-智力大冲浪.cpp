/*************************************************************************
	> File Name: 509-智力大冲浪.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月13日 星期三 20时51分33秒
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

struct node {
    int time;
    int mem;
}s[502];

bool cmp(node a, node b) {
    if(a.mem != b.mem) return a.mem > b.mem;
    else return a.time < b.time;
}
int m[502];
int main() {
    int n, w;
    cin >> w >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i].time;
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i].mem;
    }
    sort(s, s + n, cmp);
    int j;
    for(int i = 0; i < n; i++) {
        for(j = s[i].time; j > 0; j--) {
            if(m[j] == 0) {
                m[j] = 1;
                break;
            }
        }
        if(j == 0) {
            w -= s[i].mem;
        }
    }
    cout << w << endl;
    return 0;
}
