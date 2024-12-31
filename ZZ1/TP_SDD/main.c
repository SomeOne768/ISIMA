#include <stdio.h>
#include <stdlib.h>  
#include "structure.h"
#include "listecontigue.h"
#include <string.h>

///!\ A noter dans le rapport au cas où: QUITTER LE PROGRAMME AVE CTRL C PEUT CREER UEN ERREUR AVEC VALGRIND CAR FGETS RECUPERE UNE SAISIE QUI N'EXISTERA PLUS
//dONC PRECISER QUE LE PROGRAMME DOIT ETRE RESPECTER SINON PAS NOTRE FOTE KOI
//Idem pour la liberation

int main(int argc, char **argv)
{
    printf("Bonjour et bienvenu dans notre programme.\n\n");

    if(argc < 2)
    {
        printf("Veuillez relancer le programme avec un nom de fichier en paramètre.\n");
        printf("Des fichiers de test sont disponible si vous le souhaitez (exemple.txt).\n");
    }
    else
    {
        agenda_t agenda = CreerAgenda();
        int choix = 7,
            arret = 0;

        while(!arret)
        {
            char SAISIE[256];
            printf("Que souhaitez-vous faire?\n");

            printf("\t0 - Créer un nouvel agenda vide\n");

            printf("\t1 - Charger un agenda à partir d'un fichier (pris en argument d'execution)\n");

            printf("\t2 - Ajouter une action\n");

            printf("\t3 - Supprimer une action\n");

            printf("\t4 - Enregistrer un agenda\n");

            printf("\t5 - Rechercher un motif\n");

            printf("\t6 - Déroulez le programme qui traite tous les cas\n");

            printf("\t7 - Fermer le programme.\n");

            fgets(SAISIE, 256, stdin);
            sscanf(SAISIE, "%d", &choix);
            fflush(stdin);

            switch(choix)
            {
                case 0:
                    LibererAgenda(&agenda);
                    agenda = CreerAgenda();
                    break;

                case 1 :
                    //Choix charger un fichier

                    //On libère l'agenda actuel
                    LibererAgenda(&agenda);
                    //chargement du fichier
                    agenda = LectureFichier(argv[1]);
                    printf("Vous avez choisi de créer un agenda à partir du fichier %s.\n", argv[1]);
                    AfficherAgenda(agenda);
                break;

                case 2 :
                    //Ajouter une action
                    printf("Veuillez saisir une action à ajouter\n");
                    action_t * a;
                    char annee_semaine[7],
                         jour_heure[4],
                         NOM[11];
                    //Hypothèse: toutes les saisies seront correctes
                    printf("Saisir une annee et une semaine (entre 01 et 53) sous le format suivant: aaaass.\n");
                    fgets(SAISIE, 256, stdin);
                    strncpy(annee_semaine, SAISIE, 6);
                    annee_semaine[6]='\0';

                    printf("\nSaisir un jour (de 1 à 7) et d'une heure (de 00 à 24) sous le format suivant: jhh.\n");
                    fgets(SAISIE, 256, stdin);
                    strncpy(jour_heure, SAISIE, 3);
                    jour_heure[3]='\0';

                    printf("Saisir un nom d'action (10 caractères maximum). \n");
                    fgets(SAISIE, 256, stdin);
                    strncpy(NOM, SAISIE, 10);
                    NOM[10]='\0';

                    a=CreerAction(jour_heure, NOM);
                    InsererAction(&agenda, a, annee_semaine);
                    AfficherAgenda(agenda);
                    break;
                
                case 3 :
                    //Supprimer une action   
                    printf("vous avez choisi de supprimer une action. \n");
                    char annee[5],
                         semaine[3],
                         jour[2],
                         heure[3];

                    //Hypothèse toutes les saisies seront correctes
                    printf("Veuillez saisir une action\n");
                    printf("Saisir une annee sous le format suivant: aaaa\n");
                    fgets(SAISIE, 256, stdin);
                    fflush(stdin);
                    strncpy(annee, SAISIE, 4);
                    annee[4]='\0';

                    printf("\nSaisir un n° de semaine entre 01 et 53\n");
                    fgets(SAISIE, 256, stdin);
                    fflush(stdin);
                    strncpy(semaine, SAISIE,2);
                    semaine[2]='\0';

                    printf("\nSaisir un n° de jour entre 1 et 7\n");
                    fgets(SAISIE, 256, stdin);
                    fflush(stdin);
                    strncpy(jour, SAISIE,1);
                    jour[1]='\0';

                    printf("Saisir une heure entre 0 et 23\n");
                    fgets(SAISIE, 256, stdin);
                    fflush(stdin);
                    strncpy(heure, SAISIE,4);
                    heure[2]='\0';

                    SupprimerAction(&agenda, annee, semaine, jour, heure);
                    AfficherAgenda(agenda);
                    break;

                case 4 :;
                    //Enregistrer un agenda
                    printf("Vous avez choisi d'enregistrer un agenda.\n");

                    printf("Saisissez un nouveau nom de fichier pour sauvegarder l'agenda.\n");

                    char fichier_txt[256];
                    fgets(fichier_txt, 256, stdin);
                    fflush(stdin);
                    if(!EcritureFichier(fichier_txt, agenda))
                    {
                        //L'enregistrement a échoué
                        printf("L'enregistrement a échoué.\n");
                    }
                    break;

                case 5 :;
                    //Rechercher un motif
                    char motif[11];
                    liste_contigue_t liste;
                    printf("Veuillez indiquer le motif que vous voulez chercher (nombre caractères inférieur ou égal à 10). \n");
                    fgets(SAISIE, 256, stdin);
                    strncpy(motif, SAISIE, 10);
                    motif[10]='\0';

                    liste = RecupererMotifDepuisAgenda(agenda, motif);
                    AfficherListeContigue(liste);
                    LibererListeContigue(&liste);
                    break;

                case 6 :
                    //Déroulez le programme qui traite tous les cas
                    printf("\n\nDéroulement du programme qui traite tous les cas\n");
                    LibererAgenda(&agenda);
                    //Traitement de tout les cas

                    //Cas fichier non existant
                    printf("\nCas fichier non existant\n");
                    agenda = LectureFichier("Jenexistepas.txt");
                    LibererAgenda(&agenda);
    
                    //Cas fichier qui existe mais vide
                    printf("\nCas fichier qui existe mais est vide\n");
                    agenda = LectureFichier("exemplevide.txt");
                    LibererAgenda(&agenda);
    
                    //Cas fichier qui existe et pas vide.
                    //Ce fichier traite tous les cas d'insertion et de recherche
                    printf("\n\nCas fichier qui existe et non vide\n\n");
                    printf("Le fichier traite tous les cas d'insertion et de recherche\n\n");
                    agenda = LectureFichier("exemple.txt");
    
                    AfficherAgenda(agenda);
    
                    //Test de suppression dans une liste d'action
                    printf("\nSuppression dans la liste d'action suivante annee 2022 semaine 15:\n");
                    semaine_t *s = RechercheSemaine(&agenda, "202215");
                    AfficherListeAction(s->debut);
                    
                    //supression à l'intérieur
                    printf("\n\nSuppression à l'intérieur:\n");
                    SupprimerAction(&agenda, "2022", "15", "2", "12");
                    AfficherListeAction(s->debut);
    
                    //supression en fin
                    printf("\n\nSuppression en fin:\n");
                    SupprimerAction(&agenda, "2022", "15", "5", "09");
                    AfficherListeAction(s->debut);
    
                    //supression en tête
                    printf("\n\nSuppression en tête et semaine qui n'aura plus d'action:\n");
                    printf("année 2022 semaine 15 qui disparait\n");
                    SupprimerAction(&agenda, "2022", "15", "1", "08");
    
    
                    //supression d'un element n'existant pas
                    printf("supression d'un element n'existant pas\n");
                    SupprimerAction(&agenda, "2048", "11", "1", "12");
    
                    AfficherAgenda(agenda);
    
    
                    //Test suppression dans des semaines quelconques
    
                    //suppression dans une semaine à l'intérieur
                    printf("\nSupression dans une semaine à l'intérieur\n");
                    SupprimerAction(&agenda, "2022", "25", "3", "14");
                    AfficherAgenda(agenda);
    
                    //suppression dans une semaine en fin
                    printf("Supression dans une semaine en fin\n");
                    SupprimerAction(&agenda, "2024", "25", "3", "14");
                    AfficherAgenda(agenda);
    
                    //suppression dans une semaine en tête
                    printf("Supression dans une semaine en tête\n");
                    SupprimerAction(&agenda, "2019", "25", "3", "14");
                    AfficherAgenda(agenda);
    
                    //suppression dans une semaine qui n'existe pas
                    printf("\n\nSupression dans une semaine qui n'existe pas\n");
                    SupprimerAction(&agenda, "2048", "11", "1", "12");
                    AfficherAgenda(agenda);
                    
                    //Libération finale de la mémoire
                    printf("\n\nLibération mémoire et suppression de l'agenda\n");
                    LibererAgenda(&agenda);
                    AfficherAgenda(agenda);
    
                    printf("\n\n_______________________________________________________\n\n");
                    printf("                       PARTIE 2                        \n");
                    printf("_______________________________________________________\n\n");
                    printf("\n\nRepartons du même fichier pour réaliser les tests sur la seconde partie du TP.\n");
                    agenda = LectureFichier("exemple.txt");
                    AfficherAgenda(agenda);
    
                    printf("\nRecherchons le motif TPs de SDD\n");
                    liste_contigue_t L = RecupererMotifDepuisAgenda(agenda,"TPs de SDD");
                    AfficherListeContigue(L);
                    LibererListeContigue(&L);
                break;

                case 7 :
                    arret=1;
                    break;

                default :
                    printf("Mauvaise saisie. Veuillez hcoisir un chiffre entre 1 et 7.\n");

            }       
        }
        LibererAgenda(&agenda);
    }
    return 0;
}