#　shell基础





[TOC]



#### 第一个SHELL脚本

```shell
#!/bin/bash  #下面代码告诉由什么解释
echo 'Hello HaiZei' ＃简单输出
```

```
bash a.sh 或chmod + x a.sh
```

#### 变量与局部变量

* 变量的定义：

```shell
a=12
a=helloword
a=`pwd`
a=$a:a　＃拼接
```

"$"变量引用,"[]"是用来限制$范围，

* 局部变量：

```shell
local a=12
```

#### 特殊变量

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-32-11%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-41-30%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



特殊变量列表

| **变量** | **含义**                                                     |
| :------: | :----------------------------------------------------------- |
|    $0    | 当前脚本的文件名                                             |
|    $n    | 传递给脚本或函数的参数。n 是一个数字，表示第几个参数。例如，第一个参数是$1，第二个参数是$2。 |
|    $#    | 传递给脚本或函数的参数个数。                                 |
|    $*    | 传递给脚本或函数的所有参数。                                 |
|    $@    | 传递给脚本或函数的所有参数。被双引号(" ")包含时，与 $* 稍有不同，下面将会讲到。 |
|    $?    | 上个命令的退出状态，或函数的返回值。                         |
|    $$    | 当前 Shell 进程 ID。对于 Shell 脚本，就是这些脚本所在的进程 ID。 |



例如，$表示当前 Shell 进程的 ID，即 pid，看下面的代码：

```
echo $$
echo $?
```

运行结果

```
29949
0
```

请看下面的脚本：

```shell
#!/bin/bash

echo "File Name: $0"
echo "First Parameter : $1"
echo "First Parameter : $2"
echo "Quoted Values: $@"
echo "Quoted Values: $*"
echo "Total Number of Parameters : $#"
```

运行结果：

```shell
$./test.sh Zara Ali
File Name : ./test.sh
First Parameter : Zara
Second Parameter : Ali
Quoted Values: Zara Ali
Quoted Values: Zara Ali
Total Number of Parameters : 2
```

**$* 和 $@ 的区别**

$* 和 $@ 都表示传递给函数或脚本的所有参数，不被双引号(" ")包含时，都以"$1" "$2" … "$n" 的形式输出所有参数。

但是当它们被双引号(" ")包含时，"$*" 会将所有的参数作为一个整体，以"$1 $2 … $n"的形式输出所有参数；"$@" 会将各个参数分开，以"$1" "$2" … "$n" 的形式输出所有参数。



```shell
#!/bin/bash 
echo "\$*=" $*
echo "\"\$\"=" "$*"
echo "\$@=" $@
echo "\"\$@\"=" "$@"

echo "print each param from \$*"
for var in $*
do
    echo "$var"
done

echo "print each param from \$@"
for var in $@
do
    echo "$var"
done
echo "print each param from \"\$*\""
for var in "$*"
do
    echo "$var"
done

echo "print each param from \"\$@\""
for var in "$@"
do
    echo "$var"
done
```



运行结果

```shell
fangsong@fangsong-FX503VD:~/Mycode/2.f$ ./test.sh "a" "b" "c" "d"
$*= a b c d
"$"= a b c d
$@= a b c d
"$@"= a b c d
print each param from $*
a
b
c
d
print each param from $@
a
b
c
d
print each param from "$*"
a b c d
print each param from "$@"
a
b
c
d

```

#### 变量，参数展开

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-53-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

变量替换可以根据变量的状态（是否为空、是否定义等）来改变它的值

可以使用的变量替换形式：

|      形式       | 说明                                                         |
| :-------------: | :----------------------------------------------------------- |
|     ${var}      | 变量本来的值                                                 |
|  ${var:-word}   | 如果变量 var 为空或已被删除(unset)，那么返回 word，但不改变 var 的值 |
|  ${var:=word}   | 如果变量 var 为空或已被删除(unset)，那么返回 word，并将 var 的值设置为 word。 |
| ${var:?message} | 如果变量 var 为空或已被删除(unset)，那么将消息 message 送到标 准错误输出，可以用来检测变量 var 是否可以被正常赋值。若此替换出现在 Shell 脚本中，那么脚本将停止运行。 |
|  ${var:+word}   | 如果变量 var 被定义，那么返回 word，但不改变 var 的值。      |

#### 算术运算符

先来看一个使用算术运算符的例子：

```shell
#!/bin/sh

a=10
b=20
val=`expr $a + $b`
echo "a + b : $val"

val=`expr $a - $b`
echo "a - b : $val"

val=`expr $a \* $b`
echo "a * b : $val"

val=`expr $b / $a`
echo "b / a : $val"

val=`expr $b % $a`
echo "b % a : $val"

if [ $a == $b ]
then
   echo "a is equal to b"
fi

if [ $a != $b ]
then
   echo "a is not equal to b"
fi
```

运行结果：

```shell
a + b : 30
a - b : -10
a * b : 200
b / a : 2
b % a : 0
a is not equal to b
```

注意：

- 乘号(*)前边必须加反斜杠()才能实现乘法运算；
- if...then...fi 是条件语句.

| 运算符 | 说明                                          | 举例                          |
| :----- | :-------------------------------------------- | :---------------------------- |
| +      | 加法                                          | `expr $a + $b` 结果为 30。    |
| -      | 减法                                          | `expr $a - $b` 结果为 10。    |
| *      | 乘法                                          | `expr $a \* $b` 结果为  200。 |
| /      | 除法                                          | `expr $b / $a` 结果为 2。     |
| %      | 取余                                          | `expr $b % $a` 结果为 0。     |
| =      | 赋值                                          | a=$b 将把变量 b 的值赋给 a。  |
| ==     | 相等。用于比较两个数字，相同则返回 true。     | [ $a == $b ] 返回 false。     |
| !=     | 不相等。用于比较两个数字，不相同则返回 true。 | [ $a != $b ] 返回 true。      |

注意：条件表达式要放在方括号之间，并且要有空格，例如 [$a==$b] 是错误的，必须写成 [ $a == $b ]。



#### 字符串展开

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-54-19%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-54-48%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 输入输出-READ

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-26-40%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



#### 输入输出-ECHO

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-27-54%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

如果表达式中包含特殊字符，Shell 将会进行替换。例如，在双引号中使用变量就是一种替换，转义字符也是一种替换。

举个例子：

```shell
#!/bin/bash

a=10
echo -e "Value of a is $a \n"
```

运行结果：

```shell
Value of a is 10
```

这里 -e 表示对转义字符进行替换。如果不使用 -e 选项，将会原样输出：

```shell
Value of a is 10\n
```

<font color = red>可以使用 echo 命令的 -E 选项禁止转义，默认也是不转义的；使用 -n 选项可以禁止插入换行符。</font>



#### 输入输出-PRINTF

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-28-44%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

- printf命令不用加括号
- format-string可以没有引号，但最好加上，单引号双引号相似。
- 参数多于格式控制符（％）时，format-string可以重用，可以将所有参数都转换。
- arguments使用空格分隔，不用逗号。

```shell
$ printf "%d %s\n" 1 "abc"
1 abc
```



#### 函数

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-29-20%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

在 Shell中，调用函数时可以向其传递参数。在函数体内部，通过 $n 的形式来获取参数的值，例如，$1 表示第一个参数，$2 表示第二个参数...

带参数的函数示例：

```shell
#!/bin/bash
funWithParam(){
    echo "The value of the first parameter is $1 !"
    echo "The value of the second parameter is $2 !"
    echo "The value of the tenth parameter is $10 !"
    echo "The value of the tenth parameter is ${10} !"
    echo "The value of the eleventh parameter is ${11} !"
    echo "The amount of the parameters is $# !"  # 参数个数
    echo "The string of the parameters is $* !"  # 传递给函数的所有参数
}
funWithParam 1 2 3 4 5 6 7 8 9 34 73
```

运行脚本：

```shell
The value of the first parameter is 1 !
The value of the second parameter is 2 !
The value of the tenth parameter is 10 !
The value of the tenth parameter is 34 !
The value of the eleventh parameter is 73 !
The amount of the parameters is 12 !
The string of the parameters is 1 2 3 4 5 6 7 8 9 34 73 !"
```

注意，$10 不能获取第十个参数，获取第十个参数需要 ${10}。当 n>=10 时，需要使用 ${n} 来获取参数。

另外，还有几个特殊变量用来处理参数，前面已经提到：

| 特殊变量 | 说明                                              |
| :------- | :------------------------------------------------ |
| $#       | 传递给函数的参数个数。                            |
| $*       | 显示所有传递给函数的参数。                        |
| $@       | 与 $* 相同，但是略有区别，请查看 Shell 特殊变量。 |
| $?       | 函数的返回值。                                    |





#### 流程控制-IF

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-30-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



```shell
#!/bin/bash

a=10
b=20
if [ $a == $b ]
then
    echo "a=b"
else 
    echo "a!=b"
fi
```

if与[]有空格，内都有空格

- if ... fi 语句；
- if ... else ... fi 语句；
- if ... elif ... else ... fi 语句。

**1)** if ... else 语句

```shell
if [ expression ]
then
   Statement(s) to be executed if expression is true
fi

```

**2)** if ... else ... fi 语句

```shell
if [ expression ]
then
   Statement(s) to be executed if expression is true
else
   Statement(s) to be executed if expression is not true
fi
```

```shell
#!/bin/sh

a=10
b=20

if [ $a == $b ]
then
   echo "a is equal to b"
else
   echo "a is not equal to b"
fi
```

执行结果：

```sh
a is not equal to b
```

**3)** if ... elif ... fi 语句

```shell
if [ expression 1 ]
then
   Statement(s) to be executed if expression 1 is true
elif [ expression 2 ]
then
   Statement(s) to be executed if expression 2 is true
elif [ expression 3 ]
then
   Statement(s) to be executed if expression 3 is true
else
   Statement(s) to be executed if no expression is true
fi
```

if ... else 语句也经常与 test 命令结合使用，如下所示：

```shell
num1=$[2*3]
num2=$[1+5]
if test $[num1] -eq $[num2]
then
    echo 'The two numbers are equal!'
else
    echo 'The two numbers are not equal!'
fi
```

输出：

```shell
The two numbers are equal!
```

test 命令用于检查某个条件是否成立，与方括号([ ])类似。





#### 关系运算符

关系运算符只支持数字，不支持字符串，除非字符串的值是数字。

先来看一个关系运算符的例子：

```shell
#!/bin/sh

a=10
b=20
if [ $a -eq $b ]
then
   echo "$a -eq $b : a is equal to b"
else
   echo "$a -eq $b: a is not equal to b"
fi

if [ $a -ne $b ]
then
   echo "$a -ne $b: a is not equal to b"
else
   echo "$a -ne $b : a is equal to b"
fi

if [ $a -gt $b ]
then
   echo "$a -gt $b: a is greater than b"
else
   echo "$a -gt $b: a is not greater than b"
fi

if [ $a -lt $b ]
then
   echo "$a -lt $b: a is less than b"
else
   echo "$a -lt $b: a is not less than b"
fi

if [ $a -ge $b ]
then
   echo "$a -ge $b: a is greater or  equal to b"
else
   echo "$a -ge $b: a is not greater or equal to b"
fi

if [ $a -le $b ]
then
   echo "$a -le $b: a is less or  equal to b"
else
   echo "$a -le $b: a is not less or equal to b"
fi
```

