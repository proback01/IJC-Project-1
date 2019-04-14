// ppm.c
// Řešení IJC-DU1, příklad a), 09.03.2019
// Autor: Peter Vinarcik, xvinar00, FIT
// Přeloženo: gcc 5.4.0
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ppm.h"
#include "error.h"
#include "bit_array.h"
#include "eratosthenes.h"

struct ppm * ppm_read(const char * filename)
{
    FILE* LoadPic = fopen(filename, "rb");
    if (LoadPic == NULL){
        error_exit("Chyba pri nacitani suboru.\n");
    }

    unsigned xsize;
    unsigned ysize;
    unsigned control;

    int c;
    int d;
    c = fgetc(LoadPic);
    d = fgetc(LoadPic);
    if (c != 'P' || d != '6'){
        fclose(LoadPic);
        error_exit("Zly format textu v subore\n");
    }
    fscanf(LoadPic, "%u", &xsize);
    fscanf(LoadPic, "%u", &ysize);
    fgetc(LoadPic);
    fscanf(LoadPic, "%u", &control);
    if (xsize > 8000 || ysize > 8000 || control != 255){
        fclose(LoadPic);
        warning_msg("Zle zadane hodnoty vo vnutornom kodovani obrazka!\n");
        return NULL;
    }
    fgetc(LoadPic);

    struct ppm *pic = malloc(sizeof(struct ppm)+3*xsize*ysize);
    pic->xsize = xsize;
    pic->ysize = ysize;

    unsigned long read;
    if((read = fread(pic->data, 1, 3*xsize*ysize, LoadPic)) != 3*xsize*ysize){
        free(pic);
        fclose(LoadPic);
        warning_msg("Pocet nacitanych veci %lu sa nezhoduje s poctom ocakavanych %lu.\n", read, 3*xsize*ysize);
        return NULL;
    }

    fclose(LoadPic);

    return pic;
}

void ppm_free(struct ppm *p)
{
    free(p);
}
