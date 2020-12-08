# 实现cp所用到的函数

### open()打开和创建文件

open是多种语言、环境的一种[函数](https://baike.baidu.com/item/函数/18686609)，LINUX中open函数作用：[打开](https://baike.baidu.com/item/打开/1306427)和创建文件。PB程序语言中open功能：打开窗口。

[
打开](https://baike.baidu.com/item/打开)和创建文件

```
int  open(constchar*pathname,int  flags);
```

pathname 是待[打开](https://baike.baidu.com/item/打开)/创建文件的POSIX路径名（如/home/user/a.cpp）；flags 用于指定文件的打开/创建模式，这个参数可由以下[常量](https://baike.baidu.com/item/常量)（定义于[fcntl.h](https://baike.baidu.com/item/fcntl.h)）通过逻辑位或逻辑构成。

```
O_RDONLY只读模式
O_WRONLY只写模式
O_RDWR读写模式
```

```cpp

if((fd_in = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(1);
    }
```

### creat()创建一个文件并以只写的方式打开

```
int creat(const char * pathname, mode_t mode);
```

**函数功能：**

创建一个文件并以只写的方式打开。如果原来该文件存在，会将这个文件的长度截短为0。

```c
  if((fd_out= creat(argv[2], 0644)) == -1) {
        perror(argv[2]);
        exit(1);
    }

```

### read()从文件中读

```
include <unistd.h>
```

```
ssize_t read  (int fd, void *buf, size_t count);
```

参数count是请求读取的字节数，读上来的数据保存在缓冲区buf中

成功返回读取的字节数，出错返回-1并设置errno，如果在调read之前已到达文件末尾，则这次read返回0。

```c
while((nread = read(fd_in, buf, BUFSSIZE)) > 0){
        if(write(fd_out, buf, strlen(buf)) != nread){
            perror("write");
            exit(1);
        }
        memset(buf, 0, BUFSSIZE + 5);
    }

```

### write()函数

将数据写入已打开的文件内

```
write有两种用法。一种是：ssize_t write(int fd, const void *buf, size_t nbyte);
fd：文件描述符；
buf：指定的缓冲区，即指针，指向一段内存单元；
nbyte：要写入文件指定的字节数；
```

```
while((nread = read(fd_in, buf, BUFSSIZE)) > 0){
        if(write(fd_out, buf, strlen(buf)) != nread){
            perror("write");
            exit(1);
        }
        memset(buf, 0, BUFSSIZE + 5);
    }

```

