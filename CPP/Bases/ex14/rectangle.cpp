#include <iostream>

int main(void)
{
	int larg, longe;
	int i, j;

	i = 1;
	j = 1;
	std :: cout << "Entrez la largeur de ton rectangle: ";
	std :: cin >> larg;
	std :: cout << "Entrez la longeur de ton rectangle: ";
	std :: cin >> longe;

	while (i <= larg)
	{
		j = 1;
		while (j <= longe)
		{
			if (j == longe)
				std :: cout << "*" << std :: endl;
			else if (j == 1 || i == 1 || i == larg)
				std :: cout << "*";
			else
				std :: cout << " ";
			j++;
		}
		i++;
	}
}
