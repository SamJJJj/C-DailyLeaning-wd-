#include <iostream>

using std::cout;
using std::endl;
using std::string;

enum weapons
{
    sword,
    bomb,
    arrow
};

class Warrior
{
public:
    Warrior(int hp, bool owner)
        : _noRed(), _noBlue(), _hp(hp), _owner(owner)
    {
        static int noRed = 0;
        static int noBlue = 0;
        if (_owner)
        {
            ++noRed;
            _noRed = noRed;
        }
        else
        {
            ++noBlue;
            _noBlue = noBlue;
        }
        // cout << "_noRed " << _noRed << endl
        //      << "_noBlue " << _noBlue << endl
        //      << "owner" << _owner << endl;
    }
    int getNo() const
    {
        if (_owner)
        {
            return _noRed;
        }
        else
        {
            return _noBlue;
        }
    }

private:
    int _noRed;
    int _noBlue;
    int _hp;
    bool _owner; //true是红色，false是蓝色
};

const char *getWeapon(int no)
{
    switch (no)
    {
    case sword:
        return "sword";
    case bomb:
        return "bomb";
    case arrow:
        return "arrow";
    }
}

class Dragon
    : public Warrior
{
public:
    Dragon(int hp, bool owner, int res)
    : Warrior(hp, owner), _morale((float)res / hp), _weapon()
    {
        static int cnt = 0;
        ++cnt;
        _cnt = cnt;
        _weapon = getNo() % 3;
        string weapon = getWeapon(_weapon);
        string own = owner ? "red" : "blue";

        printf("%03d %s dragon %d born with strenth %d, %d dragon in %s headquartuer It has a %s, and it's morale is %.2f\n", 0, own.c_str(), getNo(), hp, _cnt, own.c_str(), weapon.c_str(), _morale);
    }

private:
    float _morale;
    int _weapon;
    int _cnt;
};



int main(int argc, char **argv)
{
    Dragon dr1(3, 1, 11);

    return 0;
}