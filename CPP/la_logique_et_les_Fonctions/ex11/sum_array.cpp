#include <iostream>
#include <vector>

void    sum_array(const std :: vector<int> &v)
{
    int sum = 0;

    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    std :: cout << "La somme est: " << sum << std :: endl;
}

int     main()
{
    std :: vector <int> v = {2, 4, 5, 6};
    sum_array(v);
}
