#include "Windows.hpp"
#include <iostream>


Windows :: Windows(std :: string t)
{
//    std :: cout << "Le titre est: " << t << " " << this <<std :: endl;
    set_title(t);
}

Windows :: ~Windows()
{
    std :: cout << "Destructeur de " << this << std :: endl;
}

std:: string Windows ::  get_title() const
{
    return this->title;
}

void Windows :: set_title(std:: string title)
{
    if (title.length() > 20)
        throw new std::invalid_argument("Le caractere max est 20.");
    this->title = title;
}