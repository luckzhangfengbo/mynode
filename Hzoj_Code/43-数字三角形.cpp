/*************************************************************************
	> File Name: 43-数字三角形.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月29日 星期三 20时14分26秒
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
/*
int n, num[1005][1005], ans[1005][1005];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j= 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i + 1][j + 1], ans[i + 1][j]) + num[i][j];
        }
    }
    cout << ans[1][1] << endl;
    return 0;

}
*/

#define MAX_N 1000
int f[MAX_N + 5][MAX_N + 5];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> f[i][j];
        }
    }
    for(int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
        }
    }
    cout << f[1][1] << endl;
    return 0;
}
