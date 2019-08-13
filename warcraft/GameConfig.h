#pragma once
#include "Enum.h"
#include <vector>
#include <map>
#include <iostream>

namespace warcraft{
using namespace std;
class GameConfig
{
public:
    static GameConfig *getInstance();
    static void destroy();
    void readFromConsole();
    void readFromFile(const string &fileName);
    void nextGroupId() { ++_currentConfigId; }

    void debug() const;

    size_t groups() const { return _groups.size(); }
    size_t currentConfigId() const { return _currentConfigId; }
    size_t cityCnt() const { return _groups[_currentConfigId]._cityCnt; }
    size_t headquarterInitElements() const { return _groups[_currentConfigId]._initElements; }
    size_t warriorInitLife(WarriorType key) const { return (_groups[_currentConfigId]._initLife.find(key))->second; }
    size_t warriorInitAttack(WarriorType key) const { return (_groups[_currentConfigId]._initAttack.find(key))->second; }

private:
    GameConfig()
    :_currentConfigId(0)
    {}
    ~GameConfig() { cout << "~GameConfig()" << endl; }
    struct InitData
    {
        size_t _initElements;
        size_t _cityCnt;
        size_t _minutes;
        map<WarriorType, size_t> _initLife;
        map<WarriorType, size_t> _initAttack;
    };
    static GameConfig *_pInstance;
    size_t _currentConfigId;
    vector<WarriorType> _initWarriorOrder;
    vector<InitData> _groups;
};
} // namespace warcraft