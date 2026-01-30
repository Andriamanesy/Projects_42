#include "Personnage.hpp"

int main()
{
    Personnage david, goliath("épee double tranchant", 0);
    //Création de 2 objets de type Personnage : david et goliath
    goliath.attaquer(david);    //goliath attaque david
    david.boire_portion_vie(20); //david récupère 20 de vie en buvant une potion
    goliath.attaquer(david);    //goliath attaque david
    david.attaquer(goliath);    //david contre-attaque... c'est assez clair non ?
    goliath.changer_arme("Double hache tranchante veneneuse de la mort", 40);
    goliath.attaquer(david);
    return 0;
}