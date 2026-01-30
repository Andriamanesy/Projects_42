#include <iostream>
#include <vector>
#include <iomanip>

bool find_max_min(const std:: vector<int> &v, int &min, int &max)
{
    if (v.empty())
        return false;
    int maxi = v[0];
    int mini = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < mini)
            mini = v[i];
        if (v[i] > max)
            maxi = v[i];
    }
    max = maxi;
    min = mini;
    return true;
}

int main(void)
{
    std :: vector<int> v;// = {0, -3, 30, -100};
    int max = 0;
    int min = 0;

    find_max_min(v, min, max);
    std :: cout << "Max est: " << max << ", Min est: " << min << std :: endl;

}




