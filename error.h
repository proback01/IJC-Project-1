// error.h
// Řešení IJC-DU1, příklad a), 09.03.2019
// Autor: Peter Vinarcik, xvinar00, FIT
// Přeloženo: gcc 5.4.0
//

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * Funkcia, ktora
 * @param fmt
 * @param ...
 */
void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);