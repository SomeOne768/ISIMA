/* -------------------------------------------------------------------- */
/* Nom du fichier: listecontigue.c                                      */
/* Definition de fonction permettant la gestion d'une liste_contigue_t  */
/* qui est un type définie dans listecontigue.h                         */
/* -------------------------------------------------------------------- */

#include <stdio.h>
#include "structure.h"
#include "listecontigue.h"
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------------- */
/* CreerListeContigue  Creer et initialiser une liste contigue          */
/*                                                                      */
/* en entrée: rien                                                      */
/*                                                                      */
/* sortie: L, une liste_contigue_t qui sera initialisé avec ses champs  */
/* à NULL                                                               */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Creer une variable de type liste_contigue_t, initialiser ses champs  */
/* à NULL puis la retourner                                             */
/* -------------------------------------------------------------------- */
liste_contigue_t CreerListeContigue()
{
    liste_contigue_t L;
    L.tete = NULL;
    //Au debut, le pointeur est mis à null car la liste est vide
    L.fin = NULL;
    return L;
}

/* -------------------------------------------------------------------- */
/* EstVideListeContigue  Indiquer si une liste_contigue_t est pleine    */
/*                                                                      */
/* en entrée: L, uneliste_contigue_t                                    */
/*                                                                      */
/* sortie:un int qui vaut 1 si la liste est vide 0 sinon                */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Récupérer une liste_contigue_t en entrée. Si son champ fin est à     */
/* NULL alors elle est vide. On retourne donc un entier qui vaut 1 si   */
/* le champ fin est à NULL 0 sinon                                      */
/* -------------------------------------------------------------------- */

int EstVideListeContigue(liste_contigue_t L)
{
    return L.fin == NULL;
}


/* -------------------------------------------------------------------- */
/* EstPleineListeContigue  Indiquer si une liste est pleine             */
/*                                                                      */
/* en entrée: L, une liste_contigue_t                                   */
/*                                                                      */
/* sortie: pleine, un int utilisé comme valeur booléenne indiquant si   */
/* la liste est pleine. Vaut 1 si la liste est pleine 0 sinon           */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupère une liste_contigue_t en entrée. Une liste est pleine     */
/* s'il ne reste pas assez de place pour insérer un nouvelle element    */
/* (Il peut y avoir encore de l'espace libre mais pas suffisament pour  */
/* que cela permette une insertion). A l'aide des CONSTANTE définissant */
/* la taille d'un mot ainsi que la taille de notre liste_contigue_t     */
/* il nous reste assez de place si l'adresse fin +k fait partie de la   */
/* liste_contigue_t (est inférieur à l'adresse tete + TAILLE_MAX)       */
/* On retourne donc 1 si l'adresse fin+K>= à l'adresse tete+TAILLE_MAX  */
/* 0 sinon                                                              */
/* -------------------------------------------------------------------- */
int EstPleineListeContigue(liste_contigue_t L)
{
    int pleine = 0;

    if(!EstVideListeContigue(L))
        pleine = (L.fin+K)>=(L.tete+TAILLE_MAX);

    return pleine;
}


/* -------------------------------------------------------------------- */
/* InsererDansListeContigue  Inserer dans une liste contigue            */
/*                                                                      */
/* en entrée: -L, un pointeur sur une liste_contigue_t                  */
/* -element une chaine de caractere à ajouter dans la liste contigue    */
/*                                                                      */
/* sortie: code_retour, un int indiquant si l'insertion a reussi.       */
/* Vaut 1 si l'insertion à réussi 0 sinon                               */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupere l'adresse d'une liste_contigue_t ainsi qu'une chaine de  */
/* caractère représentant le nouvel élément à insérer                   */
/* Si la liste est vide, on attribue de l'espace mémoire pour créer     */
/* notre liste_contigue_t et on insère en tête si l'allocation à réussi */
/* Sinon, si la liste n'est pas pleine on ajoute en fin à l'aide du     */
/* pointeur de fin.                                                     */
/* la fonction retourne 0 si l'insertion à échoué 1 sinon               */
/* -------------------------------------------------------------------- */
int InsererDansListeContigue(liste_contigue_t *L, char *element)
{
    int code_retour = 0;

    if(EstVideListeContigue(*L))
    {
        L->tete = (char*)malloc(sizeof(char) * TAILLE_MAX);
        if(L->tete)
        {
            //Allocation réussie
            L->fin = L->tete;
            strcpy(L->fin, element);
            L->fin += K;
            code_retour = 1;
        }

    }
    else
    {
        if(!EstPleineListeContigue(*L))
        {
            code_retour = 1;
            strcpy(L->fin, element);
            L->fin += K;
        }

    }

    
    return code_retour;
}


/* -------------------------------------------------------------------- */
/* EstPresentMotif  Indiquer si un motif est present dans le nom        */
/* d'une action                                                         */
/*                                                                      */
/* en entrée: name, motif, deux chaines de caractères représentant      */
/* respectivement le nom d'une action et le motif recherché             */
/*                                                                      */
/* sortie: est_present, int indiquant qui vaut 1 si le motif est dans   */
/* le nom 0 sinon                                                       */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupere deux chaines de caractères en entrée                     */
/* On regarde ensuite si la première contient la deuxième. Si oui on    */
/* retourne 1 sinon 0                                                   */
/* -------------------------------------------------------------------- */
int EstPresentMotif(char *name, char *motif)
{
    int est_present = 0,
        continuer = 1,
        i=0,
        j=0;

    while(name[i] !='\0' && continuer)
    {
        j = 0;
        while( (motif[j] != '\0') && (name[i+j] != '\0') && (name[i+j] == motif[j]) )
        {
            j++;
        }

        if(motif[j] == '\0')
        {
            //On a trouvé le motif
            continuer = 0;
            est_present = 1;
        }
        else
        {
            //sinon on continuer à chercher le motif dans le reste du nom
            i++;
        }
    }

    return est_present;

}


