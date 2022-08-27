#include <math.h>

#include "help_functions.h"

int cmp_for_double ( double x, double y ) {
	
	if( !( isfinite( x ) ) ) {
		
		if( !( isfinite( y ) ) )
			return 1;

		return 0;
	}

	return ( fabs( x - y ) < EPSILON );

}
