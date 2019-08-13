#pragma once
#include <string>
namespace warcraft
{
enum Color
{
    RED,
    BLUE,
    NOTSET
};

enum WarriorType
{
    DRAGON_TYPE,
    NINJA_TYPE,
    ICEMAN_TYPE,
    LION_TYPE,
    WOLF_TYPE
};
inline std::string toString(Color color){ //return headquarter color
    return ((color == RED) ? std::string("red") : std::string("blue"));
}

inline std::string toString(WarriorType type){//return warrior type
    switch(type){
    case DRAGON_TYPE :
        return "dragon";
    case NINJA_TYPE:
        return "ninja";
    case ICEMAN_TYPE:
        return "iceman";
    case LION_TYPE:
        return "lion";
    case WOLF_TYPE:
        return "wolf";
    default:
        return std::string();
    }
}
} // namespace warcraft