#include <iostream>

using std::cout;
using std::endl;

class Stack
{

public:
    Stack(int size = 10)
    : _size(size)
    , _top(0)
    , _nums(new int[_size]())
    {}

    bool empty()
    {
        if (0 == _top)
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
        if (_size == _top)
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
            cout << "stack is full, push failed" << endl;
            return;
        }
        else
        {
            _nums[_top] = x;
            ++_top;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "stack is empty, pop failed" << endl;
            return;
        }
        else
        {
            --_top;
        }
    }

    int top()
    {
        if (0 == _top)
        {
            cout << "empty stack, get top failed" << endl;
            return -1;
        }
        else
        {
            return _nums[_top - 1];
        }
    }

    void print()
    {
        int i;
        if (0 == _top)
        {
            cout << "empty stack" << endl;
        }
        else
        {
            for (i = _top - 1; i >= 0; --i)
            {
                cout << i << " : " << _nums[i] << endl;
            }
        }
    }

    ~Stack()
    {
        delete[] _nums;
    }

private:
    int _size;
    int _top;
    int * _nums;
};

int main(int argc, char **argv)
{
    Stack S;
    S.push(10);
    S.push(12);
    S.push(14);
    S.print();
    cout << "top = " << S.top() << endl;
    S.pop();
    cout << "top = " << S.top() << endl;
    return 0;
}