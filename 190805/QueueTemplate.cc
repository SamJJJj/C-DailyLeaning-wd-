#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <class T, int qSize = 10>
class Queue
{
public:
    Queue()
    : _head(0)
    , _tail(0)
    , _data(new T[qSize]())
    {}

    ~Queue();

    bool empty() const;
    bool full() const;
    void enQueue(const T &t);
    void deQueue();
    void display() const;

private:
    int _head, _tail;
    T *_data;
};

template<class T, int qSize>
Queue<T, qSize>::~Queue()
{
    if(_data)
        delete[] _data;
}

template<class T, int qSize>
bool Queue<T, qSize>::empty() const
{
    return _head == _tail;
}

template<class T, int qSize>
bool Queue<T, qSize>::full() const
{
    return (_tail + 1) % qSize == _head;
}

template<class T, int qSize>
void Queue<T, qSize>::enQueue(const T & t)
{
    if(!full())
    {
        _data[_tail] = t;
        _tail = (_tail + 1) % qSize;
    }
    else
    {
        cout << "Queue is full, cannot enQueue any element\n";
    }
}

template<class T, int qSize>
void Queue<T, qSize>::deQueue()
{
    if(!empty())
    {
        _head = (_head + 1) % qSize;
    }
    else
    {
        cout << "Queue is empty, cannot deQueue\n";
    }
}

template<class T, int qSize>
void Queue<T, qSize>::display() const
{
    for (int i = _head; i != _tail; (++i) % qSize)
    {
        cout << _data[i] << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    Queue<string> Q;
    // for (int i = 0; i < 10; ++i)
    // {
    //     Q.enQueue(i);
    // }
    // Q.deQueue();
    // Q.display();
    // cout << endl;
    // for (int i = 0; i < 10; ++i)
    // {
    //     Q.deQueue();
    // }
    for (int i = 0; i < 10; ++i)
    {
        Q.enQueue(string(3, 'a' + i));
    }
    Q.display();
    Q.deQueue();
    Q.display();
    return 0;
}