/*************************************************************************
	> File Name: 2.map.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月21日 星期二 20时09分46秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
    unordered_map<double, string> arr;
    arr[1.2] = "hello ";
    arr[4.3] = "world";
    arr[-4.5] = "haizei";
    arr[89.7] = "world";
    double n;
    while(cin >> n) {
        if(arr.find(n) != arr.end()){
            cout <<  "find" << endl;
        } else {
            cout << "not find" << endl;
        }
    }
    for(auto iter = arr.begin(); iter != arr.end(); iter++) {
        
        cout << iter->first << iter->second << endl;
    }
    return 0;
}
