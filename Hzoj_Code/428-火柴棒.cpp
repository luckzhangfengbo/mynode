/*************************************************************************
	> File Name: 428-火柴棒.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月20日 星期三 23时39分36秒
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

int num[10] = {
    6
,2
,5
,5
,4
,5
,6
,3
,7
,6
}, n, ans;
int func(int x) {
    if(x == 0) return num[0];
    int sum = 0;
    while(x) {
        sum += num[x % 10];
        x /= 10;
    }
    return sum;
}
int main() {
    cin >> n;
    for(int i = 0; i < 1111; i++) {
        for(int j = 0; j < 1111; j++) {
            if(func(i) + func(j) + func(i + j) + 4 == n) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
