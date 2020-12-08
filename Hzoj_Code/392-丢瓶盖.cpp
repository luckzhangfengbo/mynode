/*************************************************************************
	> File Name: 392-丢瓶盖.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月22日 星期三 19时04分26秒
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
int n, m, num[100005], mmax;

int check(int mid) {
    int cnt = 1, now = 0;
    for(int i = 1; i < n; i++) {
        if(num[i] - num[now] >= mid) {
            cnt++;
            now=i;
        }
    }
    return cnt;
}

int func() {
    int l = 1, r = mmax;
    while(l != r) {
        int mid = (l + r + 1) >> 1;
        int cnt = check(mid);
        if(cnt >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    mmax = num[n - 1] - num[0];
    cout << func() << endl;
    return 0;
}
