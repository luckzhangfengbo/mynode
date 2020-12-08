/*************************************************************************
	> File Name: 587-环.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时09分39秒
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
    int n, a, b, c, d = 0;
    cin >> n >> a >> b >> c;
    if(a > b) d++;
    if(b > c) d++;
    if(c > a) d++;
    if(d == 2) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}
