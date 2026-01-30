#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string chaine;
	char c;

	cout << "Entrez une phrase: ";
	getline(cin, chaine);
	cout << "Entrez le caractere a remplacer: ";
	cin >> c;
	for (int i = 0; i < chaine.size(); i++)
	{
		if (chaine[i] == c)
			chaine[i] = 'X';
		cout << chaine[i];
	}
	cout << endl;
}
