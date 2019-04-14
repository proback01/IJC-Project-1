// error.c
// Řešení IJC-DU1, příklad a), 09.03.2019
// Autor: Peter Vinarcik, xvinar00, FIT
// Přeloženo: gcc 5.4.0
//

#include "error.h"

void warning_msg(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void error_exit(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}