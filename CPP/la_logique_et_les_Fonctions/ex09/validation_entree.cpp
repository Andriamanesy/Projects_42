#include <iostream>

void    demanderNote(int &note)
{
    int i = 1;
    while (!(note >= 0 && note <= 20))
    {
        std :: cout << "Entrez votre note de 0 a 20: ";
        std :: cin >> note;
    }
    std :: cout << "Votre note est: " << note;
}

int main()
{
    int note = -1;
    demanderNote(note);
}
