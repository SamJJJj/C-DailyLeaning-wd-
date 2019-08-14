#pragma once
#include "Warrior.h"
#include <queue>
#include <unordered_map>

namespace warcraft{

struct WarriorComparator{
    bool operator()(WarriorPtr warrior1, WarriorPtr warrior2)
    {
        return warrior1.get()->getId() < warrior2.get()->getId();
    }
};
class Headquarter
{
public:
    Headquarter(Color color, size_t elements)
    : _color(color)
    , _elements(elements)
    , _earnElements(0)
    , _nextWarriorIndex(0)
    {}

    virtual ~Headquarter(){}
    WarriorPtr create();
    void addWinner(WarriorPtr);
    void reward();
    void increaseElements(size_t elements) { _elements += elements; }
    void setElements(size_t elements) { _elements = elements; }
    template <typename Iterator>
    void setWarriorCreateOrder(Iterator beg, Iterator end)
    {
        for(; beg != end; ++beg)
        {
            _warriorCreateOrder.push_back(*beg);
        }
    }

    size_t getId() const { return _id; }
    void setId(size_t id) {_id = id;}
    Color getColor() const { return _color; }
    size_t getElements() const { return _elements; }
    std::vector<WarriorPtr> &getWarriors() { return _warriors; }

private:
    WarriorPtr createIceman(size_t id, size_t hp, size_t force);
    WarriorPtr createLion(size_t id, size_t hp, size_t force);
    WarriorPtr createWolf(size_t id, size_t hp, size_t force);
    WarriorPtr createNinja(size_t id, size_t hp, size_t force);
    WarriorPtr createDragon(size_t id, size_t hp, size_t force);

    void nextWarriorType();
    WarriorType getNextWarriorType()
    {
        return _warriorCreateOrder[_nextWarriorIndex];
    }
protected:
    Color _color;
    size_t _id; //所在位置
    size_t _elements;
    size_t _earnElements;
    size_t _nextWarriorIndex;
    std::vector<WarriorPtr> _warriors;
    std::vector<WarriorType> _warriorCreateOrder;
    std::priority_queue<WarriorPtr, std::vector<WarriorPtr>, WarriorComparator> _winners;
    std::unordered_map<WarriorType, size_t> _warriorTypeCnt;
};

class RedHeadquarter
:public Headquarter
{
public:
    RedHeadquarter(size_t elements)
    : Headquarter(RED, elements)
    {}
};

class BlueHeadQuarter
:public Headquarter
{
public:
    BlueHeadQuarter(size_t elements)
    : Headquarter(BLUE, elements)
    {}
    
};
}; // namespace warcraft