/*************************************************************************
	> File Name: 799.最长连续不重复子序列.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月08日 星期二 22时24分34秒
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

const int  N = 100010;
int a[N], s[N];

int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0, j = 0; i < n; i++) {
        s[a[i]] ++;
        while(j <= i && s[a[i]] > 1)  {
            s[a[j]] --;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << endl; 
    return 0;
}
