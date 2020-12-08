/*************************************************************************
	> File Name: 588-数列.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时23分05秒
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
int ans[31][10005] = { {}, {1} }, n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int ind = 0;
        for(int j = 0; ans[i - 1][j] != 0; j++) {
            int x = 1;
            while(ans[i - 1][j] == ans[i - 1][j + 1]) {
                x ++;
                j ++;
            }
            ans[i][ind++] = x;
            ans[i][ind++] = ans[i - 1][j];
        }
    }
    for(int i = 0;ans[n][i] != 0; i++) {
        cout << ans[n][i];
    }
    cout << endl;
    return 0;
}
