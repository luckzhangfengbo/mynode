/*************************************************************************
	> File Name: 787.归并排序.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月06日 星期日 22时24分21秒
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
const int N = 1e6+1;
int q[N];
int temp[N];
void merge(int q[], int l, int r) {
    if(l >= r) return;
    int mid = (l + r) >> 1;
    merge(q, l, mid);
    merge(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(q[i] <= q[j]) {
            temp[k++] = q[i++];
        } else {
            temp[k++] = q[j++];
        }
    }
    while(i <= mid) {temp[k++] = q[i++];}
    while(j <= r) {temp[k++] = q[j++];}
    for(int i = l, j = 0; i <= r; i ++, j++) q[i] = temp[j];
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> q[i];
    }
    merge(q, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << q[i] << endl;
    }
    return 0;
}
