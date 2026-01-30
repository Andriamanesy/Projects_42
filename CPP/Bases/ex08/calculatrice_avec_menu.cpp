#include <iostream>

int main()
{
	int a, b, menu;

	std :: cout << "Entrez le premier nombre: ";
	std :: cin >> a;
	std :: cout << "Entrez le deuxieme nombre: ";
	std :: cin >> b;
	std :: cout << "Choisissez 1. Addition, 2. Soustraction, 3. Multiplication, 4.division: ";
	std :: cin >> menu;

	switch(menu){
		case 1:
			std :: cout << "L'addition est : " << a+b << std :: endl;
			break;
		case 2:
			std :: cout << "La soustraction est : " << a-b << std :: endl;
			break;
		case 3:
			std :: cout << "La Multiplication est : " << a*b << std :: endl;
			break;
		case 4:
			if (a != 0)
				std :: cout << "La division est : " << (float)(a/b) << std :: endl;
			else 
				std :: cout << "Le premier nobre doit different de 0" << std :: endl;
			break;
	}
}