/* -------------------------------------------------------------------- */
/* RecupererMotif  Recuperer, dans une liste_contigue_t, les dates de   */
/* de toutes les actions comprenant un motif                            */
/*                                                                      */
/* en entrée: filename, motif, deux chaines de caractères représentant  */
/* respectivement le nom du fichier à ouvrir et le motif rechercher     */
/*                                                                      */
/* sortie: L, une liste_contigue_t contenant toutes les actions du      */
/* fichier comprenant ce motif                                          */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupère deux chaines de caractères en entrée. Une correspondant  */
/* à un nom de fichier l'autre à un motif à rechercher dans les actions */
/* de ce fichier.                                                       */
/* On commence par créer une liste_contigue_t et ouvrir le fichier      */
/* Si l'ouverture réussi, on parcourt chaque ligne du fichier qui       */
/* correspondent chacune à une action et on vérifie si le motif est     */
/* présent dans celle-ci. Si le motif est présent on l'insere dans notre*/
/* liste_contigue_t. La fonction retourne ensuite la liste_contigue_t   */
/* contenant toutes les dates où ce motif est présent                   */
/* -------------------------------------------------------------------- */
//fonction qui retourne la liste des dates où un motif est présent dans un fichier

liste_contigue_t RecupererMotif(char *filename, char *motif)
{
    //Le motif rechercher est une chaine de charactere qui recherche un nom d'action et non une date
    liste_contigue_t   L = CreerListeContigue();
    FILE             * f = fopen(filename, "r");

    if(f)
    {
        //On parcourt le fichier et sur chaque ligne on verifie si le motif est présent
        //Le motif devant être chercher dans le nom d'une action, une ligne représentant une action
        char ligne[TAILLE_LIGNE_MAX];
        char annee_semaine[7];
        char jour_heure[4];
        char nom[11];
        int  continuer = 1;

        while(!feof(f) && continuer)
        {
            fgets(ligne, TAILLE_LIGNE_MAX, f);

            //Le nom se situant en fin de ligne après l'année, semaine, jour, heure
            //On commence donc à chercher au 4+2+1+2 +1= 10 eme char donc dans la case d'indice 9
            RecupererElement(ligne, annee_semaine, jour_heure, nom);
            if(EstPresentMotif(nom, motif))
            {
                //On ajoute la date de notre motif
                char tmp[10];
                strcpy(tmp, annee_semaine);
                strcat(tmp, jour_heure);

                int code_retour = InsererDansListeContigue(&L, tmp);
                if(!code_retour)
                {
                    fprintf(stdout, "Erreur insertion dans la liste contigue\n");
                    continuer = 0;
                }
            }
        }

        fclose(f);
        f = NULL;
    }

    return L;
}


liste_contigue_t RecupererMotifDepuisAgenda(agenda_t agenda, char * motif)
{
    liste_contigue_t   L = CreerListeContigue();
    semaine_t        * parcourir_semaine = agenda.debut;
    action_t         * parcourir_action;
    char               Ligne[TAILLE_LIGNE_MAX];
    while(parcourir_semaine)
    {
        parcourir_action = parcourir_semaine->debut;
        while (parcourir_action)
        {
            if(EstPresentMotif(parcourir_action->nom, motif))
            {
                strcpy(Ligne, parcourir_semaine->annee_semaine);
                strcat(Ligne, parcourir_action->jour_heure);
                InsererDansListeContigue(&L, Ligne);
            }
            parcourir_action = parcourir_action->suiv;
            
        }
        
        parcourir_semaine = parcourir_semaine->suiv;
    }

    return L;
}


/* -------------------------------------------------------------------- */
/* AfficherListeContigue  Affichage d'une liste_contigue_t              */
/*                                                                      */
/* en entrée: L, une liste_contigue_t                                   */
/*                                                                      */
/* sortie: rien                                                         */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupère une liste_contigue_t en entrée. Chaque mot étant codé sur*/
/* k cases, si la liste n'est pas vide, on affiche successivement k     */
/* cases jusqu'à avoir atteint la fin de la liste représentée par le    */
/* champ fin                                                            */
/* -------------------------------------------------------------------- */
void AfficherListeContigue(liste_contigue_t L)
{
    //Cette fonction est utilisé seulement lorsque que l'on souhaite afficher les
    //date où un motif est présent

    if(!EstVideListeContigue(L))
    {
        //Il y a au moins une date
        printf("voci les dates où apparait le motif:\n");

        char * parcourir = L.tete;
        int    i = 1;

        while(parcourir < L.fin)
        {
            printf("date n°%d: ", i);

            int j = 0;

            //Si parcourir < L.fin alors forcément on a au moins une date sur K mot
            while(j<K)
            {
                printf("%c", *parcourir);
                j++;
                parcourir += 1;
            }
            printf("\n");
            i++;
        }
    }
    else
    {
        printf("Le motif n'est pas présent dans voter agenda.\n");
    }

}



/* -------------------------------------------------------------------- */
/* LibererListeContigue  Libérer l'espace mémoire d'une liste_contigue_t*/
/*                                                                      */
/* en entrée: L, un pointeur de type liste_contigue_t                   */
/*                                                                      */
/* sortie: rien                                                         */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupère l'adresse d'une liste_contigue_t. Si elle n'est pas vide */
/* on libère la mémoire de cette liste puis on remet les champs à NULL  */
/* -------------------------------------------------------------------- */
void LibererListeContigue(liste_contigue_t *L)
{
    if(!EstVideListeContigue(*L))
    {
        free(L->tete);
        L->tete = NULL;
        L->fin = NULL;
    }
}