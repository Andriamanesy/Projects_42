#include "Personnage.hpp"

void Personnage :: recevoirDegats(int nbr_degat)
{
    m_vie -= nbr_degat;
    if (m_vie <= 0)
        m_vie = 0;

}

void Personnage :: attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_degatsArme);
}

void Personnage :: boire_portion_vie(int quantite_portion)
{
    m_vie += quantite_portion;
    if (m_vie >= 100)
        m_vie = 100;
}

void Personnage :: changer_arme(std :: string nom_nouvelle_arme, int degatsNouvelleArme)
{
    m_nomArme =  nom_nouvelle_arme;
    m_degatsArme = degatsNouvelleArme;
}

bool Personnage :: est_vivant(int &vie)
{
    return m_vie > 0;
}
/*
Personnage :: Personnage()
{
    m_vie = 100;
    m_mana = 100;
    m_nomArme = "épée rouillée";
    m_degatsArme = 10;
}
La meme chose que le constructeur ci-dessous
*/

Personnage :: Personnage() : m_vie(100), m_mana(100), m_nomArme("épee rouillée"), m_degatsArme(10)
{
}

Personnage :: Personnage(std :: string nom_arme, int degat_arme):  m_vie(100), m_mana(100), m_nomArme(nom_arme), m_degatsArme(degat_arme)
{
}







