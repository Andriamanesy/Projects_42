#include <iostream>
#include <vector>

int recherche(const std :: vector <int> &v, int nbr)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == nbr)
            return i;
    }
    return -1;
}

int main()
{
    std :: vector <int> v = {0, 4, -5, 9, 5};
    std :: cout << "l'indice est: "<< recherche(v, -5) << std :: endl;
}
