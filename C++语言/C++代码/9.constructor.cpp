/*************************************************************************
	> File Name: 9.constructor.cpp
	> Author:fangsong
	> Mail: 2035756541@qq.com
	> Created Time: 2020年07月26日 星期日 18时14分47秒
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

class People {
public:
    People() = default;
   //People() = delete;
    People(string name) {
        this->name = name;
    }
    People(int x) {
        this->x = x;
    }
    /*People() { 默认构造函数
        arr = new int[10];
        cout << "default constructor" << endl;
    }*/
    People(const People &a) {
        cout << "copy constuctor" << endl;
        this->name = name;
        this->x = a.x;
    }
	void operator=(const People &a){
        cout << "operator=" << endl;
        this->name = a.name;
        this->x = a.x;
    }
    ~People() {
        cout << "destructor" << endl;
    }
    string name;
    int x;
    //int *arr;
};


void incr(int &a) {
    a += 1;
    return;
}

int add(People a, People b) {
    return a.x + b.x;
}

int main() {
    People f;
    int w = 7;
    incr(w);
    cout << w << endl;
    cout << add(4, 5) <<endl;
    People b("fangsong");
    People a = string("string");
    People c(54);
    //a.arr[9] = 12
    cout << a.name << endl;
    c = 987;
    cout << c.x << endl;
    People d = string("fsdaf");
    cout << d.name << endl;
    People e = a;
    cout << e.name << endl;
    cout << e.x << endl;
    c = a;
    cout << c.name << endl;
    cout << c.x << endl;
    return 0;
}
