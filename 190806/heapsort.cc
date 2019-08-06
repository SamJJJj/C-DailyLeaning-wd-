#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T, typename Compare = std::less<T>>
class HeapSort
{
public:
    template <class Container>
    HeapSort(Container & c)
    : _arr(c)
    {}
    Compare comp;
    void swap(int &x, int &y)
    {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }
    void heapAdjust(int adjustPos, int arrLen)
    {
        int dad = adjustPos;
        int son = 2 * dad + 1;
        while (son < arrLen)
        {
            if (son + 1 < arrLen && comp(_arr[son], _arr[son + 1]))
            {
                son++;
            }
            if (comp(_arr[dad] , _arr[son]))
            {
                T temp;
                swap(_arr[son], _arr[dad]);
                dad = son;
                son = 2 * dad + 1;
            }
            else
            {
                break;
            }
        }
    }
    void sort()
    {
        int i;
        for (i = _arr.size() / 2 - 1; i >= 0; i--)
        {
            heapAdjust(i, _arr.size());
        }
        swap(_arr[0], _arr[_arr.size() - 1]);
        for (i = _arr.size() - 1; i > 1; i--)
        {
           heapAdjust(0, i);
            swap(_arr[0], _arr[i - 1]);
        }
    }
    void display() const
    {
        for (auto e : _arr)
        {
            cout << e << " ";
        }
        cout << endl;
    }

private:
    vector<T> _arr;
};

int main(int argc, char **argv)
{
    vector<int> arr = {1, 3, 4, 2, 9, 7};
    HeapSort<int> hsort(arr);
    hsort.sort();
    hsort.display();
    cout << endl;
    return 0;
}