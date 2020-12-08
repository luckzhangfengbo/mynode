/*************************************************************************
	> File Name: 798.子矩阵的和.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月08日 星期二 17时17分04秒
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

const int N = 1050;
int a[N][N], s[N][N];

int main() {
    int n, m, q, x1, y1, x2, y2;
    cin >>n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}
