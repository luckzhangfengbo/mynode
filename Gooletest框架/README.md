# 谷歌测试框架



##　安装Google test

下载解压 googletest-master

下载地址：[https://github.com/google/googletest.git](https://github.com/google/googletest.git)

```cpp
cmake ./ 
sudo apt-get install cmake //unbantu安装cmake
cmake ./
make
```

![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-12 15-07-50屏幕截图.png)

以上命令会将gtest编译好

此时完成cmake的安装

```cpp
fangsong@fangsong-FX503VD:~/Mycode/project$ mv googletest-master googletest-master.zip thirdpart/   //(1)
fangsong@fangsong-FX503VD:~/Mycode/project$ ll
总用量 12
drwxr-xr-x  3 fangsong fangsong 4096 1月  12 15:31 ./
drwxr-xr-x 10 fangsong fangsong 4096 1月  12 14:43 ../
drwxr-xr-x  3 fangsong fangsong 4096 1月  12 15:31 thirdpart/
fangsong@fangsong-FX503VD:~/Mycode/project$ cp -R thirdpart/googletest-master/lib ./ 
    //(2)
fangsong@fangsong-FX503VD:~/Mycode/project$ ll
总用量 16
drwxr-xr-x  4 fangsong fangsong 4096 1月  12 15:31 ./
drwxr-xr-x 10 fangsong fangsong 4096 1月  12 14:43 ../
drwxr-xr-x  2 fangsong fangsong 4096 1月  12 15:31 lib/
drwxr-xr-x  3 fangsong fangsong 4096 1月  12 15:31 thirdpart/
fangsong@fangsong-FX503VD:~/Mycode/project$ cp -R thirdpart/googletest-master/googletest/include ./ //(3)
fangsong@fangsong-FX503VD:~/Mycode/project$ ll
总用量 20
drwxr-xr-x  5 fangsong fangsong 4096 1月  12 15:32 ./
drwxr-xr-x 10 fangsong fangsong 4096 1月  12 14:43 ../
drwxr-xr-x  3 fangsong fangsong 4096 1月  12 15:32 include/
drwxr-xr-x  2 fangsong fangsong 4096 1月  12 15:31 lib/
drwxr-xr-x  3 fangsong fangsong 4096 1月  12 15:31 thirdpart/
fangsong@fangsong-FX503VD:~/Mycode/project$ ls
include  lib  thirdpart
fangsong@fangsong-FX503VD:~/Mycode/project$ ll
总用量 20
drwxr-xr-x  5 fangsong fangsong 4096 1月  12 15:32 ./
drwxr-xr-x 10 fangsong fangsong 4096 1月  12 14:43 ../
drwxr-xr-x  3 fangsong fangsong 4096 1月  12 15:32 include/
drwxr-xr-x  2 fangsong fangsong 4096 1月  12 15:31 lib/
drwxr-xr-x  3 fangsong fangsong 4096 1月  12 15:31 thirdpart/
fangsong@fangsong-FX503VD:~/Mycode/project$ 
```

```cpp
g++ main.cpp -I ./include
```

```cpp
g++ -c main.cpp -I ./include
```

```cpp
g++ -L./lib main.o unit.o -lgtest
```

![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-12 15-27-45屏幕截图.png)

![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-12 15-19-42屏幕截图.png)

![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-12 14-58-52屏幕截图.png)

![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-12 15-29-47屏幕截图.png)

![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-12 15-35-35屏幕截图.png)

![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-12 15-38-22屏幕截图.png)

编译：

```cpp
g++ -L./lib main.cpp unit.c -I./include -lgtest -lpthread 
    或者
g++ --std=c++11 -I./include -L./lib main.cpp unit.c -lgtest -lpthread
```

![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-12 17-01-40屏幕截图.png)

## 使用gtest

main.cpp

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<gtest/gtest.h> //谷歌框架的头文件
#include "unit.h"
using namespace std;

 // TEST此处应该是一个宏
TEST(test, add_function) {　// test是一个测试用例
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(0, 0), 0);　// ASSERT_EQ(add(), )　, ASSERT是如果错误到此处，强行停止
    EXPECT_EQ(add(-1, -7), -8);　
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);　// 初始化谷歌框架调用
    return RUN_ALL_TESTS();　// 运行所有的测试用例
}
```

unit.h

```cpp
#ifndef _UNIT_H
#define _UNIT_H
int add(int a, int b);
#endif
```

unit.c

```cpp
#include "unit.h"
int add(int a, int b) {
    return a + b + 1;
}
```

编译和链接程序：

```cpp
g++ --std=c++11 -I./include -L./lib main.cpp unit.c -lgtest -lpthread
```

-L./lib添加静态链接库搜索路径

-lgtest去找libgtest.a文件



```cpp
./a.out
```

结束！

![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-12 17-01-40屏幕截图.png)





### 知识点：编译和链接程序

>-E 预先，将#include的文件展开等
>-S生成汇编文件
>-c生成目标文件
>gcc XX.o -o XX  链接，，输出文件称为XX -O1
>
>，-O2，-O3 优化代码，-O3级最高，-O1为体积
>-g及-ggdb等，，生成调试信息
>
>-fPIC及-fpic，生成动态链接库时使用，，前者在多平台通用，但程序运行速度慢
>
>-M，-MM，输出文件的依赖关系（各种各样各种.h）文件（写makefile时可以使用）
>
>-std = c ++ 14（或-std = gnu ++ 14）-std = c ++ 11（或-std = gnu ++ 11）启用c ++ 14/11的信息，其中使用gnu ++ 14会启用gcc的扩展：
>https
>: //gcc.gnu.org/projects/cxx0x.html https://gcc.gnu.org/projects/cxx1y。 html
>
>
>一般直接用-c生成对象文件，再多个对象文件链接一下即可或
>不指定参数，直接从多个.cpp文件生成重定向文件-
>
>墙壁输出放置多的警告
>
>-I 头文件路径
>-L 库文件路径（静态，动态）
>
>-l库文件（不包含扩展名.so或.a)



>## [-lpthread和-pthread的区别](https://www.cnblogs.com/suntp/p/6473751.html)
>
>```
>编译程序包括 预编译， 编译，汇编，链接，包含头文件了，仅能说明有了线程函数的声明， 但是还没有实现， 加上-lpthread是在链接阶段，链接这个库。<stdio.h>等都是静态库，不需要做额外的表示，连接时会直接链接进代码里。pthread是动态库，需要用-lpthread，所有的动态库都需要用-lxxx来引用
>```
>
>用gcc编译使用了POSIX thread的程序时通常需要加额外的选项，以便使用thread-safe的库及头文件，一些老的书里说直接增加链接选项 -lpthread 就可以了
>
>而gcc手册里则指出应该在编译和链接时都增加 -pthread 选项
>
> 
>
>编译选项中指定 -pthread 会附加一个宏定义 **-D_REENTRANT**，该宏会导致 libc 头文件选择那些thread-safe的实现；链接选项中指定 -pthread 则同 -lpthread 一样，只表示链接 POSIX thread 库。由于 libc 用于适应 thread-safe 的宏定义可能变化，因此在编译和链接时都使用 -pthread 选项而不是传统的 -lpthread 能够保持向后兼容，并提高命令行的一致性。
>
> 
>
>目前gcc 4.5.2中已经没有了关于 -lpthread的介绍了。所以以后的多线程编译应该用-pthread，而不是-lpthread。
>
>
>
>参考地址：http://blog.csdn.net/skylinethj/article/details/38569243



参考：https://www.jianshu.com/p/778f835cc18c



# 修改为自己的测试框架

mian.cpp

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include "haizei_test.h"
#include "unit.h"
using namespace std;
__attribute__((constructor))  //属性构造
int haizei_init() {
    printf("hello haizei\n");
    return 0;
}

__attribute__((constructor)) //属性构造:先执行此处，在执行主函数
TEST(test, add_function) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-1, -7), -8);
}

int main(int argc, char *argv[]) {

    return RUN_ALL_TESTS();
}
```

