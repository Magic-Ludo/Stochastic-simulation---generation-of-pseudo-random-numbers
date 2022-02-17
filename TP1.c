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
 *      Programme : TP1.c                                   *
 *                                                          *
 *      Description :                                       *
 *      Génération de nombres pseudo-aléatoires             *
 *                                                          *
 ************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BITS_8 256.0
#define BITS_16 65536.0
#define NB_ITERATIONS 100000

/************************************************************
 *                                                          *
 *                  Prototypes des fonctions                *
 *                                                          *
 ************************************************************/

// ---------------------- Exercice 1-2 ----------------------
int milieuNb(int nombre);

int nbCarre(int nb_au_carre);

// ----------------------- Exercice 3 -----------------------
int LCG(int a, int c, int m, int result);

void compteurs(int nb_iterations);

int LongueurCycle(int Iterations, int result_LCG_init);

// ----------------------- Exercice 4 -----------------------
int LFSR_generator(int nombre);

int dec_to_bin(int nb_dec);

// ----------------------- Exercice 6 -----------------------

void compteur_6(int *tab, int longueur, int iterations);

/************************************************************
 *                                                          *
 *                Fonction 'main' principale                *
 *                                                          *
 ************************************************************/

int main(int argc, char *argv[])
{

    // -------------- Initialisation des variables --------------

    int nb_iterations = 1000000;
    int choix_menu;

    //  Question 1
    int N = 1301;
    int compteur_q1 = 0;

    //  Question 3
    int i;
    int result_LCG = 0;

    //  Question 4
    int nb_test = 15;

    //  Question 6
    int tab_GX[100000] = {0};     //  Tableau où seront les nombres issus de GX
    int tab_GY[100000] = {0};     //  Tableau où seront les nombres issus de GY
    int tab_result[100000] = {0}; //  Tableau où seront les nouveaux nombres aléatoires issu du brassage
    int valeur_GX = 67;           //  Initialisation de GX : un bon faible
    int valeur_GY = 0;            //  Initialisation de GY : un bon
    int indice, new_indice, alea, result, new_result;

    printf("\t\t Menu TP 1 - Projet informatique\n\n");

    printf("1-\tGénérateur du type 'élévation au carré' sur 4 digits\n");
    printf("3-\tGénérateur congruentiel linéaire\n");
    printf("4-\tGénération à base de registres à décalage bouclés\n");
    printf("6-\tBrassage de générateurs\n");
    printf("0-\tQuitter\n\n");

    printf("Veullez selectionner un exercice à afficher : ");
    scanf("%d", &choix_menu);
    printf("\n");

    switch (choix_menu)
    {
    case 1:

        // ---------------------- Exercice 1-2 ----------------------

        printf("\n");
        while (compteur_q1 <= NB_ITERATIONS)
        {
            int tmp = nbCarre(N);
            int newVal = milieuNb(tmp);
            printf("N%02d = %04d \t %04d * %04d = %08d\n", compteur_q1, N, N, N, N * N);

            N = newVal;
            compteur_q1++;
        }
        printf("\n");
        ;

        break;

    case 3:

        // ----------------------- Exercice 3 -----------------------
        //  a
/*
        printf("\n");
        for (i = 0; i <= NB_ITERATIONS; i++)
        {
            result_LCG = LCG(7, 3, BITS_8, result_LCG);
            printf("Itération %d = %03d\n", i, result_LCG);
        }

        //  b

        compteurs(NB_ITERATIONS);

        //  d
*/
        printf("\n");
        int LongCycle = LongueurCycle(NB_ITERATIONS, result_LCG);
        printf("La longueur d'un cycle avec ce LCG est de : %d\t (On a testé %d itérations)\n", LongCycle, nb_iterations);

        //  e

        // Des valeurs pertinantes sont disponibles ici :
        // https://en.wikipedia.org/wiki/Linear_congruential_generator
        // http://www.new-npac.org/projects/cdroms/cewes-1999-06-vol1/cps615course/csematerials/applications/mc/montecarlo/node105.html
        // https://aaronschlegel.me/linear-congruential-generator-r.html
        // http://www.pcg-random.org/posts/does-it-beat-the-minimal-standard.html
        // http://statmath.wu.ac.at/software/prng/doc/prng.html#Table_005fLCG
        // http://www.sci.csueastbay.edu/~btrumbo/Stat3401/Hand3401/CongGenIntroB.pdf

        break;

    case 4:

        // ----------------------- Exercice 4 -----------------------

        printf("\n");
        for (i = 0; i <= pow(2, 4) - 1; i++)
        {
            printf("Itération %d =\t", i);
            dec_to_bin(nb_test);
            printf("\n");
            nb_test = LFSR_generator(nb_test);
        }
        printf("\n");

        break;

    case 6:

        // ----------------------- Exercice 6 -----------------------

        //  Remplissage de GX
        for (i = 0; i < 100000; i++)
        {
            tab_GX[i] = LCG(2, 7, BITS_16, valeur_GX);
            valeur_GX = LCG(2, 7, BITS_16, valeur_GX);
            //printf("%d\n", tab_GX[i]);
        }

        //  Remplissage de GY
        for (i = 0; i < 100000; i++)
        {
            tab_GY[i] = LCG(123, 3, BITS_16, valeur_GY);
            valeur_GY = LCG(123, 3, BITS_16, valeur_GY);
            //printf("%d\n", tab_GY[i]);
        }

        printf("Resultat pour tab_GX : \n\n");
        compteur_6(tab_GX, 100000, 100000);
        printf("\n\n");

        printf("Resultat pour tab_GY : \n\n");
        compteur_6(tab_GY, 100000, 100000);
        printf("\n\n");

        valeur_GX = 0;

        for (i = 0; i < 100000; i++)
        {

            alea = rand() % 100000;
            indice = tab_GY[alea] % 100;

            result = tab_GX[indice];
            new_indice = tab_GY[alea] % 100;

            new_result = tab_GX[new_indice];

            tab_GX[indice] = new_result;
            tab_result[i] = result;
        }

        printf("Resultat pour uniforme : \n\n");
        compteur_6(tab_result, 100000, 100000);

        break;

    case 0:
        return EXIT_SUCCESS;

    default:
        break;
    }
}

