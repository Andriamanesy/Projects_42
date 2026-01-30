#include <iostream>

int	main(void)
{
	int n;
	int i = 0;

	std :: cout << "Entrez un nombre a multiplier: ";
	std :: cin >> n;
	while (i <= 10)
	{
		std :: cout << n << " * " << i << " = " << n*i << std :: endl;
		i++;
	}
	return (0);
}
