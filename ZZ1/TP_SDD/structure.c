/* -------------------------------------------------------------------- */
/* Nom du fichier: structure.c                                          */
/* Definition de fonctions permettant la gestion d'une action, d'une    */
/* liste chainée d'action ainsi que la gestion d'une semaine et d'une   */
/* liste chainée de semaine qui représente un agenda                    */
/* -------------------------------------------------------------------- */


#include "structure.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/* -------------------------------------------------------------------- */
/* CreerAgenda          initialise une structure de type agenda_t       */
/*                                                                      */
/* En entrée: rien                                                      */
/*                                                                      */
/* En sortie: une variable de type agenda_t avec ses champs initialisés */
/* à NULL                                                               */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/*  Créer une variable de type agenda_t et initialiser ses champs à NULL*/
/* puis la retourner                                                    */
/* -------------------------------------------------------------------- */

agenda_t CreerAgenda()
{
    agenda_t agenda;
    agenda.debut = NULL;

    return agenda;
}


/* -------------------------------------------------------------------- */
/* CreerSemaine     initialise un pointeur de structure de type semaine */
/*                                                                      */
/* En entrée: annee_semaine une chaine de caractères contenant l'année  */
/* et la semaine sous le format suivant: aaaass                         */
/*                                                                      */
/* En sortie: s un pointeur de variable de type semaine_t avec          */
/* ses champs debut et suivant initialisés à NULL et contenant l'année  */
/* et la semaine récupéré en entrée                                     */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Créer une variable de type semaine_t, initialiser ses champs à NULL  */
/* et copier la chaine entrée dans le champs annee_semaine de cette     */
/* variable puis la retourner                                           */
/* -------------------------------------------------------------------- */
semaine_t* CreerSemaine(char * annee_semaine)
{
    semaine_t * s = (semaine_t*)malloc(sizeof(semaine_t));
    s->debut = NULL;
    s->suiv = NULL;
    strcpy(s->annee_semaine, annee_semaine);
    return s;
}


/* -------------------------------------------------------------------- */
/* CreerAction      initialise un pointeur de structure de type action_t*/
/*                                                                      */
/* En entrée: jour_heure, nom Deux chaines de caractères. Une contenant */
/* le jour et l'heure sous le format suivant: jhh. Une autre contenant  */
/* le nom de cette action sur 10 caractères maximum                     */
/*                                                                      */
/* En sortie: retour un pointeur de variable de type action_t avec      */
/* ses champs jour_heure et nom initialisés avec les paramètres en entré*/
/* et son champ suivant initialisé à NULL                               */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Créer une variable de type action_t, initialiser son champs suiv à   */
/* NULL puis copier les chaines en entrée pour renseigner cette variable*/
/* pour enfin la retourner                                              */
/* -------------------------------------------------------------------- */
action_t* CreerAction(char *jour_heure, char *nom)
{
    //On suppose que les paramètres sont ok (énoncé)

    //Initialisation
    action_t *retour = (action_t*)malloc(sizeof(action_t) * 1);
    retour -> suiv = NULL;

    //On commence par recuperer l'horaire
    strcpy(retour->jour_heure, jour_heure);

    //Et maintenant le nom
    strcpy(retour->nom, nom);

    return retour;
}



/* -------------------------------------------------------------------- */
/* AfficherAction   Affiche à l'écran une action                        */
/*                                                                      */
/* En entrée: une variable de type action_t                             */
/*                                                                      */
/* En sortie: rien                                                      */
/* -------------------------------------------------------------------- */

/* --------------------   ALGORITHME DE PRINCIPE   -------------------- */
/* Afficher chacun des champs d'une action, récupérer en entrée, dans le*/
/* terminal sous un format compréhensible                               */
/* -------------------------------------------------------------------- */


void AfficherAction(action_t element)
{
    printf("jour: %c heure: %c%c \t nom : %s\n", element.jour_heure[0],
    element.jour_heure[1], element.jour_heure[2], element.nom);
}




/* -------------------------------------------------------------------- */
/* AfficherListeAction      Affiche à l'écran une liste d'action_t      */
/*                                                                      */
/* En entrée: tete un pointeur sur une variable de type action_t        */
/*                                                                      */
/* En sortie: rien                                                      */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Récuperer une tête de liste d'action_t en entrée                     */
/* Parcourir cette liste et pour chaque element de la liste afficher    */
/* l'lément à l'aide de la fonction précédente                          */
/* -------------------------------------------------------------------- */

