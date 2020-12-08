/*************************************************************************
	> File Name: 599-两数之和.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月21日 星期四 00时10分11秒
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

int n, num[10000005], target;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> target;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int l = 0, r = n - 1;
    while(l < r) {
        int sum = num[l] + num[r];
        if(sum == target) {
            cout << l << " " << r << endl;
            return 0;
        }
        if(sum < target) {
            l ++;
        } else {
            r --;
        }
    }
    return 0;
}
