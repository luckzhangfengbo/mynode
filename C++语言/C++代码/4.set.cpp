/*************************************************************************
	> File Name: 4.set.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年07月23日 星期四 18时13分36秒
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
int main() {
    set<int>s;
    s.insert(345);
    s.insert(65);
    s.insert(9956);
    s.insert(9000);
    cout << s.size() << endl;
    s.insert(65);
    cout << s.size() << endl;
    cout << *(s.begin()) << endl;
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }
    s.erase(s.begin());
    cout << *(s.begin()) << endl;
    return 0;
}