运行结果：

```shell
10 -eq 20: a is not equal to b
10 -ne 20: a is not equal to b
10 -gt 20: a is not greater than b
10 -lt 20: a is less than b
10 -ge 20: a is not greater or equal to b
10 -le 20: a is less or  equal to b
```

| 运算符 | 说明                                                  | 举例                       |
| :----- | :---------------------------------------------------- | :------------------------- |
| -eq    | 检测两个数是否相等，相等返回 true。                   | [ $a -eq $b ] 返回 true。  |
| -ne    | 检测两个数是否相等，不相等返回 true。                 | [ $a -ne $b ] 返回 true。  |
| -gt    | 检测左边的数是否大于右边的，如果是，则返回 true。     | [ $a -gt $b ] 返回 false。 |
| -lt    | 检测左边的数是否小于右边的，如果是，则返回 true。     | [ $a -lt $b ] 返回 true。  |
| -ge    | 检测左边的数是否大等于右边的，如果是，则返回 true。   | [ $a -ge $b ] 返回 false。 |
| -le    | 检测左边的数是否小于等于右边的，如果是，则返回 true。 | [ $a -le $b ] 返回 true。  |



| 运算符 | 说明                                                | 举例                                     |
| :----- | :-------------------------------------------------- | :--------------------------------------- |
| !      | 非运算，表达式为 true 则返回 false，否则返回 true。 | [ ! false ] 返回 true。                  |
| -o     | 或运算，有一个表达式为 true 则返回 true。           | [ $a -lt 20 -o $b -gt 100 ] 返回 true。  |
| -a     | 与运算，两个表达式都为 true 才返回 true。           | [ $a -lt 20 -a $b -gt 100 ] 返回 false。 |



| 运算符 | 说明                                      | 举例                     |
| :----- | :---------------------------------------- | :----------------------- |
| =      | 检测两个字符串是否相等，相等返回 true。   | [ $a = $b ] 返回 false。 |
| !=     | 检测两个字符串是否相等，不相等返回 true。 | [ $a != $b ] 返回 true。 |
| -z     | 检测字符串长度是否为0，为0返回 true。     | [ -z $a ] 返回 false。   |
| -n     | 检测字符串长度是否为0，不为0返回 true。   | [ -z $a ] 返回 true。    |
| str    | 检测字符串是否为空，不为空返回 true。     | [ $a ] 返回 true。       |



#### 流程控制-WHILE

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-31-26%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 流程控制-FOR

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-32-03%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```
for 变量 in 列表
do
    command1
    command2
    ...
    commandN
done
```

* 例如

```
for loop in 1 2 3 4 5
do
    echo "The value is: $loop"
done
```

运行结果：

```shell
The value is: 1
The value is: 2
The value is: 3
The value is: 4
The value is: 5
```

* 顺序输出字符串中的字符：

```shell
for str in 'This is a string'
do
    echo $str
done
```

运行结果：

```
This is a string
```

* 显示主目录下以 .bash 开头的文件：

```
#!/bin/bash

for FILE in $HOME/.bash*
do
   echo $FILE
done
```

运行结果：

```
/root/.bash_history
/root/.bash_logout
/root/.bash_profile
/root/.bashrc
```





#### 流程控制-UNTIL

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-32-25%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 流程控制-CASE

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-33-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### Shell 字符串

字符串是 shell 编程中最常用最有用的数据类型（除了数字和字符串，也没啥其它类型好用了），字符串可以用单引号，也可以用双引号，也可以不用引号。单双引号的区别跟 PHP 类似。

* 单引号

```shell
str='this is a string'
```

单引号字符串的限制： 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的； 单引号字串中不能出现单引号（对单引号使用转义符后也不行）。

* 双引号

```shell
your_name='qinjx'
str="Hello, I know your are \"$your_name\"! \n"
```

双引号的优点： 双引号里可以有变量 双引号里可以出现转义字符

* 拼接字符串

```shell
your_name="qinjx"
greeting="hello, "$your_name" !"
greeting_1="hello, ${your_name} !"

echo $greeting $greeting_1
```

* 获取字符串长度

```shell
string="abcd"
echo ${#string} #输出4
```

* 提取子字符串

```shell
string="alibaba is a great company"
echo ${string:1:4} #输出 liba
```

* 查找子字符串

```shell
string="alibaba is a great company"
echo `expr index "$string" is`
```



####　数组

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-34-13%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 数组操作

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-34-45%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-35-16%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

* 读取数组

读取数组元素值的一般格式是：

```shell
    ${array_name[index]}
```

使用@或*可以获取数组中的所有元素，例如：

```shell
${array_name[*]}
${array_name[@]}
```

* 获取数组的长度

获取数组长度的方法与获取字符串长度的方法相同，例如：

```shell
# 取得数组元素的个数
length=${#array_name[@]}
# 或者
length=${#array_name[*]}
# 取得数组单个元素的长度
lengthn=${#array_name[n]}
```

# 命令系统



#### man手册使用

```
man ls
man ssh
```

在man中，常见的几个数字含义：

| 代号 | 代表的含义                                     | 举例               |
| ---- | ---------------------------------------------- | ------------------ |
| １   | 用户在shell环境下可以操作的命令或可执行文件    | `man 1 ls`         |
| ２   | 系统内核可以调用的函数和工具                   | `man 2 reboot`     |
| ３   | 一些常用的函数和函数库，大部分ｃ的函数库       | `man 3 readdir`    |
| ４   | 设备文件的说明，通常实在`/dev`下的设备         | `man 4 null`       |
| ５   | 配置文件或某些文件格式                         | `man 5 interfaces` |
| ６   | 游戏                                           | `man 6 lol`        |
| ７   | 惯例与协议等，例如`linux` 文件系统，网络协议等 | `man 7 tcp`        |
| ８   | 系统管理员可用的命令                           | `man 8 reboot`     |
| ９   | 跟kernel有用的文件                             |                    |

#### shell通配符

* ?

  代表单个任意字符, 就是.cpp什么的前面是单个字符的

  几个？代表几个字符的文件

```bash
fangsong@fangsong-FX503VD:~/Mycode/2.f$ ls
8.cpp 19.cpp 20.cpp
fangsong@fangsong-FX503VD:~/Mycode/2.f$ ls ?.cpp
8.cpp
```

* *

  代表任意几个字符

 ```bash
 fangsong@fangsong-FX503VD:~/Mycode/2.f$ ls
 fangsong@fangsong-FX503VD:~/Mycode/2.f$ ls *.cpp
 8.cpp  19.cpp 20.cpp
 ```

* `[list]`匹配list中的任意单一字符

* `[!list]`匹配除list中的任意单一字符
* `[c1-c2]`匹配`c1-c2`中的任意单一字符

* `{string,string2,...}`匹配`string`或其中一个字符串

#### Shell任务控制
1.`&`
在命令的后面加上`&`表示后台执行的意思
```
command &
```
2.`;`
在命令之间用`;`项链，表示顺序执行的意思
```
command1 ;command2
```
3.`&&`
命令之间以`&&`相连时，只有前一个命令成功执行则执行第二个命令
```
command1 && command2
```
4.`||`
命令之间以`||`相连时，如果前一个命令执行失败，则执行第二个命令
```
command1 || command2
```
5.``
命令中如果包含另一个命令，则用符号｀｀将它包起来，优先执行｀｀中的子命令，然后将其结果代入父命令继续执行
```shell
command1 ` command2`
```
6.`ctrl + z`
暂时挂起
7.`bg`
挂起的命令后台执行
8.`fg`
后台执行的命令前台执行
9.`jobs`
查看后台所有挂起的任务及编号

```shell
fangsong@fangsong-FX503VD:~$ ping baidu.com
PING baidu.com (39.156.69.79) 56(84) bytes of data.
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=1 ttl=51 time=20.6 ms
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=2 ttl=51 time=22.4 ms
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=3 ttl=51 time=21.9 ms
^Z
[1]+  已停止               ping baidu.com
fangsong@fangsong-FX503VD:~$ jobs
[1]+  已停止               ping baidu.com
fangsong@fangsong-FX503VD:~$ fg
ping baidu.com
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=4 ttl=51 time=21.7 ms
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=5 ttl=51 time=21.9 ms
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=6 ttl=51 time=21.6 ms
^C
--- baidu.com ping statistics ---
6 packets transmitted, 6 received, 0% packet loss, time 360ms
rtt min/avg/max/mdev = 20.600/21.683/22.444/0.584 ms
```

#### 管道，重定向

管道｜

1.`>`
重定向符
2.`>>`
作用与>基本相同，不同的是>>将内容追加到文件的末尾，而>内容覆盖原文件
3.`<`
与>相反，是从文件到命令的重定向。他讲文件的内容输出到命令作为输入
4.`<<`
？

```shell
Num=`cat /dev/urandom | head -n 10 | cksum | cut -d ' ' -f 1`
```

此处就是管道，将前面的输出作为输入给后面

```shell
fangsong@fangsong-FX503VD:~/Mycode/2.f$ ./a.out < in.txt
```

```shell
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat > a.log <<EOF
> fs
> EOF
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat a.log
fs
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat >> a.log <<EOF
> fangsong
> EOF
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat a.log
fs
fangsong
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat > a.log <<EOF #EOF结束标志
> 0
> EOF #也可以换成其他的东西XXX
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat a.log
0
fangsong@fangsong-FX503VD:~/Mycode/2.f$ 
```

# 系统信息的获取

#### 系统信息

>uptime 打印系统运行时长和平均负载
>
>who显示当前登录系统用户信息
>
>last显示用户最近登录用户信息
>
>date显示或设置系统时间与日期
>
>w当前登录用户列表及正在执行的任务
>
>whoami打印当前有效的用户名称
>
>uname打印当前系统信息
>
>cal显示日历

#### uptime

```shell
fangsong@fangsong-FX503VD:~$ uptime
 08:26:41 up 11 min,  1 user,  load average: 0.75, 1.41, 0.97
```

#### w

```
-h :不打印头信息
-s :是hi用端输出格式
-f :切换FROM项
```

```shell
fangsong@fangsong-FX503VD:~$ w
 08:28:23 up 12 min,  1 user,  load average: 0.86, 1.27, 0.97
USER     TTY      来自           LOGIN@   IDLE   JCPU   PCPU WHAT
fangsong :0       :0               08:17   ?xdm?   1:46   0.01s /usr/lib/gdm3/g
fangsong@fangsong-FX503VD:~$ w -h
fangsong :0       :0               08:17   ?xdm?   1:49   0.01s /usr/lib/gdm3/g
fangsong@fangsong-FX503VD:~$ w -s
 08:28:39 up 13 min,  1 user,  load average: 0.75, 1.23, 0.96
USER     TTY      来自            空闲等待
fangsong :0       :0               ?xdm?  /usr/lib/gdm3/gdm-x-session --run-s
fangsong@fangsong-FX503VD:~$ w -f
 08:28:48 up 13 min,  1 user,  load average: 0.63, 1.19, 0.95
USER     TTY        LOGIN@   IDLE   JCPU   PCPU WHAT
fangsong :0        08:17   ?xdm?   1:49   0.01s /usr/lib/gdm3/gdm-x-session --r
fangsong@fangsong-FX503VD:~$ 

```

