#include <iostream>

int calculerAire(float rayon)
{
    return rayon * rayon * 3.14;
}

int calculerAire(int largeur, int hauteur)
{
    return largeur * hauteur;
}

int main(void)
{
    std :: cout << "L'aire de ton cercle est: " << calculerAire(4.5) << std :: endl;
    std :: cout << "L'aire de ton rectangle est: " << calculerAire(50, 100) << std :: endl;
    return (0);
}
