#include <stdio.h>
#include <stdlib.h>  
#include "structure.h"
#include "listecontigue.h"
#include <string.h>



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
        agenda_t agenda;
        int      choix,
                 arret = 0;

        while(!arret)
        {
            //Affichage du menu
            printf("Que souhaitez-vous faire?\n");
            printf("\t1 - Charger un agenda à partir d'un fichier.\n");

            printf("\t2 - Sauvegarder l'agenda\n");

            printf("\t3 - Ajouter une action\n");

            printf("\t4 - Supprimer une action\n");

            printf("\t5 - Rechercher un motif\n");

            printf("\t6 - Déroulez le programme qui traite tous les cas\n");

            printf("\t7 - Quitter le programme\n")
            

            scanf(" %d", &choix);

            if(choix==1)//charger agenda
            {
                LibererAgenda(&agenda);
                printf("Vous avez choisi de charger un agenda à partir d'un fichier.\n");
                agenda = LectureFichier(argv[1]);
                AfficherAgenda(agenda);
            }
            else if(choix==2)//sauvegarder agenda
            {
                //Créer un agenda directement dans le programme
                agenda = CreerAgenda();
                action_t a;
                char saisie[TAILLE_LIGNE_MAX],
                     annee[5],
                     semaine[3],
                     jour[2],
                     heure[3],
                     NOM[11];
                int  continuer = 1;
                while(continuer)
                {
                    //Hypothèse toutes les saisies seront correctes
                    printf("Veuillez saisir une action\n");
                    printf("Saisir une annee sous le format suivant: aaaa\n");
                    scanf("%s", annee);
                    //printf("aaaassjhhNOM\n a  = année\t s=n°semaine\tj=n°jour (entre 1 et 7) et un nom de taille 10 maximum.\n");
                    printf("\nSaisir un n° de semaine entre 01 et 53\n");
                    scanf("%s", semaine);

                    printf("\nSaisir un n° de jour entre 1 et 7\n");
                    scanf("%s", jour);

                    printf("Saisir une heure entre 0 et 23\n");
                    scanf("%s", saisie);
                    
                    

                    //if(InsererAction(&agenda, action_t *element, char *annee_semaine);)
                }
                

            }
            else if(choix == 3)//Ajouter une action
            {
                printf("Par defaut, nous enregistrons l'agenda dans le fichier resultat.txt\n");
                int ecriture_reussi = EcritureFichier("resultat.txt", agenda);
                if(!ecriture_reussi)
                {
                    printf("La sauvegarde a échoué.\n");
                }
                else
                {
                    printf("Sauvegarde réussi.\n");
                }
            }
            else if(choix == 4)//Supprimer une action
            {
            }
            else if(choix == 5)//rechercher un motif
            {

            }
            else if(choix == 6)//Derouler prog par defaut
            {
                //Traitement de tout les cas
                //Cas fichier non existant
                agenda = LectureFichier("Jenexistepas.txt");
                LibererAgenda(&agenda);

                //Cas fichier qui existe mais vide
                agenda = LectureFichier("exemplevide.txt");
                LibererAgenda(&agenda);

                //Cas fichier qui existe et pas vide.
                //Ce fichier traite tous les cas d'insertion et de recherche
                agenda = LectureFichier("exemple.txt");

                AfficherAgenda(agenda);

                //Test de suppression dans une liste d'action
                printf("Suppression dans la liste d'action suivante annee 2022 semaine 15:\n");
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
                printf("annéé 2022 semaine 15 qui disparait\n");
                SupprimerAction(&agenda, "2022", "15", "1", "08");


                //supression d'un element n'existant pas
                SupprimerAction(&agenda, "2048", "11", "1", "12");

                AfficherAgenda(agenda);


                //Test suppression dans des semaines quelconques

                //supression dans une semaine à l'intérieur
                printf("Supression dans une semaine à l'intérieur\n");
                SupprimerAction(&agenda, "2022", "25", "3", "14");
                AfficherAgenda(agenda);

                //supression dans une semaine en fin
                printf("Supression dans une semaine en fin\n");
                SupprimerAction(&agenda, "2024", "25", "3", "14");
                AfficherAgenda(agenda);

                //supression dans une semaine en tête
                printf("Supression dans une semaine en tête\n");
                SupprimerAction(&agenda, "2019", "25", "3", "14");
                AfficherAgenda(agenda);

                //supression dans une semaine qui n'existe pas
                printf("Supression dans une semaine qui n'existe pas\n");
                SupprimerAction(&agenda, "2048", "11", "1", "12");
                AfficherAgenda(agenda);
                
                //Libration finale de la mmoire
                printf("Libération mémoire et suppression de l'agenda\n");
                LibererAgenda(&agenda);
                AfficherAgenda(agenda);

                printf("\n\n_______________________________________________________\n\n");
                printf("                       PARTIE 2                        \n");
                printf("_______________________________________________________\n\n");
                printf("\n\nRepartons du même fichier pour réaliser les tests sur la seconde partie du TP.\n");
                agenda = LectureFichier("exemple.txt");
                AfficherAgenda(agenda);

                printf("Recherchons le motif TPs de SDD\n");
                liste_contigue_t L = RecupererMotif("exemple.txt", "TPs de SDD");
                AfficherListeContigue(L);
            }
            else//quitter le programme
            {
                arret = 1;
            }


        }//Fin menu
    }//Fin du programme


    return 0;

}