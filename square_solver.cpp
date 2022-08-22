#include <stdio.h>
#include <math.h>

#define EPSILON 1e-3

void greeting ( void ) {
	printf( "This program solves quadratic equations. Equation should be like this: ax^2 + bx + c = 0.\n" );

}

int input ( double* a, double* b, double* c ) {
	printf( "Please enter a, b, c ( with spaces ):\n" );

	int fields = 0;

	fields = scanf( "%lf %lf %lf", a, b, c );
	if( fields == 3 )
		return 0;

	printf( "Incorrect data: you should enter three real numbers.\n" );
	return 1;
}

int cmp_for_double ( double x, double y ) {
	return ( fabs( x - y ) < EPSILON );
}

void equation_solver ( const double a, const double b, const double c, double* x1, double* x2, int *n ) {
	if( cmp_for_double( a, 0 ) ) {
		if( cmp_for_double( b, 0 ) ) {
			if( cmp_for_double( c, 0 ) ) {
				( *n ) = -1;
				return;
			}
			( *n ) = 0;
			return;
		}
		( *n ) = 1;

		( *x1 ) = - c / b;
		if( cmp_for_double( *x1, 0 ) )
			( *x1 ) = 0;

		return;
	}

	double D = b * b - 4 * a * c;

	if( D < 0 ) {
		( *n ) = 0;
		return;
	}

	( *n ) = 2;

	( *x1 ) = - ( b + sqrt( D ) ) / ( 2 * a );
	if( cmp_for_double( *x1, 0 ) )
			( *x1 ) = 0;

	( *x2 ) = - ( b - sqrt( D ) ) / ( 2 * a );
	if( cmp_for_double( *x2, 0 ) )
			( *x2 ) = 0;

	return;
}

void output ( const double x1, const double x2, const int n ) {
	if( !n ) {
		printf( "Result: no roots.\n" );
		return;
	}
	if( n == -1 ) {
		printf( "Result: infinity roots.\n" );
		return;
	}
	if( n == 1 ) {
		printf( "Result: x = %.3lf.\n", x1 );
		return;
	}
	if( n == 2 ) {
		printf( "Result: x1 = %.3lf, x2 = %.3lf.\n", x1, x2 );
		return;
	}
}

int main ( void ) {
	greeting();

	int errors = 0; // 0 - no errors or correct data, 1 - incorrect data or there are some errors
	double a = 0, b = 0, c = 0;

	errors = input( &a, &b, &c );
	if( errors )
		return 1;

	int n = 0; // -1 - infinity roots, 0 - no roots, 1 - one root etc.
	double x1 = 0, x2 = 0;

	equation_solver( a, b, c, &x1, &x2, &n );
	output( x1, x2, n );

	return 0;
}
