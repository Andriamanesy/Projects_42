#include "Indonesian.hpp"

Indonesian :: Indonesian(const std:: string& name) noexcept: Someone(name)
{
}

void Indonesian ::say_good_bye() const noexcept
{
    std ::cout << _name << ": selamat tinggal... " << std ::endl;
}
