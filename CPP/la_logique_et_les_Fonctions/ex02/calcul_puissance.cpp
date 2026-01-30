 #include <iostream>
using namespace std;

long puissance(int base, int exp)
{
	long result = 1;

	for (int i = 1; i <= exp; i++)
	{
		result *= base;
	}
	return result;
}
int main(void)
{
	int i, j;
	cout << "Entrez la base de puissance: ";
	cin >> i;
	cout << "Entrez l'expo de la puissance: ";
	cin >> j;
	cout << i << " puissance de " << j << " est: " << puissance(i, j) << endl;
	return (0);
}
