#### shell：

<font color = red>简单来说就是一个"工具"，它是一个命令行解释器，把用户输入的命令传输到内核去执行。</font>

shell命令：可以让shell工具解释的命令（代码）。

shell脚本：一系列shell命令的集合。

![](/home/fangsong/Git/Figure-bed/2020-03-12%2012-13-15%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](/home/fangsong/Git/Figure-bed/2020-03-12%2012-14-25%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

 Bash，也就是 Bourne Again Shell，由于易用和免费，Bash 在日常工作中被广泛使用。同时，Bash 也是大多数Linux 系统默认的 Shell。

在一般情况下，人们并不区分 Bourne Shell 和 Bourne Again Shell，所以，像 **#!/bin/sh**，它同样也可以改为 **#!/bin/bash**。

<font color = red>**#!** 告诉系统其后路径所指定的程序即是解释此脚本文件的 Shell 程序。</font>

#### **什么是terminal**

我们在Linux下使用的terminal，<font color = red>实际上是一个“终端模拟软件”</font>，它模拟了一台真正的终端，也就是几十年前时候的终端：只包括键盘+显示器，甚至是再之前时的电传打字机。现在，我们用的终端软件指的是可以运行shell命令的软件。它一般是捆绑在桌面环境上的，例如gnome terminal等等，我们自己也可以安装另外的terminal.它就是类似于输入法的一个应用程序。

#### **什么是.bashrc**

.bashrc位于/home/<用户名>的目录下

> 来源：https://linux.cn/article-9298-1.html

bash 是一个能解释你输入进终端程序的东西，并且基于你的输入来运行命令。它在一定程度上支持使用脚本来定制功能，这时候就要用到 `.bashrc` 了。

 为了加载你的配置，bash 在每次启动时都会加载 `.bashrc` 文件的内容。每个用户的 home 目录都有这个 shell 脚本。它用来存储并加载你的终端配置和环境变量。

#### 进入.bashrc

```
vim ~/.bashrc
```

打开之后可以看到有许多项。

我们可以在这里追加alias来为命令取别名，从而简化在terminal中的输入。例如，我们可以将常用的ssh连接命令取别名，这样就不需要每次都输入一长串了。

#### bash的运行模式

> 来源：http://blog.sciencenet.cn/blog-3238131-1037461.html
>
> Bash有几种不同的运行模式，login shell与non-login shell，interactive shell与non-interactive shell（比如执行shell脚本）。这两种分类方法是交叉的，也就是说一个login shell可能是一个interactive shell，也可能是个non-interactive shell。
>
> 在下列情况下，我们可以获得一个login shell：
>
> 1. 登录系统时获得的顶层shell，无论是通过本地终端登录，还是通过网络ssh登录。这种情况下获得的login shell是一个交互式shell。
> 2. 在终端下使用--login选项调用bash，可以获得一个交互式login shell。
> 3. 在脚本中使用--login选项调用bash（比如在shell脚本第一行做如下指定：#!/bin/bash --login），此时得到一个非交互式的login shell。
> 4. 使用"su -"切换到指定用户时，获得此用户的login shell。如果不使用"-"，则获得non-login shell。
>
> login shell与non-login shell的主要区别在于它们启动时会读取不同的配置文件，从而导致环境不一样。login shell启动时首先读取/etc/profile全局配置，然后依次查找~/.bash_profile、~/.bash_login、~/.profile三个配置文件，并且读取第一个找到的并且可读的文件。login shell退出时读取并执行~/.bash_logout中的命令。
> 交互式的non-login shell启动时读取~/.bashrc资源文件。非交互式的non-login shell不读取上述所有配置文件，而是查找环境变量BASH_ENV，读取并执行BASH_ENV指向的文件中的命令。
>
> **通常我们要定制一些配置时，将配置写在~/.bashrc中，然后在~/.bash_profile中读取~/.bashrc，这样可以保证login shell和交互式non-login shell得到相同的配置。至于/etc/profile就不要轻易去改啦，毕竟会影响系统全局的配置。**

####　全局与个人设置

![](%E8%AE%A4%E8%AF%86SHELL%E5%B9%B6%E4%BD%BF%E7%94%A8%E7%9B%B8%E5%85%B3%E6%96%87%E4%BB%B6.assets/2020-03-12%2012-46-48%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

####　全局设置

System-wide Config ans Setup

```
/etc/bash.bashrc
/etc/bash.profile
/etc/bash.bash.logout
```

#### 个人设置

Individual Config ans Setup

```
~/.bashrc
~/.bsh_profile
~/.bash_logout
~/.input
```



#### shell脚本运行

当 Shell 脚本运行时，它会先查找系统环境变量 ENV，该变量指定了环境文件<font color = red>（加载顺序通常是 /etc/profile、~/.bash_profile、~/.bashrc、/etc/bashrc等）</font>，在加载了上述环境变量文件后，Shell 就开始执行 Shell 脚本中的内容。

Shell 脚本是从上到下，从左至右依次执行每一行的命令及语句的，既执行完了一个命令后在执行下一个，如果在 Shell 脚本中遇到子脚本（即脚本嵌套）时，就会先执行子脚本的内容，完成后再返回父脚本继续执行父脚本内后续的命令及语句，

通常情况下，在执行 Shell 脚本时，会向系统内核请求启动一个新的进程，以便在该进程中执行脚本的命令及子Shell脚本，基本流程如下图所示。


设置 Linux 的 crond 任务时，最好能在定时任务脚本中重新定义系统环境变量，否则，一些系统环境变量将不会被加载，这个问题需要注意 

