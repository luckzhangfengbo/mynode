/*************************************************************************
	> File Name: 235-递归实现指数型枚举.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月11日 星期三 23时11分25秒
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

int num[15], cnt, n;


void p() {
    for(int i = 0; i < cnt; i++) {
        if(i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}

void func(int s) {
    for(int i = s; i <= n; i++) {
        num[cnt] = i;
        cnt ++;
        p();
        func(i + 1);
        cnt--;
    }
}

int main() {
    cin >> n;
    func(1);
    return 0;
}

