// primes.c
// Řešení IJC-DU1, příklad a), 09.03.2019
// Autor: Peter Vinarcik, xvinar00, FIT
// Přeloženo: gcc 5.4.0
//

#include <stdio.h>
#include <string.h>

#include "error.h"
#include "eratosthenes.h"

int main()
{
    unsigned long toPrint[10];

    bit_array_create(p, 123000000);
    Eratosthenes(p);
    int counter = 10;
    for (unsigned long i = bit_array_size(p)-1; i > 2; i--) {
        if (!bit_array_getbit(p, i)) {
            toPrint[counter-1] = i;
            counter--;
        }
        if (counter == 0)
            break;
    }

    for (int i = 0; i < 10; i++){
        printf("%lu\n", toPrint[i]);
    }

    return 0;
}
