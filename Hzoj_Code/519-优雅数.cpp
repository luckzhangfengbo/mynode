/*************************************************************************
	> File Name: 519-优雅数.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月20日 星期三 15时55分24秒
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
int main() {
    ios::sync_with_stdio(false);
    long long a, b, ans = 0;
    cin >> a >> b;
    for(int i = 0; i <= 9; i++) {//一堆数
        for(int j = 0; j <= 9; j++) {//一个数
            if(i == j)continue;
            for(int k = 3; k <= 17; k++) {//数的总长度
                for(int l = 1; l <= k; l++) {//一个数的位置99989 -> 4
                    if(l == 1 && j == 0) continue;
                    if(l != 1 && i == 0) break;
                    long long t = 0;
                    for(int m = 1; m <= k; m++) {
                        if(m == l) {
                            t = t * 10 + j;
                        } else {
                            t = t * 10 + i;
                        }
                    }
                    if(t >= a && t <= b) ans ++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


