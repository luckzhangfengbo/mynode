# 消息队列

> 消息队列函数由`msgget`、`msgctl`、`msgsnd`、`msgrcv`四个函数组成。下面的表格列出了这四个函数的函数原型及其具体说明。



#### 1.  `msgget`函数原型

| `msgget`(得到消息队列标识符或创建一个消息队列对象)           |                                                              |                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------------- |
| 所需头文件                                                   | `#include <sys/types.h>#include <sys/ipc.h>#include <sys/msg.h>` |                                    |
| 函数说明                                                     | 得到消息队列标识符或创建一个消息队列对象并返回消息队列标识符 |                                    |
| 函数原型                                                     | `int msgget(key_t key, int msgflg)`                          |                                    |
| 函数传入值                                                   | key                                                          | 0(IPC_PRIVATE)：会建立新的消息队列 |
| 大于0的32位整数：视参数`msgflg`来确定操作。通常要求此值来源于`ftok`返回的`IPC`键值 |                                                              |                                    |
| `msgflg`                                                     | 0：取消息队列标识符，若不存在则函数会报错                    |                                    |
| `IPC_CREAT`：当`msgflg&IPC_CREAT`为真时，如果内核中不存在键值与key相等的消息队列，则新建一个消息队列；如果存在这样的消息队列，返回此消息队列的标识符 |                                                              |                                    |
| `IPC_CREAT|IPC_EXCL`：如果内核中不存在键值与key相等的消息队列，则新建一个消息队列；如果存在这样的消息队列则报错 |                                                              |                                    |
| 函数返回值                                                   | 成功：返回消息队列的标识符                                   |                                    |
| 出错：-1，错误原因存于error中                                |                                                              |                                    |
| 附加说明                                                     | 上述`msgflg`参数为模式标志参数，使用时需要与`IPC`对象存取权限（如0600）进行\|运算来确定消息队列的存取权限 |                                    |
| 错误代码                                                     | `EACCES`：指定的消息队列已存在，但调用进程没有权限访问它`EEXIST：key`指定的消息队列已存在，而`msgflg`中同时指定`IPC_CREAT`和`IPC_EXCL`标志`ENOENT：key`指定的消息队列不存在同时`msgflg`中没有指定`IPC_CREAT标志``ENOMEM`：需要建立消息队列，但内存不足`ENOSPC`：需要建立消息队列，但已达到系统的限制 |                                    |

如果用msgget创建了一个新的消息队列对象时，则msqid_ds结构成员变量的值设置如下：

​    msg_qnum、msg_lspid、msg_lrpid、 msg_stime、msg_rtime设置为0。

​    msg_ctime设置为当前时间。

​    msg_qbytes设成系统的限制值。

​    msgflg的读写权限写入msg_perm.mode中。

​    msg_perm结构的uid和cuid成员被设置成当前进程的有效用户ID，gid和cuid成员被设置成当前进程的有效组ID。

#### 2.  `msgctl`函数原型

| msgctl (获取和设置消息队列的属性)                            |                                                              |                |
| ------------------------------------------------------------ | ------------------------------------------------------------ | -------------- |
| 所需头文件                                                   | #include <sys/types.h>#include <sys/ipc.h>#include <sys/msg.h> |                |
| 函数说明                                                     | 获取和设置消息队列的属性                                     |                |
| 函数原型                                                     | int msgctl(int msqid, int cmd, struct msqid_ds *buf)         |                |
| 函数传入值                                                   | msqid                                                        | 消息队列标识符 |
| cmd                                                          | IPC_STAT:获得msgid的消息队列头数据到buf中                    |                |
| IPC_SET：设置消息队列的属性，要设置的属性需先存储在buf中，可设置的属性包括：msg_perm.uid、msg_perm.gid、msg_perm.mode以及msg_qbytes |                                                              |                |
| buf：消息队列管理结构体，请参见消息队列内核结构说明部分      |                                                              |                |
| 函数返回值                                                   | 成功：0                                                      |                |
| 出错：-1，错误原因存于error中                                |                                                              |                |
| 错误代码                                                     | EACCESS：参数cmd为IPC_STAT，确无权限读取该消息队列EFAULT：参数buf指向无效的内存地址EIDRM：标识符为msqid的消息队列已被删除EINVAL：无效的参数cmd或msqidEPERM：参数cmd为IPC_SET或IPC_RMID，却无足够的权限执行 |                |

