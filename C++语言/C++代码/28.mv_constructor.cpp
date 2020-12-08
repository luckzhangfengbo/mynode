/*************************************************************************
	> File Name: 28.mv_constructor.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月06日 星期四 09时41分16秒
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
        cout << "string :default constructor, " << this << endl;
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }
    string(const char *str) {
        cout << "string :const char constructor, " << this << endl;
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
    }

    string(const string &s){
        cout <<"copy constructor : " <<endl;
        this->__buff_size = s.__buff_size;
        this->__length = s.__length;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, s.buff);
    }
    string(string &&s){
         cout<< "move constructor" << endl;
        this->__buff_size = s.__buff_size;
        this->__length = s.__length;
        this->buff = s.buff;
        s.buff = nullptr;
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

    ~string(){
        cout << "string : destructor, " << this << endl;
        if(this->buff) delete this->buff;
    }


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
    //cin >> s1;
    cout <<"=====s4.being===="<< endl;
    haizei::string s4 = s1 + s2 + s3;
    haizei::string s5 = s4;
    cout << s4 << endl;
    cout << s5 << endl;
    s4[3] = '=';
    cout << s4 << endl;
    cout << s5 << endl;
    cout <<"====s4.end====" << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 <<endl;
    for(int i = 0; i < s1.size(); i++) {
       cout << s1[i] << endl; 
    }
    return 0;
}
