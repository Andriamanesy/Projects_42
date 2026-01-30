#include "English.hpp"

English :: English(const std:: string& name) noexcept: Someone(name)
{
}

void English ::say_good_bye() const noexcept
{
    std ::cout << _name << ": good bye... " << std ::endl;
}
