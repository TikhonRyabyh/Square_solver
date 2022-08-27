#include <stdio.h>
#include <stdlib.h>

#include "data_list.h"
#include "breakers.h"

int clean_list( data_list_st* entries ) {
	func_breaker( entries != NULL ); 

	data_list_st* intermed = NULL;

	while( entries != NULL ) {
		intermed = entries->next;

		free( entries );

		entries = intermed;
	}

	return 0;
}
