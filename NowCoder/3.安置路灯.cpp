/*************************************************************************
	> File Name: 3.安置路灯.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月19日 星期三 16时36分19秒
 ************************************************************************/
//https://www.nowcoder.com/questionTerminal/fc72d3493d7e4be883e931d507352a4a
#include<iostream>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    while(n --) {
        int t, ans = 0;
        string s;
        cin >> t >> s;
        for(int i = 0; i < t; i++) {
            if(s[i] == '.'){
                ans ++;
                i += 2;
            }

        }
        cout << ans << endl;
    }
}
