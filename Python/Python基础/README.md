[TOC]

## Python基础

根据[jackfrued/Python-100-Days](https://github.com/jackfrued/Python-100-Days/blob/master/)学习总结

### Python简介

>Python 被称为“胶水”语言，可以同其他语言粘合着用。

#### Python的历史

>1. 1989年圣诞节：Guido von Rossum开始写Python语言的编译器。
>2. 1991年2月：第一个Python编译器（同时也是解释器）诞生，它是用C语言实现的（后面），可以调用C语言的库函数。在最早的版本中，Python已经提供了对“类”，“函数”，“异常处理”等构造块的支持，还有对列表、字典等核心数据类型，同时支持以模块为基础来构造应用程序。
>3. 1994年1月：Python 1.0正式发布。
>4. 2000年10月16日：Python 2.0发布，增加了完整的[垃圾回收](https://zh.wikipedia.org/wiki/垃圾回收_(計算機科學))，提供了对[Unicode](https://zh.wikipedia.org/wiki/Unicode)的支持。与此同时，Python的整个开发过程更加透明，社区对开发进度的影响逐渐扩大，生态圈开始慢慢形成。
>5. 2008年12月3日：Python 3.0发布，它并不完全兼容之前的Python代码，不过因为目前还有不少公司在项目和运维中使用Python 2.x版本，所以Python 3.x的很多新特性后来也被移植到Python 2.6/2.7版本中。

目前我们使用的`Python 3.7.x`的版本是在2018年发布的，Python的版本号分为三段，形如A.B.C。其中A表示大版本号，一般当整体重写，或出现不向后兼容的改变时，增加A；B表示功能更新，出现新功能时增加B；C表示小的改动（例如：修复了某个Bug），只要有修改就增加C。如果对Python的历史感兴趣，可以阅读名为[《Python简史》](http://www.cnblogs.com/vamei/archive/2013/02/06/2892628.html)的网络文章。

#### Python的优缺点

>Python的优点很多，简单的可以总结为以下几点。
>
>1. 简单明了，学习曲线低，比很多编程语言都容易上手。
>2. 开放源代码，拥有强大的社区和生态圈，尤其是在数据分析和机器学习领域。
>3. 解释型语言，天生具有平台可移植性，代码可以工作于不同的操作系统。
>4. 对两种主流的编程范式（面向对象编程和函数式编程）都提供了支持。
>5. 代码规范程度高，可读性强，适合有代码洁癖和强迫症的人群。
>
>Python的缺点主要集中在以下几点。
>
>1. 执行效率稍低，对执行效率要求高的部分可以由其他语言（如：C、C++）编写。
>2. 代码无法加密，但是现在很多公司都不销售卖软件而是销售服务，这个问题会被弱化。
>3. 在开发时可以选择的框架太多（如Web框架就有100多个），有选择的地方就有错误。

#### Python的应用领域

>目前Python在Web应用后端开发、云基础设施建设、DevOps、网络数据采集（爬虫）、自动化测试、数据分析、机器学习等领域都有着广泛的应用。运维－>自动化，人工智能，大数据处理，游戏开发。

### 安装Python解释器

>想要开始Python编程之旅，首先得在自己使用的计算机上安装Python解释器环境，下面将以安装官方的Python解释器为例，讲解如何在不同的操作系统上安装Python环境。官方的Python解释器是用C语言实现的，也是使用最为广泛的Python解释器，通常称之为CPython。除此之外，Python解释器还有Java语言实现的Jython、C#语言实现的IronPython以及PyPy、Brython、Pyston等版本，有兴趣的读者可以自行了解。

#### Windows环境

>可以在[Python官方网站](https://www.python.org/)下载到Python的Windows安装程序（exe文件），需要注意的是如果在Windows 7环境下安装Python 3.x，需要先安装Service Pack 1补丁包（可以通过一些工具软件自动安装系统补丁的功能来安装），安装过程建议勾选“Add Python 3.x to PATH”（将Python 3.x添加到PATH环境变量）并选择自定义安装，在设置“Optional Features”界面最好将“pip”、“tcl/tk”、“Python test suite”等项全部勾选上。强烈建议选择自定义的安装路径并保证路径中没有中文。安装完成会看到“Setup was successful”的提示。如果稍后运行Python程序时，出现因为缺失一些动态链接库文件而导致Python解释器无法工作的问题，可以按照下面的方法加以解决。
>
>如果系统显示api-ms-win-crt*.dll文件缺失，可以参照[《api-ms-win-crt*.dll缺失原因分析和解决方法》](https://zhuanlan.zhihu.com/p/32087135)一文讲解的方法进行处理或者直接在[微软官网](https://www.microsoft.com/zh-cn/download/details.aspx?id=48145)下载Visual C++ Redistributable for Visual Studio 2015文件进行修复；如果是因为更新Windows的DirectX之后导致某些动态链接库文件缺失问题，可以下载一个[DirectX修复工具](https://dl.pconline.com.cn/download/360074-1.html)进行修复。

#### Linux环境

Linux环境自带了Python 2.x版本，但是如果要更新到3.x的版本，可以在[Python的官方网站](https://www.python.org/)下载Python的源代码并通过源代码构建安装的方式进行安装，具体的步骤如下所示（以CentOS为例）。

1. 安装依赖库（因为没有这些依赖库可能在源代码构件安装时因为缺失底层依赖库而失败）。

```shell
yum -y install wget gcc zlib-devel bzip2-devel openssl-devel ncurses-devel sqlite-devel readline-devel tk-devel gdbm-devel db4-devel libpcap-devel xz-devel libffi-devel
```

2. 下载Python源代码并解压缩到指定目录。

```
wget https://www.python.org/ftp/python/3.7.6/Python-3.7.6.tar.xz
xz -d Python-3.7.6.tar.xz
tar -xvf Python-3.7.6.tar
```

3. 切换至Python源代码目录并执行下面的命令进行配置和安装。

```
cd Python-3.7.6
./configure --prefix=/usr/local/python37 --enable-optimizations
make && make install
```

4. 修改用户主目录下名为.bash_profile的文件，配置PATH环境变量并使其生效。

```
cd ~
vim .bash_profile
# ... 此处省略上面的代码 ...

export PATH=$PATH:/usr/local/python37/bin

# ... 此处省略下面的代码 ...
```

5. 激活环境变量。

```
source .bash_profile
```

`切换版本：`

Ubantu中默认python路径:

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggilw800fvj30m007mgna.jpg)

首先我们先看一下有没有关于Python的可选项：

```
$ update-alternatives --display pythonupdate-alternatives: 错误: 无 python 的候选项
```

那首先先建立python的组,并添加Python2和Python3的可选项

```
$ sudo update-alternatives --install /usr/bin/python python /usr/bin/python2.7 2 # 添加Python2可选项，优先级为2$ sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.4 1 #添加Python3可选项，优先级为1
```

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggilkrz1hsj30m607njt2.jpg)

### 保留字

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggio2xutbdj30qk06pq5l.jpg)

### 标识符

1. 不能用Pthon中的保留字
2. 由字母，下划线，数字
3. 区分大小写字母
4. `__add`表示类的私有成员;
5. `__init__()`构造函数;

### 变量

变量的定义与使用

弱类型(动态类型语言):

```python
>>> print(a)
123
>>> type(a)
<class 'int'>
>>> a = "hello world"
>>> print(a)
hello world
>>> type(a)
<class 'str'>
>>> id(a) #地址
139811477572656
>>> a = 123
>>> id(a)
9306048
>>> id(123)
9306048
>>> id(123)
9306048
>>> b = 123
>>> id(b)
9306048
>>> id("hello world")
139811477572656
>>> a = "hello world"
>>> id(a)
139811477572656
>>> 
```

### 变量和类型

在程序设计中，变量是一种存储数据的载体。计算机中的变量是实际存在的数据或者说是存储器中存储数据的一块内存空间，变量的值可以被读取和修改，这是所有计算和控制的基础。计算机能处理的数据有很多种类型，除了数值之外还可以处理文本、图形、音频、视频等各种各样的数据，那么不同的数据就需要定义不同的存储类型。Python中的数据类型很多，而且也允许我们自定义新的数据类型（这一点在后面会讲到），我们先介绍几种常用的数据类型。

- 整型：Python中可以处理任意大小的整数（Python 2.x中有`int`和`long`两种类型的整数，但这种区分对Python来说意义不大，因此在Python 3.x中整数只有int这一种了），而且支持二进制（如`0b100`，换算成十进制是4）、八进制（如`0o100`，换算成十进制是64）、十进制（`100`）和十六进制（`0x100`，换算成十进制是256）的表示法。
- 浮点型：浮点数也就是小数，之所以称为浮点数，是因为按照科学记数法表示时，一个浮点数的小数点位置是可变的，浮点数除了数学写法（如`123.456`）之外还支持科学计数法（如`1.23456e2`）。
- 字符串型：字符串是以单引号或双引号括起来的任意文本，比如`'hello'`和`"hello"`,字符串还有原始字符串表示法、字节字符串表示法、Unicode字符串表示法，而且可以书写成多行的形式（用三个单引号或三个双引号开头，三个单引号或三个双引号结尾）。
- 布尔型：布尔值只有`True`、`False`两种值，要么是`True`，要么是`False`，在Python中，可以直接用`True`、`False`表示布尔值（请注意大小写），也可以通过布尔运算计算出来（例如`3 < 5`会产生布尔值`True`，而`2 == 1`会产生布尔值`False`）。
- 复数型：形如`3+5j`，跟数学上的复数表示一样，唯一不同的是虚部的`i`换成了`j`。实际上，这个类型并不常用，大家了解一下就可以了。



```python
a = int(input('a = '))
b = int(input('b = '))
print('%d + %d = %d' % (a, b, a + b))
print('%d - %d = %d' % (a, b, a - b))
print('%d * %d = %d' % (a, b, a * b))
print('%d / %d = %f' % (a, b, a / b))#精确值
print('%d // %d = %d' % (a, b, a // b))#取整
print('%d %% %d = %d' % (a, b, a % b))#取余
print('%d ** %d = %d' % (a, b, a ** b))#幂次方
```

### 运算符

Python支持多种运算符，下表大致按照优先级从高到低的顺序列出了所有的运算符，运算符的优先级指的是多个运算符同时出现时，先做什么运算然后再做什么运算。除了我们之前已经用过的赋值运算符和算术运算符，我们稍后会陆续讲到其他运算符的使用。

| 运算符                                          | 描述                           |
| ----------------------------------------------- | ------------------------------ |
| `[]` `[:]`                                      | 下标，切片                     |
| `**`                                            | 指数                           |
| `~` `+` `-`                                     | 按位取反, 正负号               |
| `*` `/` `%` `//`                                | 乘，除，模，整除               |
| `+` `-`                                         | 加，减                         |
| `>>` `<<`                                       | 右移，左移                     |
| `&`                                             | 按位与                         |
| `^` `|`                                         | 按位异或，按位或               |
| `<=` `<` `>` `>=`                               | 小于等于，小于，大于，大于等于 |
| `==` `!=`                                       | 等于，不等于                   |
| `is` `is not`                                   | 身份运算符                     |
| `in` `not in`                                   | 成员运算符                     |
| `not` `or` `and`                                | 逻辑运算符                     |
| `=` `+=` `-=` `*=` `/=` `%=` `//=` `**=` `&=` ` | =` `^=` `>>=` `<<=`            |

> **说明：** 在实际开发中，如果搞不清楚运算符的优先级，可以使用括号来确保运算的执行顺序。

### if语句的使用

在Python中，要构造分支结构可以使用`if`、`elif`和`else`关键字。所谓**关键字**就是有特殊含义的单词，像`if`和`else`就是专门用于构造分支结构的关键字，很显然你不能够使用它作为变量名（事实上，用作其他的标识符也是不可以）。下面的例子中演示了如何构造一个分支结构。

### while循环

```python
import random

answer = random.randint(1, 100)
counter = 0
while True:
    counter += 1
    number = int(input('请输入: '))
    if number < answer:
        print('大一点')
    elif number > answer:
        print('小一点')
    else:
        print('恭喜你猜对了!')
        break
print('你总共猜了%d次' % counter)
if counter > 7:
    print('你的智商余额明显不足')
```

### for-in循环

如果明确的知道循环执行的次数或者要对一个容器进行迭代（后面会讲到），那么我们推荐使用`for-in`循环，例如下面代码中计算1~100求和的结果（$\displaystyle\sum \limits_{n=1}^{100}n$）。

```python
sum = 0
for x in range(101):
    sum += x
print(sum)
```

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggkzxjash4j30o00bmta8.jpg)

- `range(101)`：可以用来产生0到100范围的整数，需要注意的是取不到101。
- `range(1, 101)`：可以用来产生1到100范围的整数，相当于前面是闭区间后面是开区间。
- `range(1, 101, 2)`：可以用来产生1到100的奇数，其中2是步长，即每次数值递增的值。
- `range(100, 0, -2)`：可以用来产生100到1的偶数，其中-2是步长，即每次数字递减的值。

### 序列

序列加法：将两种相同类型的序列加法（合并）

```python
>>> a = "hello world"
>>> type(a)
<class 'str'>
>>> a = list(a)
>>> type(a)
<class 'list'>
>>> print(a)
['h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd']
>>> a = tuple(a)
>>> print(a)
('h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd')
>>> a = set(a)
>>> print(a)
{' ', 'l', 'w', 'r', 'e', 'h', 'd', 'o'}
>>> 
```



|          | 列表 | 元组 | 字典 | 集合 |
| -------- | ---- | ---- | ---- | ---- |
|          | []   | ()   | {}   | {}   |
| 是否可变 | √    | ×    | √    | √    |
| 是否重复 | √    | √    | ×    | ×    |
| 是否有序 | √    | √    | ×    | ×    |



#### 列表

接下来我们要介绍的列表（`list`），也是一种结构化的、非标量类型，它是值的有序序列，每个值都可以通过索引进行标识，定义列表可以将列表的元素放在`[]`中，多个元素用`,`进行分隔，可以使用`for`循环对列表元素进行遍历，也可以使用`[]`或`[:]`运算符取出列表中的一个或多个元素。

如何定义列表、如何遍历列表以及列表的下标运算。

```python
list1 = [1, 3, 5, 7, 100]
print(list1) # [1, 3, 5, 7, 100]
# 乘号表示列表元素的重复
list2 = ['hello'] * 3
print(list2) # ['hello', 'hello', 'hello']
# 计算列表长度(元素个数)
print(len(list1)) # 5
# 下标(索引)运算
print(list1[0]) # 1
print(list1[4]) # 100
# print(list1[5])  # IndexError: list index out of range
print(list1[-1]) # 100
print(list1[-3]) # 5
list1[2] = 300
print(list1) # [1, 3, 300, 7, 100]
# 通过循环用下标遍历列表元素
for index in range(len(list1)):
    print(list1[index])
# 通过for循环遍历列表元素
for elem in list1:
    print(elem)
# 通过enumerate函数处理列表之后再遍历可以同时获得元素索引和值
for index, elem in enumerate(list1):
    print(index, elem)
```

如何向列表中添加元素以及如何从列表中移除元素。

```python
list1 = [1, 3, 5, 7, 100]
# 添加元素
list1.append(200)
list1.insert(1, 400)
# 合并两个列表
# list1.extend([1000, 2000])
list1 += [1000, 2000]
print(list1) # [1, 400, 3, 5, 7, 100, 200, 1000, 2000]
print(len(list1)) # 9
# 先通过成员运算判断元素是否在列表中，如果存在就删除该元素
if 3 in list1:
	list1.remove(3)
if 1234 in list1:
    list1.remove(1234)
print(list1) # [1, 400, 5, 7, 100, 200, 1000, 2000]
# 从指定的位置删除元素
list1.pop(0)
list1.pop(len(list1) - 1)
print(list1) # [400, 5, 7, 100, 200, 1000]
# 清空列表元素
list1.clear()
print(list1) # []
```

和字符串一样，列表也可以做切片操作，通过切片操作我们可以实现对列表的复制或者将列表中的一部分取出来创建出新的列表，代码如下所示。

```python
fruits = ['grape', 'apple', 'strawberry', 'waxberry']
fruits += ['pitaya', 'pear', 'mango']
# 列表切片
fruits2 = fruits[1:4]
print(fruits2) # apple strawberry waxberry
# 可以通过完整切片操作来复制列表
fruits3 = fruits[:]
print(fruits3) # ['grape', 'apple', 'strawberry', 'waxberry', 'pitaya', 'pear', 'mango']
fruits4 = fruits[-3:-1]
print(fruits4) # ['pitaya', 'pear']
# 可以通过反向切片操作来获得倒转后的列表的拷贝
fruits5 = fruits[::-1]
print(fruits5) # ['mango', 'pear', 'pitaya', 'waxberry', 'strawberry', 'apple', 'grape']
```

下面的代码实现了对列表的排序操作。

```python
list1 = ['orange', 'apple', 'zoo', 'internationalization', 'blueberry']
list2 = sorted(list1)
# sorted函数返回列表排序后的拷贝不会修改传入的列表
# 函数的设计就应该像sorted函数一样尽可能不产生副作用
list3 = sorted(list1, reverse=True)
# 通过key关键字参数指定根据字符串长度进行排序而不是默认的字母表顺序
list4 = sorted(list1, key=len)
print(list1)
print(list2)
print(list3)
print(list4)
# 给列表对象发出排序消息直接在列表对象上进行排序
list1.sort(reverse=True)
print(list1)
```

变成字典

```python
>>> for index, item in enumerate(num):
...     print(index, item)
... 
0 0
1 2
2 4
3 6
4 8
5 10
```

扩容：

```python
>>> print(num)
[0, 2, 4, 6, 8, 10]
>>> num.append("fangsong")
>>> print(num)
[0, 2, 4, 6, 8, 10, 'fangsong']
>>> list1 = ["帅", "能力强", "高", "富"]
>>> num.extend(list1)
>>> print(num)
[0, 2, 4, 6, 8, 10, 'fangsong', '帅', '能力强', '高', '富']
>>> 
```

删除等

```python
>>> num.remove(6)
>>> print(num)
[2, 4, 8, 10, 'fangsong', '帅', '能力强', '高', '富']
>>> num.remove('fangsong')
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富']
>>> num.append(5)
>>> num.append(5)
>>> num.append(5)
>>> num.append(5)
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富', 5, 5, 5, 5]
>>> num.remove(5)
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富', 5, 5, 5]
>>> num.remove(5)
>>> num.remove(5)
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富', 5]
>>> num.append(5)
>>> num.append(5)
>>> num.count(5)
3
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富', 5, 5, 5]
>>> 
```

随机列表:

```python
>>> import random
>>> randnum = [random.randint(10, 100) for i in range(10)]
>>> print(randnum)
[15, 26, 24, 14, 80, 40, 84, 32, 16, 93]
>>> print(randnum)
[15, 26, 24, 14, 80, 40, 84, 32, 16, 93]
>>> randnum = [random.randint(10, 100) for i in range(10)]
>>> print(randnum)
[60, 92, 89, 83, 37, 80, 43, 79, 54, 76]
>>> 
```

列表推导式:

newlist = [Expression for var in list]

```python
>>> num2 = [i for i in num if isinstance(i, int)]
>>> print(num2)
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100]
>>> 

```





#### 元组

比列表访问和处理速度快

Python的元组与列表类似，不同之处在于元组的元素不能修改。元组使⽤⼩括号，列表使⽤⽅括号。

```python
>>> string = "hello world"
>>> string = tuple(string)
>>> type(string)
<class 'tuple'>
>>> string
('h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd')
>>> 
```

![img](https://github.com/jackfrued/Python-100-Days/raw/master/Day01-15/res/ipython-timeit.png)

1. 访问元祖

   ```python
   >>> tuple=('hello', 100, 3.14)
   >>> tuple[0]
   'hello'
   >>> tuple[1]
   100
   >>> tuple[2]
   3.14
   ```

2. 修改元祖

   ```python
   >>> tuple[2] = 180
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   TypeError: 'tuple' object does not support item assignment
   >>> 
   
   
   >>> p = (1, 2)
   >>> p = (3, 4)
   >>> p
   (3, 4)
   >>> p = (3, 4, 5)
   >>> p
   (3, 4, 5)
   ```

   说明不能修改元素

3. count, index

   ```python
   >>> a = ('a', 'b', 'c', 'a', 'b')
   >>> a.index('a', 1, 3) # 注意是左闭右开区间
   Traceback (most recent call last):
       File "<stdin>", line 1, in <module>
   ValueError: tuple.index(x): x not in tuple
   >>> a.index('a', 1, 4)
   3
   >>> a.count('b')
   2
   >>> a.count('d')
   0
   ```

4. 比较

   如果比较的元素是同类型的,则比较其值,返回结果。

   如果两个元素不是同一种类型,则检查它们是否是数字。

   - 如果是数字,执行必要的数字强制类型转换,然后比较。
   - 如果有一方的元素是数字,则另一方的元素"大"(数字是"最小的")
   - 否则,通过类型名字的字母顺序进行比较。

   如果有一个列表首先到达末尾,则另一个长一点的列表"大"。

   如果我们用尽了两个列表的元素而且所 有元素都是相等的,那么结果就是个平局,就是说返回一个 0。

   ```python
   #!/usr/bin/python
   
   tuple1, tuple2 = (123, 'xyz'), (456, 'abc')
   
   print cmp(tuple1, tuple2);
   print cmp(tuple2, tuple1);
   tuple3 = tuple2 + (786,);
   print cmp(tuple2, tuple3)
   tuple4 = (123, 'xyz')
   print cmp(tuple1, tuple4)
   ```

   ```python
   -1
   1
   -1
   0
   ```

5. 长度

   以下实例展示了 len()函数的使用方法：

   ```python
   #!/usr/bin/python
   
   tuple1, tuple2 = (123, 'xyz', 'zara'), (456, 'abc')
   
   print "First tuple length : ", len(tuple1);
   print "Second tuple length : ", len(tuple2);
   ```

   以上实例输出结果如下：

   ```python
   First tuple length :  3
   Second tuple length :  2
   ```

6. Max

   以下实例展示了 max()函数的使用方法：

   ```python
   #!/usr/bin/python
   
   tuple1, tuple2 = (123, 'xyz', 'zara', 'abc'), (456, 700, 200)
   
   print "Max value element : ", max(tuple1);
   print "Max value element : ", max(tuple2);
   ```

   以上实例输出结果如下：

   ```
   Max value element :  zara
   Max value element :  700
   ```

#### 字典

类似哈希结构

字典是另一种可变容器模型，且可存储任意类型对象。

字典的每个键值 **key=>value** 对用冒号 **:** 分割，每个键值对之间用逗号 **,** 分割，整个字典包括在花括号 **{}** 中 ,格式如下所示：

>d = {key1 : value1, key2 : value2 }

```python
>>> num = {}
>>> type(num)
<class 'dict'> #类型
```

由两个list创建字典

```python
>>> list1 = list(range(10))
>>> list1
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> list2 = ["Marry", "shengdeng", "Zege"]
>>> list2
['Marry', 'shengdeng', 'Zege']
>>> dictionary = dict(zip(list1, list2))
>>> dictionary[0]
'Marry'
>>> dictionary[1]
'shengdeng'
>>> dictionary[2]
'Zege'
>>> dictionary[3]
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
KeyError: 3
>>> 

```



1. 访问字典中值

   ```python
   #!/usr/bin/python
    
   dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
    
   print "dict['Name']: ", dict['Name']
   print "dict['Age']: ", dict['Age']
   ```

   ```python
   dict['Name']:  Zara
   dict['Age']:  7
   ```

   如果用字典里没有的键访问数据，会输出错误如下：

   ```python
   #!/usr/bin/python
    
   dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
    
   print "dict['Alice']: ", dict['Alice']
   ```

   ```python
   dict['Alice']: 
   Traceback (most recent call last):
     File "test.py", line 5, in <module>
       print "dict['Alice']: ", dict['Alice']
   KeyError: 'Alice'
   ```

2. 修改字典

   ```python
   #!/usr/bin/python
    
   dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
    
   dict['Age'] = 8 # 更新
   dict['School'] = "RUNOOB" # 添加
    
    
   print "dict['Age']: ", dict['Age']
   print "dict['School']: ", dict['School']
   ```

   ```python
   dict['Age']:  8
   dict['School']:  RUNOOB
   ```

3. 删除字典元素

   能删单一的元素也能清空字典，清空只需一项操作。

   显示删除一个字典用del命令，如下实例：

   ```python
   #!/usr/bin/python
   # -*- coding: UTF-8 -*-
    
   dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
    
   del dict['Name']  # 删除键是'Name'的条目
   dict.clear()      # 清空字典所有条目
   del dict          # 删除字典
    
   print "dict['Age']: ", dict['Age'] 
   print "dict['School']: ", dict['School']
   ```

   但这会引发一个异常，因为用del后字典不再存在：

   ```python
   dict['Age']:
   Traceback (most recent call last):
     File "test.py", line 8, in <module>
       print "dict['Age']: ", dict['Age'] 
   TypeError: 'type' object is unsubscriptable
   ```

4. 字典键的特性

   1）不允许同一个键出现两次。创建时如果同一个键被赋值两次，后一个值会被记住，如下实例：

   ```python
   #!/usr/bin/python
    
   dict = {'Name': 'Zara', 'Age': 7, 'Name': 'Manni'} 
    
   print "dict['Name']: ", dict['Name']
   ```

   ```
   dict['Name']:  Manni
   ```

   2）键必须不可变，所以可以用数字，字符串或元组充当，所以用列表就不行，如下实例：

   ```python
   #!/usr/bin/python
    
   dict = {['Name']: 'Zara', 'Age': 7} 
    
   print "dict['Name']: ", dict['Name']
   ```

   ```
   Traceback (most recent call last):
     File "test.py", line 3, in <module>
       dict = {['Name']: 'Zara', 'Age': 7} 
   TypeError: list objects are unhashable
   
   
   ```

5. 内置方法

| 1    | [dict.clear()](https://www.runoob.com/python/att-dictionary-clear.html) 删除字典内所有元素 |
| ---- | ------------------------------------------------------------ |
| 2    | [dict.copy()](https://www.runoob.com/python/att-dictionary-copy.html) 返回一个字典的浅复制 |
| 3    | [dict.fromkeys(seq, val\)](https://www.runoob.com/python/att-dictionary-fromkeys.html) 创建一个新字典，以序列 seq 中元素做字典的键，val 为字典所有键对应的初始值 |
| 4    | [dict.get(key, default=None)](https://www.runoob.com/python/att-dictionary-get.html) 返回指定键的值，如果值不在字典中返回default值 |
| 5    | [dict.has_key(key)](https://www.runoob.com/python/att-dictionary-has_key.html) 如果键在字典dict里返回true，否则返回false |
| 6    | [dict.items()](https://www.runoob.com/python/att-dictionary-items.html) 以列表返回可遍历的(键, 值) 元组数组 |
| 7    | [dict.keys()](https://www.runoob.com/python/att-dictionary-keys.html) 以列表返回一个字典所有的键 |
| 8    | [dict.setdefault(key, default=None)](https://www.runoob.com/python/att-dictionary-setdefault.html) 和get()类似, 但如果键不存在于字典中，将会添加键并将值设为default |
| 9    | [dict.update(dict2)](https://www.runoob.com/python/att-dictionary-update.html) 把字典dict2的键/值对更新到dict里 |
| 10   | [dict.values()](https://www.runoob.com/python/att-dictionary-values.html) 以列表返回字典中的所有值 |
| 11   | [pop(key,default\])](https://www.runoob.com/python/python-att-dictionary-pop.html) 删除字典给定键 key 所对应的值，返回值为被删除的值。key值必须给出。 否则，返回default值。 |
| 12   | [popitem()](https://www.runoob.com/python/python-att-dictionary-popitem.html) 返回并删除字典中的最后一对键和值。 |

[3].  [dict.fromkeys(seq, val\)](https://www.runoob.com/python/att-dictionary-fromkeys.html) 方法

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
seq = ('Google', 'Runoob', 'Taobao')
 
dict = dict.fromkeys(seq)
print "新字典为 : %s" %  str(dict)
 
dict = dict.fromkeys(seq, 10)
print "新字典为 : %s" %  str(dict)
```

```
新字典为 : {'Google': None, 'Taobao': None, 'Runoob': None}
新字典为 : {'Google': 10, 'Taobao': 10, 'Runoob': 10}
```

[4].[dict.get(key, default=None)](https://www.runoob.com/python/att-dictionary-get.html) 方法

```python
#!/usr/bin/python

dict = {'Name': 'Runoob', 'Age': 27}

print "Value : %s" %  dict.get('Age')
print "Value : %s" %  dict.get('Sex', "Never")
```

```
Value : 27
Value : Never
```

[5].[dict.has_key(key)](https://www.runoob.com/python/att-dictionary-has_key.html) 方法

```python
#!/usr/bin/python

dict = {'Name': 'Zara', 'Age': 7}

print "Value : %s" %  dict.has_key('Age')
print "Value : %s" %  dict.has_key('Sex')
```

```
Value : True
Value : False
```

[6].    [dict.items()](https://www.runoob.com/python/att-dictionary-items.html) 

```python
#!/usr/bin/python
# coding=utf-8
 
dict = {'Google': 'www.google.com', 'Runoob': 'www.runoob.com', 'taobao': 'www.taobao.com'}
 
print "字典值 : %s" %  dict.items()
 
# 遍历字典列表
for key,values in  dict.items():
    print key,values
```

```
字典值 : [('Google', 'www.google.com'), ('taobao', 'www.taobao.com'), ('Runoob', 'www.runoob.com')]
Google www.google.com
taobao www.taobao.com
Runoob www.runoob.com
```

[7].[dict.keys()](https://www.runoob.com/python/att-dictionary-keys.html)

```python
#!/usr/bin/python

dict = {'Name': 'Zara', 'Age': 7}

print "Value : %s" %  dict.keys()
```

```
Value : ['Age', 'Name']
```

#### 集合

自动去重

```python

```

Python中的集合跟数学上的集合是一致的，不允许有重复元素，而且可以进行交集、并集、差集等运算。

![img](https://github.com/jackfrued/Python-100-Days/raw/master/Day01-15/res/python-set.png)



可以按照下面代码所示的方式来创建和使用集合。

```python
# 创建集合的字面量语法
set1 = {1, 2, 3, 3, 3, 2}
print(set1)
print('Length =', len(set1))
# 创建集合的构造器语法(面向对象部分会进行详细讲解)
set2 = set(range(1, 10))
set3 = set((1, 2, 3, 3, 2, 1))
print(set2, set3)
# 创建集合的推导式语法(推导式也可以用于推导集合)
set4 = {num for num in range(1, 100) if num % 3 == 0 or num % 5 == 0}
print(set4)
```

向集合添加元素和从集合删除元素。

```python
set1.add(4)
set1.add(5)
set2.update([11, 12])
set2.discard(5)
if 4 in set2:
    set2.remove(4)
print(set1, set2)
print(set3.pop())
print(set3)
```

集合的成员、交集、并集、差集等运算。

```python
# 集合的交集、并集、差集、对称差运算
print(set1 & set2)
# print(set1.intersection(set2))
print(set1 | set2)
# print(set1.union(set2))
print(set1 - set2)
# print(set1.difference(set2))
print(set1 ^ set2)
# print(set1.symmetric_difference(set2))
# 判断子集和超集
print(set2 <= set1)
# print(set2.issubset(set1))
print(set3 <= set1)
# print(set3.issubset(set1))
print(set1 >= set2)
# print(set1.issuperset(set2))
print(set1 >= set3)
# print(set1.issuperset(set3))
```

> **说明：** Python中允许通过一些特殊的方法来为某种类型或数据结构自定义运算符（后面的章节中会讲到），上面的代码中我们对集合进行运算的时候可以调用集合对象的方法，也可以直接使用对应的运算符，例如`&`运算符跟intersection方法的作用就是一样的，但是使用运算符让代码更加直观。

#### 字符串

所谓**字符串**，就是由零个或多个字符组成的有限序列，一般记为[![$${\displaystyle s=a_{1}a_{2}\dots a_{n}(0\leq n \leq \infty)}$$](https://github.com/jackfrued/Python-100-Days/raw/master/Day01-15/res/formula_5.png)](https://github.com/jackfrued/Python-100-Days/blob/master/Day01-15/res/formula_5.png)。在Python程序中，如果我们把单个或多个字符用单引号或者双引号包围起来，就可以表示一个字符串。

```python
>>> string = "hello world"
>>> len(string)
11
>>> string = "我的名字"
>>> len(string)
4
>>> 
```

可以在字符串中使用`\`（反斜杠）来表示转义，也就是说`\`后面的字符不再是它原来的意义，例如：`\n`不是代表反斜杠和字符n，而是表示换行；而`\t`也不是代表反斜杠和字符t，而是表示制表符。所以如果想在字符串中表示`'`要写成`\'`，同理想表示`\`要写成`\\`。可以运行下面的代码看看会输出什么。

```python
>>> s1 = '\'hello, world!\''
>>> s2 = '\n\\hello, world!\\\n'
>>> print(s1, s2, end='')
'hello, world!' 
\hello, world!\
>>> 
```

在`\`后面还可以跟一个八进制或者十六进制数来表示字符，例如`\141`和`\x61`都代表小写字母`a`，前者是八进制的表示法，后者是十六进制的表示法。也可以在`\`后面跟Unicode字符编码来表示字符，例如`\u9a86\u660a`代表的是中文“骆昊”。运行下面的代码，看看输出了什么。

```python
s1 = '\141\142\143\x61\x62\x63'
s2 = '\u9a86\u660a'
print(s1, s2)
```

如果不希望字符串中的`\`表示转义，我们可以通过在字符串的最前面加上字母`r`来加以说明，再看看下面的代码又会输出什么。

```python
s1 = r'\'hello, world!\''
s2 = r'\n\\hello, world!\\\n'
print(s1, s2, end='')
```

Python为字符串类型提供了非常丰富的运算符，我们可以使用`+`运算符来实现字符串的拼接，可以使用`*`运算符来重复一个字符串的内容，可以使用`in`和`not in`来判断一个字符串是否包含另外一个字符串（成员运算），我们也可以用`[]`和`[:]`运算符从字符串取出某个字符或某些字符（切片运算），代码如下所示。

```python
s1 = 'hello ' * 3
print(s1) # hello hello hello 
s2 = 'world'
s1 += s2
print(s1) # hello hello hello world
print('ll' in s1) # True
print('good' in s1) # False
str2 = 'abc123456'
# 从字符串中取出指定位置的字符(下标运算)
print(str2[2]) # c
# 字符串切片(从指定的开始索引到指定的结束索引)
print(str2[2:5]) # c12
print(str2[2:]) # c123456
print(str2[2::2]) # c246
print(str2[::2]) # ac246
print(str2[::-1]) # 654321cba
print(str2[-3:-1]) # 45
```

在Python中，我们还可以通过一系列的方法来完成对字符串的处理，代码如下所示。

```python
str1 = 'hello, world!'
# 通过内置函数len计算字符串的长度
print(len(str1)) # 13
# 获得字符串首字母大写的拷贝
print(str1.capitalize()) # Hello, world!
# 获得字符串每个单词首字母大写的拷贝
print(str1.title()) # Hello, World!
# 获得字符串变大写后的拷贝
print(str1.upper()) # HELLO, WORLD!
#lower()转换为小写
# 从字符串中查找子串所在位置
print(str1.find('or')) # 8
print(str1.find('shit')) # -1
# 与find类似但找不到子串时会引发异常
# print(str1.index('or'))
# print(str1.index('shit'))
# 检查字符串是否以指定的字符串开头
print(str1.startswith('He')) # False
print(str1.startswith('hel')) # True
# 检查字符串是否以指定的字符串结尾
print(str1.endswith('!')) # True
# 将字符串以指定的宽度居中并在两侧填充指定的字符
print(str1.center(50, '*'))
# 将字符串以指定的宽度靠右放置左侧填充指定的字符
print(str1.rjust(50, ' '))
str2 = 'abc123456'
# 检查字符串是否由数字构成
print(str2.isdigit())  # False
# 检查字符串是否以字母构成
print(str2.isalpha())  # False
# 检查字符串是否以数字和字母构成
print(str2.isalnum())  # True
str3 = '  jackfrued@126.com '
print(str3)
# 获得字符串修剪左右两侧空格之后的拷贝
print(str3.strip())
```

分割:

```python
str.split(str="", num=string.count(str))
```

- str -- 分隔符，默认为所有的空字符，包括空格、换行(\n)、制表符(\t)等。
- num -- 分割次数。默认为 -1, 即分隔所有。

```python
#!/usr/bin/python3
 
str = "this is string example....wow!!!"
print (str.split( ))       # 以空格为分隔符
print (str.split('i',1))   # 以 i 为分隔符
print (str.split('w'))     # 以 w 为分隔符
```

```
['this', 'is', 'string', 'example....wow!!!']
['th', 's is string example....wow!!!']
['this is string example....', 'o', '!!!']
```

以下实例以 # 号为分隔符，指定第二个参数为 1，返回两个参数列表。

```python
#!/usr/bin/python3
 
txt = "Google#Runoob#Taobao#Facebook"
 
# 第二个参数为 1，返回两个参数列表
x = txt.split("#", 1)
 
print(x)
```

```python
['Google', 'Runoob#Taobao#Facebook']
```

我们之前讲过，可以用下面的方式来格式化输出字符串。

```python
a, b = 5, 10
print('%d * %d = %d' % (a, b, a * b))
```

当然，我们也可以用字符串提供的方法来完成字符串的格式，代码如下所示。

```python
a, b = 5, 10
print('{0} * {1} = {2}'.format(a, b, a * b))
```

Python 3.6以后，格式化字符串还有更为简洁的书写方式，就是在字符串前加上字母`f`，我们可以使用下面的语法糖来简化上面的代码。

```python
a, b = 5, 10
print(f'{a} * {b} = {a * b}')
```

**字符编码**

```python
>>> string = "今天，你努力了吗？"
>>> string
'今天，你努力了吗？'
>>> string.encode()
b'\xe4\xbb\x8a\xe5\xa4\xa9\xef\xbc\x8c\xe4\xbd\xa0\xe5\x8a\xaa\xe5\x8a\x9b\xe4\xba\x86\xe5\x90\x97\xef\xbc\x9f'
>>> bit = string.encode()
>>> bit
b'\xe4\xbb\x8a\xe5\xa4\xa9\xef\xbc\x8c\xe4\xbd\xa0\xe5\x8a\xaa\xe5\x8a\x9b\xe4\xba\x86\xe5\x90\x97\xef\xbc\x9f'
>>> bit.decode()
'今天，你努力了吗？'
>>> str
<class 'str'>
>>> string
'今天，你努力了吗？'
>>> 
```

###　正则表达式

|              |                                  |                  |                                                              |
| ------------ | -------------------------------- | ---------------- | ------------------------------------------------------------ |
| 符号         | 解释                             | 示例             | 说明                                                         |
| .            | 匹配任意字符(除换行符)           | b.t              | 可以匹配bat / but / b#t / b1t等                              |
| \w           | 匹配字母/数字/下划线/汉字        | b\wt             | 可以匹配bat / b1t / b_t等 但不能匹配b#t                      |
| \s           | 匹配空白字符（包括\r、\n、\t等） | love\syou        | 可以匹配love you                                             |
| \d           | 匹配数字                         | \d\d             | 可以匹配01 / 23 / 99等                                       |
| \b           | 匹配单词的边界                   | \bThe\b          |                                                              |
| ^            | 匹配字符串的开始                 | ^The             | 可以匹配The开头的字符串                                      |
| $            | 匹配字符串的结束                 | .exe$            | 可以匹配.exe结尾的字符串                                     |
| \W           | 匹配非字母/数字/下划线           | b\Wt             | 可以匹配b#t / b@t等 但不能匹配but / b1t / b_t等              |
| \S           | 匹配非空白字符                   | love\Syou        | 可以匹配love#you等 但不能匹配love you                        |
| \D           | 匹配非数字                       | \d\D             | 可以匹配9a / 3# / 0F等                                       |
| \B           | 匹配非单词边界                   | \Bio\B           |                                                              |
| []           | 匹配来自字符集的任意单一字符     | [aeiou]          | 可以匹配任一元音字母字符                                     |
| [^]          | 匹配不在字符集中的任意单一字符   | [^aeiou]         | 可以匹配任一非元音字母字符                                   |
| *            | 匹配0次或多次                    | \w*              |                                                              |
| +            | 匹配1次或多次                    | \w+              |                                                              |
| ?            | 匹配0次或1次                     | \w?              |                                                              |
| {N}          | 匹配N次                          | \w{3}            |                                                              |
| {M,}         | 匹配至少M次                      | \w{3,}           |                                                              |
| {M,N}        | 匹配至少M次至多N次               | \w{3,6}          |                                                              |
| \|           | 分支                             | foo\|bar         | 可以匹配foo或者bar                                           |
| (?#)         | 注释                             |                  |                                                              |
| (exp)        | 匹配exp并捕获到自动命名的组中    |                  |                                                              |
| (?<name>exp) | 匹配exp并捕获到名为name的组中    |                  |                                                              |
| (?:exp)      | 匹配exp但是不捕获匹配的文本      |                  |                                                              |
| (?=exp)      | 匹配exp前面的位置                | \b\w+(?=ing)     | 可以匹配I'm dancing中的danc                                  |
| (?<=exp)     | 匹配exp后面的位置                | (?<=\bdanc)\w+\b | 可以匹配I love dancing and reading中的第一个ing              |
| (?!exp)      | 匹配后面不是exp的位置            |                  |                                                              |
| (?<!exp)     | 匹配前面不是exp的位置            |                  |                                                              |
| *?           | 重复任意次，但尽可能少重复       | a.*b a.*?b       | 将正则表达式应用于aabab，前者会匹配整个字符串aabab，后者会匹配aab和ab两个字符串 |
| +?           | 重复1次或多次，但尽可能少重复    |                  |                                                              |
| ??           | 重复0次或1次，但尽可能少重复     |                  |                                                              |
| {M,N}?       | 重复M到N次，但尽可能少重复       |                  |                                                              |
| {M,}?        | 重复M次以上，但尽可能少重复      |                  |                                                              |

匹配汉字时：

>[\u4e00 - \u9fa5]

#### 正则表达式修饰符 - 可选标志

正则表达式可以包含一些可选标志修饰符来控制匹配的模式。修饰符被指定为一个可选的标志。多个标志可以通过按位 OR(|) 它们来指定。如 re.I | re.M 被设置成 I 和 M 标志：

| 修饰符 | 描述                                                         |
| ------ | ------------------------------------------------------------ |
| re.I   | 使匹配对大小写不敏感                                         |
| re.L   | 做本地化识别（locale-aware）匹配                             |
| re.M   | 多行匹配，影响 ^ 和 $                                        |
| re.S   | 使 . 匹配包括换行在内的所有字符                              |
| re.U   | 根据Unicode字符集解析字符。这个标志影响 \w, \W, \b, \B.      |
| re.X   | 该标志通过给予你更灵活的格式以便你将正则表达式写得更易于理解。 |

#### re.match函数

re.match 尝试从字符串的起始位置匹配一个模式，如果不是起始位置匹配成功的话，match()就返回none。

**函数语法**：

```
re.match(pattern, string, flags=0)
```

函数参数说明：

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| pattern | 匹配的正则表达式                                             |
| string  | 要匹配的字符串。                                             |
| flags   | 标志位，用于控制正则表达式的匹配方式，如：是否区分大小写，多行匹配等等。参见：[正则表达式修饰符 - 可选标志](https://www.runoob.com/python3/python3-reg-expressions.html#flags) |

匹配成功re.match方法返回一个匹配的对象，否则返回None。

我们可以使用group(num) 或 groups() 匹配对象函数来获取匹配表达式。

| 匹配对象方法 | 描述                                                         |
| :----------- | :----------------------------------------------------------- |
| group(num=0) | 匹配的整个表达式的字符串，group() 可以一次输入多个组号，在这种情况下它将返回一个包含那些组所对应值的元组。 |
| groups()     | 返回一个包含所有小组字符串的元组，从 1 到 所含的小组号。     |

```python
>>> import re
>>> patter = r'mr_\w+'
>>> string = 'MR_hello mr_nihao'
>>> result = re.match(patter, string)
>>> result
>>> result = re.match(patter, string)
>>> print(result)
None
>>> result = re.match(patter, string, re.I)
>>> print(result)
<re.Match object; span=(0, 8), match='MR_hello'>
>>> print(result.start())
0
>>> print(result.end())
8
>>> print(result.string)
MR_hello mr_nihao
>>> print(result.span())
(0, 8)
>>> print(result.group())
MR_hello
>>> 
```

#### re.search方法

re.search 扫描整个字符串并返回第一个成功的匹配。

函数语法：

```
re.search(pattern, string, flags=0)
```

函数参数说明：

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| pattern | 匹配的正则表达式                                             |
| string  | 要匹配的字符串。                                             |
| flags   | 标志位，用于控制正则表达式的匹配方式，如：是否区分大小写，多行匹配等等。参见：[正则表达式修饰符 - 可选标志](https://www.runoob.com/python3/python3-reg-expressions.html#flags) |

匹配成功re.search方法返回一个匹配的对象，否则返回None。

我们可以使用group(num) 或 groups() 匹配对象函数来获取匹配表达式。

| 匹配对象方法 | 描述                                                         |
| :----------- | :----------------------------------------------------------- |
| group(num=0) | 匹配的整个表达式的字符串，group() 可以一次输入多个组号，在这种情况下它将返回一个包含那些组所对应值的元组。 |
| groups()     | 返回一个包含所有小组字符串的元组，从 1 到 所含的小组号。     |

```python
>>> pattern = 'mr_\\w+'
>>> pattern
'mr_\\w+'
>>> string = 'MR_hello mr_nihao'
>>> import re
>>> result = re.search(pattern, string)
>>> print(result)
<re.Match object; span=(9, 17), match='mr_nihao'>
>>> print(result.start())
9
>>> print(result.end())
17
>>> print(result.group())
mr_nihao
>>> print(result.string)
MR_hello mr_nihao
>>> result = re.search(pattern, string, re.IGNORECASE)
>>> print(result)
<re.Match object; span=(0, 8), match='MR_hello'>
>>> 
```

#### findall

在字符串中找到正则表达式所匹配的所有子串，并返回一个列表，如果没有找到匹配的，则返回空列表。

**注意：** match 和 search 是匹配一次 findall 匹配所有。

语法格式为：

```
re.findall(string[, pos[, endpos]])
```

```python
>>> import re
>>> string
'MR_hello mr_nihao'
>>> pattern
'mr_\\w+'
>>> result = re.findall(pattern, string)
>>> print(result)
['mr_nihao']
>>> result = re.findall(pattern, string, re.I)
>>> print(result)
['MR_hello', 'mr_nihao']
>>> 
```

#### re.sub()方法

替换敏感文字

```python
>>> import re
>>> pattern = r'(黑客)|(抓包)|(监听)'
>>> string = "我是一名程序员，我想做一名黑客，我最近在研究监听套接字!"
>>> result = re.sub(pattern, "^_^", string)
>>> print(result)
我是一名程序员，我想做一名^_^，我最近在研究^_^套接字!
>>> 
```

#### re.split()方法

split 方法按照能够匹配的子串将字符串分割后返回列表，它的使用形式如下：

```
re.split(pattern, string[, maxsplit=0, flags=0])
```

参数：

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| pattern  | 匹配的正则表达式                                             |
| string   | 要匹配的字符串。                                             |
| maxsplit | 分隔次数，maxsplit=1 分隔一次，默认为 0，不限制次数。        |
| flags    | 标志位，用于控制正则表达式的匹配方式，如：是否区分大小写，多行匹配等等。参见：[正则表达式修饰符 - 可选标志](https://www.runoob.com/python3/python3-reg-expressions.html#flags) |

```python
>>> string = "@方嵩@王胜@张志国"
>>> pattern = r"@"
>>> name = re.split(pattern, string)
>>> name
['', '方嵩', '王胜', '张志国']
```

### 函数

```python
#!/usr/bin/env python
# coding=utf-8

def gcd(a, b):
    if b == 0:
        return a
    else :
        return gcd(b, a % b)

a = int(input("ａ的值是多少"))
b = int(input("ｂ的值是多少"))
print(gcd(a, b))
```

```python
#!/usr/bin/env python
# coding=utf-8
import math

'''
def circle(r):
    result = math.pi * r * r
    return result
r = float(input('请输入圆的半径'))

print('半径为%lf' % circle(r))
'''

r = float(input("请输入圆的半径："))
result = lambda r : math.pi * r * r
print('半径为%lf' % result(r))
```

###　面向对象

更通俗易懂的说法，下面这段内容来自于[知乎](https://www.zhihu.com/)。

![img](https://github.com/jackfrued/Python-100-Days/raw/master/Day01-15/res/oop-zhihu.png)

#### 类和对象

简单的说，类是对象的蓝图和模板，而对象是类的实例。

当我们把一大堆拥有共同特征的对象的静态特征（属性）和动态特征（行为）都抽取出来后，就可以定义出一个叫做“类”的东西。

##### 定义类

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggohq0wgxwj30m509tjtm.jpg)



#### 继承与多态

```python
#!/usr/bin/env python
# coding=utf-8
"""类的继承"""
#父类
class Animal(object):
    def __init__(self, name):
        self.name = name

    def run(self):
        print("{} run...".format(self.name))

#子类(派生类)
class Cat(Animal):
    #重写父类方法
    def __init__(self, name, color):
        #调用父类的方法
        super().__init__(name)
        self.color = color
    def show(self):
        print("name = {}, color = {}".format(self.name, self.color))
#子类
class Dog(Animal):
    def run(self):
        print("{} run fast...".format(self.name))

#创建对象
cat = Cat('喵喵', '小白')
#调用方法
cat.run()
cat.show()

dog = Dog("旺仔")
dog.run()

```

```python
#!/usr/bin/env python
# coding=utf-8
"""多态"""

#父类
class Animal(object):
    def __init__(self, name):
        self.name = name
    
    def say(self):
        print("{} is an Animal, I Can Say".format(self.name))

#子类
class Cat(Animal):
    def say(self):
        print("{} is a cat, say 'miao~ miao~ miao~!'".format(self.name))

class Dog(Animal):
    def say(self):
        print("{} is a Dog, say 'Wang~ Wang~ Wang~!'".format(self.name))

#动物叫的函数

def Animal_say(animal):
    animal.say()

#传入Animal的实例
Animal_say(Animal('a'))
#传入Dog的实例
Animal_say(Dog('b'))
#传入Cat的实例
Animal_say(Cat('c'))
```

### 文件操作

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggqr3oyf69j318k0o5jx5.jpg)

mode 参数有：

| 模式 | 描述                                                         |
| :--- | :----------------------------------------------------------- |
| t    | 文本模式 (默认)。                                            |
| x    | 写模式，新建一个文件，如果该文件已存在则会报错。             |
| b    | 二进制模式。                                                 |
| +    | 打开一个文件进行更新(可读可写)。                             |
| U    | 通用换行模式（**Python 3 不支持**）。                        |
| r    | 以只读方式打开文件。文件的指针将会放在文件的开头。这是默认模式。 |
| rb   | 以二进制格式打开一个文件用于只读。文件指针将会放在文件的开头。这是默认模式。一般用于非文本文件如图片等。 |
| r+   | 打开一个文件用于读写。文件指针将会放在文件的开头。           |
| rb+  | 以二进制格式打开一个文件用于读写。文件指针将会放在文件的开头。一般用于非文本文件如图片等。 |
| w    | 打开一个文件只用于写入。如果该文件已存在则打开文件，并从开头开始编辑，即原有内容会被删除。如果该文件不存在，创建新文件。 |
| wb   | 以二进制格式打开一个文件只用于写入。如果该文件已存在则打开文件，并从开头开始编辑，即原有内容会被删除。如果该文件不存在，创建新文件。一般用于非文本文件如图片等。 |
| w+   | 打开一个文件用于读写。如果该文件已存在则打开文件，并从开头开始编辑，即原有内容会被删除。如果该文件不存在，创建新文件。 |
| wb+  | 以二进制格式打开一个文件用于读写。如果该文件已存在则打开文件，并从开头开始编辑，即原有内容会被删除。如果该文件不存在，创建新文件。一般用于非文本文件如图片等。 |
| a    | 打开一个文件用于追加。如果该文件已存在，文件指针将会放在文件的结尾。也就是说，新的内容将会被写入到已有内容之后。如果该文件不存在，创建新文件进行写入。 |
| ab   | 以二进制格式打开一个文件用于追加。如果该文件已存在，文件指针将会放在文件的结尾。也就是说，新的内容将会被写入到已有内容之后。如果该文件不存在，创建新文件进行写入。 |
| a+   | 打开一个文件用于读写。如果该文件已存在，文件指针将会放在文件的结尾。文件打开时会是追加模式。如果该文件不存在，创建新文件用于读写。 |
| ab+  | 以二进制格式打开一个文件用于追加。如果该文件已存在，文件指针将会放在文件的结尾。如果该文件不存在，创建新文件用于读写。 |

默认为文本模式，如果要以二进制模式打开，加上 **b** 。

#### file 对象

file 对象使用 open 函数来创建，下表列出了 file 对象常用的函数：

| 序号 | 方法及描述                                                   |
| :--- | :----------------------------------------------------------- |
| 1    | [file.close()](https://www.runoob.com/python3/python3-file-close.html)关闭文件。关闭后文件不能再进行读写操作。 |
| 2    | [file.flush()](https://www.runoob.com/python3/python3-file-flush.html)刷新文件内部缓冲，直接把内部缓冲区的数据立刻写入文件, 而不是被动的等待输出缓冲区写入。 |
| 3    | [file.fileno()](https://www.runoob.com/python3/python3-file-fileno.html)返回一个整型的文件描述符(file descriptor FD 整型), 可以用在如os模块的read方法等一些底层操作上。 |
| 4    | [file.isatty()](https://www.runoob.com/python3/python3-file-isatty.html)如果文件连接到一个终端设备返回 True，否则返回 False。 |
| 5    | [file.next()](https://www.runoob.com/python3/python3-file-next.html)**Python 3 中的 File 对象不支持 next() 方法。**返回文件下一行。 |
| 6    | [file.read([size\])](https://www.runoob.com/python3/python3-file-read.html)从文件读取指定的字节数，如果未给定或为负则读取所有。 |
| 7    | [file.readline([size\])](https://www.runoob.com/python3/python3-file-readline.html)读取整行，包括 "\n" 字符。 |
| 8    | [file.readlines([sizeint\])](https://www.runoob.com/python3/python3-file-readlines.html)读取所有行并返回列表，若给定sizeint>0，返回总和大约为sizeint字节的行, 实际读取值可能比 sizeint 较大, 因为需要填充缓冲区。 |
| 9    | [file.seek(offset[, whence\])](https://www.runoob.com/python3/python3-file-seek.html)移动文件读取指针到指定位置 |
| 10   | [file.tell()](https://www.runoob.com/python3/python3-file-tell.html)返回文件当前位置。 |
| 11   | [file.truncate([size\])](https://www.runoob.com/python3/python3-file-truncate.html)从文件的首行首字符开始截断，截断文件为 size 个字符，无 size 表示从当前位置截断；截断之后后面的所有字符被删除，其中 windows 系统下的换行代表2个字符大小。 |
| 12   | [file.write(str)](https://www.runoob.com/python3/python3-file-write.html)将字符串写入文件，返回的是写入的字符长度。 |
| 13   | [file.writelines(sequence)](https://www.runoob.com/python3/python3-file-writelines.html)向文件写入一个序列字符串列表，如果需要换行则要自己加入每行的换行符。 |

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggqrtcj9qij30mn0b5mxp.jpg)

| 操作模式 | 具体含义                         |
| -------- | -------------------------------- |
| `'r'`    | 读取 （默认）                    |
| `'w'`    | 写入（会先截断之前的内容）       |
| `'x'`    | 写入，如果文件已经存在会产生异常 |
| `'a'`    | 追加，将内容写入到已有文件的末尾 |
| `'b'`    | 二进制模式                       |
| `'t'`    | 文本模式（默认）                 |
| `'+'`    | 更新（既可以读又可以写）         |





### 模块

```python
#!/usr/bin/env python
# coding=utf-8
"""模块"""
import os

#打开文件
path = '/home/fangsong/'

dirs = os.listdir(path)
for file in dirs:
    print(file)
#创建多级目录
path = './test/git/a/b/c/d'
#os.makedirs(path)
#判断路径是否存在
if os.path.exists(path) == True :
    print(path, "is exist!")
else :
    dirs = os.makedirs(path)
    print(dirs)
```

```python
#!/usr/bin/env python
# coding=utf-8
"""datetime模块"""

from datetime import datetime
#获取当前时间
now = datetime.now()
print(now)

#创建指定日期对象
date1 = datetime(2015, 7, 16, 11, 50, 40)
print(date1)

#转为时间戳
print(now.timestamp())

#日期转字符串
print(now.strftime('%Y-%m-%d'))

#字符串转日期
date2 = datetime.strptime('2018-10-20 10:15:40', '%Y-%m-%d %H:%M:%S')
print(type(date2))
print(date2)
```

```python
#!/usr/bin/env python
# coding=utf-8
import random

#0~1之间的随机数

print(random.random())

#制定范围之内的随机数
print(random.randint(10, 100))

#获取列表中的一个随机数
list1 = [1, 2, 3, 5, 7, 11]
print(random.choice(list1))
```



启动本地服务，在web上查看文档** https://www.cnblogs.com/kaid/p/7992240.html

```python
fangsong@fangsong-FX503VD:~/Git/Mynotes/Python/Python基础/Pro$ python -m pydoc -p 1234
Server ready at http://localhost:1234/
Server commands: [b]rowser, [q]uit
server> b
server> q
Server stopped
```

-m 表示运行指定模块

-p表示打开本地http服务