void AfficherListeAction(action_t *tete)
{
    //Une liste d'action ne peut pas être vide
    //Elle contient au moins 1 élément
    action_t *parcourir = tete;
    while(parcourir)
    {
        AfficherAction(*parcourir);
        parcourir = parcourir->suiv;
    }
}


/* -------------------------------------------------------------------- */
/* AfficherAgenda   Affiche à l'écran un agenda entier. Donc pour chaque*/
/* semaine présente la liste d'action qu'elle contient                  */
/*                                                                      */
/* En entrée: agenda une variable de type agenda_t                      */
/*                                                                      */
/* En sortie: rien                                                      */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Rcupérer un agenda en entrée                                         */
/* Parcourir toutes les semaines de cet agenda et afficher pour chaque  */
/* semaine sa liste d'action                                            */
/* -------------------------------------------------------------------- */

void AfficherAgenda(agenda_t agenda)
{
    semaine_t *parcourir = agenda.debut;

    if(parcourir)
    {
        printf("\nVoici l'agenda\n\n");
        //Nous avons au moins 1 élément
        while(parcourir)
        {
            printf("Affichage de la liste d'action pour");
            printf("l'annee: %c%c%c%c \t semaine: %c%c\n", 
                parcourir->annee_semaine[0], parcourir->annee_semaine[1],
                parcourir->annee_semaine[2], parcourir->annee_semaine[3],
                parcourir->annee_semaine[4], parcourir->annee_semaine[5]);

            AfficherListeAction(parcourir->debut);
            parcourir = parcourir->suiv;
        }
    }
    else
    {
        //L'agenda est vide
        printf("L'agenda est vide.\n");
    }
    printf("\n\n");
}



/* -------------------------------------------------------------------- */
/* RecupererElement Permet de récupérer les différents éléments d'une   */
/* ligne d'un fichier                                                   */
/*                                                                      */
/* En entrée: ligne, une chaine de caractères                           */
/*                                                                      */
/* En entrée/sortie: annee_semaine, jour_heure, nom 3 chaines de char   */
/*                                                                      */
/* En sortie: rien                                                      */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Récupérer une ligne en entrée sous le format suivant: aaaassjhhNom   */
/* Comme la chaine respecte un format précis:                           */
/* Copier les 6 premiers caractères dans la chaine annee_semaine        */
/* Les 3 suivant dans jour_heure et le reste dans nom                   */
/* -------------------------------------------------------------------- */

void RecupererElement(char *ligne, char *annee_semaine, char *jour_heure, char *nom)
{
    int i;

    //On recupere dans l'ordre

    //Récupération de l'année 4 cases et de la semaine 2 cases
    strncpy(annee_semaine, ligne, 6);
    annee_semaine[6] = '\0';

    //Récupération du jour et de l'heure
    for(i=6; i<9; i++)
    {
        jour_heure[i - 6] = ligne[i];
    }
    jour_heure[3] = '\0';

    //Récupération du nom
    i = 9;
    int j = 0;
    while(ligne[i] != '\0' && j<10 && ligne[i] != '\n')
    {
        nom[j] = ligne[i];
        i++;
        j++;
    }
    nom[j] = '\0';
}



