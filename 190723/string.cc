#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
private:
    char *_pstr;

public:
    String();
    String(const char *pstr);
    String(const String & rhs);
    String & operator=(const String & rhs);
    ~String();

    void print();
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

String::String(const String & rhs)
{
    if(rhs._pstr)
    {
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr, rhs._pstr);
    }
    else
    {
        _pstr = nullptr;
    }
}

String & String::operator=(const String & rhs)
{
    if (&rhs != this)
    {
        delete[] _pstr;
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr, rhs._pstr);
    }
    return *this;
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

void String::print()
{
    if(_pstr)
        cout << _pstr << endl;
    else
        cout << "empty string!" << endl;
}

int main(int argc, char **argv)
{
    String str1;
    str1.print();
    
    String str2 = "Hello,world";
	String str3("wangdao");
	
	str2.print();		
	str3.print();	
	
	String str4 = str3;
	str4.print();
	
	str4 = str2;
	str4.print();
	

    return 0;
}