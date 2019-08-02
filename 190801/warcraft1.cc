#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Warrior
{

public:
    Warrior(int no, int hp)
    : _no(no)
    , _hp(hp)
    {}
    
    int getNo() const
    {
        return _no;
    }

    int getHp() const
    {
        return _hp;
    }

private:
    int _no;
    int _hp;
};

class Weapon
{
public:
    Weapon(int id)
    : _id(id)
    {}

    const char * getWeaponName() const
    {
        switch(_id)
        {
        case 0:
            return "sword";
        case 1:
            return "bomb";
        case 2:
            return "arrow";
        }
    }

private:
    int _id;
};

class Dragon
    : public Warrior
{
public:
    Dragon(int hp, int no, int res)
    : Warrior(no, hp)
    , _morale((float)res / hp)
    , _weapon(Weapon(no % 3))
    {

    }

    void print1 () const
    {
        printf("dragon %d born with strength %d,", getNo(), getHp());
    }

    void print2 () const
    {
        printf(" It has a %s and it's morale is %.2f\n", _weapon.getWeaponName(), _morale);
    }

private:
    float _morale;
    Weapon _weapon;
};

class Ninja
: public Warrior
{
public:
    Ninja(int hp, int no)
    : Warrior(no, hp)
    , _weapon1(Weapon(no%3))
    , _weapon2(Weapon(no % 3 + 1))
    {}

    void print1() const
    {
        printf("ninja %d born with strength %d,", getNo(), getHp());
    }

    void print2 () const
    {
        printf(" It has a %s and a %s\n", _weapon1.getWeaponName(), _weapon2.getWeaponName());
    }


private:
    Weapon _weapon1;
    Weapon _weapon2;
};

class Iceman
: public Warrior
{
public:
    Iceman(int hp, int no)
    : Warrior(no, hp)
    , _weapon(Weapon(no % 3))
    {}

    void print1 () const
    {
        printf("iceman %d born with strength %d,", getNo(), getHp());
    }

    void print2 () const
    {
        printf(" It has a %s \n", _weapon.getWeaponName());
    }

private:
    Weapon _weapon;
};

class Lion
: public Warrior
{
public:
    Lion(int hp, int no, int res)
    : Warrior(no, hp)
    , _loyalty(res)
    {}

    void print1 () const
    {
        printf("lion %d born with strength %d,", getNo(), getHp());
    }

    void print2 () const
    {
        printf(" It's loyalty is %d\n", _loyalty);
    }

private:
    int _loyalty;
};

class Wolf
: public Warrior
{
public:
    Wolf(int hp, int no)
    :Warrior(no, hp)
    {}
    void print1() const
    {
        printf("wolf %d born with strength %d,", getNo(), getHp());
    }
};

class Headquarter
{
public:
    Headquarter(bool color, int totalElements, int dragonHp, int ninjaHp, int icemanHp, int lionHp, int wolfHp)
    : _color(color)
    , _totalElements(totalElements)
    , _no(0)
    , _time(0)
    , _dragonHp(dragonHp)
    , _ninjaHp(ninjaHp)
    , _icemanHp(icemanHp)
    , _lionHp(lionHp)
    , _wolfHp(wolfHp)
    , _redFlag(0)
    , _blueFlag(0)
    {}

    int redCreate()
    {
        switch(_redFlag)
        {
            case 0:
                goto red0;
            case 1:
                goto red1;
            case 2:
                goto red2;
            case 3:
                goto red3;
            case 4:
                goto red4;
            case 5:
                return -1;
            };
    red0:
        if (_totalElements > _icemanHp)
        {
            ++_no;
            _totalElements -= _icemanHp;
            Iceman newIceman(_icemanHp, _no);
            _warriorIceman.push_back(newIceman);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newIceman.print1();
            printf("%ld iceman in %s headquarter\n", _warriorIceman.size(), _color ? "red" : "blue");
            newIceman.print2();
            ++_time;
            _redFlag = (_redFlag + 1) % 5;
            return 0;
        }
    red1:
        if (_totalElements > _lionHp)
        {
            ++_no;
            _totalElements -= _lionHp;
            Lion newLion(_lionHp, _no, _totalElements);
            _warriorLion.push_back(newLion);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newLion.print1();
            printf("%ld lion in %s headquarter\n", _warriorLion.size(), _color ? "red" : "blue");
            newLion.print2();
            ++_time;
            _redFlag = (_redFlag + 1) % 5;
            return 0;
        }
    red2:
        if (_totalElements > _wolfHp)
        {
            ++_no;
            _totalElements -= _wolfHp;
            Wolf newWolf(_wolfHp, _no);
            _warriorWolf.push_back(newWolf);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newWolf.print1();
            printf("%ld wolf in %s headquarter\n", _warriorWolf.size(), _color ? "red" : "blue");
            ++_time;
            _redFlag = (_redFlag + 1) % 5;
            return 0;
        }
    red3:
        if (_totalElements > _ninjaHp)
        {
            ++_no;
            _totalElements -= _ninjaHp;
            Ninja newNinja(_ninjaHp, _no);
            _warriorNinja.push_back(newNinja);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newNinja.print1();
            printf("%ld ninja in %s headquarter\n", _warriorNinja.size(), _color ? "red" : "blue");
            newNinja.print2();
            ++_time;
            _redFlag = (_redFlag + 1) % 5;
            return 0;
        }
    red4:
        if (_totalElements > _dragonHp)
        {
            ++_no;
            _totalElements -= _dragonHp;
            Dragon newDragon(_dragonHp, _no, _totalElements);
            _warriorDragon.push_back(newDragon);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newDragon.print1();
            printf("%ld ninja in %s headquarter\n", _warriorDragon.size(), _color ? "red" : "blue");
            newDragon.print2();
            ++_time;
            _redFlag = (_redFlag + 1) % 5;
            return 0;
        }
        else
        {
            printf("%03d %s headquarter stops making warriors\n", _time, _color ? "red" : "blue");
            _redFlag = 5;
            return -1;
        }
    }

