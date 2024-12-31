#include <stdio.h>
#include "structure.h"
#include <string.h>
#include "listecontigue.h"
#include <stdlib.h>


int main(void)
{
    
    //Test de création & affichage

    printf("Test des créations et affichage\n");

    action_t *tete = CreerAction("110", "TPs de SDD");
    agenda_t agenda = CreerAgenda();
    semaine_t * s = CreerSemaine("202201");

    AfficherAction(*tete);
    s -> debut = tete;
    /*
    AfficherListeAction(s->debut);

    agenda.debut = s;

    AfficherAgenda(agenda);

    s->debut = NULL;
    agenda.debut = NULL;

    //Test d'insertion

    printf("Test insertion dans une semaine\n");

    insererDansListeAction(&s->debut, tete);
    AfficherListeAction(s->debut);
    s->debut = NULL;

    printf("Test insertion dans un agenda\n");
    insererAction(&agenda, tete, "202201");
    AfficherAgenda(agenda);
    agenda.debut = NULL;


    printf("Test insertion d'un nouvel element en debut\n");
    insererAction(&agenda, tete, "202201");
    AfficherAgenda(agenda);

    printf("Test insertion d'un nouvel element en fin\n");
    action_t *fin = CreerAction("514", "Fin");
    insererAction(&agenda, fin, "202301");
    AfficherAgenda(agenda);

    printf("\n\nTest insertion d'un nouvel element au milieu\n\n");
    action_t *milieu = CreerAction("514", "milieu");
    int r = insererAction(&agenda, milieu, "202221");
    AfficherAgenda(agenda);
    printf("valeur de retour = %d\n", r);
    */

    // printf("\n\nTest lecture d'un fichier:\n");

    // agenda_t agenda = LectureFichier("exemple.txt");
    // AfficherAgenda(agenda);

    // printf("Fonction de libération:\n");
    // libererAgenda(&agenda);

    // //test etape 2: ecriture
    // agenda_t agenda = LectureFichier("exemple2");
    // ecriturefichier("exemple2.txt", agenda);

    //test de la liste contigue;

    // liste_contigue L = CreerListeContigue();
    // printf("Estvide 1==%d\n", EstVideListeContigue(L));
    // printf("insertion 1==%d\n", InsererDansListeContigue(&L, "202001223"));
    // printf("estpresent 1==%d\n", EstPresentMotif("exemple3.txt", "choco"));

    // L = RecupererMotif("exemple3.txt", "choco");
    // AfficherListeContigue(L);


    //test de suppression

    agenda_t agendaa = LectureFichier("exemple2.txt");

    AfficherAgenda(agendaa);

    return 0;
}