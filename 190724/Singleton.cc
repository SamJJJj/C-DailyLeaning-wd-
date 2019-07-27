#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//singleton例子
class Conf
{
public:
    static Conf * getConf(const char *pStr)
    {
        if(nullptr == _pConf)
        {
            _pConf = new Conf(pStr);
        }
        return _pConf;
    }

    static void destroy()
    {
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
    Conf(const char * pStr = nullptr)
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

Conf *Conf::_pConf = nullptr;

int main(int argc, char **argv)
{
    Conf *p1 = Conf::getConf("hello");
    Conf *p2 = Conf::getConf("world");
    Conf *p3 = Conf::getConf(nullptr);
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    p1->print();
    p2->print();
    p3->print();
    Conf::destroy();
    return 0;
}