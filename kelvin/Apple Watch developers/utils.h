#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>

#define ALLOCTEST( x ) if ( ( !x ) ) utils_out_of_memory( __FILE__, __LINE__ )

void utils_out_of_memory( const char *filename, const int lineno );
void utils_not_implemented( const char *filename, const int lineno );

int compare_greater( const void * a, const void * b );
int compare_less( const void * a, const void * b );

#endif //_UTILS_H_