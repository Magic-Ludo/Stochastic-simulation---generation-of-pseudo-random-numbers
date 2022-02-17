#include <stdio.h>
#include <math.h>

#define NB_INIT 15  //  doit etre <= 15

int LFSR_generator(int nombre);
int dec_to_bin(int nb_dec);

int main() {

    int i;
    int nb_test = 15;
    for (i = 0; i <= pow(2,4)-1; i++) {
        dec_to_bin(nb_test);
        nb_test = LFSR_generator(nb_test);
    }

    return 0;
}

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

int LFSR_generator(int nombre) {

    int new_nombre;

    //  Valeur du bit n°0
    int val_bit_0 = (nombre >> 0) & 1;

    //  Valeur du bit n°1
    int val_bit_1 = (nombre >> 1) & 1;

    //  Résultat du XOR
    int xor = val_bit_0 ^ val_bit_1;

    new_nombre = nombre >> 1;

    if (xor == 1) {
        new_nombre = (1 << 3) | new_nombre;
    }
    else {
        new_nombre = new_nombre & (~(1 << 3));
    }
    
    return new_nombre;
}

//  Affiche un nombre décimal en binaire (sur 4 bits)
int dec_to_bin(int nb_dec) {
    int i, j;

    for (i = 3; i >= 0; i--) {
    j = nb_dec >> i;

    if (j & 1)
      printf("1");
    else
      printf("0");
  }

  printf("\n");
}