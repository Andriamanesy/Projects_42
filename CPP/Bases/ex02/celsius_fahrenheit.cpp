#include <iostream>

int main(void)
{
	int temperature;

	std :: cout << "Entrez la temperature en Celsius: ";
	std :: cin >> temperature;
	std :: cout << "La temperature en Fahrenheit est : " << ((float)temperature * 1.8) + 32 << std :: endl;
}
