#include "Someone.hpp"

Someone :: Someone(const std:: string& name)noexcept : _name(name)
{

}

Someone :: ~Someone()
{
    
}

std :: string Someone :: get_name() const noexcept
{
    return _name;
}
void Someone :: set_name(std:: string name)
{
    this->_name = name;
}
