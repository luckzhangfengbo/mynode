/*************************************************************************
	> File Name: 216.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月23日 星期四 18时27分23秒
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
typedef pair<string, int>PSI;
int main() {
    ios::sync_with_stdio(false);
    set<PSI> s;
    string name;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name;
        //name = name.substr(name.find(".") + 1, name.size());
        name.erase(0, 3);
        s.insert(PSI(name, i));
    }
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        cout << iter->first << endl;
    }
    return 0;
}
