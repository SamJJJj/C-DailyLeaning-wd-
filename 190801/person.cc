#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person
{
public:
    Person(const char * name, const int & age)
    : _name(name)
    , _age(age)
    {
        cout << "Person(const char *, const int &)" << endl;
    }

    void display() const
    {
        cout << "name = " << _name << endl
             << "age = " << _age << endl;
    }

private:
    string _name;
    int _age;
};

class Employee
: public Person
{
public:
    Employee(const char *name, int age, const char *department, double salary)
    : Person(name, age)
    , _department(department)
    , _salary(salary)
    {
        cout << "Employee(const char *, int, const char *, double)" << endl;
        ++_cnt;
        _total += _salary;
    }

    void display() const
    {
        Person::display();
        cout << "department : " << _department << endl
             << "salary : " << _salary << endl;
    }

    double getAverage() const
    {
        return _total / _cnt;
    }

    // friend double getAverage(Employee &, Employee &, Employee &);

private:
    string _department;
    double _salary;
    static double _total;
    static int _cnt;
};

// double getAverage(Employee & e1,Employee & e2,Employee & e3)
// {
//     return (e1._salary + e2._salary + e3._salary) / 3;
// }

double Employee::_total = 0;
int Employee::_cnt = 0;

int main(int argc, char **argv)
{
    Employee sam("Sam", 22, "development", 8000);
    Employee sally("Sally", 20, "market", 8500);
    Employee dom("Dom", 24, "market", 12000);

    sam.display();
    sally.display();
    dom.display();

    cout << "average salary:" << dom.getAverage() << endl;

    return 0;
}