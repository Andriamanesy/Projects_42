#include "Point.hpp"
/*
    struct : données publiques (par defaut)
    class : données privées (par défaut)

    Niveau d'accès : Public, private, protected
*/
/*
typedef struct Point
{
    int x;
    int y;
} t_point;
*/

int main()
{
    Point p {};
    Point p1{p};
}