/* -------------------------------------------------------------------- */
/* InsererDansListeAction Inserer une action à la bonne position        */ 
/* dans une liste d'action                                              */
/*                                                                      */
/* En entrée: -debut, un double pointeur de type action_t qui représente*/
/* la tête de liste                                                     */
/* -element, un pointeur de type action_t qui represente le nouvel element*/
/* à inserer                                                            */
/*                                                                      */
/* En entrée/sortie: annee_semaine, jour_heure, nom 3 chaines de char   */
/*                                                                      */
/* En sortie: rien                                                      */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* Récupérer en entrée une tete de liste d'action et un element à       */
/* inserer.                                                             */
/* La liste étant trier en fonction du jour et de l'heure, on parcourt  */
/* la liste jusqu'à trouver la bonne position où insérer                */
/* Si la liste est vide, insérer en tete => *debut = element            */
/* Sinon parcourir la liste en gardant le précédent                     */
/* Si à un moment du parcours on trouve que la date est antérieur alors */
/* on insère avant. Si on on parcourt la liste et que l'on a pas pu     */
/* insérer alors il faut ajouter le nouvel élément en fin               */
/* -------------------------------------------------------------------- */
int InsererDansListeAction(action_t **debut, action_t *element)
{
    //Hypothèse: Il ne peut pas y avoir 2 actions différentes avec les mêmes horaires

    int insertion_reussi = 0;

    if(!(*debut))
    {
        //Insertion en tête
        (*debut) = element;
        insertion_reussi = 1;
    }
    else
    {
        if(strcmp((*debut)->jour_heure, element->jour_heure) > 0)
        {
            //On doit inserer l'element avant/tete de liste
            element->suiv = (*debut);
            (*debut) = element;
            insertion_reussi = 1;
        }
        else
        {
            //Il doit être inseré à l'intérieur ou à la fin de la liste on va donc chercher
            //où le positionner

            action_t *parcourir = (*debut);
            int continuer = 1;
            while(parcourir->suiv && continuer)
            {
                if(strcmp(parcourir->suiv->jour_heure, element->jour_heure) > 1)
                {
                    //L'element est à une date antérieur de parcourir->suiv
                    element->suiv = parcourir->suiv;
                    parcourir->suiv = element;
                    continuer = 0;
                    insertion_reussi = 1;
                }else{
                    parcourir = parcourir->suiv;
                }
            }

            if( (parcourir->suiv == NULL) && continuer)
            {
                //Il faut mettre l'element en fin de liste
                parcourir->suiv = element;
                insertion_reussi = 1;
            }

        }

    }

    return insertion_reussi;
}




/* -------------------------------------------------------------------- */
/* RechercheSemaine  rechercher une semaine en fonction de son numéro de*/
/* semaine et de son année.                                             */ 
/*                                                                      */
/* En entrée: -agenda, une variable de type agenta_t                    */
/* -annee_semaine, une chaine de caractere format aaaass                */
/*                                                                      */
/* En sortie: retour, un pointeur de type semaine_t                     */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupere en entrée un agenda et une chaine de caractère qui       */
/* représente une annee et une semaine.                                 */
/* On parcourt notre agenda en regardant pour chaque semaine son annee  */
/* et sa semaine et en la comparant avec la chaine en entrée. Si on en  */
/* trouve une identique on récupère son adresse sinon on en crée une    */
/* au bonne emplacement (l'agenda étant trié). On renvoie ensuite       */
/* l'adresse de cette nouvelle semaine. Dans le cas où une allocation   */
/* aurait échoué, la fonciton peut renvoyer NULL                        */
/* -------------------------------------------------------------------- */


semaine_t* RechercheSemaine(agenda_t *agenda, char *annee_semaine)
{
    //Fonction permettant de rechercher une semaine en fonction de son numéro de semaine et de son année.
    //3 cas: La liste est vide on alloue directement un emplacement pour celle-ci et on l'insere en tête
    //La liste est non vide et la semaine existe on retourne cette cellule
    //La liste est non vide mais la semaine n'existe pas: on l'insere en bonne position

    semaine_t *retour = NULL;
    //cas liste vide:
    if(agenda)
    {
        if(agenda->debut == NULL)
        {
            //Insertion en tête
            agenda->debut = CreerSemaine(annee_semaine);
            retour = agenda->debut;
        }
        else
        {
            //Parcours de la liste pour la recherche
            semaine_t *parcourir = agenda->debut;
            semaine_t *precedent = NULL;
            int trouve = 0;
            while( (parcourir != NULL) && !trouve )
            {
                //On recherche la bonne semaine
                if(!strcmp(parcourir->annee_semaine, annee_semaine))
                {
                    //on a trouvé notre emplacement
                    retour = parcourir;
                    trouve = 1;
                }
                else if(strcmp(parcourir->annee_semaine, annee_semaine)<0)
                {
                    //Il faut l'insérer après parcourir, on continue encore de chercher
                    precedent = parcourir;
                    parcourir = parcourir->suiv;

                }
                else
                {
                    //Il faut l'inserer avant:
                    //2 cas:
                    //precedent == NULL => on l'insere en debut de liste
                    //precedent != NULL on l'insere entre precedent et parcourir
                    retour = CreerSemaine(annee_semaine);
                    retour->suiv = parcourir;
                    if(precedent != NULL)
                    {
                        //ajout à l'intérieur de la liste
                        precedent->suiv = retour;
                    }
                    else
                    {
                        //On l'ajoute en tête
                        agenda->debut = retour;
                    }
                    trouve = 1;
                }
            }

            //On a trouvé l'emplacement:
            //Si trouve = 1 alors retour contient l'adresse où inserer
            //Si trouve = 0 alors il faut l'inserer en fin de liste
            if(!trouve)
            {
                retour = CreerSemaine(annee_semaine);
                precedent->suiv = retour;
            }
        }
    }//agenda étant forcément non null, on ne fait pas l'autre cas

    return retour;

}





