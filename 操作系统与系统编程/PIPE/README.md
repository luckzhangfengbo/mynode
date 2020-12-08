   * [进程间的通信方式——pipe（管道）](#进程间的通信方式pipe管道)
   * [1.进程间通信](#1进程间通信)
      * [1.1管道的概念](#11管道的概念)
   * [2.匿名管道](#2匿名管道)
      * [2.1管道的创建](#21管道的创建)
      * [2.2管道如何实现进程间的通信](#22管道如何实现进程间的通信)
      * [2.3如和用代码实现管道通信](#23如和用代码实现管道通信)
      * [2.4管道读取数据的四种的情况](#24管道读取数据的四种的情况)
      * [2.5管道特点](#25管道特点)

# 进程间的通信方式——pipe（管道）



# 1.进程间通信

>每个进程各自有不同的用户地址空间,任何一个进程的全局变量在另一个进程中都看不到，所以进程之间要交换数据必须通过内核,在内核中开辟一块缓冲区,进程A把数据从用户空间拷到内核缓冲区,进程B再从内核缓冲区把数据读走,内核提供的这种机制称为进程间通信。 

![这里写图片描述](https://img-blog.csdn.net/20170509155514495?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2t5cm9iZW4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

不同进程间的通信本质：进程之间可以看到一份公共资源；而提供这份资源的形式或者提供者不同，造成了通信方式不同，而 pipe就是提供这份公共资源的形式的一种。



## 1.1管道的概念

​		管道是一种剧本的`ＩＰＣ`机制，作用于有血缘关系的进程之间，完成数据传输。调用`ｐｉｐｅ`系统函数即可创建一个管道。有如下性质:

​		1.其本质是一个伪文件（实质为内核缓冲区）

​		2.有两个文件描述符引用，一个表示独断，一个表示写端

​		3.规定数据从管道的写段流入管道，从读端流出。

管道的原理：管道式为内核使用环形队列机制，借助内核缓冲区(`4k`)实现

![](README.assets/2020-04-08%2016-12-38%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

# 2.匿名管道

## 2.1管道的创建

> 管道是由调用pipe函数来创建



```c
#include <unistd.h>
int pipe (int fd[2]);
                         //返回:成功返回0，出错返回-1     
```

```C
 fd参数返回两个文件描述符,fd[0]指向管道的读端,fd[1]指向管道的写端。fd[1]的输出是fd[0]的输入。
```

## 2.2管道如何实现进程间的通信

（1）父进程创建管道，得到两个⽂件描述符指向管道的两端


（2）父进程fork出子进程，⼦进程也有两个⽂件描述符指向同⼀管道。

（3）父进程关闭fd[0],子进程关闭fd[1]，即⽗进程关闭管道读端,⼦进程关闭管道写端（因为管道只支持单向通信）。⽗进程可以往管道⾥写,⼦进程可以从管道⾥读,管道是⽤环形队列实现的,数据从写端流⼊从读端流出,这样就实现了进程间通信。

![这里写图片描述](https://img-blog.csdn.net/20170509162502566?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2t5cm9iZW4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 2.3如和用代码实现管道通信

见上文档

## 2.4管道读取数据的四种的情况

（1）读端不读，写端一直写

![这里写图片描述](https://img-blog.csdn.net/20170509235601938?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2t5cm9iZW4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

（2）写端不写，但是读端一直读

![这里写图片描述](https://img-blog.csdn.net/20170510000703098?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2t5cm9iZW4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

（3）读端一直读，且fd[0]保持打开，而写端写了一部分数据不写了，并且关闭fd[1]。![这里写图片描述](https://img-blog.csdn.net/20170510001736356?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2t5cm9iZW4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

<font color = red>如果一个管道读端一直在读数据，而管道写端的引⽤计数⼤于0决定管道是否会堵塞，引用计数大于0，只读不写会导致管道堵塞。</font>

（4）读端读了一部分数据，不读了且关闭fd[0]，写端一直在写且f[1]还保持打开状态。

![这里写图片描述](https://img-blog.csdn.net/20170510002648368?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2t5cm9iZW4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

<font color =red>总结：
如果一个管道的写端一直在写，而读端的引⽤计数是否⼤于0决定管道是否会堵塞，引用计数大于0，只写不读再次调用write会导致管道堵塞；
如果一个管道的读端一直在读，而写端的引⽤计数是否⼤于0决定管道是否会堵塞，引用计数大于0，只读不写再次调用read会导致管道堵塞；
而当他们的引用计数等于0时，只写不读会导致写端的进程收到一个SIGPIPE信号，导致进程终止，只写不读会导致read返回0,就像读到⽂件末尾⼀样。</font>

## 2.5管道特点

>1.管道只允许具有血缘关系的进程间通信，如父子进程间的通信。 
>
>2.管道只允许单向通信。 
>
>3.管道内部保证同步机制，从而保证访问数据的一致性。 
>
>4.面向字节流 
>
>5.管道随进程，进程在管道在，进程消失管道对应的端口也关闭，两个进程都消失管道也消失。

