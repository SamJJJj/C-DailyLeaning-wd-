#pragma once
#include "Enum.h"
#include "Warrior.h"
#include <iostream>
#include <vector>

namespace warcraft
{
class City
{
public:
    City(size_t id, size_t elements = 0)
    : _flag(Color::NOTSET)
    , _id(id)
    , _elements(elements)
    , _redWinCnt(0)
    , _blueWinCnt(0)
    {}

    void produceElements();
    void attach(WarriorPtr);
    void detach(WarriorPtr);
    void startBattle();
    void takenBy(WarriorPtr);

    size_t getId() const { return _id; }
    Color getFlag() const { return _flag; }
    size_t getWarriorAmount() const
    {
        return _redWarriors.size() + _blueWarriors.size();
    }
    std::vector<WarriorPtr> &getRedWarriors() { return _redWarriors; }
    std::vector<WarriorPtr> &getBlueWarriors() { return _blueWarriors; }

private:
    void battle(WarriorPtr, WarriorPtr);
    bool isChangedFlag(WarriorPtr);
    Color _flag;
    size_t _id;
    size_t _elements;
    size_t _redWinCnt;
    size_t _blueWinCnt;
    std::vector<WarriorPtr> _redWarriors;
    std::vector<WarriorPtr> _blueWarriors;
};
} // namespace warcraft
