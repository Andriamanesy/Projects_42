#include <iostream>

using namespace std;

typedef struct Produit
{
    string name;
    float price;
    bool available;
} t_produit;


int main()
{
    t_produit p{"Papier toilette", 1.29, true} ;

    cout << "Prix: "<<p .price << endl; 
    return 0;
}