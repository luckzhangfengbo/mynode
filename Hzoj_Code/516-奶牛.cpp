/*************************************************************************
	> File Name: 516-奶牛.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月20日 星期三 15时30分25秒
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
    ios::sync_with_stdio(false);
    int n, wNum[100005], cNum[100005], C = 0, W = 0;
    long long sum = 0;
    cin >> n;
    string str;
    cin >> str;
    for(int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        if(str[i] == 'C') {
            C++;
        }
        if(str[i] == 'O') {
            cNum[i] = C;
        }
        if(str[j] == 'W') {
            W++;
        }
        if(str[j] == 'O') {
            wNum[j] = W;
        }
    }
    for(int i = 0; i < n; i++) {
        if(str[i] == 'O') {
            sum += (wNum[i] * cNum[i]);
        }
    }
    cout << sum << endl;
    return 0;
}
