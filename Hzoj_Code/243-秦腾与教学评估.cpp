/*************************************************************************
	> File Name: 243-秦腾与教学评估.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 18时59分35秒
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
#define MAX_N 200000
struct Data{
    int s, e, d, c;
}arr[MAX_N + 5];
int n;

int check(int pos) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i].s > pos)continue;
        if(arr[i].e <= pos) {
            cnt += arr[i].c;
            continue;
        }
        cnt += (pos - arr[i].s) / arr[i].d + 1;
    }
    return cnt;
}

int bs(int l, int r) {
    if(l == r) return l;
    int mid = ((l ^r) >> 1) + (l & r);
    if(check(mid) % 2) return bs(l, mid);
    return bs(mid + 1, r);
}

void solve() {
    int l, r;
    cin>> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].e >> arr[i].d;
        arr[i].c = (arr[i].e - arr[i].s) / arr[i].d + 1;
        if(i == 0) l = arr[i].s, r = arr[i].e;
        l = min(arr[i].s, l);
        r = max(arr[i].e, r);
    }
    int pos = bs(l, r);
    int cnt = check(pos) - check(pos - 1);
    if(cnt % 2) {
        cout << pos <<" "<< cnt << endl;
    } else {
        cout << "Poor QIN Teng:(" << endl;
    } 
    return;
}
int main() {
    int tcase;
    ios::sync_with_stdio(false);
    cin >> tcase;
    while(tcase--) {
        solve();
    }
    return 0;
}
