#include "Windows.hpp"
#include <iostream>

/*
Windows :: Windows()
{
    std :: cout << "Constructeur par defaut créer" << this << std :: endl;
}*/

Windows :: Windows(std :: string t, int w = 8, int h= 79) noexcept : title(t), width(w), height(h)
{
    std :: cout << "Le titre est: " << t << " " << this <<std :: endl;
}

Windows :: ~Windows()
{
        std :: cout << "Destructeur ...." << this << std :: endl;
}

void Windows :: run() const noexcept
{
    std :: cout << "Affichage ........" << std :: endl;
}
