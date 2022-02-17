/************************************************************
 *     __/\\\_____________________/\\\\\\\\\_               *
 *      _\/\\\__________________/\\\////////__              *
 *       _\/\\\________________/\\\/___________             *
 *        _\/\\\_______________/\\\_____________            *
 *         _\/\\\______________\/\\\_____________           *
 *          _\/\\\______________\//\\\____________          *
 *           _\/\\\_______________\///\\\__________         *
 *            _\/\\\\\\\\\\\\\\\_____\////\\\\\\\\\_        *
 *             _\///////////////_________\/////////__       *
 *                                                          *
 *                                                          *
 *      Auteur : Ludovic Corcos                             *
 *                                                          *
 *      Université Clermont Auvergne | L2 Informatique      *
 *                                                          *
 *      Date : 18/02/2020                                   *   
 *                                                          *
 *      Programme : TP2.c                                   *
 *                                                          *
 *      Description :                                       *
 *      Génération de nombres pseudo-aléatoires             *
 *                                                          *
 ************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mt19937ar.c" //  Code de Matsumoto
#include "histogramme.c"

#define PI 3.14159265358979323846

/************************************************************
 *                                                          *
 *                  Prototypes des fonctions                *
 *                                                          *
 ************************************************************/

// ----------------------- Exercice 2 -----------------------

double uniform(double borne_inf, double borne_sup);

// ----------------------- Exercice 3 -----------------------

int *simple_simu_3classes(int nb_tests);

int *discrete_distributions(int *tab_val_gr, int taille_tab, float nb_tests);

// ----------------------- Exercice 4 -----------------------

double negExp(int moyenne);

double moyenne_reelle(int *tab, int taille_tab);

// ----------------------- Exercice 5 -----------------------

double cos_Box_Muller(double Rn1, double Rn2);

double sin_Box_Muller(double Rn1, double Rn2);

int *compteur_neg_Box_Muller(double *tab, int taille_tab);

int *concatene(int *tab1, int *tab2, int taille);

/************************************************************
 *                                                          *
 *                Fonction 'main' principale                *
 *                                                          *
 ************************************************************/