/* -------------------------------------------------------------------- */
/* InsererAction  Inserer une action dans un agenda                     */
/* semaine et de son année.                                             */ 
/*                                                                      */
/* En entrée: -agenda, une variable de type agenta_t                    */
/* -annee_semaine, une chaine de caractere format aaaass                */
/* -element, une pointeur de type action_t                              */
/*                                                                      */
/* En sortie: insertion_reussi, un code retour nous permettant de savoir*/
/* si l'insertion à été réussi                                          */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupère un agenda, une action, une annee et semaine en entrée    */
/* Pour pouvoir insérer cette nouvelle action, on commence par          */
/* rechercher une semaine en fonction de son année et de sa semaine à   */
/* l'aide de la fonction RecherSemaine. Ensuite on insere cette nouvelle*/
/* action dans cette semaine à l'aide la fonction InsererDansListeAction*/
/* -------------------------------------------------------------------- */

int InsererAction(agenda_t *agenda, action_t *element, char *annee_semaine)
{
    //On va inserer une action dans une semaine.
    int insertion_reussi = 0;

    //Pour cela on commence par chercher la bonne semaine ou on la crée en bonne position
    semaine_t *semaine_ou_inserer = RechercheSemaine(agenda, annee_semaine);
    if(semaine_ou_inserer)
        insertion_reussi = InsererDansListeAction(&semaine_ou_inserer->debut, element);


    return insertion_reussi;
}






//Recuperation d'une liste à partir d'un fichier

/* -------------------------------------------------------------------- */
/* LectureFicher  Creer un agenda à partir d'un fichier                 */ 
/*                                                                      */
/* En entrée: -filename, une chaine de caractere pour le nom de fichier */
/*                                                                      */
/* En sortie: -agenda, une variable de type agenda_t                    */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupere un nom de fichier en entrée.                             */
/* On crée un nouvel agenda puis on essaie d'ouvrir le fichier          */
/* Si l'on arrive à ouvrir le fichier, on récupère chaque ligne de notre*/
/* fichier une à une. Celles-ci respectent le format: aaaassjhhNOM      */
/* A l'aide de la fonction RécupererElement, on récupère les différents */
/* élément de notre ligne (année, semaine, jour, heure) puis on crée une*/
/* nouvelle action que l'on insere ensuite dans notre agenda            */
/* -------------------------------------------------------------------- */
agenda_t LectureFichier(char *filename)
{
    //On commence par créer notre agenda
    agenda_t agenda = CreerAgenda();
    FILE *f = fopen(filename, "r");
    if(f)
    {
        //Ouverture fichier réussi
        fseek(f, 0, SEEK_SET); //Positionnement en début de fichier

        //Création d'espace mémoire pour les futurs récupérations
        char ligne[TAILLE_LIGNE_MAX];
        char annee_semaine[7];
        char jour_heure[4];
        char nom[TAILLE_NOM];

        //On va desormais récupérer ligne par ligne notre fichier et créer des cellules
        while(!feof(f))
        {
            ligne[0] = '\0';
            //Recuperer une ligne
            fgets(ligne, TAILLE_LIGNE_MAX, f);

            if(ligne[0] != '\n' && ligne[0] != '\0')
            {
                //Gestion cas dernière de fichier ayant un retour ligne
                //Récupération des différents éléments          
                RecupererElement(ligne, annee_semaine, jour_heure, nom);

                //Créer une cellule avec cette ligne:

                //On commence par créer l'action associée:
                action_t *PsurAction = CreerAction(jour_heure, nom);

                //On insere maintenant cette action dans notre agenda
                InsererAction(&agenda, PsurAction, annee_semaine);
            }
        }

        //libération mémoire
        fclose(f);
    }
    else
    {
        fprintf(stdout, "Le fichier n'a pas pu être ouvert\n");
    }

    return agenda;
}



