/*************************************************************************
	> File Name: 23.auto.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月02日 星期日 18时40分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;




int main() {
    auto a = 123;
    cout << sizeof(a) << endl;
    map<int , int>arr;
    arr[7131] = 3213;
    arr[564] = 5646;
    for(auto iter = arr.begin() ; iter != arr.end(); iter++) {
        cout << iter->first <<" " << iter->second << endl;
    }
    for (auto x : arr) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
