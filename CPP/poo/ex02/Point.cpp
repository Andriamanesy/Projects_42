#include "Point.hpp"

Point :: Point()
{
    std :: cout << "Creation de l'objet point." << this << std :: endl;
}
Point :: Point(const Point& p)
{
    std :: cout << "Constructeur par copie" << this << std:: endl;
}


Point :: ~Point()
{
    std :: cout << "Destruction de l'objet point." << this <<  std :: endl;
}