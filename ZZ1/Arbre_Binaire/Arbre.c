//Construction d'un arbre binaire de recherche

#include <stdio.h>
#include <stdlib.h>
#include "Arbre.h"



Arbre CreerArbre()
{
	Arbre A;
	A.t = NULL;
	return A;
}


Noeud* CreerNoeud(T2 val)
{
	Noeud *N = (Noeud*)malloc(sizeof(Noeud));
	N->valeur = val;
	N->filsG = NULL;
	N->filsD = NULL;

	return N;
}

int estVideArbre(Arbre A)
{
	return A.t ==NULL;
}

void AfficherNoeud(Noeud N)
{
	printf("%d", N.valeur);
}

void InsererNoeud(Arbre *A, T2 val)
{
	Noeud *N = CreerNoeud(val);
	if(estVideArbre(*A))
		//Insertion directement en racine
		A->t = N;
	else
	{
		//On parcours et on recherche la position
		Noeud *parcourir = A->t;
		int trouve = 0;
		while(!trouve)
		{
			if(parcourir->valeur > N->valeur)
			{
				//Il faut l'insérer dans le sous arbre gauche
				if(parcourir->filsG == NULL)
				{
					//On peut l'inserer
					parcourir->filsG = N;
					trouve = 1;
				}
				else
				{
					parcourir = parcourir->filsG;
				}
			}
			else if(parcourir->valeur < N->valeur)
			{
				//Il faut l'insérer dans le sous arbre droit
				if(parcourir->filsD == NULL)
				{
					//On l'insere en fils droit de ce noeud
					parcourir->filsD = N;
					trouve = 1;
				}
				else
				{
					//On recherche dans le sous arbre droit
					parcourir = parcourir->filsD;
				}
			}
		}
	}
}



void InsererNoeud2(Arbre *A, T2 val)
{
	//On prend l'adresse de la racine
	Noeud **prec = &(A->t);//pointe sur la racine qui peut être NULL
	//adresse du nouveau noeud
	Noeud *N = CreerNoeud(val);//Création du nouveau noued

	while((*prec)!=NULL)
	{		
		if( val > (*prec)->valeur )
		{
			//Il faut l'inserer à droite
			prec = &( (*prec)->filsD );
		}
		else if( val < (*prec)->valeur )
		{
			//Il faut l'inserer à gauche
			prec = &( (*prec)->filsG );
		}
	}

	//Ici le noeud pointé est NULL
	//On a donc l'endroit où insérer
	(*prec) = N;
}


Arbre LectureFichier(char* filename)
{
	Arbre A = CreerArbre();
	FILE *f = fopen(filename, "r");
	if(f)
	{
		//Ouverture de fichier réussi
		fseek(f, 0, SEEK_SET);
		int val;
		while(!feof(f))
		{
			//Tant que ce n'est pas la fin du fichier
			fscanf(f, "%d", &val);//avance dans le flux

			InsererNoeud2(&A, val);
		}
	}

	return A;
}



/*T Defiler(File_t *F);
	int Enfiler(File_t *F, T elt);
*/

void AffichageLargeur(Arbre A)
{

	if(!estVideArbre(A))
	{
		File_t F = InitFile(TAILLE_MAX);

		//On commence par enfiler la racine
		Enfiler(&F, A.t);
		Noeud *N = NULL;


		//Tant que notre file n'est pas vide on recupere la tete et on insere son fils gauche puis droit
		while(!EstVideFile(F))
		{
			N = Defiler(&F);

			//On affiche notre Noeud
			AfficherNoeud(*N);


			//On enfile maintenant ses fils s'il en a

			if(N->filsG)//On a un filsG
				Enfiler(&F, N->filsG);

			if(N->filsD)//On a un filsD
				Enfiler(&F, N->filsD);
			

		}
	}
}



void infixe(Noeud *N)
{
	if(N)
	{
		infixe(N->filsG);
		AfficherNoeud(*N);
		infixe(N->filsD);
	}
}


//En iter:

void infixeIter(Arbre A)
{
	if(!estVideArbre(A))
	{
		printf("\n\ninfixeIter:\n");
		Pile_t P = initPile(TAILLE_MAX);

		//On souhaite afficher tous le sous arbre gauche puis nous même puis tous le sous arbre droit
		//On empile donc dans l'ordre le fils droit puis nous même et on descend dans le sous arbre gauche
		//Quand un noeud n'a plus de fils gauche on l'affiche puis on depile

		//Initialisation

		Noeud *parcourir = A.t;
		int fin = 0;
		while(!fin)
		{
			if(parcourir)
			{
				//On est sur un noeud valide
				//si il a un filsG il faut passer à lui, on empile donc "le contexte"
				//On passe ensuite au fils G
				Empiler(&P, parcourir);
				parcourir = parcourir->filsG;
			}
			else if(!EstVidePile(P))
			{
				//Le pointeur courant est null
				//IL faut donc depiler "l'ancien contexte" et faire la suite de la fonction
				parcourir = Depiler(&P);
				AfficherNoeud(*parcourir);
				//Il ne faut pas oublier de passer au fils droit
				parcourir = parcourir->filsD;
			}
			else
			{
				//Notre noeud est NULL et la pile est vide
				//La fonction est donc terminée
				fin = 1;
			}
		}
		printf("\n");

		//On oublie pas de liberer la Pile

	}
	
}
