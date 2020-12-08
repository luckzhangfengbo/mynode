/*************************************************************************
	> File Name: 503-独木舟.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月13日 星期三 18时01分43秒
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
#define MAX_N 30005
int w, n, a[MAX_N];
int main() {
    ios::sync_with_stdio(false);
    cin >> w >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0, r = n - 1, count = 0;
    while(l <= r) {
        if(a[l] + a[r] > w) {
            count ++;
            r --;
        } else {
            count ++;
            r --;
            l ++;
        }
    }
    cout << count << endl;
    return 0;
}
