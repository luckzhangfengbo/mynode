/*************************************************************************
	> File Name: main.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月14日 星期五 16时38分25秒
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
#include<functional>
#include"thread_poll.h"
using namespace std;

int main() {

    haizei::ThreadPoll tp(2);
    tp.start();
    for(int i = 0; i < 10; i++) {
        tp.add_one_task(func, i, ref(n));
    }
    return 0;
}
