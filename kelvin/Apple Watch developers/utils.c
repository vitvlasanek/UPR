#include "utils.h"

void utils_out_of_memory( const char *filename, const int lineno ) {

    fprintf( stderr, "Oops! Out of memory (%s:%i)\n", filename, lineno );
    exit( -1 );

} //utils_out_of_memory

void utils_not_implemented( const char *filename, const int lineno )
{
    fprintf( stderr, "Oops! Method not implemented (%s:%i)\n", filename, lineno );
    exit( -1 );
} //utils_not_implemented


int compare_greater( const void * a, const void * b )
{
    if ( *(float*)a >  *(float*)b ) return -1;
    if ( *(float*)a == *(float*)b ) return  0;
    if ( *(float*)a <  *(float*)b ) return  1;
    else return 0;
} //compare_greater


int compare_less( const void * a, const void * b )
{
    if ( *(float*)a <  *(float*)b ) return -1;
    if ( *(float*)a == *(float*)b ) return  0;
    if ( *(float*)a >  *(float*)b ) return  1;
    else return 0;
} //compare_less