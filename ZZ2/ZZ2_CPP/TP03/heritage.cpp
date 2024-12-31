#include <iostream>
#include "Mere.hpp"
#include "Fille.hpp"

/*
 * A ne pas oublier:
 * Lorsque l'on fait de l'heritage et que l'on veut rendre possible
 * la redefinition de fonction, il faut utiliser le virtual qui 'autorise'
 * la modification. De plus, virtual associé à un '=0' en fin permet de
 * définir la méthode comme étant abstraite. ce qui forcera les classes filles
 * à definir le comportement (mis à part si re classe abstraite)
 */

int main(int, char **)
{

    Mere m{};

    Fille f{};

    printf("%d\n", Mere::getCompteur());
    printf("%d\n", m.getCompteur());
    printf("%d\n", f.getCompteur());
    m.afficher();
    f.afficher();

    return 0;
}