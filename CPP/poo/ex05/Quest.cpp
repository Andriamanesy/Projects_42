#include "Quest.hpp"
#include "Quest_status.hpp"

Quest:: ~Quest()
{
}

Quest :: Quest(const std:: string& name, const std::string& description, int unitId) noexcept: _name(name), _description(description)
{
    _status = Quest_status::disabled;
}

std:: string Quest :: get_name()const noexcept
{
    return this->_name;
}
std:: string Quest :: get_description()const noexcept
{
    return this->_description;
}
void Quest :: set_name(std:: string name)
{
    this->_name = name;
}
void Quest :: set_description(std:: string description)
{
    this->_description = description;
}

void Quest :: show() const noexcept
{
    std:: cout << _name << std:: endl;
    std:: cout << _description << std :: endl;
}