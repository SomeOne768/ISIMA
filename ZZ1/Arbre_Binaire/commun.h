//Ce fichier a été modifié pour pouvoir utilisé des types Noeud
// Le type générique est donc désormais un Noeud

#ifndef COMMUN_H
#define COMMUN_H

//Taille maximal du tableau utilisé pour simuler la file et la pile
#define TAILLE_MAX 100



typedef int T2;

//Propre à l'utilisation d'un arbre
typedef struct Noeud{

	T2 valeur;
	struct Noeud *filsG;
	struct Noeud *filsD;
}Noeud;

//Element générique
typedef Noeud* type_generique;
typedef type_generique T;

void AfficherElement(T elt);
T ElementNeutreT();
#endif