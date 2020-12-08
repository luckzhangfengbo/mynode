/*************************************************************************
	> File Name: 29.singleton.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月21日 星期五 10时25分41秒
 ************************************************************************/
#include <iostream>
#include <mutex>
using namespace std;

class HttpServer {
public :
    static HttpServer *getInstance() {
        if (instance == nullptr) {
            std::unique_lock<std::mutex> lock(m_mutex);
            if (instance == nullptr) {
                instance = new HttpServer();
            }
        }
        return instance;
    }
private:
    static HttpServer *instance;
    static std::mutex m_mutex;
    HttpServer() {}
    HttpServer(const HttpServer &) = delete;
    ~HttpServer() {}
};

HttpServer *HttpServer::instance = nullptr;
std::mutex HttpServer::m_mutex;

int main() {
    HttpServer *t1 = HttpServer::getInstance();
    HttpServer *t2 = HttpServer::getInstance();
    cout << t1 << " " << t2 << endl;
    return 0;
}