#### 3.  `msgsnd`函数原型

| msgsnd (将消息写入到消息队列)                                |                                                              |                |
| ------------------------------------------------------------ | ------------------------------------------------------------ | -------------- |
| 所需头文件                                                   | #include <sys/types.h>#include <sys/ipc.h>#include <sys/msg.h> |                |
| 函数说明                                                     | 将msgp消息写入到标识符为msqid的消息队列                      |                |
| 函数原型                                                     | int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg) |                |
| 函数传入值                                                   | msqid                                                        | 消息队列标识符 |
| msgp                                                         | 发送给队列的消息。msgp可以是任何类型的结构体，但第一个字段必须为long类型，即表明此发送消息的类型，msgrcv根据此接收消息。msgp定义的参照格式如下：  struct s_msg{ /*msgp定义的参照格式*/    long type; /* 必须大于0,消息类型 */       char mtext[256]; /*消息正文，可以是其他任何类型*/   } msgp; |                |
| msgsz                                                        | 要发送消息的大小，不含消息类型占用的4个字节,即mtext的长度    |                |
| msgflg                                                       | 0：当消息队列满时，msgsnd将会阻塞，直到消息能写进消息队列    |                |
| IPC_NOWAIT：当消息队列已满的时候，msgsnd函数不等待立即返回   |                                                              |                |
| IPC_NOERROR：若发送的消息大于size字节，则把该消息截断，截断部分将被丢弃，且不通知发送进程。 |                                                              |                |
| 函数返回值                                                   | 成功：0                                                      |                |
| 出错：-1，错误原因存于error中                                |                                                              |                |
| 错误代码                                                     | EAGAIN：参数msgflg设为IPC_NOWAIT，而消息队列已满EIDRM：标识符为msqid的消息队列已被删除EACCESS：无权限写入消息队列EFAULT：参数msgp指向无效的内存地址EINTR：队列已满而处于等待情况下被信号中断EINVAL：无效的参数msqid、msgsz或参数消息类型type小于0 |                |

  msgsnd()为阻塞函数，当消息队列容量满或消息个数满会阻塞。消息队列已被删除，则返回EIDRM错误；被信号中断返回E_INTR错误。

 如果设置IPC_NOWAIT消息队列满或个数满时会返回-1，并且置EAGAIN错误。

msgsnd()解除阻塞的条件有以下三个条件：

①  不满足消息队列满或个数满两个条件，即消息队列中有容纳该消息的空间。

②  msqid代表的消息队列被删除。

③  调用msgsnd函数的进程被信号中断。

#### 4. ` msgrcv`函数原型

