#include <iostream>

int fibonacci(int nbr)
{
    if (nbr == 0)
        return 0;
    else if (nbr == 1)
        return 1;
    else
        return (fibonacci(nbr - 1) + fibonacci(nbr - 2));
}

int main()
{
    std :: cout << fibonacci(10) << std :: endl;
}
