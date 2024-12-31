/************************************/
/*	Version SDD cours 				*/
/************************************/

#ifndef __FILE_H__
#define __FILE_H__
#define TAILLE_MAX 100
#include "commun.h" 

typedef struct{
	int nbElt;
	int taille;
	int indice_debut;
	int indice_fin;
	T *tab;

}File_t;

File_t InitFile(int taille);
void AfficherFile(File_t F);
int EstVideFile(File_t F);
int EstPleineFile(File_t F);
int NombreElementFile(File_t F);
T Defiler(File_t *F);
int Enfiler(File_t *F, T elt);
void DetailsFile(File_t F);

#endif