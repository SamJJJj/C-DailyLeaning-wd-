#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String();
    String(const char *pstr);
    String(const String &rhs);
    ~String();
    String &operator=(const String &);
    String &operator=(const char *);
    String &operator+=(const String &);
    String &operator+=(const char *);
    char &operator[](std::size_t);
    const char &operator[](std::size_t index) const;
    std::size_t size() const;
    const char *c_str() const;

    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend std::istream &operator>>(std::istream &is, String &s);
private:
    char *_pstr;

};

String::String()
{
    _pstr = nullptr;
}

String::String(const char *pstr)
{
    _pstr = new char[strlen(pstr) + 1]();
    strcpy(_pstr, pstr);
}

String::String(const String &rhs)
{
    if (rhs._pstr)
    {
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr, rhs._pstr);
    }
    else
    {
        _pstr = nullptr;
    }
}

String &String::operator=(const String &rhs)
{
    if (&rhs != this)
    {
        delete[] _pstr;
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr, rhs._pstr);
    }
    return *this;
}

String &String::operator=(const char *str)
{
    if (strlen(str) != 0)
    {
        if(_pstr)
        {
            free(_pstr);
            _pstr = new char[strlen(str) + 1]();
        }
        else
            _pstr = new char[strlen(str) + 1]();
        for (int i = 0; i < strlen(str); ++i)
        {
            _pstr[i] = str[i];
        }
    }
    return *this;
}

std::size_t String::size() const
{
    return strlen(_pstr);
}

String &String::operator+=(const String &rhs)
{
    if (rhs._pstr)
    {
        int totalSize = strlen(_pstr) + rhs.size() - 1;
        String temp = *this;
        free(_pstr);
        _pstr = new char[totalSize]();
        strcat(_pstr, temp._pstr);
        strcat(_pstr, rhs._pstr);
        temp.~String();
    }
    return *this;
}

String &String::operator+=(const char *str)
{
    if (str && _pstr)
    {
        int totalSize = strlen(_pstr) + strlen(str) - 1;
        String temp = *this;
        free(_pstr);
        _pstr = new char[totalSize]();
        strcat(_pstr, temp._pstr);
        strcat(_pstr, str);
        temp.~String();
    }
    else if(_pstr==nullptr)
    {
        _pstr = new char[strlen(str) + 1];
        strcat(_pstr, str);
    }
    return *this;
}

char &String::operator[](std::size_t index)
{
    if (index >= 0 && index <= this->size())
    {
        return _pstr[index];
    }
    else
    {
        static char nullChar = '\0';
        cout << "access over boundary" << endl;
        return nullChar;
    }
}

const char &String::operator[](std::size_t index) const
{
    if (index >= 0 && index <= this->size())
    {
        return _pstr[index];
    }
    else
    {
        static char nullChar = '\0';
        cout << "access over boundary" << endl;
        return nullChar;
    }
}

const char *String::c_str() const
{
    return _pstr;
}

bool operator==(const String &lhs, const String &rhs)
{
    return (!strcmp(lhs._pstr, rhs._pstr));
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    return (strcmp(lhs._pstr, rhs._pstr) < 0);
}

bool operator>(const String &lhs, const String &rhs)
{
    return (strcmp(lhs._pstr, rhs._pstr) > 0);
}

bool operator<=(const String &lhs, const String &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const String &lhs, const String &rhs)
{
    return !(lhs < rhs);
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s._pstr;
    return os;
}

std::istream &operator>>(std::istream &is, String &s)
{
    char temp[1024];
    is.get(temp, 1024, '\n');
    s = temp;
    return is;
}

String::~String()
{
    if (_pstr)
    {
        delete[] _pstr;
        _pstr = NULL;
    }
    cout << "~String()" << endl;
}


int main(int argc, char **argv)
{
    String str1;
    std::cin >> str1;
    cout << str1 << endl;    

    return 0;
}