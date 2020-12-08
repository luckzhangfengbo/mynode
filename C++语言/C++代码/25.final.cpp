/*************************************************************************
	> File Name: 25.final.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月02日 星期日 19时49分09秒
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

class A :public  map<int, int> {
    public :
    virtual void say() {
        cout << "Class A : hello world" << endl;
    }
};

class B final : public A{
    public : 
    void say() final override{
        cout << "Class B : hello world" << endl;
    }
};

/*
class C : public B{
    public :
    void say() override {
        cout << "Class :hello world" << endl;
    }
};*/

int main() {
    A a;
    a[123] =456;
    a[987] = 46513;
    for(auto x : a) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
