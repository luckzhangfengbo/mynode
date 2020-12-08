/*************************************************************************
	> File Name: 227-64位整数乘法.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月24日 星期五 17时00分55秒
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
typedef long long ll;

ll mul(ll a, ll b, ll p) {
    ll temp = a, ans = 0;
    while(b) {
        if(b & 1) ans = (ans + temp) % p;
        temp = temp * 2 % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll a, b ,q;
    cin >> a >> b >> q;
    cout << mul(a , b , q) << endl;
    return 0;
}