/************************************************************
 *                                                          *
 *                   Fonctions d'exercices                  *
 *                                                          *
 ************************************************************/

// ---------------------- Exercice 1-2 ----------------------

//  Renvoi les 4 chiffres au milieu d'un nombre de 8 chiffres
int milieuNb(int nombre)
{
    int nbFin = (nombre / 100) % 10000;
    return nbFin;
}

//  Renvoi un nombre au carré
int nbCarre(int nb_au_carre)
{
    return nb_au_carre * nb_au_carre;
}

/*
Avec le germe N = 1234, le générateur s'écrase à partir de 54 itérations
Avec le germe N = 4100, le générateur s'écrase à partir de 4 itérations, on voit une boucle se créer
*/

// ----------------------- Exercice 3 -----------------------

//  Générateur de type LCG
int LCG(int a, int c, int m, int result)
{
    // Formule = N(k+1) = (a * N(k) + c ) mod m
    int result_fin = (a * result + c) % m;
    return result_fin;
}

void compteurs(int nb_iterations)
{

    int i = 0;
    unsigned int result_LCG = 0;

    //  Définition des groupes :
    int comp1 = 0;  //[0.0 - 0.1[
    int comp2 = 0;  //[0.1 - 0.2[
    int comp3 = 0;  //[0.2 - 0.3[
    int comp4 = 0;  //[0.3 - 0.4[
    int comp5 = 0;  //[0.4 - 0.5[
    int comp6 = 0;  //[0.5 - 0.6[
    int comp7 = 0;  //[0.6 - 0.7[
    int comp8 = 0;  //[0.7 - 0.8[
    int comp9 = 0;  //[0.8 - 0.9[
    int comp10 = 0; //[0.9 - 1.0[

    for (i; i <= nb_iterations; i++)
    {
        result_LCG = LCG(7, 5, BITS_16, result_LCG);
        float NewResult_LCG = (double)result_LCG / BITS_16;
        //printf("Itération %d = %03d\n", i, result_LCG);
        //printf("Itération %d = %04f\n", i, NewResult_LCG);

        if (NewResult_LCG < 0.1)
            comp1++;
        else if (NewResult_LCG >= 0.1 && NewResult_LCG < 0.2)
            comp2++;
        else if (NewResult_LCG >= 0.2 && NewResult_LCG < 0.3)
            comp3++;
        else if (NewResult_LCG >= 0.3 && NewResult_LCG < 0.4)
            comp4++;
        else if (NewResult_LCG >= 0.4 && NewResult_LCG < 0.5)
            comp5++;
        else if (NewResult_LCG >= 0.5 && NewResult_LCG < 0.6)
            comp6++;
        else if (NewResult_LCG >= 0.6 && NewResult_LCG < 0.7)
            comp7++;
        else if (NewResult_LCG >= 0.7 && NewResult_LCG < 0.8)
            comp8++;
        else if (NewResult_LCG >= 0.8 && NewResult_LCG < 0.9)
            comp9++;
        else
            comp10++;
    }

    printf("\n");
    printf("Nombre de valeurs sur [0.0 - 0.1[ = %d sur %d tirages\n", comp1, nb_iterations);
    printf("Nombre de valeurs sur [0.1 - 0.2[ = %d sur %d tirages\n", comp2, nb_iterations);
    printf("Nombre de valeurs sur [0.2 - 0.3[ = %d sur %d tirages\n", comp3, nb_iterations);
    printf("Nombre de valeurs sur [0.3 - 0.4[ = %d sur %d tirages\n", comp4, nb_iterations);
    printf("Nombre de valeurs sur [0.4 - 0.5[ = %d sur %d tirages\n", comp5, nb_iterations);
    printf("Nombre de valeurs sur [0.5 - 0.6[ = %d sur %d tirages\n", comp6, nb_iterations);
    printf("Nombre de valeurs sur [0.6 - 0.7[ = %d sur %d tirages\n", comp7, nb_iterations);
    printf("Nombre de valeurs sur [0.7 - 0.8[ = %d sur %d tirages\n", comp8, nb_iterations);
    printf("Nombre de valeurs sur [0.8 - 0.9[ = %d sur %d tirages\n", comp9, nb_iterations);
    printf("Nombre de valeurs sur [0.9 - 1.0[ = %d sur %d tirages\n", comp10, nb_iterations);
}

