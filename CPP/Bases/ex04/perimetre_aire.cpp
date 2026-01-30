#include <iostream>

int 	main()
{
	float rayon;

	std :: cout << "Entrez le rayon du cercle: ";
	std :: cin >> rayon;
	std :: cout << "Le perimetre de ton cercle est " << (2*rayon) * 3.14 <<". Et le aire de ton cercle est: " << 3.14*rayon*rayon << std :: endl;
}
