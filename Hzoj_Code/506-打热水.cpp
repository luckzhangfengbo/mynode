/*************************************************************************
	> File Name: 506-打热水.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月13日 星期三 16时31分59秒
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
/*
#define MAX_N 35
struct Node {
    int val;
    int index;
}s[MAX_N];
bool cmp(Node a, Node b) {
    if(a.val!=b.val) return a.val < b.val;
    else {
        return a.index < b.index;
    }
}
int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    double sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> s[i].val;
        s[i].index = i + 1;
    }
    sort(s, s + n, cmp);
    for(int i = 0; i < n; i++) {
        i != 0 && cout << " ";
        cout << s[i].index;
        ans += s[i].val;
        sum += ans - s[i].val;
    }
    cout << endl;
    printf("%.2lf", sum * 1.0/ n);
    return 0;
}
*/

struct node {
    int num, time;
};
int n;
node s[35];

bool cmp(node a, node b) {
    return a.time < b.time;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i].time;
        s[i].num = i + 1;
    }
    sort(s, s + n, cmp);
    int ans = 0, now = 0;
    for(int i = 0; i < n; i++) {
        i!= 0&&cout << " ";
        cout << s[i].num;
        ans += now;
        now += s[i].time;
    }
    printf("\n%.2lf\n", (double)ans / n);
    return 0;
}

