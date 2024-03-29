/*************************************************************************
	> File Name: 389-暴躁的程序猿.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月08日 星期三 20时55分48秒
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

int func2(int len){
    int cnt = 1, now = 0;
    for(int i = 1; i < n; i++) {
        if(num[i] - num[now] >= len){
            cnt ++;
            now = i;
        }
    }
    return cnt;
}

int func() {

    int l = 0, r = mmax;
    while(l != r) {
        int mid = (l + r + 1) >> 1;
        int cnt = func2(mid);
        if(cnt >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
     scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        mmax = max(mmax, num[i]);
    }
    sort(num, num + n);
    cout << func() << endl;
    return 0;

}
