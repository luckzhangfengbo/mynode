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
    #endif//0
```

