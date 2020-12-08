/*************************************************************************
	> File Name: 49-多重背包.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月29日 星期三 19时45分07秒
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

int all, n, ind ,v[100005], w[100005], ans[100000];
int main() {
    cin >> all >> n;
    for(int i = 0; i < n; i++) {
        int x, y ,z ;
        cin >> x >> y >> z;
        for(int j = 0; j < z; j++) {
            ind ++;
            w[ind] = x;
            v[ind] = y;
        }
    }
    for(int i = 1; i <= ind; i++) {
        for(int j = all; j >= w[i]; j--) {
            ans[j] = max(ans[j], ans[j - w[i]] + v[i]);
        }
    }
    cout << ans[all] << endl;
    return 0;
}
