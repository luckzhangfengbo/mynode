/*************************************************************************
	> File Name: 48-完全背包.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月22日 星期三 20时53分30秒
 ************************************************************************/
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int all, n, w[105], v[105], ans[105][100005];

int main() {
    cin >> n >> all;
    for(int i = 1; i <= n; i++) {
        cin >>w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= all; j++) {
            if(j < w[i]) {
                ans[i][j] = ans[i - 1][j];
            } else {
                ans[i][j] = max(ans[i - 1][j], v[i] + ans[i][j - w[i]]);
            }
        }
    }
    cout << ans[n][all] << endl;
    return 0;
}
*/

#include<iostream>
#include<cstdio>
using namespace std;

int all, n, w[10002], v[10002], ans[10002];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> all;
    for(int i = 1; i <= n; i++) {
        cin >>w[i] >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = w[i]; j <= all; j++) {
                ans[j] = max(ans[j], v[i] + ans[j - w[i]]);
        }
    }
    cout << ans[all] << endl;
    return 0;
}