/* -------------------------------------------------------------------- */
/* LibererListeAction  Libérer la mémoire d'une liste d'action          */
/*                                                                      */
/* En entrée: -s, un pointeur de type semaine_t                         */
/*                                                                      */
/* En sortie: rien                                                      */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupère un pointeur d'une semaine_t en entrée                    */            
/* On parcourt chaque action de sa liste associée et pour chacune de ces*/
/* actions, on libère la mémoire                                        */
/* -------------------------------------------------------------------- */

void LibererListeAction(semaine_t *s)
{
    if(s != NULL)
    {
        action_t *parcourir = s->debut;
        s->debut = NULL;
        while(parcourir)
        {
            action_t *tmp = parcourir;
            parcourir = parcourir->suiv;
            free(tmp);
        }
    }
}


/* -------------------------------------------------------------------- */
/* LibererAgenda  Libérer la mémoire de tout un agenda                  */
/*                                                                      */
/* En entrée: -agenda, un pointeur de type agenda_t                     */
/*                                                                      */
/* En sortie: rien                                                      */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupere un pointeur sur un agenda en entrée.                     */
/* On parcourt chaque semaine de cet agenda et poru chacune d'entre elle*/
/* on libère sa liste d'action puis la mémoire qui lui est associé.     */
/* -------------------------------------------------------------------- */
void LibererAgenda(agenda_t *agenda)
{
    if(agenda!=NULL)
    {
        semaine_t *parcourir = agenda->debut;
        agenda->debut = NULL;

        while(parcourir)
        {
            semaine_t *tmp = parcourir;
            parcourir = parcourir->suiv;

            LibererListeAction(tmp);
            free(tmp);
        }
    }

}





/* -------------------------------------------------------------------- */
/* Ecriturefichier  Sauvegarder un agenda dans un fichier               */
/*                                                                      */
/* En entrée: -filename, une chaine de caractère représentant le nom    */
/* d'un fichier.                                                        */
/* -agenda, variable de type agenda_t                                   */
/*                                                                      */
/* En entrée/sortie: ecriture_reussi, retourne 1 si l'écriture à réussi */
/* 0 sinon                                                              */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupère un agenda et un nom de fichier en entrée                 */
/* On commence par essayer d'ouvrir le fichier, si l'ouverture à réussi */
/* On parcourt chaque semaine de notre agenda. Pour chaque semaine on   */
/* on parcourt sa liste d'action et on écrit dans le fichier l'annee et */
/* le numéro de semaine ainsi que le jour, l'heure et le nom de l'action*/ 
/* en respectant le format: aaaassjhhNOM avec le NOM sur 10 caractère   */
/* maximum                                                              */
/* Si on a réussi à ouvrir le fichier et que l'on a pu écrire dedans,   */
/* la fonction retourne 1 sinon 0                                       */
/* -------------------------------------------------------------------- */

//Etape 2 ecrire dans un fichier
int EcritureFichier(char *filename, agenda_t agenda)
{

    int ecriture_reussi = 0;

    FILE *f = fopen(filename, "w+");
    if(f)
    {
        //Ouverture fichier réussi

        //On parcourt chaque semaine de notre agenda et pour chacune d'entre elles on sauvegarde la liste correspondante
        semaine_t *parcourir = agenda.debut;
        while(parcourir)
        {
            action_t *cour = parcourir->debut;
            while(cour)
            {
                //On inscrit l'action (année semaine jour heure nom) dans notre fichier
                fprintf(f, "%s%s%s\n", parcourir->annee_semaine, cour->jour_heure, cour->nom);
                cour = cour->suiv;
            }
            parcourir = parcourir->suiv;
        }
        fclose(f);
        ecriture_reussi = 1;
    }

    return ecriture_reussi;
}



