/*************************************************************************
	> File Name: unordered_map.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月16日 星期六 19时32分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

/*哈希表*/
int main() {
    unordered_map<double, int> h;
    h[2.3] = 123;
    h[345.6] = 123456;
    cout << h[2.3] << endl;
    cout << h[345.6] << endl;
    cout << h[88] << endl;
}
