// bit_array.h
// Řešení IJC-DU1, příklad a), 09.03.2019
// Autor: Peter Vinarcik, xvinar00, FIT
// Přeloženo: gcc 5.4.0
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "error.h"

typedef unsigned long bit_array_t[];

/**
 * Makro vytvori bitove pole o zadanej velkosti a do prveho indexu ulozi velkostp ola v bitoch
 *
 * @param jmeno_pole Nazov pola, ktore ma byt vytvorene
 * @param velikost Velkost pola v bitoch
 *
 */
#define bit_array_create(jmeno_pole, velikost) unsigned long jmeno_pole[(velikost % (CHAR_BIT*sizeof(unsigned long)) == 0) ? \
                                                                        velikost / (CHAR_BIT*sizeof(unsigned long)) + 1 : \
                                                                        velikost / (CHAR_BIT*sizeof(unsigned long)) + 2] = {velikost}; \
                                                                        static_assert(velikost > 0, "bit_array_create: Velikost musi byt vacsia ako 0")

/**
 * Makro vytvori bitove pole o zadanej velkosti a do prveho indexu ulozi velkost pola v bitoch
 * Makro je dynamicky alokovane
 *
 * @param jmeno_pole Naozv pola, ktore ma byt naalokovane
 * @param velikost Velkost pola v bitoch
 *
 */
#define bit_array_alloc(jmeno_pole, velikost) unsigned long *jmeno_pole = calloc((velikost % (CHAR_BIT*sizeof(unsigned long)) == 0) ? \
                                                                        velikost / (CHAR_BIT*sizeof(unsigned long)) + 1 : \
                                                                        velikost / (CHAR_BIT*sizeof(unsigned long)) + 2,sizeof(unsigned long)); \
                                                                        *jmeno_pole = velikost; \
                                                                        assert(velikost > 0); \
                                                                        if (jmeno_pole == NULL) \
                                                                            fprintf(stderr, "bit_array_alloc: Chyba alokace paměti\n")

/**
 * Makro uvolni pamat naalokovanu makrom bit_array_alloc
 *
 * @param jmeno_pole Nazov pola, ktore ma byt dealokovane
 *
 */

#define bit_array_free(jmeno_pole) free(jmeno_pole)

#ifndef USE_INLINE

/**
 * Makro, ktore vrati deklarovanu velkost pola v bitoch (ulozenu v poli)
 *
 * @param jmeno_pole Nazov pola, ktoreho velkost v bitoch chceme zistit
 *
 */
#define bit_array_size(jmeno_pole) jmeno_pole[0]

/**
 * Makro, ktore nastavi bit na vybranom indexe
 * Ak je bit nulovy nastavi na nulu ak nenulovy bit == 1
 *
 * @param jmeno_pole Meno pola, ktore bude modifikovane
 * @param index Index pola, kde bude bit nastaveny
 * @param vyraz Nenulovy vyraz bit == 1 inak bit == 0
 *
 */
#define bit_array_setbit(jmeno_pole, index, vyraz) \
if (index < 0 || index > jmeno_pole[0]-1) { \
    (error_exit("bit_array_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, jmeno_pole[0]-1)); \
}  \
                                                    if (vyraz != 0) {jmeno_pole[(index/(CHAR_BIT*sizeof(unsigned long)))+1] |= ((unsigned long)1 << (index%(CHAR_BIT*sizeof(unsigned long))));} \
                                                    else            {jmeno_pole[(index/(CHAR_BIT*sizeof(unsigned long)))+1] &= ~((unsigned long)1 << (index%(CHAR_BIT*sizeof(unsigned long))));};

/**
 * Makro ktore ziska hodnota z pola na danom indexe
 *
 * @param jmeno_pole Meno pola, z ktore bude index precitany
 * @param index Index pola na ktorom sa dany bit nachadza
 *
 */
#define bit_array_getbit(jmeno_pole, index) (jmeno_pole[(index/(CHAR_BIT*sizeof(unsigned long)))+1] & ((unsigned long)1 << (index%(CHAR_BIT*sizeof(unsigned long))))) \

#else

extern inline unsigned long bit_array_size(bit_array_t jmeno_pole)
{
    return jmeno_pole[0];
}

extern inline void bit_array_setbit(bit_array_t jmeno_pole, unsigned long index, unsigned long vyraz)
{
    if (index < 0 || index > jmeno_pole[0]-1) {
        (error_exit("bit_array_setbit: Index %lu mimo rozsah 0..%lu\n", index, jmeno_pole[0]-1));
    }
    if (vyraz) {
        jmeno_pole[(index/(CHAR_BIT*sizeof(unsigned long)))+1] |= ((unsigned long)1 << (index%(CHAR_BIT*sizeof(unsigned long))));
    }
    else{
        jmeno_pole[(index/(CHAR_BIT*sizeof(unsigned long)))+1] &= ~((unsigned long)1 << (index%(CHAR_BIT*sizeof(unsigned long))));
    }
}

extern inline unsigned long bit_array_getbit(bit_array_t jmeno_pole, unsigned long index)
{
    if (index < 0 || index > jmeno_pole[0]-1) {
        (error_exit("bit_array_getbit: Index %lu mimo rozsah 0..%lu\n", index, jmeno_pole[0]-1));
    }
    return jmeno_pole[(index/(CHAR_BIT*sizeof(unsigned long)))+1] & ((unsigned long)1 << (index%(CHAR_BIT*sizeof(unsigned long))));
}

#endif