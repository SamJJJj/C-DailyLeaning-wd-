#include <iostream>

using std::cout;
using std::endl;

class Queue
{
public:
    Queue(int size = 10)
    : _size(size)
    , _head(0)
    , _tail(0)
    , _nums(new int[_size]())
    , _emptyFlag(1)
    {
        cout << "Queue initialized" << endl;
    }

    bool empty()
    {
        if (1 == _emptyFlag && _head == _tail)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool full()
    {
        if (0 == _emptyFlag && _head == _tail)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int x)
    {
        if (full())
        {
            cout << "Queue is full, push failed" << endl;
            return;
        }
        else
        {
            if (1 == _emptyFlag)
            {
                _emptyFlag = 0;
            }
            _nums[_tail] = x;
            _tail = (_tail + 1) % _size;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty, pop failed" << endl;
            return;
        }
        else
        {
            _head = (_head + 1) % _size;
            if(_head == _tail)
            {
                _emptyFlag = 1;
            }
        }
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue is empty, get front failed" << endl;
            return -1;
        }
        else
        {
            return _nums[_head];
        }
    }

    int back()
    {
        if (empty())
        {
            cout << "Queue is empty, get back failed" << endl;
            return -1;
        }
        else
        {
            if (_tail > 0)              //可以不判断用：return _nums[(_tail+_size - 1)%_size]
                return _nums[_tail - 1]; 
            else
                return _nums[_size - 1];
        }
    }

    void print()
    {
        int i;
        if (empty())
        {
            cout << "empty Queue" << endl;
        }
        else
        {
            i = _head;
            while(1)
            {
                cout << _nums[i] << " ";
                i= (i + 1) % _size;
                if(i == _tail)
                    break;
            }
            cout << endl;
        }
    }

    
    ~Queue()
    {
        delete[] _nums;
    }
private:
    int _size;
    int _head, _tail;
    int * _nums;
    int _emptyFlag;
};

int main(int argc, char **argv)
{
    Queue Q;
    int i;
    for (i = 0; i < 10; ++i)
    {
        Q.push(i);
    }
    cout << "push over" << endl;
    Q.print();
    cout << "front = " << Q.front() << endl;
    cout << "back = " << Q.back() << endl;
    Q.pop();
    Q.push(41);
    Q.print();
    cout << "front = " << Q.front() << endl;
    cout << "back = " << Q.back() << endl;
    while(!Q.empty())
    {
        Q.pop();
    }
    cout << "empty = " << Q.empty() << endl;
    return 0;
}