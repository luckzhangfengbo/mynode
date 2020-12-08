/*************************************************************************
	> File Name: 577-讲话模式.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月24日 星期五 17时13分52秒
 ************************************************************************/
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
void check(string &str) {
    for(int i = 0;i < str.size(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 'a' -'A';
        }
    }
}

int main() {
    map<string, int>m;
    string str, ans;
    int ans_cnt = 0;
    while(cin >> str) {
        check(str);
        m[str] ++;
        if(m[str] > ans_cnt) {
            ans_cnt = m[str];
            ans = str;
        } else if(m[str] == ans_cnt && str < ans) {
            ans_cnt = m[str];
            ans = str;
        }
    }
    cout<< ans << " " << ans_cnt << endl;
    return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;



int main() {
    map<string, int>mmap;
    string str, ans_str;
    int ans = 0;
    while(cin >> str) {
        transform(str.begin(),str.end(),str.begin(),::tolower);
        mmap[str]++;
        if(mmap[str] > ans) {
            ans = mmap[str];
            ans_str = str;
        } else if(mmap[str] == ans && str < ans_str) {
            ans = mmap[str];
            ans_str = str;
        }
    }
    cout << ans_str << " " << ans << endl;
    return 0;
}