| USER       | TTY                  | FROM       | LOGIN@   | IDLE     | JCPU                                                   | PCPU             | WHAT                     |
| ---------- | -------------------- | ---------- | -------- | -------- | ------------------------------------------------------ | ---------------- | ------------------------ |
| 登录用户名 | 登录后系统分配的端号 | 登录主机名 | 登录时间 | 空闲时间 | 和终端相连的所有进程所占用时间，当前正在执行的后台作业 | 当前进程占用时间 | 当前进程正在执行的的命令 |

#### who

```shell
fangsong@fangsong-FX503VD:~$ who -H #显示各栏标题新系列
名称   线路       时间           备注
fangsong :0           2020-03-15 08:17 (:0)
fangsong@fangsong-FX503VD:~$ who -q#登录用户总人数
fangsong
# 用户数=1
fangsong@fangsong-FX503VD:~$ who -a
           系统引导 2020-03-15 08:15
           运行级别 5 2020-03-15 08:16
fangsong ? :0           2020-03-15 08:17   ?          1763 (:0)
fangsong@fangsong-FX503VD:~$ who -u#显示空闲时间
fangsong :0           2020-03-15 08:17   ?          1763 (:0)

```

#### LAST

显示用户最近登录用户信息

```shell
fangsong@fangsong-FX503VD:~$ last -n 5#指定输出记录数
fangsong :0           :0               Sun Mar 15 08:17   still logged in
reboot   system boot  5.0.0-38-generic Sun Mar 15 08:15   still running
fangsong :0           :0               Sat Mar 14 10:08 - down   (13:37)
reboot   system boot  5.0.0-38-generic Sat Mar 14 10:06 - 23:45  (13:38)
fangsong :0           :0               Fri Mar 13 16:55 - 00:41  (07:45)

wtmp begins Mon Nov 25 15:04:07 2019

```

#### uname

```shell
fangsong@fangsong-FX503VD:~$ uname -a#全部信息
Linux fangsong-FX503VD 5.0.0-38-generic #41-Ubuntu SMP Tue Dec 3 00:27:35 UTC 2019 x86_64 x86_64 x86_64 GNU/Linux
fangsong@fangsong-FX503VD:~$ uname -m#电脑类型
x86_64
fangsong@fangsong-FX503VD:~$ uname -n#网络上主机的名称
fangsong-FX503VD
fangsong@fangsong-FX503VD:~$ uname -v#os版本
#41-Ubuntu SMP Tue Dec 3 00:27:35 UTC 2019
fangsong@fangsong-FX503VD:~$ uname -p#处理器类型
x86_64
fangsong@fangsong-FX503VD:~$ uname -i#硬件
x86_64
fangsong@fangsong-FX503VD:~$ uname -o#操作系统名称
GNU/Linux
```

#### date

ntp协议：标准的时间

```shell
fangsong@fangsong-FX503VD:~$ date
2020年 03月 15日 星期日 08:43:00 CST
fangsong@fangsong-FX503VD:~$ date +%s
1584232994
fangsong@fangsong-FX503VD:~$ date +%S
22
fangsong@fangsong-FX503VD:~$ date +%T
08:43:31
fangsong@fangsong-FX503VD:~$ date +%H+%M+%S
08+43+55
```

# 基本系统



#### 目录结构

