/*************************************************************************
	> File Name: 4.迷路的牛牛.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月19日 星期三 16时36分39秒
 ************************************************************************/
//https://www.nowcoder.com/questionTerminal/fc72d3493d7e4be883e931d507352a4a
#include<iostream>
using namespace std;
int n, cnt = 1001;
char s[1010], ans[4] = {'W', 'N', 'E', 'S'};
int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] =='R')cnt++;
        else cnt--;
    }
    cout << ans[cnt % 4] << endl;
    return 0;
}
