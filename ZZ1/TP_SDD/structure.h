/* -------------------------------------------------------------------- */
/* Nom du fichier: structure.h                                          */
/* Definition de:                                                       */
/*  -type agenda_t                                                      */
/*  -type semaine_t                                                     */
/*  -type action_t                                                      */
/*  -fonction de gestion pour la liste d'action                         */
/*  -fonction de gestion pour la liste de semaine avec son pointeur de  */
/*  tete de type agenda_t représentant notre agenda                     */
/*  -La taille maximale d'un nom (comprenant le caractère fin de chaine */
/*  -La taille macimale d'une ligne d'un fichier                        */
/* -------------------------------------------------------------------- */

#ifndef structure_h
#define structure_h 

/* -------------------------------------------------------------------- */
/*  Dans une ligne il y a:                                              */
/*      -4 cases pour année                                             */
/*      -2 cases pour semaine                                           */
/*      -1 case pour jour                                               */
/*      -2 cases pour heure                                             */
/*      -10 cases max pour le nom                                       */
/*      -On ajoute 1 case pour '\0' et 1 pour retour ligne \n           */
/*  Total: 22                                                           */
/*  Le fichier ne peut pas contenir d'erreur                            */
/* -------------------------------------------------------------------- */
#define TAILLE_LIGNE_MAX 22
#define TAILLE_NOM 11


/******************************************************************************/
typedef struct action{
    //Un jour nécéssite 1 caractère tandis qu'un horaire 2, 
    //on sauvegarde donc les 2 ensembles pour gagner un octet en évitant de répéter le '\0'
    char jour_heure[4];

    //Nom de l'action, taille du nom 10 max + 1 pour '\0'
    char nom[11]; 

    //Pointeur vers l'action suivante   
    struct action *suiv;
}action_t;




typedef struct semaine{
    //Pour les memes raisons que précédemment, on code l'année et la semaine dans
    //Le meme champ afin d'économiser de la mémoire
    char annee_semaine[7];
    
    //Pointeur vers la liste des actions de la semaine
    action_t *debut; 

    //Pointeur vers la semaine suivante
    struct semaine *suiv;
}semaine_t;

typedef struct {
    semaine_t *debut;
    //debut représente la tete fictive de notre agenda (liste de semaine)
}agenda_t;

/******************************************************************************/



//Initialisation de nos types
action_t* CreerAction(char *jour_heure, char *nom);
agenda_t CreerAgenda();
semaine_t* CreerSemaine(char *annee_semaine);

//Affichage de nos types
void AfficherAction(action_t action);
void AfficherListeAction(action_t *tete);
void AfficherAgenda(agenda_t agenda);

//Fonction utilitaire
void RecupererElement(char *ligne, char *annee_semaine, char *jour_heure, char *nom);
int InsererDansListeAction(action_t **debut, action_t *element);
semaine_t* RechercheSemaine(agenda_t *agenda, char *annee_semaine);
int InsererAction(agenda_t *agenda, action_t *element, char *annee_semaine);

//Fonction des exercices
agenda_t LectureFichier(char *filename);
int EcritureFichier(char *filename, agenda_t agenda);

//Fonction de libération mémoire
void LibererListeAction(semaine_t *s);
void LibererAgenda(agenda_t *agenda);
void SupprimerAction(agenda_t *agenda, char *annee, char *semaine, char *jour, char *heure);

#endif





















