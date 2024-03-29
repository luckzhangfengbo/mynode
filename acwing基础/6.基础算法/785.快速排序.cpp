/*************************************************************************
	> File Name: 785.快速排序.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月06日 星期日 21时25分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
const int N = 1e6 + 1;
int q[N];
void qsort(int q[], int l, int r) {
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j) {
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if(i < j) {
            swap(q[i], q[j]);
        }
    }
    qsort(q, l, j);
    qsort(q, j + 1, r);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
         cin >> q[i];
    }
    qsort(q, 0, n - 1);
    for(int i = 0; i < n; i++) {
         cout << q[i] << endl;
    }
    return 0;
}
