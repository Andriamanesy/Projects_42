#include <iostream>

int factorielle(int nbr)
{
    if (nbr <= 1)
        return 1;
    else
        return (nbr * factorielle(nbr - 1));
}

int     main(void)
{
    std :: cout << factorielle(5) << std :: endl;
    return (0);
}
