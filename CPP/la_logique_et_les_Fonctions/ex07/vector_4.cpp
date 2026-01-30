#include <iostream>
#include <vector>

void    sup_negatif(std::vector<int>&v)
{
    for (size_t i = 0; i < v.size(); )
    {
        if (v[i] < 0)
            v.erase(v.begin() + i);
        else 
            i++;
    }
}

int main(void)
{
    std :: vector <int> v = {2, 3, -4 , -7};
    sup_negatif(v);
    for (int i = 0; i < v.size(); i++)
        std :: cout << v[i] << ", ";
    std :: cout << std :: endl;
    return 0;
}
