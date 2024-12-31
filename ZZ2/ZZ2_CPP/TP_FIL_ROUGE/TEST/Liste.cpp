#include <iostream>
#include "Liste.hpp"

Liste::Liste()
{
    compteur = 0;
    nb_c = 0;
    nb_r = 0;
}

void Liste::afficherTab(Forme tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i].afficher();
    }
}

// void Liste::afficherTab(Rectangle tab[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%s ", tab[i].toString().c_str());
//     }
// }

// void Liste::afficherTab(Cercle tab[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%s ", tab[i].toString().c_str());
//     }
// }

int Liste::getCompteur()
{
    return compteur;
}

std::string Liste::toString()
{
    // On affiche dans l'ordre
    int i = 0,
        j = 0;

    std::string out = "";
    while (i < nb_c && j < nb_r)
    {
        if (cercles[i].ordre < rectangles[j].ordre)
        {
            out += cercles[i].toString();
            out += " ";
            i++;
        }
        else
        {
            out += rectangles[j].toString();
            out += " ";
            j++;
        }
    }

    if (i != nb_c)
    {
        // Il reste des cercles à afficher
        while (i < nb_c)
        {
            out += cercles[i].toString();
            out += " ";
            i++;
        }
    }

    else if (j != nb_r)
    {
        // Il reste des rectangles à afficher
        while (j < nb_r)
        {
            out += rectangles[j].toString();
            out += " ";
            j++;
        }
    }

    return out;
}

void Liste::afficher()
{
    int i = 0,
        j = 0;

    while (i < nb_c && j < nb_r)
    {
        if (cercles[i].ordre < rectangles[j].ordre)
        {
            cercles[i].afficher();
            i++;
        }
        else
        {
            rectangles[j].afficher();
            j++;
        }
    }

    if (i != nb_c)
    {
        // Il reste des cercles à afficher
        while (i < nb_c)
        {
            cercles[i].afficher();
            i++;
        }
    }

    else if (j != nb_r)
    {
        // Il reste des rectangles à afficher
        while (j < nb_r)
        {
            rectangles[j].afficher();
            j++;
        }
    }
}

void Liste::add(Rectangle &r)
{
    if (nb_r < TAILLE)
    {
        r.ordre = compteur;
        this->rectangles[nb_r] = r;
        nb_r++;
        compteur++;
    }
}

void Liste::add(Cercle &c)
{
    if (nb_r < TAILLE)
    {
        c.ordre = compteur;
        this->cercles[nb_c] = c;
        nb_c++;
        compteur++;
    }
}