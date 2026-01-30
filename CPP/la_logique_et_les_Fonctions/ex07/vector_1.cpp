#include <iostream>
#include <vector>

void somme_moyenne(const std:: vector <int>v)
{
    int somme = 0;
    float moyenne = 0;

    for (size_t i = 0; i < v.size(); i++)
    {
        std :: cout << v[i] << ", ";
        somme += v[i];
    }
    moyenne = (float)somme / v.size();
    std :: cout << "\nLe moyenne est: " << moyenne << std :: endl;
    std :: cout << "La somme est: " << somme << std :: endl;
}

int main(void)
{
    std :: vector <int>v = {2, 8, -6, 10, -11};
    somme_moyenne(v);
    return 0;
}




