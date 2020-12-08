/*************************************************************************
	> File Name: 4.多重背包.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年06月01日 星期一 20时27分02秒
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
const int N = 110;
int n, m;
int f[N];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
         int v, w, s;
        cin >> v >> w >> s;
        for(int j = m; j >= 0; j--){
            for(int k = 1; k <= s && k * v <= j; k++) {
                f[j] = max(f[j], f[j - k * v] + k * w);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}
