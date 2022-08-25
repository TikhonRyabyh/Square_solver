#include <math.h>

#include "breakers.h"
#include "help_functions.h"

int cmp_for_double ( double x, double y ) {
	
	program_breaker( isfinite( x ) );
	program_breaker( isfinite( y ) );

	return ( fabs( x - y ) < EPSILON );
}
