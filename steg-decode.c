//
// Created by vinco on 9.3.19.
//

#include "ppm.h"
#include "error.h"
#include "bit_array.h"
#include "eratosthenes.h"

int main(int argc, char *argv[])
{
    if (argc == 2) {
        struct ppm * printPic;
        printPic = ppm_read(argv[1]);

        if (printPic == NULL){
            error_exit("Chybny format suboru\n");
        }

        bit_array_alloc(p,3*printPic->xsize*printPic->ysize);
        Eratosthenes(p);

        int counter = 0;
        char toprint = 0;
        for (unsigned long i = 19; i < bit_array_size(p)-1; i++){
            if (!bit_array_getbit(p,i)){
                if (counter < 8){
                    if (printPic->data[i] & 1) {
                        toprint |= (printPic->data[i] & 1) << counter;
                    }
                    else {
                        toprint &= ~((printPic->data[i] & 1) << counter);
                    }
                    counter++;
                }
                if (toprint == '\0' && counter == 8){
                    break;
                }
                if (counter == 8){
                    printf("%c", toprint);
                    counter = 0;
                    toprint = 0;
                }
            }
        }
        printf("\n");

        ppm_free(printPic);
        bit_array_free(p);

        return 0;
    }
    else{
        error_exit("Zle zadane argumenty!\n");
    }
}