    int blueCreate()
    {
        switch(_blueFlag)
        {
            case 0:
                goto blue0;
                break;
            case 1:
                goto blue1;
                break;
            case 2:
                goto blue2;
                break;
            case 3:
                goto blue3;
                break;
            case 4:
                goto blue4;
                break;
            case 5:
                return -1;
        };
    blue0:
        if (_totalElements > _lionHp)
        {
            ++_no;
            _totalElements -= _lionHp;
            Lion newLion(_lionHp, _no, _totalElements);
            _warriorLion.push_back(newLion);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newLion.print1();
            printf("%ld lion in %s headquarter\n", _warriorLion.size(), _color ? "red" : "blue");
            newLion.print2();
            ++_time;
            _blueFlag = (_blueFlag + 1) % 5;
            return 0;
        }
    blue1:
        if (_totalElements > _dragonHp)
        {
            ++_no;
            _totalElements -= _dragonHp;
            Dragon newDragon(_dragonHp, _no, _totalElements);
            _warriorDragon.push_back(newDragon);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newDragon.print1();
            printf("%ld ninja in %s headquarter\n", _warriorDragon.size(), _color ? "red" : "blue");
            newDragon.print2();
            ++_time;
            _blueFlag = (_blueFlag + 1) % 5;
            return 0;
        }
    blue2:
        if (_totalElements > _ninjaHp)
        {
            ++_no;
            _totalElements -= _ninjaHp;
            Ninja newNinja(_ninjaHp, _no);
            _warriorNinja.push_back(newNinja);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newNinja.print1();
            printf("%ld ninja in %s headquarter\n", _warriorNinja.size(), _color ? "red" : "blue");
            newNinja.print2();
            ++_time;
            _blueFlag = (_blueFlag + 1) % 5;
            return 0;
        }
    blue3:
        if (_totalElements > _icemanHp)
        {
            ++_no;
            _totalElements -= _icemanHp;
            Iceman newIceman(_icemanHp, _no);
            _warriorIceman.push_back(newIceman);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newIceman.print1();
            printf("%ld iceman in %s headquarter\n", _warriorIceman.size(), _color ? "red" : "blue");
            newIceman.print2();
            ++_time;
            _blueFlag = (_blueFlag + 1) % 5;
            return 0;
        }
    blue4:
        if (_totalElements > _wolfHp)
        {
            ++_no;
            _totalElements -= _wolfHp;
            Wolf newWolf(_wolfHp, _no);
            _warriorWolf.push_back(newWolf);
            printf("%03d %s ", _time, _color ? "red" : "blue");
            newWolf.print1();
            printf("%ld wolf in %s headquarter\n", _warriorWolf.size(), _color ? "red" : "blue");
            ++_time;
            _blueFlag = (_blueFlag + 1) % 5;
            return 0;
        }
        else
        {
            printf("%03d %s headquarter stops making warriors\n", _time, _color ? "red" : "blue");
            _blueFlag = 5;
            return -1;
        }
    }

    int getTotalElements() const
    {
        return _totalElements;
    }

    int createWarrior()
    {
        if (_color)
        {
            return redCreate();
        }
        else
        {
            return blueCreate();
        }
    }

private:
    bool _color; //true----red, false----blue;
    int _totalElements;
    int _no;
    int _time;
    int _dragonHp;
    int _ninjaHp;
    int _icemanHp;
    int _lionHp;
    int _wolfHp;
    int _redFlag;
    int _blueFlag;
    vector<Dragon> _warriorDragon;
    vector<Wolf> _warriorWolf;
    vector<Lion> _warriorLion;
    vector<Iceman> _warriorIceman;
    vector<Ninja> _warriorNinja;
};

int main(int argc, char **argv)
{
    Headquarter red(true, 20, 3, 4, 5, 6, 7);
    Headquarter blue(false, 20, 3, 4, 5, 6, 7);
    int ret1 = 0, ret2 = 0;
    while (1)
    {
        ret1 = red.createWarrior();
        ret2 = blue.createWarrior();
        if(ret1==-1&&ret2==-1)
        {
            break;
        }
    }
}