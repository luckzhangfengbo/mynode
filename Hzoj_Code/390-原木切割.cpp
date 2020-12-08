/*************************************************************************
	> File Name: 390-原木切割.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月08日 星期三 20时22分44秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, num[100005], mmax;

int func(int len) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += num[i] / len;
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        mmax = max(mmax, num[i]);
    }
    int l = 0, r = mmax;
    while(l != r) {
        int mid = (l + r + 1) >> 1;
        int s = func(mid);
        if(s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", l);
    return 0;
}
