#include <iostream>

int main()
{
	int i;
	int factorielle;
	int tmp;

	factorielle = 1;
	std :: cout << "Entrer un nombre: ";
	std :: cin >> i;
	tmp = i;
	while (i > 1)
	{
		factorielle *= i;
		i--;
	}
	std :: cout << "Le factielle" << i << " est " << factorielle << std :: endl;
}