/* -------------------------------------------------------------------- */
/*  SupprimerAction  Supprimer une action d'un agenda                   */
/*                                                                      */
/* en entrée: annee, s, jour, heure, des chaines de caractère           */
/*                                                                      */
/* en entrée/sortie: agenda, une variable de type agenda_t              */
/*                                                                      */
/* sortie: rien                                                         */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* On récupere en entrée l'adresse d'un agenda ainsi que 4 chaine de    */
/* caractère représentant une année, une semaine, un jour et une heure  */
/* dans le but de supprimé l'action à cette date d'un agenda.           */
/* On commence donc par rechercher la semaine correspondante puis       */
/* l'action correspondante. Si on la trouve, on libère la mémoire tout  */
/* faisant attention de ne pas brisé la chaine de notre liste chainée   */
/* -------------------------------------------------------------------- */
void SupprimerAction(agenda_t *agenda, char *annee, char *s, char *jour, char *heure)
{
    //On parcourt nos semaines et actions jusqu'à trouver une action correspondante
    semaine_t * parcourir_semaine_t = agenda->debut,
              * prec_semaine_t = NULL;
    char        annee_semaine[7];

    while(parcourir_semaine_t)
    {
        //Parcours des semaines
        strcpy(annee_semaine, annee);
        strcat(annee_semaine, s);

        if(!strcmp(annee_semaine, parcourir_semaine_t->annee_semaine))
        {
            //On a trouvé la bonne semaine
            //Parcours des actions
            action_t *parcourir_action_t = parcourir_semaine_t->debut;
            action_t *prec_action_t = NULL;
            while(parcourir_action_t)
            {
                char jour_heure[4];
                strcpy(jour_heure, jour);
                strcat(jour_heure, heure);
                if(!strcmp(parcourir_action_t->jour_heure, jour_heure))
                {
                    //On a trouvé l'action
                    if(!prec_action_t)
                    {
                        //Si !prec_action_t alors l'action est en tête
                        parcourir_semaine_t->debut = parcourir_action_t->suiv;
                    }
                    else
                    {
                        prec_action_t->suiv = parcourir_action_t->suiv;
                    }

                    free(parcourir_action_t);
                    parcourir_action_t = NULL;
                    

                    //On pense également à supprimer la semaine si celle-ci est vide

                    if(parcourir_semaine_t->debut == NULL)
                    {
                        //La semaine n'a désormais plus d'action, il faut la supprimer
                        if(prec_semaine_t)
                        {
                            //Il y a une semaine avant donc on change son champ suiv
                            prec_semaine_t->suiv = parcourir_semaine_t->suiv;
                        }
                        else
                        {
                            //On doit changer le champ debut de notre agenda
                            agenda->debut = parcourir_semaine_t->suiv;
                        }

                        free(parcourir_semaine_t);
                    }
                    parcourir_semaine_t = NULL;
                }
                else
                {
                    //On continue le parcours des actions
                    prec_action_t = parcourir_action_t;
                    parcourir_action_t = parcourir_action_t->suiv;
                }

            }
        }
        else
        {
            //On continue notre parcours pour trouver la bonne semaine
            prec_semaine_t = parcourir_semaine_t;
            parcourir_semaine_t = parcourir_semaine_t->suiv;
        }
    }
}




/* -------------------------------------------------------------------- */
/*  SupprimerActionFichier  Supprimer une action d'un agenda            */
/*                                                                      */
/* en entrée: filename, annee, s, jour, heure, des chaines de caractère */
/*                                                                      */
/* sortie: rien                                                         */
/* -------------------------------------------------------------------- */

/* --------------------    ALGORITHME DE PRINCIPE  -------------------- */
/* -------------------------------------------------------------------- */
/*void SupprimerActionFichier(char *filename, char *annee, char *s, char *jour, char *heure)
{
    //On parcourt nos semaines et action jusqu'a trouvé une action correspondante
    semaine_t *parcourir;
    parcourir = agenda->debut;
    while(parcourir)
    {
        //Parcours des semaines
        char annee_semaine[7];
        strcpy(annee_semaine, annee);
        strcat(annee_semaine, s);

        if(!strcmp(annee_semaine, parcourir->annee_semaine))
        {
            //Parcours des actions
            action_t *cour = parcourir->debut;
            action_t *prec = NULL;
            while(cour)
            {
                char jour_heure[4];
                strcpy(jour_heure, jour);
                strcat(jour_heure, heure);
                if(!strcmp(cour->jour_heure, jour_heure))
                {
                    if(!prec)
                    {
                        parcourir->debut = cour->suiv;
                    }
                    else
                    {
                        prec->suiv = cour->suiv;
                    }

                    free(cour);
                }

            }
        }
    }
}*/