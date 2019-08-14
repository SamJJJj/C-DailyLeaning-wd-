#pragma once
#include "Enum.h"
#include "Headquarter.h"
#include <memory>
#include <iostream>

namespace warcraft{
class Warrior;
typedef std::shared_ptr<Warrior> WarriorPtr;
class Warrior
: public std::enable_shared_from_this<Warrior>
{
public:
    Warrior(Color color,
            size_t id,
            size_t hp,
            size_t force,
            WarriorType type)
        : _color(color) 
        , _id(id)
        , _hp(hp)
        , _force(force)
        , _type(type)
        {}
    virtual ~Warrior();

    virtual void march();
    virtual void attack(WarriorPtr);
    virtual void defence(WarriorPtr);
    void beWinner();
    void beRewarded();
    void sentElem2Headquarter(size_t);
    void setHp(size_t hp) { _hp = hp; }
    void setCity(size_t id) { _cityId = id; }
    void setHeadquarter(Headquarter *headquarter) { _headquarter = headquarter; }

    Color getColor() const { return _color; }
    size_t getId() const { return _id; }
    size_t getHp() const { return _hp; }
    size_t getForce() const { return _force; }
    size_t getCityId() const { return _cityId; }
    size_t getEarnElements() const { return _earnElements; }
    WarriorType getType() const { return _type; }

protected:
    Color _color;
    size_t _id;
    size_t _hp;
    size_t _force;
    size_t _cityId;
    size_t _earnElements;
    WarriorType _type;
    Headquarter *_headquarter;
};

class Dragon
: public Warrior
{
public:
    Dragon(Color color, size_t id, size_t hp, size_t force, float morale)
    : Warrior(color, id, hp, force, DRAGON_TYPE)
    , _morale(morale)
    {}
    float getMorale() const { return _morale; }

private:
    float _morale;
};

class Ninja
: public Warrior
{
public:
    Ninja(Color color, size_t id, size_t hp, size_t force)
    :Warrior(color, id, hp, force, NINJA_TYPE)
    {}
    virtual void defence(WarriorPtr warrior) override;
};

class Iceman
: public Warrior
{
public:
    Iceman(Color color, size_t id, size_t hp, size_t force)
    : Warrior(color, id, hp, force, ICEMAN_TYPE)
    , _steps(0)
    {}

    virtual void march() override;

private:
    size_t _steps;
};

class Lion
: public Warrior
{
public:
    Lion(Color color, size_t id, size_t hp, size_t force, size_t loyalty)
    : Warrior(color, id, hp, force, LION_TYPE)
    , _loyalty(loyalty)
    {}

    size_t getLoyalty() const { return _loyalty; }

private:
    size_t _loyalty;
};

class Wolf
: public Warrior
{
public:
    Wolf(Color color, size_t id, size_t hp, size_t force)
    : Warrior(color, id, hp, force, WOLF_TYPE)
    , _killTimes(0)
    {}

    virtual void attack(WarriorPtr warrior) override;

private:
    int _killTimes;
};
} // namespace warcraft