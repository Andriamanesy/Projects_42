#include <vector>
#include "Someone.hpp"
#include "English.hpp"
#include "Indonesian.hpp"

int main() {
    // 1. On crée un vecteur de pointeurs vers la classe de base (Someone)
    std::vector<Someone*> groupe;

    // 2. On ajoute des instances des classes dérivées
    groupe.push_back(new English("Brian"));
    groupe.push_back(new Indonesian("Ada"));
    groupe.push_back(new English("John")); // Maintenant John est bien là !

    std::cout << "--- Le groupe s'en va ---" << std::endl;

    // 3. La magie du polymorphisme : 
    // Bien que 'p' soit un pointeur de type Someone*, 
    // C++ appelle la version de 'say_good_bye' de l'objet RÉEL.
    for (Someone* p : groupe) {
        p->say_good_bye(); 
    }

    // 4. Nettoyage de la mémoire (très important avec 'new')
    for (Someone* p : groupe) {
        delete p;
    }

    return 0;
}