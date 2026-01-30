#include <iostream>
#include <vector>

void trierTableau(std :: vector<int> &v)
{
    size_t i = 0;
    size_t j = 0;
    size_t tmp = 0;
    while (i < v.size())
    {
        j = 0;
        while (j < v.size())
        {
            if (v[i] < v[j])
            {
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

int main(void)
{
    std :: vector <int> v = {-40, 8, 100, 1, 5};
    trierTableau(v);
    for (int i = 0; i < v.size(); i++)
        std :: cout << v[i] << ", ";
    std :: cout << std :: endl;
}



