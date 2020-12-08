/*************************************************************************
	> File Name: 41.singleton.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月22日 星期六 16时07分49秒
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
#include<mutex>
using namespace std;

class Singleton {
public :
    static Singleton *getInstance() {
        if(single == nullptr) {
            std::unique_lock<mutex>lock(m_mutex);
            if(single == nullptr) {
                single = new Singleton();
            }
        }
        return single;
    }

private:
    static Singleton *single;
    static std::mutex m_mutex;
    Singleton()=default;
    Singleton(const Singleton &) = default;
    ~Singleton(){}
};

Singleton *Singleton::single = nullptr;
std::mutex Singleton::m_mutex;

int main() {
    Singleton *p = Singleton::getInstance();


    return 0;
}
