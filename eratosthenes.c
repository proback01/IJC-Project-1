// eratosthenes.c
// Řešení IJC-DU1, příklad a), 09.03.2019
// Autor: Peter Vinarcik, xvinar00, FIT
// Přeloženo: gcc 5.4.0
//

#include <math.h>

#include "eratosthenes.h"

void Eratosthenes(bit_array_t pole)
{
    for (unsigned long i = 2; i < bit_array_size(pole); i+=2){
        if(!bit_array_getbit(pole, i)){
            bit_array_setbit(pole, i, 1);
        }
    }

    for (unsigned long i = 3; i < sqrt(bit_array_size(pole)); i+=2){
        if(!bit_array_getbit(pole, i)){
            for (unsigned long n = 3; n*i < bit_array_size(pole); n+=2){
                bit_array_setbit(pole, n*i, 1);
            }
        }
    }
}
