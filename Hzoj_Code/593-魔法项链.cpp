/*************************************************************************
	> File Name: 592-魔法项链.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月13日 星期三 19时52分32秒
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
int n, m, ans[30005], mem[30005];
char str[30005];

int main() {
    cin >> n >> m >> &str[1];
    for(int i = 1; i <= n / 2; i++) {
        int same = 0;
        for(int j = 1, k = i + 1; j <= i; j++, k++) {
            if(str[j] == str[k]) {
                same++;
            }
        }
        ans[same]++;
        for(int j = 2; j + 2 * i - 1 <= n; j++) {
            if(str[j - 1] == str[j - 1 + i]) {
                same--;
            }
            if(str[j + i - 1] == str[j + 2 * i - 1]) {
                same++;
            }
            ans[same]++;
        }
        mem[i] = same;
    }
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(t == 2) {
            cin >> t;
            cout << ans[t] << endl;
            continue;
        }
        char l;
        cin >> l;
        str[++n] = l;
        if(n % 2 == 0) {
            int same = 0, mid = n / 2;
            for(int j = 1, k = 1 + mid; j <= mid; j++, k++) {
                if(str[j] == str[k]) {
                    same ++;
                }
            }
            ans[same] ++;
            mem[mid] = same;
        }
        for(int j = 1; j <= (n - 1) / 2; j++) {
            if(str[n - j - j] == str[n - j]) {
                mem[j] --;
            }
            if(str[n] == str[n - j]){
                mem[j] ++;
            }
        ans[mem[j]]++;    
        }
    }
    return 0;
}
