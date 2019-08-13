#include "GameConfig.h"
#include <iostream>
#include <fstream>

namespace warcraft{

GameConfig *GameConfig::getInstance()
{
    if(_pInstance == nullptr)
        _pInstance = new GameConfig();
    return _pInstance;
}

vector<WarriorType> initOrder = {
        DRAGON_TYPE,
        NINJA_TYPE,
        ICEMAN_TYPE,
        LION_TYPE,
        WOLF_TYPE};
GameConfig *GameConfig::_pInstance = nullptr;

void GameConfig::destroy()
{
    if(_pInstance)
        delete _pInstance;
}

void GameConfig::readFromConsole()
{
    _initWarriorOrder.insert(_initWarriorOrder.begin(),initOrder.begin(), initOrder.end());
    struct InitData data;
    size_t input;
    cin >> input;
    cin >> input;
    data._initElements = input;
    cin >> input;
    data._cityCnt = input;
    cin >> input;
    data._minutes = input;
    auto it = _initWarriorOrder.begin();
    while (cin >> input)
    {
        data._initLife[*it] = input;
        it++;
        if(it == _initWarriorOrder.end())
        {
            it = _initWarriorOrder.begin();
            break;
        }
    }
    while(cin >> input)
    {
        data._initAttack[*it] = input;
        it++;
        if(it == _initWarriorOrder.end())
        {
            break;
        }
    }
    _groups.push_back(data);
}

void GameConfig::readFromFile(const string &fileName)
{
    ifstream ifs;
    ifs.open(fileName);
        struct InitData data;
    vector<WarriorType> initOrder = {
        DRAGON_TYPE,
        NINJA_TYPE,
        ICEMAN_TYPE,
        LION_TYPE,
        WOLF_TYPE};
    _initWarriorOrder.insert(_initWarriorOrder.begin(),initOrder.begin(), initOrder.end());
    size_t input;
    ifs >> input;
    ifs >> input;
    data._initElements = input;
    ifs >> input;
    data._cityCnt = input;
    ifs >> input;
    data._minutes = input;
    auto it = _initWarriorOrder.begin();
    while (ifs >> input)
    {
        data._initLife[*it] = input;
        it++;
        if(it == _initWarriorOrder.end())
        {
            it = _initWarriorOrder.begin();
            break;
        }
    }
    while(ifs >> input)
    {
        data._initAttack[*it] = input;
        it++;
        if(it == _initWarriorOrder.end())
        {
            break;
        }
    }
    _groups.push_back(data);
    ifs.close();
}

void GameConfig::debug() const
{
    // cout << _groups[_currentConfigId]._initElements << endl
    //      << _groups[_currentConfigId]._cityCnt << endl
    //      << _groups[_currentConfigId]._minutes << endl
        //  << _groups[_currentConfigId]._initLife[DRAGON_TYPE] << endl
        //  << _groups[_currentConfigId]._initLife[NINJA_TYPE] << endl
        //  << _groups[_currentConfigId]._initLife[ICEMAN_TYPE] << endl
        //  << _groups[_currentConfigId]._initLife[LION_TYPE] << endl
        //  << _groups[_currentConfigId]._initLife[WOLF_TYPE] << endl
        //  << _groups[_currentConfigId]._initAttack[DRAGON_TYPE] << endl
        //  << _groups[_currentConfigId]._initAttack[NINJA_TYPE] << endl
        //  << _groups[_currentConfigId]._initAttack[ICEMAN_TYPE] << endl
        //  << _groups[_currentConfigId]._initAttack[LION_TYPE] << endl
        //  << _groups[_currentConfigId]._initAttack[WOLF_TYPE] << endl;
}
}