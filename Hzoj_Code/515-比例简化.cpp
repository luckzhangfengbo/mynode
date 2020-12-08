/*************************************************************************
	> File Name: 515-比例简化.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月20日 星期三 23时56分22秒
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
int a, b, l, aa, bb;
double raw, now = 99999999;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    cin >> a >> b >> l;
    raw = (double) a/ b;
    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= l; j++) {
            double t = (double)i / j;
            if(t >= raw && t - raw < now - raw && gcd(i, j) == 1) {
                now = t;
                aa = i;
                bb = j;
            }
        }
    }
    cout << aa << " " << bb << endl;
    return 0;
}
