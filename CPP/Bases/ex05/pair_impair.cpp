#include <iostream>

int main()
{
	int nbr;

	std :: cout << "Entrez un nombre: ";
	std :: cin >> nbr;
	if (nbr < 0)
		std :: cout << "N" << std :: endl;
	else 
		std :: cout << "P" << std :: endl;
}
