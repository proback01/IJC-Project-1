// ppm.h
// Řešení IJC-DU1, příklad a), 09.03.2019
// Autor: Peter Vinarcik, xvinar00, FIT
// Přeloženo: gcc 5.4.0
//

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[]; // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);   //načte obsah PPM souboru do touto funkcí dynamicky alokované struktury.
                                                // Při chybě formátu použije funkci warning_msg a vrátí NULL.
                                                // Pozor na "memory leaks".

void ppm_free(struct ppm *p); //uvolní paměť dynamicky alokovanou v ppm_read