# 理解select、poll和epoll区别

## １、IO复用模型

![图片](https://static.dingtalk.com/media/lALPDiQ3KR9S0PHNApTNA5Q_916_660.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22627064533%3A627064533%22%2C%22msgId%22%3A%223484896791903%22%7D&bizType=im&open_id=627064533)

## ２、目前的常用的IO复用模型有三种：select，poll，epoll

(1)select时间复杂度O(n)

他仅仅知道有I/O事件发生了，却不知道是哪那几个流(可能有一个，多个，甚至全部),我们只能无差别轮询所有的流，找出能读出数据，或者能写入数据的流，对他们进行操作。所以<font color = red>select具有o(n)无差别轮询的时间复杂度</font>，同时处理的流越多，无差别轮询时间就越长。

(2)poll时间复杂度O(n)

poll本质上与select没有区别,他讲用户传入的数组拷贝到内核空间，然后查询每个fd对应的设备状态，但是<font color = red>它没有最大连接的限制</font>，原因是它给予链表来存储的。

(3)epoll时间复杂度O(1)

epoll可以理解为evnt poll, 不同于忙轮训和无差别轮训,epoll会把那个流发生怎样的I/O时间通知我们。所以我们说epoll实际上是<font color = red>事件驱动(每个事件关联上fd)</font>的，此时我们对这些流的操作都是有意义的,它是红黑树,(复杂度降到了O(1));



select, poll, epoll 都是IO多路复用机制。I/O多路复用就是通过这种机制，可以监视多个描述度，一旦某个描述符就绪(一般是读就绪或者写就绪)，能够通知程序进行相应的读写操作。但select,poll,epoll本质上都是I/O,因为他们都需要在读写时间就绪后自己负责进行读写，也就是说这个读写过程是阻塞的，而异步I/O则无需自己负责进行读写，异步I/O的实现会负责吧数据从内核拷贝到用户空间。



epoll跟select都能提供多路I/O服用的解决方案。在现在的Linux内核中都能够支持，其中epoll是linux所特有，而select则应该是POSIX所规定,一般操作系统均有实现;



## ３、**select、poll、epoll 区别总结：**

### 3.1、支持一个进程所能打开的<font color = red>最大连接数</font>

select：单个进程所能打开的最大连接数有FD_SETSIZE宏定义，其大小是32个整数的大小（在32位的机器上，大小就是32×32，同理64位机器上FD_SETSIZE为32×64），当然我们可以对进行修改，然后重新编译内核，但是性能可能会受到影响，这需要进一步的测试。

poll：poll本质上和select没有区别，但是它没有最大连接数的限制，原因是它是基于链表来存储的。

epoll：虽然连接数有上限，但是很大，1G内存的机器上可以打开10万左右的连接，2G内存的机器可以打开20万左右的连接。

### 3.2、FD剧增后带来的IO<font color = red>效率问题</font>

select：因为每次调用时都会对连接进行线性遍历，所以随着FD的增加会造成遍历速度慢的“线性下降性能问题”。

poll:	同上。

epoll:	因为epoll内核中实现是根据每个fd上的callback函数实现的，只有活跃的socket才会主动调用callback,所以在活跃socket较少的情况下,使用epoll没有前面两者线性下降的性能问题，但是所有的sockfd都在活跃情况下，可能会出现性能问题。

### 3.3、<font color = red>消息传递方式</font>

select：内核需要将消息传递到用户空间，都需要内核拷贝动作

poll：同上

epoll：epoll通过内核和用户空间共享一块内存来实现的。

### **总结：**

综上，在选择select，poll，epoll时要根据具体的使用场合以及这三种方式的自身特点。

**1、表面上看epoll的性能最好，但是在连接数少并且连接都十分活跃的情况下，select和poll的性能可能比epoll好，毕竟epoll的通知机制需要很多函数回调**

**2、select低效是因为每次它都需要轮询。但低效也是相对的，视情况而定，也可通过良好的设计改善** 

![图片](https://static.dingtalk.com/media/lALPDhJzr-nhBnbNApPNA8U_965_659.png_620x10000q90g.jpg?auth_bizType=IM&auth_bizEntity=%7B%22cid%22%3A%22627064533%3A627064533%22%2C%22msgId%22%3A%223485696508656%22%7D&bizType=im&open_id=627064533)

<img src="https://static.dingtalk.com/media/lALPDiCpqpJJGZLNAY7NA84_974_398.png_620x10000q90g.jpg?auth_bizType=IM&amp;auth_bizEntity=%7B%22cid%22%3A%22627064533%3A627064533%22%2C%22msgId%22%3A%223505296142785%22%7D&amp;bizType=im&amp;open_id=627064533" alt="图片" style="zoom:150%;" />

