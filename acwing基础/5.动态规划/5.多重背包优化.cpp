/*************************************************************************
	> File Name: 5.多重背包优化.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年06月01日 星期一 21时25分32秒
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
const int N = 2010;
int n, m;
int f[N];
struct Good{
    int v, w;
};
int main() {
    cin >> n >> m;
    vector<Good> goods;
    for(int i = 0; i < n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for(int k = 1; k <= s; k *= 2) {
            s -= k;
            goods.push_back({v * k, w * k});
        }
        if(s > 0) goods.push_back({v * s, w * s});
    }
    for(auto good : goods) {
        for(int j = m; j >= good.v; j--) {
            f[j] = max(f[j], f[j - good.v] + good.w);
        }
    }
    cout << f[m] << endl;
    return 0;
}
