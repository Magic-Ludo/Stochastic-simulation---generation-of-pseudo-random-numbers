#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*****************************************************
                    Utilisation
                    -----------

- Valeurs possible pour Motif :
    1 : Block carré (254 - ASCII) -> ■
    2 : Block entier (219 - ASCII) -> █
    3 : Block transparent à 20 % (178 - ASCII) -> ▒
    4 : Block transparent à 80 % (176 - ASCII) -> ▓
    5 : Affiche des |

- Option possible pour Aff_chiffre (affiche le nombre d'éléments dans chaque case du tableau): 
    0 : N'affiche pas les chiffres
    1 : Affiche les chiffres
    
******************************************************/
void Affche_Simple_HistogrammeL(int *Tab_histo, int Taille_histo, int Motif, int Aff_chiffre, int Fateur_div)
{
    int i, j;

    setlocale(LC_ALL, "");

    for (i = 0; i < Taille_histo; i++)
    {

        printf("[%d]\t", i);

        for (j = 0; j < (int)Tab_histo[i] / Fateur_div; j++)
        {

            if (Motif == 1)
            {
                printf("■");
            }
            if (Motif == 2)
            {
                printf("█");
            }
            if (Motif == 3)
            {
                printf("▒");
            }
            if (Motif == 4)
            {
                printf("▓");
            }
            if (Motif == 5)
            {
                printf("|");
            }
        }
        if (Aff_chiffre == 1)
        {
            printf(" %d\n", Tab_histo[i]);
        }
        else
        {
            printf("\n");
        }
    }
    printf("\n");
}

void AffcheHistogrammeL(int *Tab_histo, int Taille_histo, int Motif, int Aff_chiffre, double Intervalle, int Fateur_div)
{
    int i, j;
    double new_interval = 0.0;
    int decimal = CompteurDecimal(Intervalle);

    setlocale(LC_ALL, "");

    for (i = 0; i < Taille_histo; i++)
    {

        if (Intervalle == 1)
        {
            printf("[%d - %d[ \t", (int)new_interval, (int)(new_interval + Intervalle));
        }
        else
        {
            printf("[%.*f - %.*f[\t", decimal, new_interval, decimal, new_interval + Intervalle);
        }

        for (j = 0; j < (int)Tab_histo[i] / Fateur_div; j++)
        {

            if (Motif == 1)
            {
                printf("■");
            }
            if (Motif == 2)
            {
                printf("█");
            }
            if (Motif == 3)
            {
                printf("▒");
            }
            if (Motif == 4)
            {
                printf("▓");
            }
            if (Motif == 5)
            {
                printf("|");
            }
        }
        if (Aff_chiffre == 1)
        {
            printf(" %d\n", Tab_histo[i]);
        }
        else
        {
            printf("\n");
        }

        new_interval += Intervalle;
    }
    printf("\n");
}

void AffcheHistogrammeW(int *Tab_histo, int Taille_histo, int Motif, int Aff_chiffre, double Intervalle, int Fateur_div)
{
    int i, j;
    double new_interval = 0.0;
    int decimal = CompteurDecimal(Intervalle);

    for (i = 0; i < Taille_histo; i++)
    {

        if (Intervalle == 1)
        {
            printf("[%d - %d[\t", (int)new_interval, (int)(new_interval + Intervalle));
        }
        else
        {
            printf("[%.*f - %.*f[\t", decimal, new_interval, decimal, new_interval + Intervalle);
        }

        for (j = 0; j < (int)Tab_histo[i] / Fateur_div; j++)
        {

            if (Motif == 1)
            {
                printf("%c", 254);
            }
            if (Motif == 2)
            {
                printf("%c", 219);
            }
            if (Motif == 3)
            {
                printf("%c", 177);
            }
            if (Motif == 4)
            {
                printf("%c", 178);
            }
            if (Motif == 5)
            {
                printf("|");
            }
        }
        if (Aff_chiffre == 1)
        {
            printf(" %d\n", Tab_histo[i]);
        }
        else
        {
            printf("\n");
        }

        new_interval += Intervalle;
    }
    printf("\n");
}

int *CreeTabValeurs(double *Tab_histo, int Taille_histo, int Borne_Sup, int Borne_Inf, double Intervalle)
{

    //  Taille du nouveau tableau
    int taille_new_histo = (int)(Borne_Sup / Intervalle);

    //  Tableau contenant le nombre de valeurs présententes dans un intervalle
    int *Tab_Result;
    int i, j;

    //  Permet de ramener l'intervalle à un entier
    double new_interval_factor = 1.0 / Intervalle;

    Tab_Result = (int *)calloc(taille_new_histo, sizeof(int));

    for (i = 0; i < Taille_histo; i++)
    {
        Tab_Result[(int)(Tab_histo[i] * new_interval_factor)]++;
    }

    return Tab_Result;
}

int CompteurDecimal(double nombre)
{
    int i;
    int compteur = 0;
    char chaine_chiffre[10];

    sprintf(chaine_chiffre, "%f", nombre);

    for (i = 0; i <= 10; i++)
    {
        if (chaine_chiffre[i] == '0' || chaine_chiffre[i] == '.')
        {
            compteur++;
        }
        else
        {
            return compteur - 1;
        }
    }
}
