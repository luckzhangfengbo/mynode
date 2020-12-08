/*************************************************************************
	> File Name: 34.thread_poll.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月13日 星期四 16时07分55秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<functional>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>
using namespace std;
class Task{
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...);
    }
    void operator()() {
        this->func();
        return;
    }
private:
    function<void()>func;
};

void thread_func1(int a, int b) {
    cout << a << " + " << b << " = "<< a + b << endl;
    return ;
}

void thread_func2(int &n) {
    n += 1;
    return;
}

class ThreadPool{
public:
    ThreadPool(int n = 5)
    : max_threads_num(n),
    m_mutex(),
    m_cond() {}
    void start() {
        for(int i = 0; i < this->max_threads_num; i++) {
            //创建线程添加到线程池中
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
        return;
    }
    void worker() {
        thread::id id = this_thread::get_id();
        is_running[id] = true;
        while(is_running[id]) {
            //取任务
            Task *t = this->getOneTask();
            //执行任务
            (*t)();
            //释放任务
            delete t;
        }
    }
    void stop() {
        this_thread::sleep_for(chrono::seconds(2)); 
        for(int i = 0; i < this->max_threads_num; i++) {
            this->addOneTask(&ThreadPool::stop_task, this);
        } 
        for(int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return;
    }

    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS...args) {
        unique_lock<mutex> lock(m_mutex);//抢占锁
        this->task_queue.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();//添加一个通知一次,92行等待就会往下走
        return;
    }
private:
    void stop_task() {
        thread::id id = this_thread::get_id();
        is_running[id] = false;
        return;
    }
    //不想让main访问所以放在private;
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex);//抢碗
        while(task_queue.empty()){
            m_cond.wait(lock);//等待lock里的队列有资源,等待同时释放这个锁
        }//等待,直到队列中存在任务
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    int max_threads_num;
    vector<thread *> threads;
    queue<Task *>task_queue;
    map<thread::id, bool>is_running;
    mutex m_mutex;
    condition_variable m_cond;
};

void task_func(int x) {
    cout << "task func : " << x << endl;
    return;
}

int is_prime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}


int cnt = 0;
void count_prime(int l, int r) {
    for(int i = l; i <= r; i++) {
        if(is_prime(i))__sync_fetch_and_add(&cnt, 1);
    }
    return;
}


int main() {
    Task t1(thread_func1, 3, 4);
    Task t2(thread_func1, 5, 4);
    Task t3(thread_func1, 9, 4);
    t1();
    t2();
    t3();
    int n = 0;
    Task t4(thread_func2, ref(n));
    t4();
    t4();
    t4();
    cout << n << endl;

    ThreadPool tp(6);
    tp.start();
    for(int i = 0, j = 1; i < 5; i++, j += 200000) {
        tp.addOneTask(count_prime, j, j + 200000 - 1);   
    }
    tp.stop();
    cout << cnt << endl;
    std::cout << "hello world" << std::endl;
    return 0;
}