int main(int argc, char *argv[])
{

    // -------------- Initialisation des variables --------------

    //  Question 2
    int i;
    double tab_result_a_b[1000000]; //  Sont contenu ici les valeurs généré
                                    //  entre borne_sup et borne_inf
                                    //  par le générateur de loi uniforme
    int iterations = 1000000;

    //  Question 4
    double tab_negExp_1000[1000];       //  Création des tableaux qui seront utilisés
    double tab_negExp_1000000[1000000]; //  Pour tester la fonction negExp

    //  Question 5
    double Box_Muller_1000_cos[1000];
    double Box_Muller_1000000_cos[1000000];

    double Box_Muller_1000_sin[1000];
    double Box_Muller_1000000_sin[1000000];


    // ----------------------- Exercice 2 -----------------------
/*
    for (i = 0; i < iterations; i++)
    {
        tab_result_a_b[i] = uniform(0.0, 1.0);
    }

    // Sont stocké ici le nombre de valeurs pour chaque intervalle en 0 et 1 par pas de 0.1
    int *new_tab_a_b = CreeTabValeurs(tab_result_a_b, iterations, 1, 0, 0.1);

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", new_tab_a_b[i]);
    }

    //  Appel à ma fonction ppur afficher un histograme des valeur de new_tab_a_b
    AffcheHistogrammeL(new_tab_a_b, 10, 1, 1, 0.1, 2000);

    // ----------------------- Exercice 3 -----------------------

    //  Le tableau test_tab_simu_3classes permet de tester le bon fonctionnement de la fonction discrete_distributions
    int *test_tab_simu_3classes = simple_simu_3classes(1000);
    int *test2_tab_simu_3classes = simple_simu_3classes(1000000);

    printf("Vérification des valeurs pour la fonction discrete_distributions : \n\n");

    printf("Pour test_tab_simu_3classes (1 000 essais) : \n");
    int *new_tab_t1 = discrete_distributions(test_tab_simu_3classes, 3, 1000);

    printf("Pour test_tab_simu_3classes (1 000 000 essais) : \n");
    int *new_tab_t2 = discrete_distributions(test2_tab_simu_3classes, 3, 1000000);

    printf("Affichage des histogrammes cumulatifs: \n\n");

    printf("Pour test_tab_simu_3classes (1 000 essais)\n");
    Affche_Simple_HistogrammeL(new_tab_t1, 3, 1, 1, 30);

    printf("Pour test_tab_simu_3classes (1 000 000 essais)\n");
    Affche_Simple_HistogrammeL(new_tab_t2, 3, 1, 1, 15000);
*/
    // ----------------------- Exercice 4 -----------------------

    for (i = 0; i < 1000; i++)
    {
        tab_negExp_1000[i] = negExp(10); //  V1 = Version 1
    }

    for (i = 0; i < 1000000; i++)
    {
        tab_negExp_1000000[i] = negExp(10); //  V2 = Version 2
    }

    printf("Moyenne réelle pour negExp à 1 000 valeurs = %f\n\n", moyenne_reelle(tab_negExp_1000, 1000));

    printf("Moyenne réelle pour negExp à 1 000 000 valeurs = %f\n\n", moyenne_reelle(tab_negExp_1000000, 1000000));

    printf("Histogramme de la fonction negExp pour 1 000 essais :\n\n");

    //  On crée ici les différentes tableaux de valeurs, présence des valeurs dans l'interval [a, b[
    //  Et ensuite, on affiche leurs histogrammes respectifs

    int *tab_val_negExp_V1 = CreeTabValeurs(tab_negExp_1000, 1000, 20, 0, 1.0);
    AffcheHistogrammeL(tab_val_negExp_V1, 20, 1, 1, 1.0, 2);

    printf("Histogramme de la fonction negExp pour 1 000 000 essais :\n\n");

    int *tab_val_negExp_V2 = CreeTabValeurs(tab_negExp_1000000, 1000000, 40, 0, 1.0);
    AffcheHistogrammeL(tab_val_negExp_V2, 40, 1, 1, 1.0, 1500);

    // ----------------------- Exercice 5 -----------------------
/*
    //  Remplissage des générateurs à fonction cosinus
    for (i = 0; i < 1000; i++)
    {
        double Rn1 = genrand_real2();
        double Rn2 = genrand_real2();
        //printf("%f\n", cos_Box_Muller(Rn1, Rn2));

        Box_Muller_1000_cos[i] = cos_Box_Muller(Rn1, Rn2);
    }

    for (i = 0; i < 1000000; i++)
    {
        double Rn1 = genrand_real2();
        double Rn2 = genrand_real2();
        //printf("%f\n", cos_Box_Muller(Rn1, Rn2));

        Box_Muller_1000000_cos[i] = cos_Box_Muller(Rn1, Rn2);
    }
    
    */
/*
    //  Remplissage des générateurs à fonction sinus
    for (i = 0; i < 1000; i++)
    {
        double Rn1 = genrand_real2();
        double Rn2 = genrand_real2();
        //printf("%f\n", cos_Box_Muller(Rn1, Rn2));

        Box_Muller_1000_sin[i] = sin_Box_Muller(Rn1, Rn2);
    }

    for (i = 0; i < 1000000; i++)
    {
        double Rn1 = genrand_real2();
        double Rn2 = genrand_real2();
        //printf("%f\n", cos_Box_Muller(Rn1, Rn2));

        Box_Muller_1000000_sin[i] = sin_Box_Muller(Rn1, Rn2);
    }

    printf("Affichage des résultats : \n\n");

    printf("Pour la fonction cosinu : \n\n");

    int *tab_BOX_cos_1000 = compteur_neg_Box_Muller(Box_Muller_1000_cos, 1000);
    int *tab_BOX_cos_1000000 = compteur_neg_Box_Muller(Box_Muller_1000000_cos, 1000000);

    printf("Avec 1 000 nombres générés :\n");
    Affche_Simple_HistogrammeL(tab_BOX_cos_1000, 20, 1, 1, 1);

    printf("Avec 1 000 000 nombres générés :\n");
    Affche_Simple_HistogrammeL(tab_BOX_cos_1000000, 20, 1, 1, 1000);

    free(tab_BOX_cos_1000);
    free(tab_BOX_cos_1000000);
/*
    printf("Pour la fonction sinus : \n\n");

    int *tab_BOX_sin_1000 = compteur_neg_Box_Muller(Box_Muller_1000_sin, 1000);
    int *tab_BOX_sin_1000000 = compteur_neg_Box_Muller(Box_Muller_1000000_sin, 1000000);

    printf("Avec 1 000 nombres générés :\n");
    Affche_Simple_HistogrammeL(tab_BOX_sin_1000, 20, 1, 1, 1);

    printf("Avec 1 000 000 nombres générés :\n");
    Affche_Simple_HistogrammeL(tab_BOX_sin_1000000, 20, 1, 1, 1000);
*/
    return EXIT_SUCCESS;
}

/************************************************************
 *                                                          *
 *                   Fonctions d'exercices                  *
 *                                                          *
 ************************************************************/

// ----------------------- Exercice 2 -----------------------

//  Permet de générer un nombre aléatoire entre borne_inf et borne_sup de manière uniforme
double uniform(double borne_inf, double borne_sup)
{
    return (borne_inf + (borne_sup - borne_inf) * genrand_real2());
}

// ----------------------- Exercice 3 -----------------------

//  a
//  Permet d'obtenir la répartition sur les 3 groupes en fonction de la règle du sujet de TP
//  Retourne également un tableau tab_test contenant les valeurs des groupes.
int *simple_simu_3classes(int nb_tests)
{
    int class1 = 0;
    int class2 = 0;
    int class3 = 0;
    int i;

    int *tab_test;
    tab_test = (int *)calloc(3, sizeof(int));

    for (i = 0; i < nb_tests; i++)
    {
        double rand_gene = genrand_real2();
        //printf("%f\n",rand_gene);
        if (rand_gene < 0.50)
        {
            class1++;
            tab_test[0]++;
        }
        else if (rand_gene > 0.50 && rand_gene < 0.60)
        {
            class2++;
            tab_test[1]++;
        }
        else if (rand_gene > 0.60)
        {
            class3++;
            tab_test[2]++;
        }
    }
    printf("\n");
    printf("Valeurs pour %d essais : \n\n", nb_tests);
    printf("Class 1 = %d %%\n", (int)(class1 * 100) / nb_tests);
    printf("Class 2 = %d %%\n", (int)(class2 * 100) / nb_tests);
    printf("Class 3 = %d %%\n", (int)(class3 * 100) / nb_tests);
    printf("\n");

    return tab_test;
}