unit.h

```cpp

#ifndef _UNIT_H
#define _UNIT_H
int add(int a, int b);
#endif

```

unit.cc

```cpp
#include "unit.h"
int add(int a, int b) {
    return a + b + 1;
}
```

haizei_test.h

```cpp
#ifndef _HAIZEI_TEST_H
#define _HAIZEI_TEST_H

#define TEST(a, b) void a##b()

#define EXPECT_EQ(a, b) {\
    if(a == b) {\
        printf("YES\n");\
    } else {\
        printf("NO\n");\
    }\
}

int RUN_ALL_TESTS();
#endif

```

haizei_test.cc

```cpp
int RUN_ALL_TESTS() {
    return 0;
}
```



#### 改进

haizei_test.h

```cpp
#ifndef _HAIZEI_TEST_H
#define _HAIZEI_TEST_H

#define MAX_N 1000
typedef void (*Func_T)();
extern Func_T func_arr[MAX_N];

extern int func_cnt;

#define TEST(a, b) \
         void a##b(); \
         __attribute__((constructor)) \
         void add_##a##b() { \
             func_arr[func_cnt++] = a##b;\
         } \
         void a##b()

#define EXPECT_EQ(a, b) {\
    if(a == b) {\
        printf("YES\n");\
    } else {\
        printf("NO\n");\
    }\
}

int RUN_ALL_TESTS();
#endif
```

haizei_test.cc

```cpp
#include <stdio.h>
#include "haizei_test.h"

Func_T func_arr[MAX_N];

int func_cnt = 0;

int RUN_ALL_TESTS() {
    for(int i = 0; i < func_cnt; i++) {
        printf("run TEST %d \n", i + 1);
         func_arr[i]();
    }
    return 0;
}
```







##　泛型宏

根据类型不一样，替换操作











＃停





文件：

```cpp
    haizei_test.c 
    main.c    
    test.cpp   
    unit.c
    bin    
    haizei_test.h  lib      
    makefile  
    thirdpart  
    unit.h
```



![](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/2020-01-14 18-43-28屏幕截图.png)建立makefile

```cpp
all: //目标
	gcc -o ./bin/haizei_test -std=c11 ./main.c ./haizei_test.c ./unit.c　// 编译 
	./bin/haizei_test　// 执行
clean:　// 编译目标
	rm ./bin/haizei_test
        
```

然后make









颜色控制：

```cpp
#include<iostream>
#include<cstdio>
using namespace std;

#define COLOR(str, code) "\033[" #code "m" str "\033[0m"
#define YELLOW(str) COLOR(str, 33)
//#define YELLOW(str) "\033[33m" str"\033[0m"

int main() {
    printf(YELLOW("ping攻击中...\n"));
    printf("\033[5;33;46m警告！！！\033[0m");
}

```



## bug

```

```

