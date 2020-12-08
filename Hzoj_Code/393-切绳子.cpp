/*************************************************************************
	> File Name: 393-切绳子.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月22日 星期三 19时14分49秒
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
int n, k;
double num[10005], mmax;

int check(double mid) {
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += num[i] / mid;
    }
    return cnt;
}

double func() {
    double l = 0, r = mmax;
    while(r - l > 0.000001) {
        double mid = (l + r) / 2;
        int x = check(mid);
        if(x >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    double ans = func();
    printf("%d.%d\n", (int)ans, (int)(ans * 100)%100);
    return 0;
}
