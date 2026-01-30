#include <iostream>
using namespace std;

double cube(double n)
{
	return (n * n * n);
}

int main(void)
{
	double n;

	cout << "Entrez un nombre: " ;
	cin >> n;
	cout << "Le cube de ce nombre est " << cube(n) << endl;
	return (0);
}
