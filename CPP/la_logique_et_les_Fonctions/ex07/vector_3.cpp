#include <iostream>
#include <vector>

std :: vector<int> filtrage(const std::vector<int> &v)
{
    std :: vector <int>vec;
    vec.reserve(v.size());
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
        {
            vec.push_back(v[i]);
        }
    }
    return vec;
}

int     main()
{
    std::vector<int> v = {1, 2, 30, -5};
    std::vector<int> v_2 = filtrage(v);
    for (size_t i = 0; i < v_2.size(); i++)
    {
        std :: cout << v_2[i] << ", ";
    }
    std :: cout << std :: endl;
    return 0;
}
