//
// Created by vinco on 18.3.19.
//

#include "bit_array.h"

#ifdef USE_INLINE

extern inline unsigned long bit_array_size(bit_array_t jmeno_pole);

extern inline void bit_array_setbit(bit_array_t jmeno_pole, unsigned long index, unsigned long vyraz);

extern inline unsigned long bit_array_getbit(bit_array_t jmeno_pole, unsigned long index);

#endif