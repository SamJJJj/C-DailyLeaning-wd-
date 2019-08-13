#pragma once
#include <vector>

namespace warcraft
{
class Headquarter;
class City;

class WarcraftWord{
public:
    explicit
    WarcraftWord()
    : _redHeadquarter(nullptr)
    , _blueHeadQuarter(nullptr)
    {
        init();
    }
    void start()
    {
        while(1)
        {
            createWarrior();
            if(!warriorMarch())
            {
                break;
            }
            cityProduceElements();
            takeCityElements();
            battle();
            headquarterReport();
        }
    }

private:
    void init();//配置文件读得数据并初始化
    void createWarrior();   //00分开始
    bool warriorMarch();
    void cityProduceElements();
    void takeCityElements();
    void battle();
    void headquarterReport();//50分报告战况

    bool createWarrior(Headquarter *);
    void warriorMarch(Headquarter *);
    bool checkRedBetaken();
    bool checkBlueBetaken();
private:
    Headquarter * _redHeadquarter;
    Headquarter *_blueHeadQuarter;
    std::vector<City> _cities;
};
} // namespace warcraft