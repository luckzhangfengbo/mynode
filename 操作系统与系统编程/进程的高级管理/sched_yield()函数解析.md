# sched_yield()函数解析

## 1、让出CPU

Linux提供一个系统调用运行进程主动让出执行权：sched_yield。进程运行的好好的，为什么需要这个函数呢？有一种情况是用户空间线程的锁定。如果一个线程试图取得另一个线程所持有的锁，则新的线程应该让出处理器知道该锁变为可用。用户空间锁没有内核的支持，这是一个最间单、最有效率的做法。但是现在Linux线程实现引入一个使用futexes的优化解决方案。

另一个情况是在有处理器密集型程序可用周期性调用sched_yield，试图将该进程对系统的冲击减到最小。不管怎么说，如何调度程序应该是系统的事情，而不是进程自己去管。eg：

```
int main(){
    int ret, i;
    ret = sched_yield();
    if(ret == -1){
    printf("调用sched_yield失败!\n");
    }
    return 0;
}
```

## 2、进程的优先级

看过CFS中会看到进程的nice value会决定进程会运行多长时间，或者说是占用的百分比。可以通过系统调用nice来设置、获取进程的nice value。该值的范围是-20～19，越低的值越高的优先级（这个在计算虚拟时间的时候放在分母上），实时进程应该是负数，eg：

```
int main(){
    int ret, i;
    ret = nice(0);
    printf("当前进程的nice value：%d\n", ret);
    ret = nice(10);
    printf("当前进程的nice value：%d\n", ret);
    return 0;
}
```

因为ret本来就可以是-1，那么在判断是否系统调用失败的时候就要综合ret和errno。还有两个系统调用可以更灵活地设置，getpriority可以获得进程组、用户的任何进程中优先级最高的。setpriority将所指定的所有进程优先级设置为prio，eg：

```
int main(){
    int ret, i;
    ret = getpriority(PRIO_PROCESS, 0);
    printf("nice value:%d\n", ret);
    ret = setpriority(PRIO_PROCESS, 0, 10);
    ret = getpriority(PRIO_PROCESS, 0);
    printf("nice value:%d\n", ret);
    return 0;
}
```

进程有在处理器上执行的优先级，也有传输数据的优先级：I/O优先级。linux有额外的两个系统调用可用显示设置和取得I/O nice value，但是尚未导出：

```
int ioprio_get(int which, int who);
int ioprio_set(int which, int who, int ioprio);
```

