/*************************************************************************
	> File Name: main.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月10日 星期一 12时01分55秒
 ************************************************************************/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include "BSTree.h"
#include <set>
using namespace std;

class A {
public :
    void operator++() {
        cout << "no param" << endl;
    }
    void operator++(int) {
        cout << "has int param" << endl;
    }
};

int main() {
    haizei::BSTree<int> root_bs;
    std::set<int> root_s;
    for (int i = 0; i < 10; i++) {
        root_bs.insert(rand() % 100);
        root_s.insert(rand() % 100);
    }
    for (std::set<int>::iterator iter = root_s.begin(); iter != root_s.end(); iter++) {
        cout << *iter << endl;
    }
    for (haizei::BSTree<int>::iterator iter = root_bs.begin(); iter != root_bs.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}