int LongueurCycle(int Iterations, int result_LCG_init)
{
    int i = 0;
    int compteur = 0;
    int NewVal = 0;

    int valeur = LCG(15, 9, BITS_16, result_LCG_init); //  Valeur de début de cycle
    printf("Valeur = %d\n\n", valeur);

    for (i; i < Iterations; i++)
    {
        NewVal = LCG(15, 9, BITS_16, NewVal);
        printf("Itération %d = %d\n", i, NewVal);
        compteur++;
        if (i > 1 && valeur == NewVal)
        {
            return compteur - 2;
        }
    }
}

// ----------------------- Exercice 4 -----------------------

/************************************************************
 *    Représentation des indices desnombres biniare (ici)
 *    ---------------------------------------------------
 * 
 *      Un nombre binaire sur 4 bits :
 *          1   0   1   0   =   10 (décimal)
 *      Indice position :
 *          3   2   1   0
 *
 ************************************************************/

//  Générateur de type LFSR
int LFSR_generator(int nombre)
{

    int new_nombre;

    //  Valeur du bit n°0
    int val_bit_0 = (nombre >> 0) & 1;

    //  Valeur du bit n°1
    int val_bit_1 = (nombre >> 1) & 1;

    //  Résultat du XOR
    int xor = val_bit_0 ^ val_bit_1;

    new_nombre = nombre >> 1;

    if (xor == 1)
    {
        new_nombre = (1 << 3) | new_nombre;
    }
    else
    {
        new_nombre = new_nombre & (~(1 << 3));
    }

    return new_nombre;
}

//  Affiche un nombre décimal en binaire (sur 4 bits)
int dec_to_bin(int nb_dec)
{
    int i, j;

    for (i = 3; i >= 0; i--)
    {
        j = nb_dec >> i;

        if (j & 1)
            printf("1");
        else
            printf("0");
    }
}

// ----------------------- Exercice 6 -----------------------

//  Permet de compter l'apparaition des nombres pour un LCG sur 16 bits
void compteur_6(int *tab, int longueur, int iterations)
{
    int i;

    int comp1 = 0; //  [0 - 10 000[
    int comp2 = 0; //  [10 000 - 20 000[
    int comp3 = 0; //  [20 000 - 30 000[
    int comp4 = 0; //  [30 000 - 40 000[
    int comp5 = 0; //  [40 000 - 50 000[
    int comp6 = 0; //  [50 000 - 60 000[
    int comp7 = 0; //  [60 000 - 70 000[
    int comp8 = 0; //  [70 000 - 80 000[

    for (i = 0; i < longueur; i++)
    {
        if (tab[i] < 8192)
            comp1++;
        else if (tab[i] >= 8192 && tab[i] < 16384)
            comp2++;
        else if (tab[i] >= 16384 && tab[i] < 24576)
            comp3++;
        else if (tab[i] >= 24576 && tab[i] < 32768)
            comp4++;
        else if (tab[i] >= 32768 && tab[i] < 40960)
            comp5++;
        else if (tab[i] >= 40960 && tab[i] < 49152)
            comp6++;
        else if (tab[i] >= 49152 && tab[i] < 57344)
            comp7++;

        else
        {
            comp8++;
        }
    }

    printf("Nombre de valeurs sur [0 - 8 192[ = %d sur %d tirages\n", comp1, iterations);
    printf("Nombre de valeurs sur [8 192 - 16 384[ = %d sur %d tirages\n", comp2, iterations);
    printf("Nombre de valeurs sur [16 384 - 24 576[ = %d sur %d tirages\n", comp3, iterations);
    printf("Nombre de valeurs sur [24 576 - 32 768[ = %d sur %d tirages\n", comp4, iterations);
    printf("Nombre de valeurs sur [32 768 - 40 960[ = %d sur %d tirages\n", comp5, iterations);
    printf("Nombre de valeurs sur [40 960 - 49 152[ = %d sur %d tirages\n", comp6, iterations);
    printf("Nombre de valeurs sur [49 152 - 57 344[ = %d sur %d tirages\n", comp7, iterations);
    printf("Nombre de valeurs sur [57 344 - 65 536[ = %d sur %d tirages\n", comp8, iterations);
}
