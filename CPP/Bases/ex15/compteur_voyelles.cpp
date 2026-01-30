#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i;
	int count;

	count = 0;
	std :: string chaine;
	std :: cout << "Entrez une phrase: ";
	getline(cin, chaine);
	i = chaine.size();

	for (int j = 0; j < i; j++)
	{
		if (chaine[j] == 'a' || chaine[j] == 'e' || chaine[j] == 'i' || chaine[j] == 'o' || chaine[j] == 'u' || chaine[j] == 'y')
			count++;
	}

	std :: cout << "Les nombres de voyelles dans ton phrase sont: " << count << std :: endl;
}