| msgrcv (从消息队列读取消息)                                  |                                                              |                |
| ------------------------------------------------------------ | ------------------------------------------------------------ | -------------- |
| 所需头文件                                                   | #include <sys/types.h>#include <sys/ipc.h>#include <sys/msg.h> |                |
| 函数说明                                                     | 从标识符为msqid的消息队列读取消息并存于msgp中，读取后把此消息从消息队列中删除 |                |
| 函数原型                                                     | ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,           int msgflg); |                |
| 函数传入值                                                   | msqid                                                        | 消息队列标识符 |
| msgp                                                         | 存放消息的结构体，结构体类型要与msgsnd函数发送的类型相同     |                |
| msgsz                                                        | 要接收消息的大小，不含消息类型占用的4个字节                  |                |
| msgtyp                                                       | 0：接收第一个消息                                            |                |
| >0：接收类型等于msgtyp的第一个消息                           |                                                              |                |
| <0：接收类型等于或者小于msgtyp绝对值的第一个消息             |                                                              |                |
| msgflg                                                       | 0: 阻塞式接收消息，没有该类型的消息msgrcv函数一直阻塞等待    |                |
| IPC_NOWAIT：如果没有返回条件的消息调用立即返回，此时错误码为ENOMSG |                                                              |                |
| IPC_EXCEPT：与msgtype配合使用返回队列中第一个类型不为msgtype的消息 |                                                              |                |
| IPC_NOERROR：如果队列中满足条件的消息内容大于所请求的size字节，则把该消息截断，截断部分将被丢弃 |                                                              |                |
| 函数返回值                                                   | 成功：实际读取到的消息数据长度                               |                |
| 出错：-1，错误原因存于error中                                |                                                              |                |
| 错误代码                                                     | E2BIG：消息数据长度大于msgsz而msgflag没有设置IPC_NOERROREIDRM：标识符为msqid的消息队列已被删除EACCESS：无权限读取该消息队列EFAULT：参数msgp指向无效的内存地址ENOMSG：参数msgflg设为IPC_NOWAIT，而消息队列中无消息可读EINTR：等待读取队列内的消息情况下被信号中断 |                |

msgrcv()解除阻塞的条件有以下三个：

①  消息队列中有了满足条件的消息。

②  msqid代表的消息队列被删除。

③  调用msgrcv()的进程被信号中断。

 

消息队列使用程序范例

```cpp
/*************************************************************************
	> File Name: msg.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年05月10日 星期日 16时52分54秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[80];
};

static void usage(char *prog_name, char *msg) { //出错函数
    if (msg != NULL)
        fputs(msg, stderr);

    fprintf(stderr, "Usage: %s [options]\n", prog_name);
    fprintf(stderr, "Options are:\n");
    fprintf(stderr, "-s        send message using msgsnd()\n");
    fprintf(stderr, "-r        read message using msgrcv()\n");
    fprintf(stderr, "-t        message type (default is 1)\n");
    fprintf(stderr, "-k        message queue key (default is 1234)\n");
    exit(EXIT_FAILURE);
}

static void send_msg(int qid, int msgtype) {
    struct msgbuf msg;
    time_t t;

    msg.mtype = msgtype;

    time(&t);//取时间
    snprintf(msg.mtext, sizeof(msg.mtext), "a message at %s", 
             ctime(&t));

    if (msgsnd(qid, (void *) &msg, sizeof(msg.mtext),
                IPC_NOWAIT) == -1) {
        perror("msgsnd error");
        exit(EXIT_FAILURE);
    }
    printf("sent: %s\n", msg.mtext);
}

static void get_msg(int qid, int msgtype) {
    struct msgbuf msg;

    if (msgrcv(qid, (void *) &msg, sizeof(msg.mtext), msgtype,
               MSG_NOERROR | IPC_NOWAIT) == -1) {
        if (errno != ENOMSG) {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("No message available for msgrcv()\n");
    } else
        printf("message received: %s\n", msg.mtext);
}

int main(int argc, char *argv[]) {
    int qid, opt;
    int mode = 0;               /* 1 = send, 2 = receive */
    int msgtype = 1;
    int msgkey = 1234;

    while ((opt = getopt(argc, argv, "srt:k:")) != -1) {
        switch (opt) {
        case 's':
            mode = 1;
            break;
        case 'r':
            mode = 2;
            break;
        case 't':
            msgtype = atoi(optarg);
            if (msgtype <= 0)
                usage(argv[0], "-t option must be greater than 0\n");
            break;
        case 'k':
            msgkey = atoi(optarg);
            break;
        default:
            usage(argv[0], "Unrecognized option\n");
        }
    }

    if (mode == 0)
        usage(argv[0], "must use either -s or -r option\n");

    qid = msgget(msgkey, IPC_CREAT | 0666);

    if (qid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    if (mode == 2)
        get_msg(qid, msgtype);
    else
        send_msg(qid, msgtype);

    exit(EXIT_SUCCESS);
    return 0;
}
```



