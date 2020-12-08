/*************************************************************************
	> File Name: KMP.cpp
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年04月27日 星期一 21时30分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;



void init_next(string str, int *next, int length) {
    next[0] = -1;
    int k = -1; 
    for(int i = 1; i < length; i++) {
        while(k > -1 && str[k + 1] != str[i]) {
            k = next[k];
        }
        if(str[k + 1] == str[i]) {
            k++;
        }
        next[i] = k;
    }
}

int KMP(string str, string ptr) {
    int *next = new int[ptr.size()];
    init_next(ptr, next, ptr.size());
    int k = -1;
    for(int i = 0; i < str.size(); i++) {
        while(k > -1 && ptr[k + 1] != str[i]) {
            k = next[k];
        }
        if(ptr[ k + 1 ] == str[i]) k++;
        if(k == ptr.size() - 1) {
            return i - ptr.size() + 1;
        }
    }
    return -1;
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << KMP(s1, s2) << endl;
    return 0;
}
