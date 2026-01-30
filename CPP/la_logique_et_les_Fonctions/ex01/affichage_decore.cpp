#include <iostream>
using namespace std;

void afficherTitre(string titre)
{
	int i = titre.size()/2;
	int j = 0;
	int tmp = 0;

	while (j <= i)
	{
		if (tmp == i)
		{
			j = 0;
			while(j < titre.size())
			{
				cout << titre[j] ;
				j++;
			}
			j = 0;
		}
		if (j < i)
			cout << "*";
		tmp++;
		j++;
	}
	cout << endl;
}

int main(void)
{
	afficherTitre("Brian");
}
