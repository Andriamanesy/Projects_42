#include "Unit.hpp"

Unit::Unit(int id, const std :: string& name) noexcept: _id(id), _name(name)
{

}

Unit::~Unit()
{

}

int Unit:: get_id()const noexcept
{
    return this->_id;
}
std :: string Unit:: get_name()const noexcept
{
    return this->_name;
}
void Unit:: set_id(int id)
{
    this->_id = id;
}
void Unit:: set_name(std::string name)
{
    this->_name = name;
}