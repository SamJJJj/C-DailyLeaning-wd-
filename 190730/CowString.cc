#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
class CharProxy;

class CowString
{
    friend class CharProxy;

public:
    CowString()
        : _pstr(new char[5]() + 4)
    {
        initRefCnt();
        cout << "CowString()" << endl;
    }

    CowString(const char *pstr)
        : _pstr(new char[strlen(pstr) + 5] + 4)
    {
        initRefCnt();
        strcpy(_pstr, pstr);
        cout << "CowString(const char *)" << endl;
    }

    CowString(const CowString &rhs)
        : _pstr(rhs._pstr)
    {
        cout << "CowString(const CowString &)" << endl;
        incrRefCnt();
    }

    CowString &operator=(const CowString &rhs)
    {
        if (this != &rhs)
        {
            release();
            _pstr = rhs._pstr;
            incrRefCnt();
        }
        return *this;
    }

    const char *c_str() const
    {
        return _pstr;
    }

    int refCnt()
    {
        return *(int *)(_pstr - 4);
    }

    int size()
    {
        return strlen(_pstr);
    }

    CharProxy operator[](int idx);
    ~CowString()
    {
        release();
    }
    friend std::ostream &operator<<(std::ostream &os, const CowString &s);

private:
    char *_pstr;
    void initRefCnt()
    {
        *(int *)(_pstr - 4) = 1;
    }

    void incrRefCnt()
    {
        ++*(int *)(_pstr - 4);
    }

    void decrRefCnt()
    {
        --*(int *)(_pstr - 4);
    }
    void release()
    {
        decrRefCnt();
        if (0 == refCnt())
        {
            delete[](_pstr - 4);
            cout << "_pstr already free " << endl;
        }
    }
};

std::ostream &operator<<(std::ostream &os, const CowString &s)
{
    os << s._pstr;
    return os;
}

class CharProxy
{
public:
    CharProxy(CowString & myStr, int idx)
        : _myStr(myStr), _idx(idx)
    {
        cout << "CharProxy(CowString, int)" << endl;
    }

    CharProxy &operator=(const char &c)
    {
        if (_idx >= 0 && _idx < _myStr.size())
        {
            _myStr.release();
            char *ptmp = new char[_myStr.size() + 5]() + 4;
            strcpy(ptmp, _myStr._pstr);
            ptmp[_idx] = c;
            _myStr._pstr = ptmp;
            _myStr.initRefCnt();
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const CharProxy &s);

private:
    CowString &_myStr;
    int _idx;
};

std::ostream &operator<<(std::ostream &os, const CharProxy &s)
{
    if (s._idx >= 0 && s._idx < s._myStr.size())
        os << *(s._myStr.c_str() + s._idx);
    else
        os << '\0';
    return os;
}

CharProxy CowString::operator[](int idx)
{
    return CharProxy(*this, idx);
}

int main(int argc, char **argv)
{
    CowString s1 = "hello,world";

    CowString s2 = "hello,world";

    CowString s3 = "shenzhen";
    cout << "s3 = " << s3 << endl;
    s3 = s1;

    cout << "执行赋值操作之后:" << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address is %p\n", s1.c_str());
    printf("s2's address is %p\n", s2.c_str());
    printf("s3's address is %p\n", s3.c_str());
    cout << "s1's refCnt = " << s1.refCnt() << endl;
    cout << "s2's refCnt = " << s2.refCnt() << endl;
    cout << "s3's refCnt = " << s3.refCnt() << endl;

    cout << "\n修改共享字符串的内容之后:" << endl;
    s3[0] = 'X';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address is %p\n", s1.c_str());
    printf("s2's address is %p\n", s2.c_str());
    printf("s3's address is %p\n", s3.c_str());
    cout << "s1's refCnt = " << s1.refCnt() << endl;
    cout << "s2's refCnt = " << s2.refCnt() << endl;
    cout << "s3's refCnt = " << s3.refCnt() << endl;

    cout << "s1[0] = " << s1[0] << endl;
    printf("s1's address is %p\n", s1.c_str());

    return 0;
}