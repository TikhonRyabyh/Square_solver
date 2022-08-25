#include <stdio.h>
#include <math.h>

#include "square_solver.h"
#include "breakers.h"

int output ( const double x1, const double x2, const int n ) {
	
	func_breaker( n != ERROR );
	
	if( !n ) {
		printf( "Result: no roots.\n" );
		return 0;
	}
	if( n == INFINITY_ROOTS ) {
		printf( "Result: infinity roots.\n" );
		return 0;
	}
	if( n == 1 ) {
		func_breaker( isfinite( x1 ) );
		
		printf( "Result: x = %.3lf.\n", x1 );
		return 0;
	}
	if( n == 2 ) {
		func_breaker( isfinite( x1 ) );
		func_breaker( isfinite( x2 ) );

		printf( "Result: x1 = %.3lf, x2 = %.3lf.\n", x1, x2 );
		return 0;
	}

	printf( "Error: n has another value.\n" );
	return 1;
}
