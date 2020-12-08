/*************************************************************************
	> File Name: 18.string.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月01日 星期六 14时32分23秒
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

class string {
public :
    string() {
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }
    string(const char *str) {
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
    }
    char &at(int ind) {
        if(ind < 0 || ind >= __length) {
            cout << "String Error : out of range" << endl;
            return __end;
        }
        return this->operator[](ind);
    }
    char &operator[](int ind) {
        return buff[ind];
    }
    const char *c_str() const {
        return buff;
    }
    string operator+(const string &s) {
        int size = this->__length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }
    int size() {return this->__length;}
friend istream &operator>>(istream &in, const haizei::string &s);

private:
    int __length, __buff_size;
    char *buff;
    char __end;
};
istream &operator>>(istream &in, const haizei::string &s) {
    in >> s.buff;
    return in;
}

}


ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str() << endl;
    return out;
}


int main() {
    haizei::string s1 = "hello world", s2 = ", haizei", s3 = "harbin.";
    cout << s1 << endl;
    cin >> s1;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 <<endl;
    for(int i = 0; i < s1.size(); i++) {
       cout << s1[i] << endl; 
    }
    return 0;
}