![2020-03-15 09-33-20屏幕截图.png](https://github.com/fangsong0517/Figure-bed/blob/master/2020-03-15%2009-33-20%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png?raw=true)
![2020-03-15 09-43-10屏幕截图.png](https://github.com/fangsong0517/Figure-bed/blob/master/2020-03-15%2009-43-10%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png?raw=true)
![2020-03-15 09-43-36屏幕截图.png](https://github.com/fangsong0517/Figure-bed/blob/master/2020-03-15%2009-43-36%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png?raw=true)

* **/bin**：
  bin是Binary的缩写, 这个目录存放着最经常使用的命令。

* **/boot：**
  这里存放的是启动Linux时使用的一些核心文件，包括一些连接文件以及镜像文件。

* **/dev ：**
  dev是Device(设备)的缩写, 该目录下存放的是Linux的外部设备，在Linux中访问设备的方式和访问文件的方式是相同的。

* **/etc：**
  这个目录用来存放所有的系统管理所需要的配置文件和子目录。

* **/home**：
  用户的主目录，在Linux中，每个用户都有一个自己的目录，一般该目录名是以用户的账号命名的。

* **/lib**：
  这个目录里存放着系统最基本的动态连接共享库，其作用类似于Windows里的DLL文件。几乎所有的应用程序都需要用到这些共享库。

* **/lost+found**：
  这个目录一般情况下是空的，当系统非法关机后，这里就存放了一些文件。

* **/media**：
  linux系统会自动识别一些设备，例如U盘、光驱等等，当识别后，linux会把识别的设备挂载到这个目录下。

* **/mnt**：
  系统提供该目录是为了让用户临时挂载别的文件系统的，我们可以将光驱挂载在/mnt/上，然后进入该目录就可以查看光驱里的内容了。

* **/opt**：
   这是给主机额外安装软件所摆放的目录。比如你安装一个ORACLE数据库则就可以放到这个目录下。默认是空的。

* **/proc**：
  这个目录是一个虚拟的目录，它是系统内存的映射，我们可以通过直接访问这个目录来获取系统信息。
  这个目录的内容不在硬盘上而是在内存里，我们也可以直接修改里面的某些文件，比如可以通过下面的命令来屏蔽主机的ping命令，使别人无法ping你的机器：

* **/root**：
  该目录为系统管理员，也称作超级权限者的用户主目录。

* **/sbin**：
  s就是Super User的意思，这里存放的是系统管理员使用的系统管理程序。

* **/selinux**：
   这个目录是Redhat/CentOS所特有的目录，Selinux是一个安全机制，类似于windows的防火墙，但是这套机制比较复杂，这个目录就是存放selinux相关的文件的。

* **/srv**：
   该目录存放一些服务启动之后需要提取的数据。

* **/sys**：

   这是linux2.6内核的一个很大的变化。该目录下安装了2.6内核中新出现的一个文件系统 sysfs 。

  sysfs文件系统集成了下面3种文件系统的信息：针对进程信息的proc文件系统、针对设备的devfs文件系统以及针对伪终端的devpts文件系统。该文件系统是内核设备树的一个直观反映。

  当一个内核对象被创建的时候，对应的文件和目录也在内核对象子系统中被创建
  
* **/tmp**：
这个目录是用来存放一些临时文件的。
  
* **/usr**：
 这是一个非常重要的目录，用户的很多应用程序和文件都放在这个目录下，类似于windows下的program files目录。
  
* **/usr/bin：**
  系统用户使用的应用程序。

* **/usr/sbin：**
  超级用户使用的比较高级的管理程序和系统守护程序。

* **/usr/src：**
  内核源代码默认的放置目录。

* **/var**：
  这个目录中存放着在不断扩充着的东西，我们习惯将那些经常被修改的目录放在这个目录下。包括各种日志文件。

* **/run**：
  是一个临时文件系统，存储系统启动以来的信息。当系统重启时，这个目录下的文件应该被删掉或清除。如果你的系统上有 /var/run 目录，应该让它指向 run。

**/etc**： 上边也提到了，这个是系统中的配置文件，如果你更改了该目录下的某个文件可能会导致系统不能启动。

**/bin, /sbin, /usr/bin, /usr/sbin**: 这是系统预设的执行文件的放置目录，比如 ls 就是在/bin/ls 目录下的。

值得提出的是，/bin, /usr/bin 是给系统用户使用的指令（除root外的通用户），而/sbin, /usr/sbin 则是给root使用的指令。

**/var**： 这是一个非常重要的目录，系统上跑了很多程序，那么每个程序都会有相应的日志产生，而这些日志就被记录到这个目录下，具体在/var/log 目录下，另外mail的预设放置也是在这里。

# 文件与目录操作

```shell
[root@www /]# ls -l
total 64
dr-xr-xr-x   2 root root 4096 Dec 14  2012 bin
dr-xr-xr-x   4 root root 4096 Apr 19  2012 boot
```

实例中，bin文件的第一个属性用"d"表示。"d"在Linux中代表该文件是一个目录文件。

在Linux中第一个字符代表这个文件是目录、文件或链接文件等等。

- 当为[ **d** ]则是目录
- 当为[ **-** ]则是文件；
- 若是[ **l** ]则表示为链接文档(link file)；
- 若是[ **b** ]则表示为装置文件里面的可供储存的接口设备(可随机存取装置)；
- 若是[ **c** ]则表示为装置文件里面的串行端口设备，例如键盘、鼠标(一次性读取装置)。

![363003_1227493859FdXT](https://www.runoob.com/wp-content/uploads/2014/06/363003_1227493859FdXT.png)

#### chgrp：更改文件属组

语法：

```
chgrp [-R] 属组名 文件名
```

参数选项

- -R：递归更改文件属组，就是在更改某个目录文件的属组时，如果加上-R的参数，那么该目录下的所有文件的属组都会更改。

#### chown：更改文件属主，也可以同时更改文件属组

语法：

```
chown [–R] 属主名 文件名
chown [-R] 属主名：属组名 文件名
```

进入 /root 目录（~）将install.log的拥有者改为bin这个账号：

```shell
[root@www ~] cd ~
[root@www ~]# chown bin install.log
[root@www ~]# ls -l
-rw-r--r--  1 bin  users 68495 Jun 25 08:53 install.log
```

将install.log的拥有者与群组改回为root：

```shell
[root@www ~]# chown root:root install.log
[root@www ~]# ls -l
-rw-r--r--  1 root root 68495 Jun 25 08:53 install.log
```

#### chmod：更改文件9个属性

Linux文件属性有两种设置方法，一种是数字，一种是符号。

Linux文件的基本权限就有九个，分别是owner/group/others三种身份各有自己的read/write/execute权限。

先复习一下刚刚上面提到的数据：文件的权限字符为：『-rwxrwxrwx』， 这九个权限是三个三个一组的！其中，我们可以使用数字来代表各个权限，各权限的分数对照表如下：

- r:4
- w:2
- x:1

每种身份(owner/group/others)各自的三个权限(r/w/x)分数是需要累加的，例如当权限为： [-rwxrwx---] 分数则是：

- owner = rwx = 4+2+1 = 7
- group = rwx = 4+2+1 = 7
- others= --- = 0+0+0 = 0

所以等一下我们设定权限的变更时，该文件的权限数字就是770啦！变更权限的指令chmod的语法是这样的：

```shell
 chmod [-R] xyz 文件或目录
```

选项与参数：

- xyz : 就是刚刚提到的数字类型的权限属性，为 rwx 属性数值的相加。
- -R : 进行递归(recursive)的持续变更，亦即连同次目录下的所有文件都会变更

举例来说，如果要将.bashrc这个文件所有的权限都设定启用，那么命令如下：

```shell
[root@www ~]# ls -al .bashrc
-rw-r--r--  1 root root 395 Jul  4 11:45 .bashrc
[root@www ~]# chmod 777 .bashrc
[root@www ~]# ls -al .bashrc
-rwxrwxrwx  1 root root 395 Jul  4 11:45 .bashrc
```

那如果要将权限变成 *-rwxr-xr--* 呢？那么权限的分数就成为 [4+2+1][4+0+1][4+0+0]=754。

#### 符号类型改变文件权限

还有一个改变权限的方法，从之前的介绍中我们可以发现，基本上就九个权限分别是：

- (1)user
- (2)group
- (3)others

那么我们就可以使用 **u, g, o** 来代表三种身份的权限！

此外， **a** 则代表 **all**，即全部的身份。读写的权限可以写成 **r, w, x**，也就是可以使用下表的方式来看：

|       |      |         |      |            |
| ----- | ---- | ------- | ---- | ---------- |
|       | u    | +(加入) | r    |            |
| chmod | g    | -(除去) | w    | 文件或目录 |
|       | o    | =(设定) | x    |            |
|       | a    |         |      |            |



如果我们需要将文件权限设置为 **-rwxr-xr--** ，可以使用 **chmod u=rwx,g=rx,o=r 文件名** 来设定:

```shell
#  touch test1    // 创建 test1 文件
# ls -al test1    // 查看 test1 默认权限
-rw-r--r-- 1 root root 0 Nov 15 10:32 test1
# chmod u=rwx,g=rx,o=r  test1    // 修改 test1 权限
# ls -al test1
-rwxr-xr-- 1 root root 0 Nov 15 10:32 test1
```

而如果是要将权限去掉而不改变其他已存在的权限呢？例如要拿掉全部人的可执行权限，则：

```shell
#  chmod  a-x test1
# ls -al test1
-rw-r--r-- 1 root root 0 Nov 15 10:32 test1
```

- **绝对路径：**
  路径的写法，由根目录 / 写起，例如： /usr/share/doc 这个目录。
- **相对路径：**
  路径的写法，不是由 / 写起，例如由 /usr/share/doc 要到 /usr/share/man 底下时，可以写成： cd ../man 这就是相对路径的写法啦！

#### CD切换工作目录

```shell
cd /etc #直接切换到/etc目录
cd .. #切换到上层目录
cd . #切换到当前目录
cd #回到自己的家目录
cd ~#回到自己的家目录
cd -#回到上次的工作目录
```

#### PWD

```shell
L 显示逻辑工作目录
P 显示物理工作目录
```

pwd 是 **Print Working Directory** 的缩写，也就是显示目前所在目录的命令。

```
[root@www ~]# pwd [-P]
```

选项与参数：

- **-P** ：显示出确实的路径，而非使用连结 (link) 路径。

实例：单纯显示出目前的工作目录：

```shell
[root@www ~]# pwd
/root   <== 显示出目录啦～
```

实例显示出实际的工作目录，而非连结档本身的目录名而已。

```shell
[root@www ~]# cd /var/mail   <==注意，/var/mail是一个连结档
[root@www mail]# pwd
/var/mail         <==列出目前的工作目录
[root@www mail]# pwd -P
/var/spool/mail   <==怎么回事？有没有加 -P 差很多～
[root@www mail]# ls -ld /var/mail
lrwxrwxrwx 1 root root 10 Sep  4 17:54 /var/mail -> spool/mail
# 看到这里应该知道为啥了吧？因为 /var/mail 是连结档，连结到 /var/spool/mail 
# 所以，加上 pwd -P 的选项后，会不以连结档的数据显示，而是显示正确的完整路径啊！
```

#### MkDIR创建目录

```shell
-p 自动创建父目录：帮助你直接将所需要的目录(包含上一级目录)递归创建起来！
-m 设置权限：配置文件的权限喔！直接配置，不需要看默认权限 (umask) 的脸色～
```

实例：请到/tmp底下尝试创建数个新目录看看：

```shell
[root@www ~]# cd /tmp
[root@www tmp]# mkdir test    <==创建一名为 test 的新目录
[root@www tmp]# mkdir test1/test2/test3/test4
mkdir: cannot create directory `test1/test2/test3/test4': 
No such file or directory       <== 没办法直接创建此目录啊！
[root@www tmp]# mkdir -p test1/test2/test3/test4
```

加了这个 -p 的选项，可以自行帮你创建多层目录！

实例：创建权限为 **rwx--x--x** 的目录。

```shell
[root@www tmp]# mkdir -m 711 test2
[root@www tmp]# ls -l
drwxr-xr-x  3 root  root 4096 Jul 18 12:50 test
drwxr-xr-x  3 root  root 4096 Jul 18 12:53 test1
drwx--x--x  2 root  root 4096 Jul 18 12:54 test2
```

上面的权限部分，如果没有加上 -m 来强制配置属性，系统会使用默认属性。

如果我们使用 -m ，如上例我们给予 -m 711 来给予新的目录 drwx--x--x 的权限。

#### RMDIR删除目录

```shell
p删除祖先
-p ：连同上一级『空的』目录也一起删除
```

删除 runoob 目录

```
[root@www tmp]# rmdir runoob/
```

将 mkdir 实例中创建的目录(/tmp 底下)删除掉！

```
[root@www tmp]# rmdir -p test1/test2/test3/test4
[root@www tmp]# ls -l        <==您看看，底下的输出中test与test1不见了！
```

利用 -p 这个选项，立刻就可以将 test1/test2/test3/test4 一次删除。

不过要注意的是，这个 rmdir 仅能删除空的目录，你可以使用 rm 命令来删除非空目录。

#### CP

cp 即拷贝文件和目录。

```shell
-i :若文件存在，询问用户
-r :递归赋值
-a ：pdr的集合
-p: 连同文件属性一起复制
-d:若源文件为链接文件的属性，则赋值链接文件的属性
-s:拷贝为软连接
-l:拷贝为硬链接
-u：原文件比目的文件新才拷贝
```

用 root 身份，将 root 目录下的 .bashrc 复制到 /tmp 下，并命名为 bashrc

```shell
[root@www ~]# cp ~/.bashrc /tmp/bashrc
[root@www ~]# cp -i ~/.bashrc /tmp/bashrc
cp: overwrite `/tmp/bashrc'? n  <==n不覆盖，y为覆盖
```

#### RM

```
 rm [-fir] 文件或目录
```

```shell
-i :互动模式互动模式，在删除前会询问使用者是否动作
-r :递归删除递归删除啊！最常用在目录的删除了！这是非常危险的选项！！！
-f：force忽略不存在的文件，不会出现警告信息；
```





#### MV

移动文件与目录，或修改名称

```shell
[root@www ~]# mv [-fiu] source destination
[root@www ~]# mv [options] source1 source2 source3 .... directory
```

```shell
-i :互动模式若目标文件 (destination) 已经存在时，就会询问是否覆盖！
-f：force强制的意思，如果目标文件已经存在，不会询问而直接覆盖；
-u:源文件跟新才会移动若目标文件已经存在，且 source 比较新，才会升级 (update)
```

复制一文件，创建一目录，将文件移动到目录中

```
[root@www ~]# cd /tmp
[root@www tmp]# cp ~/.bashrc bashrc
[root@www tmp]# mkdir mvtest
[root@www tmp]# mv bashrc mvtest
```

将某个文件移动到某个目录去，就是这样做！

将刚刚的目录名称更名为 mvtest2

```
[root@www tmp]# mv mvtest mvtest2
```

### Linux 文件内容查看

Linux系统中使用以下命令来查看文件的内容：

- cat 由第一行开始显示文件内容
- tac 从最后一行开始显示，可以看出 tac 是 cat 的倒著写！
- nl  显示的时候，顺道输出行号！
- more 一页一页的显示文件内容
- less 与 more 类似，但是比 more 更好的是，他可以往前翻页！
- head 只看头几行
- tail 只看尾巴几行

#### CAT

```shell
-A:相当于-VET
-v:列出看不到的字符
-E:显示断行符为￥
-T：显示TAB为^I
-b:列出行号列出行号，仅针对非空白行做行号显示，空白行不标行号！
-n:列出行号，空行也编号
```

#### TAC

tac与cat命令刚好相反，文件内容从最后一行开始显示，可以看出 tac 是 cat 的倒着写！如：

```shell
[root@www ~]# tac /etc/issue

Kernel \r on an \m
CentOS release 6.4 (Final)
```

#### NL输出行号显示文件

```
nl [-bnw] 文件
```

```shell
-b a:相当于cat -a表示不论是否为空行，也同样列出行号
-b t:相当于cat -b如果有空行，空的那一行不要列出行号
-n ln:行号在屏幕的最左边显示
-n rn:行号在自己字段的最右边显示且不加 0 
-n rz:行号在自己字段的最右边显示，前面自动补0
-w <num>：行号所占位数
```

实例一：用 nl 列出 /etc/issue 的内容

```
[root@www ~]# nl /etc/issue
     1  CentOS release 6.4 (Final)
     2  Kernel \r on an \m
```

#### HEAD查看头几行

```shell
head [-n num] <file>
-n num:显示前几行
-n -num:除后几行外，其他都显示
```

取出文件前面几行

语法：

```
head [-n number] 文件 
```

选项与参数：

- -n ：后面接数字，代表显示几行的意思

```
[root@www ~]# head /etc/man.config
```

默认的情况中，显示前面 10 行！若要显示前 20 行，就得要这样：

```
[root@www ~]# head -n 20 /etc/man.config
```

#### TAIL查看末尾几行

```shell
tail [-n num] <file>
-n num:显示文件后num行
-n +num:除前几行外，其他都显示
```

选项与参数：

- -n ：后面接数字，代表显示几行的意思
- -f ：表示持续侦测后面所接的档名，要等到按下[ctrl]-c才会结束tail的侦测

```
[root@www ~]# tail /etc/man.config
# 默认的情况中，显示最后的十行！若要显示最后的 20 行，就得要这样：
[root@www ~]# tail -n 20 /etc/man.config
```

#### 文件时间及隐藏属性

> 文件的三个时间
>
> >mtime :内容数据改动时才更新这个时间
> >
> >ctime:文件的权限，文件改动更新这个时间
> >
> >atime:文件的内容被取用access时，更新这个时间

```shell
ls -l --time=ctime /etc/hostname
```

ls -l #是行列表形式
--time=ctime# 显示这个时间为ctime, --后面通常加原型
每个文件都有这三种属性

#### 修改文件时间与新建文件

>touch [-acdmt] <file>
>
>>-a:仅修改访问时间
>>-c:金修改文件的时间，若文件不存在，不新建
>>-d:修改文件日期
>>-m:金修改mtime
>>-t:修改文件时间[yymmddhhmm]

#### 文件隐藏属性

>chattr [+-=] [ASacdistu] <file_or_dir>
>
>A:不修改atime 
>S:同步写入 //不缓存直接写到磁盘上，例如银行
>a:只能增加数据　//通常用在日志上
>c:自动压缩，解压 
>d:不会被dump程序备份
>i:不能删除修改建立连接 //写死了
>s:文件删除时，直接从磁盘删除
>u:文件删除时，文件内容存在磁盘中

#### 文件的特殊权限

> set_uid    s占位符       作用二进制程序文件，费脚本　　　　　用户在执行该程序时获取程序所有者权限
> set_git　s占位符        目录和二进制文件　　　　　　　　　　用户在该目录下，有效组变为目录所属组
> sticky Bit　t占位符　　目录　　　　　　　　　再改目录下，用户只能删除自己穿就爱你的内容

 

# 文件与目录操作、实现ls命令

#### 如何在Linux中查找文件

| 命令   | 功能                 | 命令    | 功能           |
| ------ | -------------------- | ------- | -------------- |
| which  | 寻找可执行文件       | whereis | 寻找特定文件   |
| locate | 搜索文件(可部分查找) | find    | 多样化高级查找 |

* which寻找可执行文件

```shell
fangsong@fangsong-FX503VD:~$ ls -a `which ping`
/usr/bin/ping
```

* whereis寻找特定文件

  -b:查找二进制文件

  -m:查找man手册

  -s:查找source源文件

```shell
fangsong@fangsong-FX503VD:~$ whereis ping
ping: /usr/bin/ping /usr/share/man/man8/ping.8.gz
```

* locate模糊定义

  -i:忽略大小写

  -r:后面可接正则表达式

```shell
fangsong@fangsong-FX503VD:~$ locate prime.cpp
/home/fangsong/Mycode/1.c语言/4/1.prime.cpp
/home/fangsong/Mycode/2.EP/prime.cpp
/home/fangsong/Mycode/2.f/prime.cpp
```

* find高级查找

  find [path] [option] [action]

  与时间相关的参数：-atime -ctime -mtime

  -mtime n : ｎ天前的"一天之内"修改的文件 amin

  -mtime +n: n天之前，不包含ｎ，修改过的文件

  -mtime -n:ｎ天之内，包含ｎ，修改过的文件

  -newer file:比file 还要新的文件

  与用户或者用户组相关的参数：

  -uid n:用户UID为ｎ

  -gid n:群组GID为ｎ

  -user name:用户名为name

  -group name:群组名为name

  nouser:文件所有者不存在

  nogroup:文件所有组不存在

  与文件权限名称有关的参数：

  -name filename: 文件名为filrname

  -size [+-] SIZE:查找比SIZE大或小的

  -type TYPE：f b c d l s p

  -perm mode : mode 刚好等于的文件

  -perm -mode: 全部包含mode的文件

```shell
find -exec ls -l {} \;

find . -name "*.cpp" -mtime -1 -exec wc -l {} \ #一天前.cpp文件的统计行数
```

查找家目录下所有.cpp,.c,.sh,.h的行数总和

```shell
find ~ -name "*.cpp" -o -name "*.c" -o -name "*.h" -o -name "*.sh" | xargs wc -l
```





#### 实现ls需要用到的函数

##### opendir()

**头文件**
　　#include<sys/types.h>
　　#include<dirent.h>
**函数原型**
　　DIR* opendir (const char * path ); （获取path子目录下的所由文件和目录的列表，如果path是个文件则返回值为NULL）
**功能**
　　<font color= red>打开一个目录，在失败的时候返回一个空的指针。</font>
**返回值(DIR)**
       DIR 结构体的原型为：struct_dirstream
       在Linux系统中：

```c
 typedef struct __dirstream DIR;

       struct __dirstream
       {
         void *__fd; /* `struct hurd_fd' pointer for descriptor.   */
         char *__data; /* Directory block.   */
         int __entry_data; /* Entry number `__data' corresponds to.   */
         char *__ptr; /* Current pointer into the block.   */
         int __entry_ptr; /* Entry number `__ptr' corresponds to.   */
         size_t __allocation; /* Space allocated for the block.   */
         size_t __size; /* Total valid data in the block.   */
         __libc_lock_define (, __lock) /* Mutex lock for this structure.   */
        };
```

##### readdir()

**头文件**
#include<dirent.h>
**函数原型**
struct dirent* readdir(DIR* dir_handle); （个人理解循环读取dir_handle,目录和文件都读）
**功能**
<font color = red>读取opendir 返回值的那个列表</font>
**返回值**
返回dirent结构体指针，dirent结构体成员如下，（文件和目录都行）

```c
struct dirent
　　{
　　long d_ino; /* inode number 索引节点号 */
　　off_t d_off; /* offset to this dirent 在目录文件中的偏移 */
　　unsigned short d_reclen; /* length of this d_name 文件名长 */
　　unsigned char d_type; /* the type of d_name 文件类型 */
　　char d_name [NAME_MAX+1]; /* file name (null-terminated) 文件名，最长255字符 */
　　}
```

##### perror()

<font color = red>将上一个函数发生错误的原因输出</font>

##### closedir()

```c
#include<sys/types.h>
#include<dirent.h>
int closedir(DIR *dir);
```

​     closedir()关闭参数dir所指的目录流。关闭成功则返回0，失败返回-1，错误原因存于errno 中。EBADF 参数dir为无效的目录流。注意：目录文件作为一种文件，再打开必须关闭，否则会由于文件的进程打开文件过多而不能打开新的文件。因此opendir函数和closedir函数同样是配对出现的

##### stat函数

 作用：<font color = red>获取文件信息</font>

 头文件：include <sys/types.h> #include <sys/stat.h> #include <unistd.h>

 函数原型：```int stat(const char *path, struct stat *buf)```

 返回值：成功返回0，失败返回-1；

 参数：文件路径（名），struct stat 类型的结构体

struct stat 结构体详解：

```c
struct stat
{
    dev_t     st_dev;     /* ID of device containing file */文件使用的设备号
    ino_t     st_ino;     /* inode number */    索引节点号 
    mode_t    st_mode;    /* protection */  文件对应的模式，文件，目录等
    nlink_t   st_nlink;   /* number of hard links */    文件的硬连接数  
    uid_t     st_uid;     /* user ID of owner */    所有者用户识别号
    gid_t     st_gid;     /* group ID of owner */   组识别号  
    dev_t     st_rdev;    /* device ID (if special file) */ 设备文件的设备号
    off_t     st_size;    /* total size, in bytes */ 以字节为单位的文件容量   
    blksize_t st_blksize; /* blocksize for file system I/O */ 包含该文件的磁盘块的大小   
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */ 该文件所占的磁盘块  
    time_t    st_atime;   /* time of last access */ 最后一次访问该文件的时间   
    time_t    st_mtime;   /* time of last modification */ /最后一次修改该文件的时间   
    time_t    st_ctime;   /* time of last status change */ 最后一次改变该文件状态的时间   
};
```


stat结构体中的st_mode 则定义了下列数种情况：

    S_IFMT   0170000    文件类型的位遮罩
    S_IFSOCK 0140000    套接字
    S_IFLNK 0120000     符号连接
    S_IFREG 0100000     一般文件
    S_IFBLK 0060000     区块装置
    S_IFDIR 0040000     目录
    S_IFCHR 0020000     字符装置
    S_IFIFO 0010000     先进先出
    
    S_ISUID 04000     文件的(set user-id on execution)位
    S_ISGID 02000     文件的(set group-id on execution)位
    S_ISVTX 01000     文件的sticky位
    
    S_IRUSR(S_IREAD) 00400     文件所有者具可读取权限
    S_IWUSR(S_IWRITE)00200     文件所有者具可写入权限
    S_IXUSR(S_IEXEC) 00100     文件所有者具可执行权限
    
    S_IRGRP 00040             用户组具可读取权限
    S_IWGRP 00020             用户组具可写入权限
    S_IXGRP 00010             用户组具可执行权限
    
    S_IROTH 00004             其他用户具可读取权限
    S_IWOTH 00002             其他用户具可写入权限
    S_IXOTH 00001             其他用户具可执行权限
    
    上述的文件类型在POSIX中定义了检查这些类型的宏定义：
    S_ISLNK (st_mode)    判断是否为符号连接
    S_ISREG (st_mode)    是否为一般文件
    S_ISDIR (st_mode)    是否为目录
    S_ISCHR (st_mode)    是否为字符装置文件
    S_ISBLK (s3e)        是否为先进先出
    S_ISSOCK (st_mode)   是否为socket
    若一目录具有sticky位(S_ISVTX)，则表示在此目录下的文件只能被该文件所有者、此目录所有者或root来删除或改名，在linux中，最典型的就是这个/tmp目录啦。

st_mode 的结构

st_mode 主要包含了 3 部分信息：

15-12 位保存文件类型

11-9 位保存执行文件时设置的信息

8-0 位保存文件访问权限

##### getpwuid()

头文件：#include <sys/types.h>  #include <pwd.h>

getpwuid函数是通过用户的uid查找用户的passwd数据。如果出错时，它们都返回一个空[指针](https://baike.baidu.com/item/指针/2878304)并设置errno的值，用户可以根据perror函数查看出错的信息。

函数说明

<font color =red>查找用户的passwd数据</font>

```c
和系统数据相关的passwd 结构 
和系统数据相关的一个结构passwd定义如下 
/* The passwd structure.      */ 
struct passwd 
{ 
      char *pw_name;       /* 用户名*/ 
      char *pw_passwd;     /* 密码.*/ 
      __uid_t pw_uid;      /* 用户ID.*/ 
      __gid_t pw_gid;      /*组ID.*/ 
      char *pw_gecos;      /*真实名*/ 
      char *pw_dir;        /* 主目录.*/ 
      char *pw_shell;      /*使用的shell*/ 
}; 

#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <pwd.h> 
int main (void) 
{ 
       struct passwd *passwd; 
       passwd=getpwuid(getuid()); 
       /** passwd=getcwnam("phpos"); **/ 
       printf("Username:%s/n",passwd->pw_name); 
       printf("Password:%s/n",passwd->pw_passwd); 
       printf("uid:%d/n",passwd->pw_uid); 
       printf("gid:%d/n",passwd->pw_gid); 
       printf("shell:%s/n",passwd->pw_shell); 
       printf("dir:%s/n",passwd->pw_dir); 
       return 0; 
} 
```

##### getgrgid()

**C语言getgrgid()函数：从组文件中取得指定gid的数据**

头文件：

```
#include <grp.h>  #include <sys/types.h>
```

定义函数：

```
strcut group * getgrgid(gid_t gid);
```

函数说明：getgrgid()用来依参数gid 指定的组识别码逐一搜索组文件, 找到时便将该组的数据以group 结构返回. 返回值：返回 group 结构数据, 如果返回NULL 则表示已无数据, 或有错误发生.

通过gid,找到该组的相关信息,并以group结构体返回其信息, 头文件:#include <grp.h>,#include <sys/types.h> 参数     文件所属组的组id; 返回值:成功返回group结构体,错误返回NULL; group结构体: struct group { char *gr_name; /*组名称*/ char *gr_passwd; /* 组密码*/ gid_t gr_gid; /*组识别码*/ char **gr_mem; /*组成员账号*/ } 看个例子:

范例

```
/* 取得gid＝3 的组数据 */
#include <grp.h>
#include <sys/types.h>
main()
{
  strcut group *data;
  int i = 0;
  data = getgrgid(3);
  printf("%s:%s:%d:", data->gr_name, data->gr_passwd, data->gr_gid);
    while(data->gr_mem[i])
    printf("%s, ", data->mem[i++]);
    printf("\n");
}
```

```c
    struct passwd  
    {  
        char * pw_name; /* Username, POSIX.1 */  
        char * pw_passwd; /* Password */  
        __uid_t pw_uid; /* User ID, POSIX.1 */  
        __gid_t pw_gid; /* Group ID, POSIX.1 */  
        char * pw_gecos; /* Real Name or Comment field */  
        char * pw_dir; /* Home directory, POSIX.1 */  
        char * pw_shell; /* Shell Program, POSIX.1 */  
    };  

    struct group
    {
        char *gr_name;  /* Group name */
        char *gr_passwd;  /* password */
        __gid_t gr_gid;  /* Group ID */
        char **gr_mem;  /* Member list */
    }
    #endif//
```

#### 完整代码

```c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<sys/ioctl.h>
#include<sys/stat.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>
#define FILEMAX 1024
#define NAMEMAX 256
int flag_a = 0;
int flag_l = 0;

int fg_c, bg_c;

char names[FILEMAX][NAMEMAX];

void size_window(char filename[][NAMEMAX],int cnt, int *row,int *col) {
    struct winsize size;
    int len[cnt] , max = 0, total = 0;
    memset(len, 0, sizeof(int)*cnt);
    /*if(isatty(STDOUT_DILENO) == 0) {
        exit(1);
    }*/
    //struct winsize size;
    //ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    if(ioctl(STDIN_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctal");
        exit(1);
    }
    printf("window size row = %d, col = %d\n", size.ws_row, size.ws_col);
    for(int i = 0; i < cnt; i++) {
        len[i] = strlen(filename[i]);
        if(max < len[i])max = len[i];
        total += len[i] + 1;
    }
    if(max + 1 >= size.ws_col) {
        *row = cnt;
        *col = 1;
        return;
    }
    if(total <= size.ws_col) {
        *row = 1;
        *col = cnt;
        return;
    }
    int try_begin = 0;
    for(int i = 0, tmp = 0; i < cnt; i++) {
        tmp += (len[i] + 1);
        if(tmp >= size.ws_col) {
            try_begin = i;
            break;
        }
    }
    for(int i = try_begin;;i--) {
        int *wide = (int *)malloc(sizeof(int) * i);
        memset(wide, 0, sizeof(int) * i);
        *row =(int)ceil(cnt / i);
        int try_sum = 0;
        for(int x = 0; x < i; x ++) {
            for(int y = x * *row; y < (x + 1) * *row && y < cnt; y++) {
                if(wide[x] < len[y])wide[x] = len[y];
            }
            try_sum += (wide[x] + 1);
        }
        if(try_sum > size.ws_col)continue;
        if(try_sum <= size.ws_col) {
            *col = i;
            break;
        }
    }
}

void update_color(mode_t mode) {
    bg_c = 1;
    fg_c = 37;
    if(mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
        fg_c = 32;
    }
    switch(mode & S_IFMT) {
        case S_IFDIR :
        fg_c = 34;
        break;
        case S_IFLNK :
        fg_c = 36;
        break;
    }
}

void show_files(char filename[][NAMEMAX], int cnt, int row, int col) {
    int wide_file[cnt];
    memset(wide_file, 0, sizeof(int) * cnt);
    for(int i = 0; i < col; i++) {
        for(int j = (i * row); j < (i + 1) * row && j < cnt; j++) {
            if(wide_file[i] < strlen(filename[j])) wide_file[i] = strlen(filename[j]);
        }
    }
    struct stat tmp_st;
    for(int i = 0; i < row; i++) {
        for(int  j = i; j < i + (row * col) && j < cnt; j = j + row) {
            int tmp = j / row;
            lstat(filename[j], &tmp_st);
            update_color(tmp_st.st_mode);
            printf("\033[%d;%dm%-*s\033[0m",bg_c,fg_c ,wide_file[tmp] + 1, filename[j]);
        }
        printf("\n");
    }
}

void mode_to_str(mode_t mode, char *str) {
    if(S_ISREG(mode))str[0] = '-';
    if(S_ISDIR(mode))str[0] = 'd';
    if(S_ISCHR(mode))str[0] = 'c';
    if(S_ISBLK(mode))str[0] = 'b';
    if(S_ISSOCK(mode))str[0] = 's';
    if(S_ISLNK(mode))str[0] = 'l';
    if(S_ISFIFO(mode))str[0] = 'p';

    if(mode & S_IRUSR) str[1] = 'r';
    if(mode & S_IWUSR) str[2] = 'w';
    if(mode & S_IXUSR) str[3] = 'x';

    if(mode & S_IRGRP) str[4] = 'r';
    if(mode & S_IWGRP) str[5] = 'w';
    if(mode & S_IXGRP) str[6] = 'x';
    
    if(mode & S_IROTH) str[7] = 'r';
    if(mode & S_IWOTH) str[8] = 'w';
    if(mode & S_IXOTH) str[9] = 'x';
    if((mode & S_IXUSR) && (mode & S_ISUID)) str[3] = 's';
    update_color(mode);
}

char *uid_to_name(uid_t uid) {
    struct passwd *pw_ptr;
    static char tmpstr[10] = {0};
    if((pw_ptr = getpwuid(uid)) == NULL) {
        sprintf(tmpstr, "%d", uid);
        return tmpstr;
    } else {
        return pw_ptr->pw_name;
    }
}

char *gid_to_name(gid_t gid) {
    struct group *gr_ptr;
    static char tmpstr[10] = {0};
    if((gr_ptr = getgrgid(gid)) == NULL) {
        sprintf(tmpstr, "%d" , gid);
        return tmpstr;
    } else {
        return gr_ptr->gr_name;
    }
}

void show_info(char *filename, struct stat *info) {
    char modestr[11] = "----------";
    mode_to_str(info->st_mode, modestr);
    printf("%s ", modestr);
    printf("%4ld ", info->st_nlink);
    printf("%10s ", uid_to_name(info->st_uid));
    printf("%10s ", gid_to_name(info->st_gid));
    printf("%10ld ", info->st_size);
    printf("%.15s ",4 + ctime(&info->st_mtime));
    /*if(S_ISDIR(info->st_mode)) {
    printf("\033[1;34m%s\033[0m\n",filename);
    } else {
        printf("%s\n", filename);
    }*/
    if(modestr[0] == 'l') {
    printf("\033[%d;%dm%s\033[0m", bg_c,fg_c , filename);
    }
    if(modestr[0] == 'l') {
        int cnt;
        char buf[NAMEMAX] = {0};
        if((cnt = readlink(filename, buf,NAMEMAX )) < 0) {
            perror("readlink");
        } else {
            printf("-> %s\n", buf);
        }
    } else {
        printf("\033[%d;%dm%s\033[0m\n", bg_c,fg_c , filename);
    }
}

void do_stat(char *filename) {
    struct stat st;
    if(lstat(filename, &st) < 0) {
        perror(filename);
    } else {
        show_info(filename, &st);
    }
}

int cmp_name(const void *_a, const void *_b) {
    char *a = (char *)_a;
    char *b = (char *)_b;
    return strcmp(a, b);
}


void do_ls(char *dirname) {
    //printf("Doing with dir %s\n", dirname);
    DIR *dirp = NULL;
    struct dirent *direntp;
    if((dirp = opendir(dirname)) == NULL) {
        if(access(dirname, R_OK) == 0) {
            if(flag_l == 0) {
                struct stat tmp_st;
                lstat(dirname, &tmp_st);
                update_color(tmp_st.st_mode);
                printf("\033[%d;%dm%s\033[0m\n",bg_c, fg_c, dirname);
                return;
            } else {
                do_stat(dirname);
                return;
            }
        } else {
            perror(dirname);
            return;
        }
    } else {
        printf("%s:\n", dirname);
        chdir(dirname);
        int cnt = 0;
        while((direntp = readdir(dirp))!=NULL) {
            if(direntp->d_name[0] =='.'&&(flag_a == 0)) continue;
            strcpy(names[cnt++], direntp->d_name);
        }
        qsort(names, cnt, NAMEMAX, cmp_name);

        if(flag_l == 1) {
            for(int i = 0; i < cnt; i++) {
                do_stat(names[i]);
            }
        } else {
            //printf("Print all file \n");
             int row, col;
            size_window(names, cnt, &row, &col);
            // printf("row =%d, col = %d\n", row, col);
            show_files(names, cnt, row, col);
        }

    }
    
}

int main(int argc, char **argv) {
    int opt;
    while((opt = getopt(argc, argv, "al" )) !=-1 ) {
        switch(opt) {
            case 'a' :flag_a = 1;
                break;
            case 'l' :flag_l = 1;
                break;
            default:
                fprintf(stderr, "Usage : %s [-al] [filename]\n", argv[0]);
                exit(1);
        }
    }
    //printf("flag_a = %d, flag_l = %d\n", flag_a, flag_l);
   // printf("optind = %d\n", optind);
    argc -= (optind - 1);
    argv += (optind - 1);
    //printf("argv=%s\n", *(argv+1));
    if(argc == 1) {
        do_ls(".");
    } else {
        while(--argc) {
            do_ls(*(++argv));
        }
    }

    return 0;
}
```

#### 实现more函数

##### fopen函数

**函数功能：**打开一个文件

**函数原型：**FILE * f[open](http://www.cnblogs.com/lemma/ShowInnerLink.htm?lemmaId=593034&ss_c=ssc.citiao.link)([const](http://www.cnblogs.com/lemma/ShowInnerLink.htm?lemmaId=7610856&ss_c=ssc.citiao.link) [char](http://www.cnblogs.com/lemma/ShowInnerLink.htm?lemmaId=4836436&ss_c=ssc.citiao.link) * [path](http://www.cnblogs.com/lemma/ShowInnerLink.htm?lemmaId=7872928&ss_c=ssc.citiao.link),const char * [mode](http://www.cnblogs.com/lemma/ShowInnerLink.htm?lemmaId=4766078&ss_c=ssc.citiao.link));

**返回值：**文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开失败则返回NULL，并把[错误代码](http://www.cnblogs.com/lemma/ShowInnerLink.htm?lemmaId=62665122)存在[errno](http://www.cnblogs.com/lemma/ShowInnerLink.htm?lemmaId=70889372&ss_c=ssc.citiao.link) 中。

#####　fgets函数

函数原型

char *fgets(char *str, int n, FILE *stream);

参数

- **str**-- 这是指向一个字符数组的指针，该数组存储了要读取的字符串。
- **n**-- 这是要读取的最大字符数（包括最后的空字符）。通常是使用以 str 传递的数组长度。
- **stream**-- 这是指向 FILE 对象的指针，该 FILE 对象标识了要从中读取字符的流。

##### fgetc函数

fgetc是一种计算机[C语言](https://baike.baidu.com/item/C语言/105958)中的函数。意为从[文件指针](https://baike.baidu.com/item/文件指针/1953678)stream指向的文件中读取一个字符，读取一个字节后，光标位置后移一个字节。格式：int fgetc(FILE *stream);。

- 功  能

  函数从流中返回一个字符值

* 返回值

  得到的字符值

```c
#include<stdio.h>
#include<stdlib.h>
#define LENLINE 512
#include<termios.h>
#include<sys/ioctl.h>
#include<termios.h>
#include<signal.h>
#include<unistd.h>
int PAGLINE;

void f(){
    struct winsize size;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    PAGLINE = size.ws_row;
}

int get_cmd(FILE *fp) {
    printf("more:");
    int c;
    while((c = fgetc(fp))!=EOF) {
        if(c == 'q') return 0;
        else if(c == ' ') return PAGLINE;
        else if(c == '\n')return 1;
    }
    return -1;
}

void do_more(FILE *fp) {
    char line[LENLINE] = {0};
    FILE *cmd = fopen("/dev/tty", "r");
    int num_line = 0, reply, get_cmd(FILE *);
    while(fgets(line, LENLINE, fp)) {
        if(num_line == PAGLINE) {
            reply = get_cmd(cmd);
            if(reply == 0) break;
            num_line -= reply;
        }
        if(fputs(line, stdout) == EOF) {
            perror("fputs");
            exit(1);
        }
        num_line++;
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    f();
    if(argc == 1) {
        do_more(stdin);
    } else {
        while(--argc) {
            if((fp = fopen(*++argv,"r"))!=NULL) {
                do_more(fp);
            }
        }
    }
    return 0;
}
```









# 数据提取操作

* 数据提取操作

| 命令  | 说明         | 命令  | 说明             |
| ----- | ------------ | ----- | ---------------- |
| cut   | 切分         | grep  | 检索             |
| sort  | 排序         | wc    | 统计字符字数行数 |
| uniq  | 去重         | tee   | 双重导向         |
| split | 文件切分     | xargs | 参数代换         |
| tr    | 替换压缩删除 |       |                  |

* cut切分
  cut [-dfc] <file>
  -d c:以字符分割
  -f num：显示ｎｕｍ字段内容【ｎ- ;n - m; -m】
  -c num: 字节
  -b num: 字符

* grep检索
  grep [-acinv] <string> <file>
  -a: 将二进制文件以普通文件形式搜寻数据
  -c : 统计搜寻到的次数
  -i：忽略大小写
  -n：顺序输出行号
  -v：反向输出（输出没找到的）

* sort排序

  sort [-fnMnrtuk] <file_or_stdio>

  -f:忽略大小写

  -b:忽略最前面的空格符

  -M:以月份名称排序

  -n:以纯数字方式排序

  -r:反向排序

  -u:uniq

  -t:分隔符，默认[TAB]

  -k:以那个区间排序

  

* wc统计字符字数，行数

  wc [-lwm] <file_or_stdin>

  -l: 仅列出行号

  -w:仅列出多少字

  -m:仅列出多少字符

* uniq去重

  uniq [-ic]

  -i :忽略大小写字符的不同

  -c:进行计数

* split文件切分

  split [-bl] <file> PREFIX

  -b SIZE: 切分为ＳＩＺＥ大小的文件

  -l ｎｕｍ：以ｎｕｍ行为大小切

```shell
ls /etc | splist -l 10  
```

* xargs参数xargs替换

  -0：将特殊字符还原为普通字符

  -eEOF:当xargs读到ＥＯＦ时停止

  -p:执行指令前询问

  -n num:每次执行command时需要的参数个数

```shell
cat /etc/passwd | cut -d ":" -f 1 | xargs -n 1 -efangsong id
```

* tr替换压缩删除  

  tr [cdst] <字符集>　<字符集>

  c 取代所有不属于第一字符集的字符

  d 删除所有属于第一字符集的字符

  s 将连续重复的字符以单独一个字符表示

  t 先删除第一字符集比第二字符集字符集多的字符

```shell
 cat fangsong | tr [0-9] [a-z]
 cat fangsong | tr -d [0-9]
 cat fangsong | tr -s [a-z]
 cat fangsong | tr -t [0-9] [a-z]

 文件夹下文件名大写变小写
ls | tr [a - z] [A  - Z]
for i in `ls`; do
>mv $i `echo $i` | tr [a-z] [A-Z]
>done
```

如何统计文件中单词的个数，逆序输出

```shell
 cat fangsong | tr -s -c [a-z] ' ' | tr ' ' '\n' | sort | uniq -c | sort -n -r | head -n 20
 先把不是字符的去掉，然后把空格替换为'\n',然后排序去重然后逆序输出前二十行
```



# 用户管理

### **用户管理的重要配置文件**

| 配置文件     | 内容                                                      |
| ------------ | --------------------------------------------------------- |
| /etc/passwd  | 用户名　密码为　用户编号　归属组编号　姓名　$HOME　$SHELL |
| /etc/shadow  | 用户名　已加密密码　密码改动信息　密码策略                |
| /etc/group   | 群组名　密码为　群组编号　组内用户                        |
| /etc/gshadow | 群组密码相关文件                                          |
| /etc/sudoers | 用户名　权限定义　权限(sudo)                              |

#### **/etc/password文件说明**

```shell
fangsong@fangsong-FX503VD:/etc$ cat passwd
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
```

| root     | x    | 0    | 0    | root     | /root | /bin/bash |
| -------- | ---- | ---- | ---- | -------- | ----- | --------- |
| 账户名称 | 密码 | uid  | gid  | 用户信息 | $HOME | SHELL     |

#### **/etc/shadow文件说明**

```shell
root:!:18225:0:99999:7:::
daemon:*:18002:0:99999:7:::
bin:*:18002:0:99999:7:::
sys:*:18002:0:99999:7:::
```

| root     | !    | 18225          | 0                | 99999                | 7                    | null               | null         | null |
| -------- | ---- | -------------- | ---------------- | -------------------- | -------------------- | ------------------ | ------------ | ---- |
| 账户名称 | 密码 | 修改密码的日期 | 密码不可更改日期 | 密码需要重新修改日期 | 密码更新期限清高日期 | 密码过期的宽限时间 | 账户失效日期 | 保留 |

#### **/etc/group文件说明**

```
adm:x:4:syslog,fangsong
tty:x:5:
disk:x:6:
```

| adm  | x        | 4    | syslog,fangsong |
| ---- | -------- | ---- | --------------- |
| 组名 | 群组密码 | gid  | 支持的账户      |

#### **/etc/gshadow文件说明**

```
lpadmin:!::fangsong,saned
scanner:!::
avahi:!::
```

| lpadmin | !    | null       | fangsong,saned       |
| ------- | ---- | ---------- | -------------------- |
| 组名    | 密码 | 群组管理员 | 加入该群组的所属账号 |



### **用户管理相关的命令**

| 命令    | 说明          | 命令    | 说明             |
| ------- | ------------- | ------- | ---------------- |
| su      | 切换用户      | sudo    | 临时切换root用户 |
| passwd  | 设定用户密码  | gpasswd | 设定群组密码     |
| chsh    | 更改用户shell | usermod | 修改用户账号     |
| useradd | 新建用户      | userdel | 删除用户         |
| id      | 显示用户信息  | ...     | ．．．           |

#### su命令

>su [-lmpfc] <username>
>
>-l | -1 :重新登录
>
>-m | -p:不改变环境变量
>
>-c comand:切换后执行命令，并退出

####　sudo命令

>sudo [-siul] <command>
>
>-s :切换为root shell
>
>-i:切换为root shell ，并初始化
>
>-u username | uid：执行命令身份
>
>-1:显示自己的权限

#### passwd命令

>passwd [-dleSxnf] <username>
>
>-d:清除密码
>
>-l:锁定用户
>
>-e:使密码过期
>
>-S:显示密码认证信息
>
>-x days:密码过期后最大使用天数
>
>-n days:密码冻结后最小使用时间
>
>-s:更改登录shell
>
>-f:更改用户信息

#### gpasswd命令

>gpasswd [-adeAm]<群组名>
>
>-a username :将用户加入群组
>
>-d username :将用户从群组中删除
>
>-r :删除密码
>
>-A username:将用户设置为群组管理员
>
>-M username1,username2...:设置为群成员

#### chsh命令

>chsh -s shell <username>

```shell
fangsong@fangsong-FX503VD:~$ chsh -s /bin/sh fangsong
密码： 
fangsong@fangsong-FX503VD:~$ su - fangsong
密码： 
$ echo $SHELL
/bin/sh
$ exit
fangsong@fangsong-FX503VD:~$ chsh -s /bin/bash fangsong
密码： 
fangsong@fangsong-FX503VD:~$ su - fangsong
密码： 
Good evening. 天行健，君子以自强不息；地势坤，君子以厚德载物！
Please input the username: fangsong
fangsong is online.
fangsong@fangsong-FX503VD:~$ echo $SHELL
/bin/bash
fangsong@fangsong-FX503VD:~$ 
```

#### useradd命令添加新的用户账号

```
useradd 选项 用户名
```

>useradd [-dMsugGnefcD] <username>
>
>-d dir:指定$HOME
>
>-m:自动建立$HOME
>
>-M:不自动建立$HOME
>
>-s shell:设置用户登录ｓｈｅｌｌ
>
>-u uid:设置用户编号
>
>-g groupname:设定用户归属群组
>
>-G groupname:设置用户归属附加群组
>
>-n:不建立以用户名称为群组名称的群组
>
>-e days:设置账号过期时间
>
>-f days:缓冲时间,days天后关闭账号
>
>-c string:设置用户备注
>
>-D[表达式]:更改预设值

>/etc/login.defs新建用户规则
>
>/etc/skel/新建用户默认文件

实例1

```
# useradd –d  /home/sam -m sam
```

此命令创建了一个用户sam，其中-d和-m选项用来为登录名sam产生一个主目录 /home/sam（/home为默认的用户主目录所在的父目录）。

实例2

```
# useradd -s /bin/sh -g group –G adm,root gem
```

此命令新建了一个用户gem，该用户的登录Shell是 `/bin/sh`，它属于group用户组，同时又属于adm和root用户组，其中group用户组是其主组。

这里可能新建组：`#groupadd group及groupadd adm`

增加用户账号就是在/etc/passwd文件中为新用户增加一条记录，同时更新其他系统文件如/etc/shadow, /etc/group等。

Linux提供了集成的系统管理工具userconf，它可以用来对用户账号进行统一管理。

####　userdel 用户名删除帐号

>userdel -r <username>
>
>-r :删除用户相关文件和目录

如果一个用户的账号不再使用，可以从系统中删除。删除用户账号就是要将/etc/passwd等系统文件中的该用户记录删除，必要时还删除用户的主目录。

删除一个已有的用户账号使用`userdel`命令，其格式如下：

```
userdel 选项 用户名
```

常用的选项是 **-r**，它的作用是把用户的主目录一起删除。

例如：

```
# userdel -r sam
```

此命令删除用户sam在系统文件中（主要是/etc/passwd, /etc/shadow, /etc/group等）的记录，同时删除用户的主目录。

#### usermode 命令

>usermod [-cdefgGlLsuU] <username>
>
>-c string :修改备注信息
>
>-d dir:修改$HOME
>
>-e dats:密码期限
>
>-f days:密码过期后宽限的日期
>
>-g groupname:修改用户所属群组
>
>-G groupname:修改用户所属附加群组

#### usermod 命令修改帐号

>usermod [-defgGlLsuU]<username>
>
>-l username : 修改用户账号名称
>
>-L:锁定用户密码，使密码无效
>
>-s shell:修改用户登录后所使用的shell
>
>-u uid:修改用户ID
>
>-U:接除密码锁定

修改用户账号就是根据实际情况更改用户的有关属性，如用户号、主目录、用户组、登录Shell等。

修改已有用户的信息使用`usermod`命令，其格式如下：

```
usermod 选项 用户名
```

常用的选项包括`-c, -d, -m, -g, -G, -s, -u以及-o等`，这些选项的意义与`useradd`命令中的选项一样，可以为用户指定新的资源值。

另外，有些系统可以使用选项：-l 新用户名

这个选项指定一个新的账号，即将原来的用户名改为新的用户名。

例如：

```
# usermod -s /bin/ksh -d /home/z –g developer sam
```

此命令将用户sam的登录Shell修改为ksh，主目录改为/home/z，用户组改为developer。

####　id命令

>id [-gGnru]<username>
>
>-g :下属所属组ID
>
>-G:显示附加组ID
>
>-n:显示用户，所属组，或附加群组的名称
>
>-u:显示用户ID
>
>-r:显示实际ID





# SOCKET编程基础

![](linux%E7%AC%94%E8%AE%B0.assets/2020-03-22%2022-47-53%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](linux%E7%AC%94%E8%AE%B0.assets/2020-03-22%2022-48-59%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](linux%E7%AC%94%E8%AE%B0.assets/2020-03-22%2022-49-42%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](linux%E7%AC%94%E8%AE%B0.assets/2020-03-22%2022-50-11%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### socket()创建socket

```
 完成两个应用程序之间的数据传输, 应用程序可以通过它发送或接收数据,网络套接字是IP地址与端口的组合;
```

socket()函数调用的格式

>SOCKET PASCAL FAR socket（int af，int type，int protocol）；

参数af指定套接字使用的协议族, 

type参数指定所需的通信类型。包括数据流（SOCK_STREAM）、数据报（SOCK-DGRAM）和原始类型（S0CK_RAW）。

参数protocol说明该套接字使用的协议族中的特定协议。如果调用者不希望特别指定使用的协议，则置为0，使用默认的连接模式。

![](linux%E7%AC%94%E8%AE%B0.assets/2020-03-22%2022-56-22%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```c
int port, server_listen;
    port = atoi(argv[1]);
if((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) { // 完成两个应用程序之间的数据传输, 应用程序可以通过它发送或接收数据,网络套接字是IP地址与端口的组合;
        perror("socket");
        exit(1);
    }
```

### bind()绑定IP地址及端口

bind()函数通过给一个[未命名](https://baike.baidu.com/item/未命名/278232)套接口分配一个本地名字来为套接口建立本地捆绑（[主机地址](https://baike.baidu.com/item/主机地址/9765500)/[端口号](https://baike.baidu.com/item/端口号/10883658)）。

```c
#include <sys/types.h>
#include <sys/socket.h>
/*
 struct sockaddr_in {
     short sin_family;//Address family一般来说AF_INET（地址族）PF_INET（协议族）
     unsigned short sin_port; // Port number(必须要采用网络数据格式,普通数字可以用htons()函数转换成网络数据格式的数字)
     struct in_addr sin_addr;//IP address in network byte order（Internet address）;
     }
     */
bind(server_listen, (struct sockaddr *)&server, sizeof(server))
   //  返回值：成功返回0，失败返回-1.
```

参数列表中，server_listen 表示已经建立的socket编号（描述符）；

server 是一个指向sockaddr结构体类型的指针；

参数sizeof(server)表示server结构的长度，可以用sizeof操作符获得。

```c
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) { //将一本地地址与一套接口捆绑
        perror("bind");
        exit(1);
    }
```

### listen()监听socket

```
创建一个套接口并监听申请的连接.
#include <sys/socket.h>
int listen( int sockfd, int backlog);
sockfd：用于标识一个已捆绑未连接套接口的描述字。
backlog：等待连接队列的最大长度。
```

```c
  /*
    #include <sys/socket.h>
    int listen( int sockfd, int backlog);
    sockfd：用于标识一个已捆绑未连接套接口的描述字。
    backlog：等待连接队列的最大长度。
    */
    if(listen(server_listen, 20) < 0) { // 创建一个套接口并监听申请的连接
        perror("server");
        exit(1);
    }
```

![](linux%E7%AC%94%E8%AE%B0.assets/2020-03-22%2023-07-04%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



### connect()建立连接

![](linux%E7%AC%94%E8%AE%B0.assets/2020-03-22%2023-53-13%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```
connect()用于建立与指定socket的连接。
头文件: #include <sys/socket.h>
函数原型: int connect(SOCKET s, const struct sockaddr * name, int namelen);
参数:
s：标识一个未连接socket
name：指向要连接套接字的sockaddr结构体的指针
namelen：sockaddr结构体的字节长度
```

```c
    printf("Socket create.\n");
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }
```



### accept()接收连接

\#include <sys/socket.h>

```
accept()是在一个套接口接受的一个连接
     SOCKET accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
     sockfd：套接字描述符，该套接口在listen()后监听连接。
```

```c
 int sockfd;
        if((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }

```

![](linux%E7%AC%94%E8%AE%B0.assets/2020-03-22%2023-48-17%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)







### send()发送数据

  send（）是一个计算机函数，功能是向一个已经连接的socket发送数据
     int send( SOCKET s, const char FAR *buf, int len, int flags );
     不论是客户还是服务器应用程序都用send函数来向TCP连接的另一端发送数据。
    客户程序一般用send函数向服务器发送请求，而服务器则通常用send函数来向客户程序发送应答。
（1）第一个参数指定发送端套接字描述符；
（2）第二个参数指明一个存放应用程序要发送数据的缓冲区；
（3）第三个参数指明实际要发送的数据的字节数；
（4）第四个参数一般置0。

```c
    if(send(sockfd, "fangsong", sizeof("fangsong"), 0) < 0) {
        perror("send");
        exit(1);
    }
```

### recv()接收数据

![](linux%E7%AC%94%E8%AE%B0.assets/2020-03-22%2023-50-55%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```c
    if(recv(sockfd, name, sizeof(name), 0) <= 0) {
           perror("recv");
            close(sockfd);
         // continue;
        }    if(recv(sockfd, name, sizeof(name), 0) <= 0) {
           perror("recv");
            close(sockfd);
         // continue;
        }
```



# 实现一个socket程序

### server.c

```c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s powrt\n", argv[0]);
        exit(1);
    }

    int port, server_listen;
    port = atoi(argv[1]);
    if((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) { // 完成两个应用程序之间的数据传输, 应用程序可以通过它发送或接收数据,网络套接字是IP地址与端口的组合;
        perror("socket");
        exit(1);
    }
    /*
     server_listen: 标识一未捆绑套接口的描述字。
     server: 赋予套接口的地址
     struct sockaddr_in {
     short sin_family;//Address family一般来说AF_INET（地址族）PF_INET（协议族）
     unsigned short sin_port; // Port number(必须要采用网络数据格式,普通数字可以用htons()函数转换成网络数据格式的数字)
     struct in_addr sin_addr;//IP address in network byte order（Internet address）;
     }
    */
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) { //将一本地地址与一套接口捆绑
        perror("bind");
        exit(1);
    }
    /*
    #include <sys/socket.h>
    int listen( int sockfd, int backlog);
    sockfd：用于标识一个已捆绑未连接套接口的描述字。
    backlog：等待连接队列的最大长度。
    */
    if(listen(server_listen, 20) < 0) { // 创建一个套接口并监听申请的连接
        perror("server");
        exit(1);
    }

    /*
     accept()是在一个套接口接受的一个连接
     SOCKET accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
     sockfd：套接字描述符，该套接口在listen()后监听连接。
    */

    /* fork系统调用用于创建一个新进程，称为子进程，它与进程（称为系统调用fork的进程）同时运行，此进程称为父进程。创建新的子进程后，两个进程将执行fork（）系统调用之后的下一条指令。子进程使用相同的pc（程序计数器），相同的CPU寄存器，在父进程中使用的相同打开文件。
    */
    while(1) {
        int sockfd;
        if((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }
        pid_t pid;
        if((pid = fork()) < 0) {
            perror("fork");
            continue;
        }
        if(pid == 0) {
        close(server_listen);
        char name[20] = {0};
        if(recv(sockfd, name, sizeof(name), 0) <= 0) {
           perror("recv");
            close(sockfd);
         // continue;
        }
        printf("name: %s\n", name);
        close(sockfd);
            exit(0);
        }
    }
    close(server_listen);
    return 0;
}
```

### client.c

```c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(int argc, char **argv) {
    int sockfd, port;
    struct sockaddr_in server;
    if(argc != 3) {
        fprintf(stderr, "Usage: %s ip port\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[2]);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    /*
     connect()用于建立与指定socket的连接。
     头文件: #include <sys/socket.h>
     函数原型: int connect(SOCKET s, const struct sockaddr * name, int namelen);
    参数:
    s：标识一个未连接socket
    name：指向要连接套接字的sockaddr结构体的指针
    namelen：sockaddr结构体的字节长度
     */
    printf("Socket create.\n");
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }
    /*
     send（）是一个计算机函数，功能是向一个已经连接的socket发送数据
     int send( SOCKET s, const char FAR *buf, int len, int flags );
     不论是客户还是服务器应用程序都用send函数来向TCP连接的另一端发送数据。
    客户程序一般用send函数向服务器发送请求，而服务器则通常用send函数来向客户程序发送应答。
（1）第一个参数指定发送端套接字描述符；
（2）第二个参数指明一个存放应用程序要发送数据的缓冲区；
（3）第三个参数指明实际要发送的数据的字节数；
（4）第四个参数一般置0。
    */
    if(send(sockfd, "fangsong", sizeof("fangsong"), 0) < 0) {
        perror("send");
        exit(1);
    }
    close(sockfd);
    return 0;
}
```

