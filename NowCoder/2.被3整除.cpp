/*************************************************************************
	> File Name: 2.被3整除.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月19日 星期三 16时08分38秒
 ************************************************************************/

//https://www.nowcoder.com/questionTerminal/51dcb4eef6004f6f8f44d927463ad5e8
/*
来源：牛客网

一个数所有位数的和相加如果等于3的倍数，则这个整数是3的倍数。 这里第一个数是1，第二个是12，第三个是123……第n个数是123……(n-1)n，各个位之和可以算成(i+1)*i/2,这里如果是大于等于两位数，它算成一个数和把每一位分开计算对3取余的结果都是一样的，所以没关系。 所以，直接遍历l到r，根据通项公式判断即可。*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll l , r;
    while(cin >> l >> r){
        ll count = 0;
        for(int i = l; i <= r; i++){
            if((i+1)*i/2 % 3 == 0)    count++;
        }
        cout << count << endl;
    }
    return 0;
}
