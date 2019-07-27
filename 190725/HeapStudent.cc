#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
    Student(int id = 0, const char * name = nullptr)
    : _id(id)
    , _name(new char[strlen(name) + 1]())
    {
        cout << "Student(int, const char *)" << endl;
        strcpy(_name, name);
    }

    void print() const
    {
        cout << "id = " << _id << endl
             << "name = " << _name << endl;
    }

    void destroy()
    {
        if(this)
            delete this;
    }

private:
    int _id;
    char *_name;
    ~Student()
    {
        cout << "~Student()" << endl;
        if (_name)
        {
            delete[] _name;
        }
    }
};

int main(int argc, char **argv)
{
    Student *stu1 = new Student(101, "Sam");
    //Student stu2(102, "Sally");
    stu1->print();
    //stu2.print();
    return 0;
}