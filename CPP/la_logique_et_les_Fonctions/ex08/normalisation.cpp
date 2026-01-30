#include <iostream>
#include <string>

void normalisation(std :: string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
}

int main ()
{
    std :: string name = "Andriamanesy";
    normalisation(name);
    for(int i = 0; i <name.size(); i++)
        std :: cout << name[i];
    std :: cout << std :: endl;
}
