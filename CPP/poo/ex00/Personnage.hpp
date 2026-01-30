#ifndef PERSO_H
#define PERSO_H
#include <string>
#include <iostream>

class Personnage
{
    private :
    int m_vie;
    int m_mana;
    std :: string m_nomArme;
    int m_degatsArme;

    public :
    Personnage();
    Personnage(std :: string nom_arme, int degat_arme);
    void recevoirDegats(int vie);
    void attaquer (Personnage &cible);
    void boire_portion_vie(int vie);
    void changer_arme(std :: string ancien_arme, int degatsNouvelleArme);
    bool est_vivant(int &vie);
};

#endif