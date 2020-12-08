/*************************************************************************
	> File Name: 264-最大矩形面积.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月28日 星期二 20时37分50秒
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

#define MAX_N 100000
typedef long long inti;
inti a[MAX_N + 5];
inti s[MAX_N + 5], top = -1; 
inti l[MAX_N + 5], r[MAX_N + 5];

int main() {
    inti n;
    cin >> n;
    for(inti i = 1; i <= n; i++) cin >> a[i];
    a[0] =a[n + 1]= -1;
    s[top = 0] = 0;
    for(inti i = 1; i <= n; i++) {
        while(a[s[top]] >= a[i]) -- top;
        l[i] = s[top];
        s[++top] = i;
    }
    s[top = 0] = n + 1;
    for(inti i = n; i >= 1; i--) {
        while(a[s[top]] >= a[i]) -- top;
        r[i] = s[top];
        s[++top] = i;
    }
    inti ans = 0;
    for(inti i = 1; i <= n; i++) {
         ans = max(ans, a[i] * (r[i] - l[i] - 1));
    }
    cout << ans<< endl;
    return 0;
}
