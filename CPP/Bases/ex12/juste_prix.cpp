#include <iostream>

int main()
{
	int nbr;
	int nbr_2;
	int i;

	i = 1;
	nbr_2 = 0;
	std :: cout << "Entrez le nombre secret et ton amie le devine: ";
	std :: cin >> nbr;
	std :: cout << "Diviner le nombre secret: ";
	std :: cin >> nbr_2;
	while (i == 1)
	{
		if (nbr_2 == nbr)
		{
			std :: cout << "Felicitation, tu as trouve le nombre secret." << std :: endl;
			i = 0;
		}
		else if (nbr < nbr_2)
		{
			std :: cout << "Moins." << std :: endl << "Entrez: ";
			std :: cin >> nbr_2;
		}
		else
		{
			std :: cout << "Plus." << std :: endl << "Entrez: ";
			std :: cin >> nbr_2;
		}
	}
}
