#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string chaine;
	int i, j, bol;

	i = 0;
	bol = 1;
	cout << "Entrez un mot: ";
	cin >> chaine;
	j = chaine.size() - 1;
	
	while (i <= j)
	{
		if(chaine[i] != chaine[j])
			bol = 0;
		i++;
		j--;
	}
	if (bol == 1)
		cout << "Le mot est palindrome" << endl;
	else
		cout << "Le mot n'est pas palindrome" << endl;

}
