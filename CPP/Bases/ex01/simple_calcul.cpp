#include <iostream>

int main(void)
{
	int nbr_1;
	int nbr_2;
	
	std :: cout << "Entrez le premier nombre : ";
	std :: cin >> nbr_1;
	std :: cout << "Entrez le deuxieme nombre : ";
	std :: cin >> nbr_2;
	std :: cout << "La somme du nbr_1 et nbr_2 est " << nbr_1 + nbr_2 << std :: endl;
	std :: cout << "Le produit du nbr_1 et nbr_2 est " << nbr_1 * nbr_2 << std :: endl;
	std :: cout << "La difference du nbr_1 et nbr_2 est " << nbr_1 - nbr_2 << std :: endl;
	if (nbr_1 != 0)
		std :: cout << "Le quotient  du nbr_1 et nbr_2 est " << (float)nbr_1 / (float)nbr_2 << std :: endl;
	else
		std :: cout << "Le nbr_1 doit etre different de 0" << std :: endl;

}
