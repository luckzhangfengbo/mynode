/*************************************************************************
	> File Name: 4.nth_element.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月21日 星期二 21时06分54秒
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
    cin >> n; 
    int a[100005];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    nth_element(a, a + n / 2, a + n);
    int pos = a[n / 2], sum = 0;
    for(int i = 0; i < n; i++) {
        sum += abs(a[i] - pos);
    }
    cout << sum << endl;    
    return 0;
}
