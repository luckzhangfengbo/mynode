/*************************************************************************
	> File Name: 5.287.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月23日 星期四 19时04分38秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
int main() {
    int n,a, sum, t = 0;
    cin >> n;
    set<PII>s;
    for(int i = 0; i < n; i++) {
        cin >> a;
        s.insert(PII(a, t++));
    }
    for(int i = 0; i < n - 1; i++) {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        sum += a+ b;
        s.insert(PII(a + b, t++));
    }
    cout << sum << endl;
    return 0;
}
