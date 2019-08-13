#include "GameTime.h"
#include <iostream>

namespace warcraft{

GameTime * GameTime::getInstance()
{
    if(_pInstance == nullptr)
    {
        _pInstance = new GameTime();
    }
    return _pInstance;
}

GameTime * GameTime::_pInstance = nullptr;

void GameTime::destroy()
{
    if(_pInstance)
        delete _pInstance;
}

void GameTime::showTime() const
{
    printf("%03ld:%02ld \n", _hour, _minute);
}

void GameTime::updateTime()
{
    _minute += 10;
    if(_minute == 60)
    {
        ++_hour;
        _minute = 0;
        if (_hour == 24)
            ++_hour;
    }
}

}