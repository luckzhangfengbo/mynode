/*************************************************************************
	> File Name: 391-数列分段.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月22日 星期三 18时03分59秒
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

long long n, m , num[100005], mmax, x;

long long check(long long mid) {
    int now = 0, cnt = 0;
    for(int i = 0 ; i < n; i ++) {
        if(now + num[i] == mid) {
            cnt ++;
            now = 0;
        } else if(now + num[i] > mid) {
            cnt ++;
            now = num[i];
        } else {
            now += num[i];
        }
    } 
    if(now > 0) cnt++;
    return cnt;
}

long long func() {
    long long l = x, r = mmax;
    while(l != r) {
        long long mid = (l + r) >> 1;
        long long cnt = check(mid);
        if(cnt > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        mmax += num[i];
        x = max(x, num[i]);
    }
    cout << func() << endl;
    return 0;
}
