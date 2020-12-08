

## 类和对象

**类型 = 类型<font color = red>数据</font> + 类型<font color = green>操作</font>**

![image-20200725154924208](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200725154924208.png)

![img](https://github.com/jackfrued/Python-100-Days/raw/master/Day01-15/res/oop-zhihu.png)

### 访问权限

![image-20200725155708004](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200725155708004.png)

注：友元方法

学习C++重点：运行时的bug编程编译时的bug

### C语言与C++中struct

```cpp
//c语言//
//声明 
struct stu
{
    ...
};
//定义 
struct stu student;
```

```cpp
//c++//
//声明
struct stu
{
    ...
};
//定义
1.struct stu student;
2.stu student;
```

![image-20200726205745836](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726205745836.png)

```c++
class People{
    public:
    int x, y;
};

struct People2{
    int x, y;
};
```

如果想在c语言中直接用结构体名定义变量，需要用到 typedef 

```c++
//typedef的一般用法
typedef type new_type;
```

**特别的**当type为用户自定义类型时，type 和 new_type 可以相同。

用于结构体时 

```cpp
typedef struct stu
{
    ...
}Stu;
//定义
1.Stu student;
2.struct stu student;
```

### 第一个class小例子

```c++
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

class People{
    friend int main();//友元#隔壁老宋
    int x, y;
public :
    void set(int x);
    void say();
};

struct People2{
    int x, y;
};

void People::set(int x) {
    cout << "set functiona : " << this << endl;
    this->x = x;
    return;
}

void People::say() {
    cout << x << " " << y << endl;
    return;
}

int main() {
    People a;
    People2 b;
    a.y = 18432;//友元
    cout << "a pbject : " << &a << endl;
    a.set(3);
    b.x = 4;
    a.say();
    cout << b.x << endl;
    return 0;
}
```



## 封装

我该有的我该做的

### 构造函数与析构函数

![image-20200726181013896](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726181013896.png)

![image-20200728182108059](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728182108059.png)

```c++
class People {
public:
    People(){}
    People(string name) {//有参构造
        this->name = name;
    }
    /*People() { 默认构造函数
        arr = new int[10];
        cout << "default constructor" << endl;
    }*/
    ~People() {
        cout << "destructor" << endl;
    }
    string name;
    //int *arr;
};

int main() {
    People b("fangsong");
    People a = string("string");
    //a.arr[9] = 12
    cout << a.name << endl;
    return 0;
}
```

**拷贝构造为什么要用&**

![image-20200726185155194](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726185155194.png)

```c++
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class People {
public :
    People() {}
    //People() = default; //  //隐藏规则变为显示规则，易于代码维护
   //People() = delete;
    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(int x) {
        cout << "int param constructor" << endl;
        this->x = x;
    }
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
        this->x = a.x;
    }
    
    void operator=(const People &a) {
        cout << "operator =" << endl;
        this->name = a.name;
        this->x = a.x;
        return ;
    }

    ~People() {
        cout << "destructor" << endl;
    }
    string name;
    int x;
};

void incr(int &a) {
    a += 1;
    return ;
}

int add(People a, People b) {
    return a.x + b.x;
}

int main() {
    int n = 7;
    incr(n);
    cout << n << endl;
    cout << add(4, 5) << endl;
    People a("hug");
    People b = string("hug");
    People c(543);
    People d = 678;
    cout << a.name << endl;
    cout << b.name << endl;
    cout << c.x << endl;
    cout << d.x << endl;
    c = 987;
    cout << c.x << endl;
    d = string("duanchenyang");
    cout << d.name << endl;
    People e = a;
    cout << e.name << endl;
    cout << e.x << endl;
    c = a;
    cout << c.name << endl;
    cout << c.x << endl;
    return 0;
}
```

### 类属性方法

static   类成员，类方法

类的成员与方法

![image-20200726193613579](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726193613579.png)

类属性与类方法中，类属性可以记录类对象的个数，类方法中不能访问this指针;

### CONST方法

![image-20200726194132004](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726194132004.png)

不去修改对象中的值

const类型对象只能调用const类型方法

修饰后只能类const访问

### 类属性与const代码演示

```c++
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Point {
public :
    Point() {
        cout << "constructor : " << this << endl;
        Point::total_cnt += 1;
    }
    Point(const Point &a) : Point() {
        cout << "copy constructor : " << this << endl;
        this->x = a.x;
        this->y = a.y;
    }
    Point(double z) : Point() {
        cout << "convert constructor : " << this << endl;
        this->x = 99, this->y = 99;
    }
    Point(int x, int y) : Point() {
        cout << "param constructor : " << this << endl;
        this->x = x;
        this->y = y;
    }

    void operator=(const Point &a) {
        cout << "operator= : " << this << endl;
        this->x = a.x, this->y = a.y;
        return ;
    }
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void seek() const {
        seek_cnt += 1;
        cout << x << " " << y << endl;
    }

    void s() const{
        cout << seek_cnt << endl;
    }

    static int T() { return Point::total_cnt; }//类承成员方法

    ~Point() {
        cout << "destructor : " << this << endl;
        Point::total_cnt -= 1;
    }

private:
    int x, y;
    mutable int seek_cnt = 0;
    static int total_cnt;//类方法成员属性
};
int Point::total_cnt = 0;

void test() {
    Point a;
    cout << Point::T() << endl;
    return ;
}
int main() {
    Point a;
    cout << a.T() << endl;
    test();
    Point b;
    cout << b.T() << endl;
    Point c(3, 4);
    cout << c.T() << endl;
    Point d(3.4);
    cout << d.T() << endl;
    c = 5.6;
    cout << c.T() << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    d.seek();
    c.seek();
    const Point e(6, 7);
    e.seek();
    e.seek();
    e.seek();
    e.seek();
    e.s();
    return 0;
}
```



![image-20200726202545004](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726202545004.png)

![image-20200726202933371](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726202933371.png)

对象放在栈区，类放在堆区，全局是堆区



### 深拷贝与浅拷贝

```c++

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

class A {
public :
    A() {
        this->arr = new int[100];
    }
    A(const A &obj) : x(obj.x), y(obj.y) {
        this->arr = new int[100];
        memcpy(this->arr, obj.arr, sizeof(int) * 100);
    }
    int *arr;
    int x, y;
};

int main() {
    A a;
    a.x = 3, a.y = 6;
    a.arr[0] = 123;
    A b = a;
    b.arr[0] = 456;
    cout << a.arr[0] << " " << b.arr[0] << endl;
    cout << b.x << " " << b.y << endl;
    b.x = 6;
    cout << a.x << " " << a.y << endl;
    cout << b.x << " " << b.y << endl;
    return 0;
}
```

### 类型转换

```c++
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
```



### 返回值优化

![image-20200726210134448](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210134448.png)

![image-20200726210240902](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210240902.png)

![image-20200726210611028](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210611028.png)

![image-20200726210710988](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210710988.png)

![image-20200726210804996](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210804996.png)

![image-20200726210955727](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210955727.png)





```cpp
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


class People{
public:
    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
    }
private:
    string name;
};

People func() {
    People temp_a("fangsong");
    return temp_a;
}


int main() {
    People a = func();
    return 0;
}
```

```cpp
g++ -fno-elide-constructors//关闭优化
```

![image-20200726211911968](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726211911968.png)

### 运算符重载

![image-20200728181735933](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728181735933.png)

![image-20200727190130791](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727190130791.png)

```c++
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
```

```c++
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

class Point{
public:
    Point() : __x(0), __y(0){}
    Point(int x, int y) : __x(x), __y(y){}
    int x() const {return __x;}
    int y() const {return __y;}
    Point operator+(const Point &a) {
    /*this<---a
     * a<----b 
     */
    return Point(x() + a.x(), y() + a.y());
    }
    Point &operator+=(const Point &a) {
        __x += a.x();
        __y += a.y();
        return *this;
    }
    Point &operator++(){
        __x +=1;
        __y +=1;
        return *this;
    }
    Point operator++(int) {
        Point temp(*this);
        __x += 1;
        __y += 1;
        return temp;
    }
private:
    int __x, __y;
};

ostream &operator<<(ostream &out, const Point &a) {
    cout << "Point (" << a.x() << "," <<a.y() << ")";
    return out;
};



int main() {
    Point a(4, 5), b(3, 4), c(1, 1);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << a << " " << b << endl;
    cout << a + b << endl;
    cout << ++(c += b) << endl;
    cout << c << endl;
    cout << c++ << endl;
    cout << c << endl;
    int n = 6, m = 7;
    (n += m) ++;
    cout << n << endl;
    return 0;
}
```



```c++
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

class A{
public:
    A() {
        arr = new int[10];
    }
    A(const A &a) : A() {
        for(int i = 0; i < 10; i++) {
            this->arr[i] = a.arr[i];
        }
        this->x = a.x;
        this->y = a.y;
        return;
    }
    int x, y;
    int *arr;
};

class B{
public :
    B() : obj(nullptr) {
        arr = new int[10];
        arr[3] = 9973;
    }
    B(A *obj) : B() {
        this->obj = obj;
    }
    int operator() (int a, int b) {
        return a + b;
    }
    int &operator[](int ind) {
        return arr[ind];
    }
    void operator[](const char *msg) {
        cout << msg << endl;
        return;
    }
    A *operator->() {
        return obj;
    }
    A &operator*() {
        return *obj;
    }
    ~B() {
        delete arr;
    }
private:
    int *arr;
    A *obj;
};

ostream &operator <<(ostream &out, const A &a) {
    out << "A（" << a.x << " ," << a.y << ")" << endl;
    return out;
}

int main() {
    B add;
    cout << add(3, 4) << endl;
    cout << add[3] << endl;
    add[3] = 8876;
    cout << add[3] << endl;
    add["hello world"];

    A a, b(a);
    a.x = 67, a.y = 99;
    B p = &a;
    cout << p->x << " " << p->y << endl;
    cout << *p << endl;
    
    a.arr[3] = 9973;
    b.arr[3] = 6687;
    cout << a.arr[3] << endl;
    cout << b.arr[3] << endl;
    return 0;
}
```



## 继承

叫一声爸爸，开启财富之门

```c++
class Animal{
  public :
    string name() {retrun this->name;}
  private:
    string __name;
};
class Cat : public Animal {  
};
```

类与类之间的关系，在Animal中所有的属性和方法都包含在猫类中.

Cat是子类（派生类）

Animal是父类（基类）

![image-20200801150947920](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200801150947920.png)

### 继承-子类的访问权限

![image-20200727122409900](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727122409900.png)

|           | public                                            | protected                                         | private                                           |
| --------- | ------------------------------------------------- | ------------------------------------------------- | ------------------------------------------------- |
| public    | <button style="background-color:green">√</button> | <button style="background-color:green">√</button> | <button style="background-color:green">√</button> |
| protected | <button style="background-color:green">√</button> | <button style="background-color:green">√</button> | <button style="background-color:green">√</button> |
| private   | <button style="background-color:red">×</button>   | <button style="background-color:red">×</button>   | <button style="background-color:red">×</button>   |

当子类无论是这哪三个，都可以访问父类中的public, 与private;

它所影响的是外部对子类的访问权限-->

### 继承-对外的访问权限

子类从父类继承过来的权限对外的权限;

影响的外部对于子类继承父类的方法与属性的权限，这些方法与属性权限只能被压低不能被提升

|           |                public                |              protected               |             private              |
| :-------: | :----------------------------------: | :----------------------------------: | :------------------------------: |
|  public   |   <font color = blue>public</font>   | <font color = green>protected</font> | <font color = red>private</font> |
| protected | <font color = green>protected</font> | <font color = green>protected</font> | <font color = red>private</font> |
|  private  |       <font color=red>×</font>       |      <font color = red>×</font>      |    <font color = red>×</font>    |

子类继承过来的对外



```c++
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

class Animal {
public :
    Animal(){}
    Animal(string name, int age) : __name(name), age(age) {}
    void say() {
        cout << "my name is " << __name  << ", my age is " << age << endl;
    }

protected:
    string __name;


private:
    int age;
};


class Cat : public Animal{
public :
    Cat() = delete;
    Cat(string name, int age) : Animal(name, age){}
};

class Bat : protected Animal{
public: 
    Bat() = delete;
    Bat(string name, int age) : Animal(name, age){}
    void say() {
        this->Animal::say();
        cout << "class Bat : " << __name << endl;
        //cout << "class age : " << age <<endl; 不能访问
    }
};

int main() {
    Cat a("kitty", 29);
    a.say();
    Bat b("fsong", 16384);
    b.say();//不能直接访问say();
    return 0;
}
```



### 继承-构造函数

![image-20200727114849386](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727114849386.png)



调用基类的构造函数->调用成员对象的构造函数->调用自身的构造函数。

```cpp
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


class D {
public :
    D() {cout << "D constructor" << endl;}
    ~D() {
        cout << "D destructor" << endl;
    }
};

class A {
public :
    A() = delete;
    A(int x, int y) {cout << "A constructor" << endl;}
    ~A() {
        cout << "A destructor" << endl;
    }
};

class B {
    public :
    B() {cout << "B constructor" << endl;}
    ~B() {
        cout << "B destructor" << endl;
    }
    
};

class C : public D{
public :
    C() : a(3, 4) {cout << "C constructor" << endl;}
    ~C() {
        cout << "C destructor" << endl;
    }
private:
    B b; 
    A a;
};

int main() {
    C c;
    return 0;
}
```

```c++
D constructor
B constructor
A constructor
C constructor
C destructor
A destructor
B destructor
D destructor
```



### 菱形继承

![image-20200727125950494](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727125950494.png)

所以才引出：允许一个实体类，多个接口类

![image-20200801154342587](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200801154342587.png)

**指代不明**

```c
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

struct A{
    int x;
};

struct B : virtual public A{//解决菱形继承的问题使用virtual
    void set(int x) {
        this->x = x;
        cout << "set :" << &this->x << endl;
    }
};


struct C : virtual public A{
    int get() {
        cout << "get : " << &this->x << endl;
        return this->x;
    }
};

struct D : public B, public C{};

int main() {
    D d;
    cout << sizeof(d) << endl;
    d.set(9973);
    cout << d.get() << endl;
    return 0;
}
```

```
24
set :0x7fffc89da2c0
get : 0x7fffc89da2c0
9973
```

解决方法用virtual,　合并产生冲突的父亲类

![image-20200801154324483](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200801154324483.png)



### 继承下的拷贝构造

![image-20200727132324997](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727132324997.png)



```c++
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


class A {
public :
    A() {
        cout << "class A constuctor" << endl;
        this->x = 0x01020304;
    }
    A(const A &a) {
        cout << "class A copy constuctor : "<< this << endl;
    }
    int x;
};


class B : public A {
    /*头部存储父类相关的信息;
    * */
public :
    B() {
        this->y = 0x05060708;
        cout << "class B constuctor" << endl;
    }
    B(const B &b) : A(b) {
        cout <<  "class B copy constuctor : " << this << endl;
    }
    int y;
};

int main() {
    B b1;
    B b2(b1);
    const char *msg = (const char *)(&b1);
    for(int i = 0; i < sizeof(B); i++) {
        printf("%X", msg[i]);
    }
    
    return 0;
}
```



### string的简单实现

```c++
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
private:
    int __length, __buff_size;
    char *buff;
    char __end;
};

}

ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str() << endl;
    return out;
}


int main() {
    haizei::string s1 = "hello world", s2 = ", haizei", s3 = "harbin.";
    cout << s1 << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 <<endl;
    for(int i = 0; i < s1.size(); i++) {
       cout << s1[i] << endl; 
    }
    return 0;
}
```



## 多态

![image-20200801205542749](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200801205542749.png)

普通的成员跟着类走

虚函数跟着对象走

### 虚函数

虚函数是实现多态的最关键的手段

![image-20200730101858970](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200730101858970.png)

![image-20200730101843373](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200730101843373.png)

有虚函数时，就是调用的相关对象方法；c->run()调用的是Cat中的run方法了；

虚函数是跟着对象走的;如果有是个对象run，那么就会不知道是调用的哪个;

### 纯虚函数

![image-20200730103658301](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200730103658301.png)

纯虚函数类似接口；子类中必须得实现的方法;

![image-20200730110330489](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200730110330489.png)

### 虚函数与纯虚函数区别

虚函数声明后，子类可以不写此方法

纯虚函数声明后，子类必须写此方法

### 抽象类-{接口类}

抽象类不可能产生对象的类

抽象类也叫纯虚函数

![image-20200801184440129](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200801184440129.png)

![image-20200730104022429](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200730104022429.png)



![image-20200730105952288](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200730105952288.png)

![image-20200730110037077](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200730110037077.png)



### VIRTUAL关键字

![image-20200730110217384](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200730110217384.png)

因为类方法只能跟着类走;

override更加明确的告诉编译器覆盖父亲类的虚函数;起到报错作用.



父类中析构函数必须加virtual

```c++
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

class Animal{
public: 
    virtual void run() {
        cout << "I don't hnow how to run" << endl;
    }
};

class Cat : public Animal {
public :
    void run() override {
        cout << "I can run with four legs" << endl;
    }
};

class Dog : public Animal {
public :
    void run() override {
        cout << "I can run with four legs,yao~ yao~ yao~" << endl;
    }
};

class Bat : public Animal {
public :
    void run() override {
        cout << "I can fly" << endl;
    }
};


class A {
public :
    A() = default;
    A(string s) {
        cout << "param constructor" << endl;
    }
    A(const A &a) {
        cout << "copy constructor" << endl;
    }
    int x;
    virtual void say(int x) {
        cout << this << endl;
        cout << "class A : I can say, x = "<< x <<endl;
    }
};

typedef void (*func)(void *, int);

A retA() {
    A temp_a("hello world");
    return temp_a;
}


class Base{
    public :
    Base() {
        cout << "Base constructor" << endl;
        this->x = new int;
    }
    virtual ~Base() {//父类中析构函数必须加virtual
        cout << "Base destructor" << endl;
        delete[] this->x;
    }
    private:
    int *x;
};

class Base_A : public Base {
    public :
    Base_A() {
        cout << "Base_A constructor" << endl;
        this->y = new int;
    }
    ~Base_A() {
        cout << "Base_A destructor" << endl;
        delete this->y;
    }
    private:
    int *y;
};

int main() {
    Base *ba = new Base_A();
    delete ba;


    cout << sizeof(A) << endl;
    A temp_a, temp_b;
    temp_a.x = 9973;
    temp_b.x = 10000;
    temp_a.say(67);
    A temp_c = retA();
    ((func **)(&temp_a))[0][0](&temp_b, 6);
    srand(time(0));
    Cat a;
    Animal &b = a;
    Animal *c[10];
    cout << sizeof(Cat) << endl;

    for(int i = 0; i < 10; i++) {
        int op = rand() % 3;
        switch(op) {
            case 0:c[i] = new Cat();break;
            case 1:c[i] = new Dog();break;
            case 2:c[i] = new Bat();break;
        }
    }
    for(int i = 0; i < 10; i++) {
        c[i]->run();
    }
    return 0;
}

```



### 虚继承&final关键字



### 虚函数表

![image-20200730153051831](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200730153051831.png)

![image-20200801165115045](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200801165115045.png)

![image-20200801202134605](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200801202134605.png)

每个类对应着一张虚函数表







C++中一个类是公用一张虚函数表的，基类有基类的虚函数表，子类是子类的虚函数表，这极大的节省了内存

![image-20200801170308244](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200801170308244.png)

say前面有一个隐藏的this指针



### 实现哈希表

```c++
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

namespace haizei {//海贼

class IHashFunc {//自定义的哈希Func,用于继承
public :
    virtual int operator()(int) = 0;
};

class HashTable {
    typedef int (*HashFunc_T)(int);//对应函数
    typedef pair<int, int> PII;
public :
    HashTable(HashFunc_T);
    HashTable(IHashFunc &);
    int &operator[](int);

private:
    HashTable(HashFunc_T, IHashFunc *, int);
    int hash_type;//是1还是2
    HashFunc_T func1;//int 
    IHashFunc *func2;//虚函数的继承

    int __size;//长度大小
    PII **data;//存的值
};

HashTable::HashTable(HashFunc_T func1, IHashFunc *func2, int hash_type) 
: func1(func1), func2(func2), hash_type(hash_type) {//初始化哈希表
    this->__size = 1000;
    this->data = new PII*[this->__size];
    for (int i = 0; i < this->__size; i++) this->data[i] = nullptr;
}

HashTable::HashTable(HashFunc_T func) 
: HashTable(func, nullptr, 1) {}

HashTable::HashTable(IHashFunc &func) 
: HashTable(nullptr, &func, 2) {}


int &HashTable::operator[](int x) {//重载[]
    int hash = 0;
    switch (hash_type) {
        case 1: hash = func1(x); break;
        case 2: hash = (*func2)(x); break;
    }
    if (hash < 0) hash &= 0x7fffffff;
    int ind = hash % __size, t = 1;
    while (data[ind] && data[ind]->first != x) {
        ind += t * t;
        if (ind < 0) ind = ind & 0x7fffffff;
        ind %= __size;
        t += 1;
    }
    if (data[ind] == nullptr) data[ind] = new PII(x, 0);
    return data[ind]->second;
}

} // end of namespace haizei

int hash1(int x) {//普通函数
    return (x << 1) ^ (x << 3) ^ (x >> 5);
}

class MyHashFunc : public haizei::IHashFunc {//传参函数
public :
    int operator()(int x) override {
        return (x << 1) ^ (x << 3) ^ (x >> 5);
    }
};

int main() {
    MyHashFunc hash2;
    haizei::HashTable h1(hash1);
    haizei::HashTable h2(hash2);
    h1[123] = 345;
    h2[123] = 678;
    cout << h1[123] << endl;
    cout << h2[123] << endl;
    cout << h1[789] << endl;
    cout << h2[1000000] << endl;
    return 0;
}
```





### 类型转化

```c++
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

class A{
public:
    virtual ~A(){

    }
private:

};

class B:public A{
    public:
    void sayB() {
        cout << "this is class B, x = " << x  << endl;
    }
    int x;
};
class C:public A{
    public :
    void sayC() {
        cout << "this is class C, x = " << x << endl;
    }
    double x;
};
class D:public A{
    public :
    void sayD() {
        cout << "this is class D, x = " << x << endl;
    }
    string x;
};


int my_dynamic_cast(A *ta) {
    char  **pa = (char **)(ta);
    char  **pb = (char **)(new B());
    char  **pc = (char **)(new C());
    char  **pd = (char **)(new D());
    int ret = -1;
    if(pa[0] == pb[0]) ret = 0;
    else if(pa[0] == pc[0]) ret = 1;
    else if(pa[0] == pd[0]) ret = 2;
    return ret;
}

int main() {
    srand(time(0));
    A *pa;
    B *pb;
    C *pc;
    D *pd;
    switch(rand() % 3) {
        case 0 : pb = new B();pa = pb;pb->x = 123;break;
        case 1 : pc = new C();pa = pc;pc->x = 45.6;break;
        case 2 : pd = new D();pa = pd;pd->x = "hello haize";break;
    }
    if((pb = dynamic_cast<B *>(pa))) {
        cout << "Class B : ";
        pb->sayB();
    } else if((pc = dynamic_cast<C *>(pa))) {
        cout << "Class C : ";
        pc->sayC();
    } else if((pd = dynamic_cast<D *>(pa))) {
        cout << "Class D : ";
        pd->sayD();
    }

    switch(my_dynamic_cast(pa)) {
        case 0: ((B *)(pa))->sayB();break;
        case 1: ((C *)(pa))->sayC();break;
        case 2: ((D *)(pa))->sayD();break;
    }
    return 0;
}

```

##　总结与思考

![image-20200802185534116](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802185534116.png)

### auto关键字

不能用于：

函数参数

模板参数

定义数组

非静态成员变量

```c++
如果表达式为数组，且auto带上&，则推导出的类型为数组类型，如：
　　int32_t a[3] = {};
　　auto& arr = a;
　　std::cout <<typeid(arr).name() std::endl; // 这里输出int [3]
```

### constexpr关键字

编译期常量

![image-20200802190056679](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802190056679.png)

![image-20200802190131029](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802190131029.png)

12是编译期常量所以合法了



普通变量，修饰函数，构造函数

```c
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

constexpr int f(int x) {//修饰函数
    if(x == 1) return 1;
    return x * f(x - 1);
}

class A {
    public:
    constexpr A(int x,int y) : x(x), y(y) {}//修饰构造函数
    int x, y;
};

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    constexpr int m = f(12);
    cout << m << endl;
    constexpr A a(2, 3);
    cout << a.x << " "<< a.y << endl;
    return 0;
}
```

### final关键字

防止子类的相关覆盖重写，防止子类的继承

```c++
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
```

###　`nullptr`关键字

NULL在C++与Ｃ之间的区别

C++中NULL所带来的歧义：`func(int), func(int *)`

`nullptr`是空指针更准确的、无歧义的语义表达

nullptr是真正的空地址

NULL是一个强转的0//(void *)0

### override关键字

override更加明确的告诉编译器覆盖父亲类的虚函数; 起到报错作用.

```c++
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

int f(int x) {
    cout << "output int value : ";
    cout  << x << endl;
    return 0;
}

int f(int *x) {
    cout << "output address : ";
    cout << x << endl;
    return 0;
}

int main() {
    printf("%lld", (long long)(nullptr));
    //cout << nullptr << endl;
    //cout << NULL << endl;
    int n, *p = &n;
    f(n);
    f(p);
    f(nullptr);//<---- 地址
    f((int)NULL);//0 <---- 当成地址 (void *)0
    return 0;
}
```

### 右值引用

![image-20200802201837950](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802201837950.png)

![image-20200802202252159](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802202252159.png)



同样的变量，单一方式，同样的结果；

右值表临时；

![image-20200802205005586](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802205005586.png)



```c
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define TEST(a, f) { \
    cout << #a <<  " : " << #f << " "; \
    f(a); \
}

void f2(int &x) {//左值引用
    cout << "left value" << endl;
}

void f2(int &&x) {//右值引用
    cout << "right value" << endl;
}

void f(int &x) {
    cout << "left value" << endl;
    TEST(move(x), f2);
}

void f(int &&x) {
    cout << "right value" << endl;
    //TEST(forward<int &&>(x), f2);//强制将x的属性传递下去
    TEST(move(x), f2);//强制转换为右值传递下去
}

int main() {
    int a, b = 1, c = 3;
    (++a) = b + c;
    cout << a << endl;
    (a++);
    (a = b) = c;
    cout << a << " " << b << endl;
    int arr[10];
    arr[3] = 12;
    (a += 3) = 67;
    cout << a << endl;
    TEST(a += 3, f);
    TEST(1 + 4, f);
    TEST(b + c, f);
    TEST(a++, f);
    TEST(++a, f);
    return 0;
}
```

区分处理流程，速度提升

#### 移动构造拷贝

```cpp
    string(const string &s): __length(s.__length){
        cout << "copy constructor" << endl;
        this->__buff_size = s.__buff_size;        
        this->buff = new char[s.__buff_size];
        strcpy(this->buff, s.buff);
    }

    string (string &&s) { //O(1)，用于匿名变量直接的拷贝，把要释放的临时空间直接做成需要开辟的空间
        cout<< "move constructor" << endl;
        this->__buff_size = s.__buff_size;
        this->__length = s.__length;
        this->buff = s.buff;
        s.buff = nullptr;
    }
```

```c
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
    string(string &&s){//用于匿名变量直接的拷贝，把要释放的临时空间直接做成需要开辟的空间
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
```





## 模板

程序=算法＋数据结构

数据机构：能够存储任意类型

算法：能够操作存储任意类型数据结构

### 泛型编程

|              | 泛型编程           |
| ------------ | ------------------ |
| 面向过程编程 | 用模板实现函数过程 |
| 面向对象编程 | 用模板实现类       |

###　模板

#### 模板函数

```c++
template<typename T>
T add(T a, T b) {
    cout << "add function : " << sizeof(T) << endl;
    return a + b;
}
/*
int add(int a, int b) {
    cout << "add function : " << sizeof(T) << endl;
    return a + b; 
}
*/
int main() {
    cout << add(2, 3) << endl;//当传入2, 3时此时模板会生成上面注释的那些代码,替换成真正存在的类型，模板帮我们生成相关的代码，真正编译的时候，模板没有任何作用。类似宏定义，但是比宏强大的多，模板类型抽象，代码逻辑；
    cout << add(3.5, 6.7) << endl;
}
```

**问题一、**

![image-20200803155855361](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200803155855361.png)

![image-20200803155916241](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200803155916241.png)

怎么解决32行问题，我们可以将32行转为double类型就不会报错了：
![image-20200803160102330](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200803160102330.png)

**问题二、**

同样类型的模板是不是调用的同一个模板产出的代码呢 ? 验证

```cpp
template<typename T>
T add(T a, T b) {
    cout << "add function : " << sizeof(T) << endl;
    static int i = 0;
    cout <<"i : "<< (++i) << endl;
    return a + b;
}
int main() {
    cout << add(2, 3) << endl;//隐式推导
    cout << add(2.3, 4.5) << endl;
    cout << add<double>(2.3, 3) << endl;//显式推导，与上一行调用同一个模板扩展出来的代码

    return 0;
}
```

>add function : 4
>i : 1
>5
>add function : 8
>i : 1
>6.8
>add function : 8
>i : 2
>5.3

有结果可知，调用同一个模板扩展出来的代码，例子中两个double可以看出，模板只是制造作用

#### `decltype`推导类型

```cpp
template<class T, class U>
decltype(T() + U()) add(T a, U b) {
    return a + b;
}
```





#### 模板类

```c++
template<typename T>
struct PrintAny{
    PrintAny(std::ostream &out) : out(out) {}
    void operator()(const T &a) {
        out << a;
    }
    std::ostream &out;
};
```

```c++
template<typename T>
class Array {
public:
    Array(int n) : n(n) {
        this->arr = new T[n];
    }
    T &operator[](int ind) {
        if(ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];    
    }
    template<typename U>
    friend ostream &operator<< (ostream &, const Array<U> &);
private:
    T *arr;
    T __end;
    int n;
};

template<typename T>
ostream &operator<<(ostream &out, const Array<T> &a) {//重载输出
    out << "Class Array : ";
    for(int i = 0; i < a.n; i++) {
        out << a.arr[i] << " " << endl;
    }
    return out;
}

int main() {
    Array<int>a(10);//模板类
    Array<double> b(10);
    a[0] = 123;
    a[-123] = 456;
    for(int i = 0; i < 10; i++) {
        b[i] = (rand() % 100)/100.0;
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}

```

1. 类内

```c
class PrintAny {
public:
    template<typename T>
    void operator()(const T &a) {
        cout << a << endl;
    }
};
PrintAny print3;//不用<int>
PrintAny print4;
PrintAny print5;
```

2. 类外

```c
template<typename T>
class PrintAny {
public:
    void operator()(const T &a) {
        cout << a << endl;
    }
};
PrintAny<int> print1;//用<int>

```

在实例化的时候会生成代码：

![image-20200806150053846](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200806150053846.png)



![image-20200806152525179](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200806152525179.png)



模板在编译的时候进行展开，实例化出来的是具体的方法具体的类，在编译阶段的事情在链接阶段对重复的合并。



template.h

```c
#ifndef _TEMPLATE_H
#define _TEMPLATE_H
template<typename T>
T add(T a, T b) {
    return a + b;
}
int func();
#endif
```

test1.cpp

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include"template.h"
using namespace std;
int main() {
    cout << add(2, 3) << endl;
    return 0;
}
```

test2.cpp

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include"template.h"

int func() {
    return add(123, 456);
}
```

gcc -c test1.cpp//生成了test1.o

gcc -c test2.cpp//生成了test2.o

gcc test1.o test2.o//链接在一起

nm -C test1.o //看生成的目标程序

>1.预处理 选项 gcc -E test.c -o test.c
>
>预处理完成就停下来，产生结果放在test.i文件中。
>
>2.编译 选项 gcc -S test.c
>
>编译完成之后就停下来，结果保存在test.s中。
>
>3.编译 gcc -C test.c
>
>汇编完成之后就停下来，结果保存在test.o中。



#### 模板类＋模板函数

```c++
template<typename T>
struct Print{
    template<typename U>
    void operator()(const U &a) {
        cout << a << endl;
        cout << this->__temp << endl;
    }
    void set(const T &temp) {this->__temp = temp;}
    T __temp;
};
```

### 模板的特化与偏特化

#### 特化

![image-20200802112825838](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802112825838.png)

![image-20200802113014638](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802113014638.png)![image-20200802113041379](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802113041379.png)

```c++
template<>
int add(int a, int b) {
    cout << "specific template add function" << endl;
    return a + b;
}
```

```cpp
template<>
class Array<double> {
public:
    Array(int n) : n(n) {
        cout << "double array template" << endl;
        this->arr = new double[n];
    }
    double &operator[](int ind) {
        if(ind < 0 || ind >= n) return this->__end;
        return this->arr[ind];    
    }
    template<typename T>
    friend ostream &operator<<(ostream &, const Array<T> &);
private:
    double *arr;
    double __end;
    int n;
};
```

对某些特定的类型进行特化版本的书写；



#### add实现

```cpp
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

class A{
    public:
    A(int x) : x(x) {}
    int x;
};
class B{
    public:
    B(int y) : y(y) {}
    int y;
};
int operator+(const A &a, const B &b) {
    return a.x + b.y;
}


template<class T, class U>
auto add(T a, U b) -> decltype(a + b) {//推导返回值类型，解决类对象相加问题
    return a + b;
}


int main() {
    A a(1000);
    B b(645);
    cout << a + b << endl;
    cout << add(2, 3) << endl;//隐式推导
    cout << add(3.5, 4.5) << endl;
    cout << add<double>(4, 5.5) << endl;//显式推导
    cout << add(a, b) << endl;
    
    cout << max(4, 3) << endl;
    cout << max<double>(4.3, 3) << endl;//标准库中的一个bug解决

    return 0;
}

```



####　偏特化

![image-20200802113324083](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802113324083.png)

任意类型的指针类型

```cpp
template<typename T>
T add(T *a, T *b) {
    cout << "T * add function" << endl;
    return *a + *b;//有问题的
}
int main() {
int a_num = 123, b_num = 456;
cout << add(&a_num, &b_num) << endl;
}
```

```cpp
template<class T, class U>//类偏特化
auto add(T *a, U *b) -> decltype(*a + *b) {
    return add(*a, *b);//未解决二维指针问题
}

template<>
int add(int a, int b) {//特化
    cout << "add int : " <<a <<" "<< b <<  endl;
    return a + b;
}
```





#### 可变参模板

```c++
template<typename T, typename ...ARGS>
void Print (const T &a, ARGS... args) {
    cout << a << endl;
    Print(args...);
}
```

代码讲解: `ARGS`代表模板中剩余部分的类型数量是可变的，但是最少为１个，此代码会递归展开模板函数`Print`

![image-20200802115107542](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802115107542.png)

![image-20200802115157228](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802115157228.png)



![image-20200802123438900](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802123438900.png)

```c
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

template<typename T>
void print(const T &a) {
    cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;
}

template<int n, typename T, typename ...ARGS> 
struct ARG {
    typedef typename ARG<n - 1, ARGS...> ::getT getT;
    typedef ARG<n - 1, ARGS...> N;
};

template<typename T, typename ...ARGS>
struct ARG<0, T, ARGS...>{
    typedef T getT;
};

template<typename T>
struct ARG<0, T> {
    typedef T getT;
    typedef T finalT;
};

template<typename T, typename ...ARGS> class Test;
template<typename T, typename ...ARGS>
class Test<T(ARGS...)>{
public:
    T operator()(typename ARG<0, ARGS...>::getT a, typename ARG<1, ARGS...>::N::finalT b) {
        return a + b;
    }
};

int main() {
    print(123, "hello world", 78, 1.05);
    Test<int(double, float)> e;
    cout << e(2.3, 4.5) << endl;
    return 0;
}
```

