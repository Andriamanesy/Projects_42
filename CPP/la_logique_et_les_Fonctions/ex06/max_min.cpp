#include <iostream>
#include <vector>

void    max_min(const std::vector<int> &v, int &max, int &min)
{
    int mini = v[0];
    int maxi = v[0];

    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] <= mini)
            mini = v[i];
        if (v[i] >= maxi)
            maxi = v[i];
    }
    max = maxi;
    min = mini;
}

int main(void)
{
    std::vector<int> v = {2, 20, 40, 0, -2};
    int max, min;
    max_min(v, max, min);
    std :: cout << "max: " << max << "  min: " << min << std :: endl;
    return 0;
}








