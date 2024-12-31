#include <stdio.h>
#include <stdlib.h>  
#include "structure.h"
#include "listecontigue.h"



int main(int argc, char **argv)
{

    printf("Bonjour et bienvenu dans le programme de Abdeljalil ZOGHLAMI et Yassine KHIERA.\n\n");

    //Menu d'utilisation
    if(argc < 2)
    {
        //Il faut un nom de fichier pour pouvoir utiliser le programme
        printf("Pour pouvoir utiliser ce programme veuillez donner en argument un fichier de test.\n");
    }
    else
    {
        FILE * f = fopen(argv[1], "r");

        if(f)
        {
            //Le nom de fichier est valide, l'ouverture à réussi
            printf("Voici le nom de fichier ouvert: %s \n", argv[1]);


            //Menu programme:
            int arret = 0;
            int choix;

            while(!arret)
            {
                printf("Que souhaitez-vous ?\n");
                printf("\t1 - Lire un fichier\n");
                printf("\t2 - Sauvegarder une structure dans un fichier\n");
                printf("\t3 - Supprimer une action de votre structure\n");

                scanf("%d", &choix);
                if(choix<1 || choix >3)
                {
                    printf("Mauvaise saisie. Veuillez entrez un nombre entre 1 et 3\n");
                }
                else
                {
                    if(choix == 1)
                    {
                        //Exercice 1: crée une liste chainée à partir d'un fichier donnée en argument
                        printf("Création d'un agenda à partir de :%s\n", argv[1]);
                        agenda_t agenda = LectureFichier(argv[1]);

                        AfficherAgenda(agenda);
                    }
                    else if(choix == 2)
                    {agenda_t agenda = LectureFichier(argv[1]);
                        //Exercice2: enregistrer une SDD dans un fichier
                        //printf("Enregistrement de la structure de donnée dans le fichier: %s\n", argv[1]);
                        printf("Enregistrement de la structure de donnée dans le fichier: ttt.txt pour le moment\n");
                        int ecriture_reussi = EcritureFichier("ttt.txt", agenda);
                        if(!ecriture_reussi)
                        {
                            printf("L'écriture a échoué\n");
                        }
                    }
                    else
                    {
                        //exercice3: Suppression d'une action connaissant année semaine jour heur
                    }
                }

                arret = 1;
            }


            fclose(f);
        }
        else
        {
            //echec de l'ouverture
            printf("Désolé, nous n'avons pas réussi à ouvrir votre fichier.\n");
            printf("Le fichier n'existe pas ou alors une erreur s'est produite.\n");
            printf("Veuillez réessayer avec les fichiers exemple{i}.txt\n");
        }
    }


    return 0;
}