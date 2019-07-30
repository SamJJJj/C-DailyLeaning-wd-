#include <string.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//实现自动singleton对象销毁
//方法二：atexit函数
class Conf
{
public:
    static Conf * getConf(const char *pStr = nullptr)
    {
        if(nullptr == _pConf)
        {
            ::atexit(destroy);          //程序结束自动调用destroy
            _pConf = new Conf(pStr);
        }
        return _pConf;
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

//Conf *Conf::_pConf = nullptr; //懒汉模式
Conf *Conf::_pConf = getConf(); //饿汉模式，此时可以用来保证线程安全

int main(int argc, char **argv)
{
    Conf *p1 = Conf::getConf("hello");
    Conf *p2 = Conf::getConf("world");
    Conf *p3 = Conf::getConf(nullptr);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    //Conf::destroy();
    return 0;
}