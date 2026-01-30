#include <iostream>

int main(void)
{
	int i;
	int somme;
	int tmp;

	somme = 0;
	std :: cout << "Combien de nombre vous voulez faire la somme: ";
	std :: cin >> i;
	while (i > 0)
	{
		std :: cout << "Entrez un nombre: ";
		std :: cin >> tmp;
		somme += tmp;
		i--;
	}
	std :: cout << "La somme de tout les nombre sont: " << somme << std :: endl;
}