//  b
//  Fonction plus générique que la première, elle permet de calculer la probabilté d'etre dans groupe
//  et le met dans un tableau
//  Elle renvoi aussi un tableau avec les probabilités cumulées
int *discrete_distributions(int *tab_val_gr, int taille_tab, float nb_tests)
{
    int i;

    //  Initialisation du tableau où seront affecté les résultats cumulés
    int *cumulative_tab;
    cumulative_tab = (int *)calloc(taille_tab, sizeof(int));
    /*
    for (i = 0; i < 3; i++) {
        printf("%d\n", tab_val_gr[i]);
    }
*/
    //  On garde en mémoire la première valeur du tableau pris en entré
    cumulative_tab[0] = tab_val_gr[0];

    for (i = 0; i < taille_tab; i++)
    {

        //  Calcul de la probabilité
        float proba = tab_val_gr[i] / nb_tests;

        printf("Probabilité d'etre dans le groupe %d = %g, soit %d %%\n",
               i + 1, proba, (tab_val_gr[i] * 100) / (int)nb_tests);

        cumulative_tab[i] = cumulative_tab[i - 1] + tab_val_gr[i];
    }
    printf("\n");
    return cumulative_tab;
}

// ----------------------- Exercice 4 -----------------------

//  Générateur selon une loi exponentielle
double negExp(int moyenne)
{
    return -moyenne * log(1 - genrand_real2());
}

//  Renvoi la moyenne d'un tableau
double moyenne_reelle(int *tab, int taille_tab)
{
    double somme = 0.0;
    int i;

    for (i = 0; i < taille_tab; i++)
    {
        somme += tab[i];
    }

    return somme / taille_tab;
}

// ----------------------- Exercice 5 -----------------------

double cos_Box_Muller(double Rn1, double Rn2)
{

    double result = (cos(2 * PI * Rn2) * sqrt(-2 * log(Rn1)));

    return result;
}

double sin_Box_Muller(double Rn1, double Rn2)
{

    double result = (sin(2 * PI * Rn2) * sqrt(-2 * log(Rn1)));

    return result;
}

int *compteur_neg_Box_Muller(double *tab, int taille_tab)
{
    int i;

    int *compteur_tab;
    compteur_tab = (int *)calloc(20, sizeof(int));

    for (i = 0; i < taille_tab; i++)
    {
        if (tab[i] >= -1.0 && tab[i] < -0.9)
            compteur_tab[0]++;
        else if (tab[i] >= -0.9 && tab[i] < -0.8)
            compteur_tab[1]++;
        else if (tab[i] >= -0.8 && tab[i] < -0.7)
            compteur_tab[2]++;
        else if (tab[i] >= -0.7 && tab[i] < -0.6)
            compteur_tab[3]++;
        else if (tab[i] >= -0.6 && tab[i] < -0.5)
            compteur_tab[4]++;
        else if (tab[i] >= -0.5 && tab[i] < -0.4)
            compteur_tab[5]++;
        else if (tab[i] >= -0.4 && tab[i] < -0.3)
            compteur_tab[6]++;
        else if (tab[i] >= -0.3 && tab[i] < -0.2)
            compteur_tab[7]++;
        else if (tab[i] >= -0.2 && tab[i] < -0.1)
            compteur_tab[8]++;
        else if (tab[i] >= -0.1 && tab[i] < 0.0)
            compteur_tab[9]++;
        else if (tab[i] >= 0.0 && tab[i] < 0.1)
            compteur_tab[10]++;
        else if (tab[i] >= 0.1 && tab[i] < 0.2)
            compteur_tab[11]++;
        else if (tab[i] >= 0.2 && tab[i] < 0.3)
            compteur_tab[12]++;
        else if (tab[i] >= 0.3 && tab[i] < 0.4)
            compteur_tab[13]++;
        else if (tab[i] >= 0.4 && tab[i] < 0.5)
            compteur_tab[14]++;
        else if (tab[i] >= 0.5 && tab[i] < 0.6)
            compteur_tab[15]++;
        else if (tab[i] >= 0.6 && tab[i] < 0.7)
            compteur_tab[16]++;
        else if (tab[i] >= 0.7 && tab[i] < 0.8)
            compteur_tab[17]++;
        else if (tab[i] >= 0.8 && tab[i] < 0.9)
            compteur_tab[18]++;
        else if (tab[i] >= 0.9 && tab[i] < 1.0)
            compteur_tab[19]++;
    }

    return compteur_tab;
}
