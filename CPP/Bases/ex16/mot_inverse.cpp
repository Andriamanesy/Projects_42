#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string chaine;

	cout << "Entrez une phrase: ";
	getline(cin, chaine);
	for (int i = (chaine.size() - 1); i >= 0; i--)
		cout << chaine[i];
	cout << endl;
}
