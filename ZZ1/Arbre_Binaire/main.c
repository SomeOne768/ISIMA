#include <stdio.h>
#include "Arbre.h"

/*	Arbre CreerArbre();
	Noeud* CreerNoeud(T val);
	int estVideArbre(Arbre A);
	void InsererNoeud(Arbre *A, T val);
	Arbre LectureFichier(char* filename);
*/

int main()
{
	
	/*Noeud *N1 = CreerNoeud(5);
	AfficherNoeud(*N1);
	printf("\n");
	Noeud *N2 = CreerNoeud(105);
	AfficherNoeud(*N2);
	printf("\n");
	Noeud *N3 = CreerNoeud(205);
	AfficherNoeud(*N3);
	printf("\n");

	File_t F = InitFile(3);
	Enfiler(&F, N1);
	Enfiler(&F, N2);
	Enfiler(&F, N3);

	AfficherFile(F);
	N1 = Defiler(&F);
	AfficherFile(F);
	N1 = Defiler(&F);
	AfficherFile(F);
	N1 = Defiler(&F);
	AfficherFile(F);
	N1 = Defiler(&F);
	printf("Valeur de N:%p\n", N1);*/


	/*printf("\n\nTest defilage en série\n");
	for(int i=0; i<10; i++)
	{
		printf("************  Dfilage en série numéro: %d************\n", i);
		for(int j=0; j<3; j++)
		{

			N1 = CreerNoeud(j*i+j);
			Enfiler(&F, N1);
		}
		printf("Nmbre:\n");
		AfficherFile(F);
		N1 = Defiler(&F);
		AfficherFile(F);
		N1 = Defiler(&F);
		AfficherFile(F);
		N1 = Defiler(&F);
		AfficherFile(F);
		printf("\n\n");
	}*/

	/*printf("--------------------------\n\n\n");
	F = InitFile(3);
	DetailsFile(F);
	printf("\n\n");
	for(int j=0; j<3; j++)
	{


		N1 = CreerNoeud(j*0+j);
		Enfiler(&F, N1);
		DetailsFile(F);
		printf("\n\n");
	}

	Defiler(&F);
	DetailsFile(F);

	printf("\n\n");
	Defiler(&F);
	DetailsFile(F);

	printf("\n\n");
	Defiler(&F);
	DetailsFile(F);
	*/


	Arbre A = CreerArbre();
	A = LectureFichier("data.txt");
	//AffichageLargeur(A);
	infixe(A.t);
	infixeIter(A);
	
	return 0;
}