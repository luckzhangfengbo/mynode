/*************************************************************************
	> File Name: 560-开心的金明.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月29日 星期三 18时53分14秒
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
#define N 30004
#define M 30 
long long f[N], v[M], w[M];
int n, m;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> v[i] >> w[i];
        w[i] *= v[i];
    }
    for(int i = 1; i <= m; i++) {
        for(int j = n; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}
