#include <iostream>
#include <string>

void affiche(const std :: string &str)
{
    for (int i = 0; i < str.size(); i++)
        std :: cout << str[i];
    std :: cout << std :: endl;
}

int main()
{
    std :: string str = "Bonjour anao !!!! ";
    affiche(str);
}
