/*************************************************************************
	> File Name: 11.RVO.cpp
	> Author:fangsong
	> Mail: 2035756541@qq.com
	> Created Time: 2020年07月26日 星期日 21时11分33秒
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


class People{
public:
    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
    }
private:
    string name;
};
People func() {
    People temp_a("fangsong");
    return temp_a;
}


int main() {
    People a = func();
    return 0;
}
