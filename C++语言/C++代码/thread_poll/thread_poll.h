/*************************************************************************
	> File Name: ThreadPoll.h
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月14日 星期五 16时33分53秒
 ************************************************************************/

#ifndef _THREAD_POLL_H
#define _THREAD_POLL_H
namespace haizei{
class Task{
public:
    template<typename Func_T, typename ...ARGS>
    Task(Func_T f, ARGS ...args) {
        func = std::bind(f, forward<ARGS>(args)...);
        //由于是拷贝行为,不能把他的类型改变所以此处加上一个forward,不要改变类型
    }
    void run() {
        func();
    }
private:
    function<void()>func;
};
    
class ThreadPoll {
public:
    ThreadPoll(int thread_size = 5) :
    is_started(false), 
    thread_size(thread_size),
    m_mutex(),
    m_cond(m_mutex){}
    //默认启动5个线程

    void start();   //多线程的初始化
    void stop();    //销毁
    ~ThreadPoll() {
        stop();
    }
private:
    bool is_started;
    void thread_loop();//入口函数
    Task *get_one_task();//去队列中取任务
    void add_one_task(Task *);
    int thread_size;
    //每一位存储的线程对象
    std::vector<std::thread *> Threads;
    std::queue<Task *>Tasks;//若干个任务
    std::mutex m_mutex;//互斥锁
    std::condition_variable m_cond;//条件变量
};

void ThreadPoll::start() {
    std::unique_lock<std::mutex> loc(m_mutex);//获取互斥锁
    is_started = true;
    for(int i = 0; i < thread_size; i++) {
        //添加线程
        Threads.push_back(new thread(&ThreadPoll::thread_loop, this));
    }
}

void ThreadPoll::stop() {
    std::unique_lock<std::mutex> loc(m_mutex);//获取互斥锁
    is_started = false;//是否在运行状态
    for(int i = 0; i < Threads.size(); i++) {
        Threads[i]->join();
        delete Threads[i];
    }
    Threads.clear();
    return;
}

void ThreadPoll::get_one_task() {
    //先获取跟条件变量绑定的到相关的锁
    //m_cond条件成熟的时候,我么可以调用m_cond.notifyAll通知所有等待的条件成熟了
    std::unique_lock<std::mutex> lock(m_mutex);//获取互斥锁
    while(Tasks.empty() && is_started) {
        //任务队列空,线程池还在运行
        m_cond.wait(lock);//等待相关的线程,等待条件成立,当有人添加的时候会通知我//阻塞线程一直等到条件成立
    }
    Task *t = nullptr;
    if(!Tasks.empty() && is_started) {//取任务
        t = Tasks.front();
        Tasks.pop();
    }
    return t;
}


void ThreadPoll::add_one_task(Task *t) {
    std::unique_lock<std::mutex> loc(m_mutex);//获取互斥锁
    Tasks.push(t);
    //通知所有等待的条件成熟了
    m_cond.notify();
    return t;
}

void ThreadPoll::thread_loop() {
    while(is_started) {
        Task *t = get_one_task();//去任务队列中取任务,当任务队列中为空一直等,当有人放取出来,返回指针t,下面执行
        if(t != nullptr) {
            t->run();
        }
    }
    return ;
}
}
#endif
