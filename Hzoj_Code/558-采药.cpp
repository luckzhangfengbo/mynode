/*************************************************************************
	> File Name: 558-采药.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月29日 星期三 18时11分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int N = 1500;
int w[N], v[N];
int m, n;
int f[N];
int main() {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >>v[i]>> w[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
