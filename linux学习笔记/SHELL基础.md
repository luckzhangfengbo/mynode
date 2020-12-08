

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

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2019-32-11%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2019-41-30%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



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

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2019-53-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

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

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2019-54-19%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2019-54-48%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 输入输出-READ

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-26-40%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



#### 输入输出-ECHO

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-27-54%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

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

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-28-44%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

- printf命令不用加括号
- format-string可以没有引号，但最好加上，单引号双引号相似。
- 参数多于格式控制符（％）时，format-string可以重用，可以将所有参数都转换。
- arguments使用空格分隔，不用逗号。

```shell
$ printf "%d %s\n" 1 "abc"
1 abc
```



#### 函数

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-29-20%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

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

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-30-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



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

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-31-26%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 流程控制-FOR

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-32-03%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

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

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-32-25%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 流程控制-CASE

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-33-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

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

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-34-13%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 数组操作

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-34-45%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](SHELL%E5%9F%BA%E7%A1%80.assets/2020-03-12%2021-35-16%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

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