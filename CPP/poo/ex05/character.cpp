#include "Character.hpp"


Character::Character(int id, const std :: string& name, int level) noexcept : Unit(id, name), _level(level)
{
}

Character::~Character()
{

}

int Character:: get_level()const noexcept
{
    return _level;
}

void Character:: set_level(int level)
{
    this->_level = level;
}