/*************************************************************************
	> File Name: 245-货仓选址.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月17日 星期日 19时26分23秒
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
int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int pos = a[n / 2];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += abs(a[i] - pos);
    }
    cout << sum << endl;
    return 0;
}
