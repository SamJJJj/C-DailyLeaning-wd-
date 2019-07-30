#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using std::cout;
using std::endl;

//实现自动singleton对象销毁
//方法三：atexit函数
class Conf
{
public:
    static Conf * getConf()
    {
        pthread_once(&_once, init);
        return _pConf;
    }

    static void init()
    {
        _pConf = new Conf();
        ::atexit(destroy);
    }

    static void destroy()
    {
        cout << "destroy()" << endl;
        if(_pConf)
            delete _pConf;
        
    }

    void print()
    {
        cout << _message << endl;
    }

private:
    char *_message;
    static Conf *_pConf;
    static pthread_once_t _once;
    Conf(const char *pStr = nullptr)
    {
        cout << "Conf(const char *pStr = nullptr)" << endl;
        if (pStr == nullptr)
        {
            _message = nullptr;
        }
        else
        {
            _message = new char[strlen(pStr) - 1];
            strcpy(_message, pStr);
        }
    }

    ~Conf()
    {
        cout << "~Conf()" << endl;
        if (nullptr != _message)
        {
            delete[] _message;
            _message = nullptr;
        }
    }
};

Conf *Conf::_pConf = nullptr; //懒汉模式
//Conf *Conf::_pConf = getConf(); //饿汉模式，此时可以用来保证线程安全
pthread_once_t Conf::_once = PTHREAD_ONCE_INIT;

int main(int argc, char **argv)
{
    Conf *p1 = Conf::getConf();
    Conf *p2 = Conf::getConf();
    Conf *p3 = Conf::getConf();
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    //Conf::destroy();
    return 0;
}