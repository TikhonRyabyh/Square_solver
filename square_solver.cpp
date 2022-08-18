#include <stdio.h>
#include <math.h>

int main ( void ) {
	printf( "This program solves quadratic equations. Equation should be like this: ax^2 + bx + c = 0.\n" );
	double a, b, c;
	printf( "Please enter a, b, c ( with spaces ):\n" );
	scanf( "%lf %lf %lf", &a, &b, &c );
	if( !a ) {
		if( !b ) {
			if( !c ) {
				printf( "Result: infinity roots.\n" );
				return 0;
			}
			printf( "Result: no roots.\n" );
			return 0;
		}
		printf( "Result: x = %.3lf.\n", - ( c / b ) );
		return 0;
	}
	double D = b * b - 4 * a * c;
	if( D < 0 ) {
		printf( "Result: no roots.\n" );
		return 0;
	}
	printf( "Result: x1 = %.3lf, x2 = %.3lf.\n", - ( b + sqrt( D ) ) / ( 2 * a ), - ( b - sqrt( D ) ) / ( 2 * a ) );
	return 0;
}
