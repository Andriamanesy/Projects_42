#include <iostream>
using namespace std;

void    conversion_heure(int seconde_totale, int& heure, int& minute, int& seconde)
{
    heure = seconde_totale/3600;
    minute = (seconde_totale%3600) / 60;
    seconde = seconde_totale%60;    
}

int main(void)
{
    int total;
    cout << "Entrez les seconde à convertir: ";
    cin >> total;
    int h, m, s;
    conversion_heure(total, h, m, s);

    cout << h << "H : " << m << "M " << s << "S" << endl;
    return (0);
}
