#include <iostream>

int main()
{
	int moyenne;

	std :: cout << "Entrez votre moyenne: ";
	std :: cin >> moyenne;

	if (moyenne < 10)
		std :: cout << "Refuse" << std :: endl;
	else if (moyenne >= 10 && moyenne < 12)
		std :: cout << "Passable" << std :: endl;
	else if (moyenne >= 12 && moyenne < 14)
		std :: cout << "Assez bien" << std :: endl;
	else if (moyenne >= 14 && moyenne < 16)
		std :: cout << "Bien" << std :: endl;
	else 
		std :: cout << "Tres bien" << std :: endl;

}
