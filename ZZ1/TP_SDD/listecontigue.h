/* -------------------------------------------------------------------- */
/* Nom du fichier: listecontigue.h                                      */
/* Definition de:                                                       */
/*  - Du type listecontigue_h représentant une liste contigue           */
/*  - La taille maximale d'une liste liste_contigue_t                   */
/*  - La taille d'un mot, K                                             */
/*  - Prototype des fonctions du fichier listecontigue.c                */
/* -------------------------------------------------------------------- */

#ifndef listecontigue_h

#define listecontigue_h
#define TAILLE_MAX 101

//Une date étant codé avec des char (1 octet) et necessitant 10 caractère aaaassjhh\0
#define K 10

//But de cette partie:
// 1 - rechercher un motif (dans le nom)
// 2 - conserver dans une liste contigue le jour de cette action
// 3 - Pour conserver: on garde que la date

typedef struct {
    char *tete;
    char *fin;
}liste_contigue_t;


liste_contigue_t CreerListeContigue();
int EstVideListeContigue(liste_contigue_t L);
int EstPleineListeContigue(liste_contigue_t L);
int InsererDansListeContigue(liste_contigue_t *L, char *element);
int EstPresentMotif(char *name, char *motif);
liste_contigue_t RecupererMotif(char *filename, char *motif);
liste_contigue_t RecupererMotifDepuisAgenda(agenda_t agenda, char * motif);

void AfficherListeContigue(liste_contigue_t L);
void LibererListeContigue(liste_contigue_t *L);
#endif