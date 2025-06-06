/*************************************************************************
	> File Name: 3.完全背包.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月31日 星期日 10时23分43秒
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
int v[1005], w[1005];
int f[1005];
int main() {
    int N, V;
    cin >> N >> V;
    for(int i = 1; i <= N; i++) {
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = v[i]; j <= V; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V] << endl;
    return 0;
}

