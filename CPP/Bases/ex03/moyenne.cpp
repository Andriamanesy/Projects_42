#include <iostream>

int main(void)
{
	int a, b, c;

	std :: cout << "Entrez note de EPS: ";
	std :: cin >> a;
	std :: cout << "Entrez note de Math: ";
	std :: cin >> b;
	std :: cout << "Entrez note de chimie: ";
	std :: cin >> c;
	std :: cout << "Votre moyenne est " << (float)((a + b + c) / 3) << std :: endl;
}
