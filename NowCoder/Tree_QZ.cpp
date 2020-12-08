/*************************************************************************
	> File Name: Tree_QZ.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月26日 星期三 15时18分20秒
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

string q, z;

void func(int qs, int qe, int zs, int ze) {
    if(qe < qs) {
        return;
    }
    if(qs == qe) {
        cout << q[qs];
        return;
    }
    char root = q[qs];
    for(int i = zs; i <= ze; i++) {
        if(z[i] == root) {
            func(qs + 1, (i - zs) + qs, zs, i - 1);
            func(i - zs + qs + 1, qe, i + 1, ze);
            cout << root;
            break;
        }
    }
}

int main() {
    cin >>q >> z;
    func(0, q.size() - 1, 0, z.size() - 1);
    cout << endl;
    return 0;
}
