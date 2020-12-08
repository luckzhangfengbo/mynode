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
#include<queue>
#include<functional>
#include<thread>
#include<ctime>
#include<mutex>
#include<condition_variable>
using namespace std;
class Task{
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...);
    }
    void run(){
        this->func();
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

void thread_func2(int t, int &n) {
    n += 1;
    return;
}

class ThreadPool{
public:
    ThreadPool(int n = 5)
    : is_running(false), max_threads_num(n),
    m_mutex(), m_cond(){}

    void start() {
        if(is_running)return;
        is_running = true;
        for(int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
        return;
    }
    Task *get_one_task() {
        unique_lock<mutex> lock(m_mutex);
        while(Tasks.empty() && is_running){
            m_cond.wait(lock);
        }
        Task *t = nullptr;
        if(!Tasks.empty() && is_running){
            t = Tasks.front();
            Tasks.pop();
        }
        return t;
    }
    void worker() {
        while(is_running) {
            Task *t = get_one_task();
            if(t != nullptr) {
             cout << "thread_loop tid : " << this_thread::get_id() << endl;
               t->run(); 
            }
        }
    }
    void stop() {
        if(is_running == false) return;
        is_running = false;
        for(int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return;
    }
    template<typename Func_T, typename ...ARGS>
    void add_one_task(Func_T f, ARGS...args){
        __add_one_task(new Task(f, forward<ARGS>(args)...));
    }
    void __add_one_task(Task *t){
        unique_lock<mutex> lock(m_mutex);
        Tasks.push(t);
        m_cond.notify_one();
    }
private:
    bool is_running;
    int max_threads_num;
    vector<thread *> threads;
    queue<Task *> Tasks;
    mutex m_mutex;
    condition_variable m_cond;
};

int main() {
    Task t1(thread_func1, 3, 4);
    Task t2(thread_func1, 5, 4);
    Task t3(thread_func1, 9, 4);
    t1();
    t2();
    t3();
    int n = 0;
    /*
    Task t4(thread_func2, ref(n));
    t4();
    t4();
    t4();
    cout << n << endl;
*/
    ThreadPool tp(6);
    tp.start();
    for(int i = 0; i < 10; i ++) {
        tp.add_one_task(thread_func2, i, ref(n));
    }
    tp.stop();
    return 0;
}
