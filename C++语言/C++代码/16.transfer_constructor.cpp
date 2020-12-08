/*************************************************************************
	> File Name: 16.transfer_constructor.cpp
	> Author:fangsong
	> Mail: 2035756541@qq.com
	> Created Time: 2020年07月27日 星期一 10时17分41秒
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
class BigInt{
    public :
    BigInt() {}
    BigInt(int x) {
        num.push_back(x);
        process_digit();
    }
    friend ostream &operator<<(ostream &, const BigInt &);
    private:
    vector<int>num;
    void process_digit() {
        for(int i = 0; i < num.size(); i++) {
            if(num[i] < 10) continue;
            if(i + 1 == num.size())num.push_back(0);
            num[i + 1] = num[i]/10;
            num[i] %= 10;
        }
        return;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for(int i = a.num.size() - 1; i >= 0; i--) {
        out << a.num[i];
    }
    return out;
}

void func(BigInt a) {
    cout << "func : " << a << endl;
}

int main() {
    BigInt a;
    a = 1234;
    cout << a << endl;
    func(5670);
    return 0;
}
