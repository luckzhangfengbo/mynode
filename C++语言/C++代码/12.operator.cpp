/*************************************************************************
	> File Name: 12.operator.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年07月27日 星期一 18时30分13秒
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

namespace haizei {
    
class istream{
public :
    istream &operator>>(int &n){
        std::cin >> n;
        return *this;
    }
private:

};

class ostream {
public :
    ostream &operator<<(int &n) {
        std::cout << n;
        return *this;
    }
    ostream &operator<<(const char *msg) {
        std::cout<< msg;
        return *this;
    }
private:

};
istream cin;
ostream cout;
};


haizei::ostream &operator<<(haizei::ostream &out, double &z) {
    std::cout << z;
    return out;
}

ostream &operator+(ostream &out,const int &z){
    out << z;
    return out;
}


int main() {
    int n, m;
    haizei::cin >> n >> m;
    haizei::cout << n <<" "<< m << "\n";
    double k = 5.6;
    haizei::cout << k << "\n";
    cout + 8 + 9 + 10;
    cout + k;
    (((((cout + 8 )<< " ") + 9) << " ") + 10) << endl;
    return 0;
}
