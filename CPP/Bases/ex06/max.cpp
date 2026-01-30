#include <iostream>

int main()
{
	int max, tmp;

	max = 0;
	std :: cout << "Entrez un nombre_1 : ";
	std :: cin >> tmp;
	if (max < tmp)
		max = tmp;
	std :: cout << "Entrez un nombre_2 : ";
	std :: cin >> tmp;
	if (max < tmp)
		max = tmp;
	std :: cout << "Entrez un nombre_3 : ";
	std :: cin >> tmp;
	if (max < tmp)
		max = tmp;
	std :: cout << "Le max est " << max << std :: endl;

}
