/*************************************************************************
	> File Name: 504-删数.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月13日 星期三 15时45分56秒
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
/*
string s;
int main() {
    int t;
    cin >> s >>t;
    while(t) {
        int i;
        for(i = 0; i < s.size() - 1 && s[i] <= s[i + 1]; i++);
        s.erase(i, 1);
        t--;
    }
    if(s.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int i;
    for(i = 0; i < s.size(); i++) {
        if(s[i] !='0')break;
    }
    cout << s.substr(i) << endl;
    return 0;
}
*/

string s;
int main() {
    int n;
    cin >> s >> n;
    for(int i = 0; i < n; i++) {
        int ind = s.size() - 1;
        for(int j = 0; j < s.size() - 1; j ++) {
            if(s[j] > s[j + 1]) {
                ind = j;
                break;
            }
        }
        s.replace(ind, 1, "");
    }
    int flag = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != 0)flag = 1;
        if(flag)cout << s[i];
    }
    cout << endl;
    return 0;
}
