/*************************************************************************
	> File Name: 271-滑动窗口.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月28日 星期二 19时52分06秒
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
#define MAX_N 300000
int a[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;
//下标索引值，q存储下标
/*
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < k; i++) {//先往单调队列中放入k-1个元素
        while(tail - head && a[q[tail - 1]] >= a[i]) tail --;//判断末尾大于等于，违反，踢了
        q[tail++] = i;//当前入队列
    }
    for(int i = k; i <= n; i++) {
        while(tail - head && a[q[tail - 1]] >= a[i]) tail --;
        q[tail++] = i;        
        if(q[head] <= i - k) head ++;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    head = tail = 0;
    for(int i = 1; i < k; i++) {
        while(tail - head && a[q[tail - 1]] <= a[i]) tail --;
        q[tail++] = i;
    }
    for(int i = k; i <= n; i++) {
        while(tail - head && a[q[tail - 1]] <= a[i]) tail --;
        q[tail++] = i;
        if(q[head] <= i - k) head ++;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    return 0;
}
*/

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];//a数组存储序列，q数组存储单调队列
    for(int i = 1; i <= n; i++) {
        while(tail - head && a[q[tail - 1]] >= a[i]) tail --; //维护单调性
        q[tail++] = i;
        if(q[head] <= i - k) head ++;//已出队列
        if(i < k)continue;
        i == k || cout << " ";
        cout << a[q[head]];//头部存最小的
    }
    cout << endl;
    head = tail = 0;
    for(int i = 1; i <= n; i++) {
        while(tail - head && a[q[tail - 1]] <= a[i]) tail --;
        q[tail++] = i;
        if(q[head] <= i - k) head ++;
        if(i < k) continue;
        i == k || cout << " ";
        cout << a[q[head]];
    }
    cout << endl;
    return 0;
}

