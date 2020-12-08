/*************************************************************************
	> File Name: 674-宿舍楼里的电竞赛.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月12日 星期三 17时14分37秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int n, m, ans[105][105], x[105], y[105];
//ans[i][j], a->j最短距离是多少, x[]前右多少个，y后有多少个
int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ans[a][b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);//从j->k和从j->i->k的比较小的记录下
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] != 0x3f3f3f3f) {//不是极大值，说明从i->j能过来
                x[j]++;//记录前面有多少
                y[i]++;//记录后面后多少
            }
        }
    }
    int fin = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] + y[i] == n - 1) {//全部的时候
            fin++;
        }
    }
    cout << fin << endl;
    return 0;
}
