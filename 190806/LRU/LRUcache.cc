#include <iostream>
#include <unordered_map>
#include <list>
using std::cout;
using std::endl;
using std::list;
using std::unordered_map;

class LRUCache
{
public:
    LRUCache(int capacity)
    :_capacity(capacity)
    {}

    int get(int key)
    {
        auto it = _cacheMap.find(key);
        if(it != _cacheMap.end())
        {
            _cacheList.push_front(_CacheNode(key, _cacheMap[key]));
            if(_cacheList.size() > _capacity)
            {
                _cacheList.pop_back();
            }
            return _cacheMap[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        auto it = _cacheMap.find(key);
        struct _CacheNode node(key, value);
        if (it != _cacheMap.end())
        {
            it->second = value;
        }
        else
        {
            _cacheMap.insert({key, value});
        }

        if(_cacheList.size() == _capacity)
        {
            auto e = _cacheList.back();
            _cacheList.pop_back();
            _cacheMap.erase(e._key);
        }
        _cacheList.push_front(node);
    }

    void display() const
    {
        for(auto e : _cacheList)
        {
            cout << e._key << " , " << e._value << endl;
        }
        cout << "--------" << endl;
    }

private:
    struct _CacheNode{
        int _key;
        int _value;
        _CacheNode(int k, int v)
        : _key(k)
        , _value(v)
        {}
    };
    int _capacity;
    unordered_map<int, int> _cacheMap;
    list<_CacheNode> _cacheList;
};

int main(int argc, char **argv)
{
    LRUCache cache(2 /* capacity */);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.display();
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3); // evicts key 2
    cache.display();
    cout << cache.get(2) << endl;    // returns -1 (not found)
    cache.put(4, 4); // evicts key 1
    cache.display();
    cout << cache.get(1) << endl;    // returns -1 (not found)
    cout << cache.get(3) << endl;    // returns 3
    cout << cache.get(4) << endl;    // returns 4

    return 0;
}