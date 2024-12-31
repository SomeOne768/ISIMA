/*	Ce fichier a été modifié pour pouvoir utiliser la pile et la file
	Càd, il faut décommenter la definition du type noeud pour l'utiliser séparément
*/

#ifndef __ARBRE_H_
#define __ARBRE_H_
#include "commun.h"
#include "File.h"
#include "Pile.h"

//typedef int T2;

/*
typedef struct Noeud{

	T2 valeur;
	struct Noeud *filsG;
	struct Noeud *filsD;
}Noeud;
*/


typedef struct{
	Noeud *t;//Racine de notre arbre
}Arbre;

Arbre CreerArbre();
Noeud* CreerNoeud(T2 val);
void AfficherNoeud(Noeud N);
int estVideArbre(Arbre A);
void InsererNoeud(Arbre *A, T2 val);
Arbre LectureFichier(char* filename);
void AffichageLargeur(Arbre A);
void infixe(Noeud *N);
void infixeIter(Arbre A);

#endif