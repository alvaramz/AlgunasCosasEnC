/*

Para compilar correctamente en windows (LOS MODIFICADORES DEL PRINTF SON DIFERENTES)
gcc test.c -o test.exe -std=c99 -D__USE_MINGW_ANSI_STDIO=1

En este caso el problema se da con el modificador %zu.

*/

#include <stdlib.h>
#include <stdio.h>

int main(void){
	double A[5] = {
		[0] = 9.0,
		[1] = 2.9,
		[4] = 3.E+25,
		[3] = .0007,
	};
	
	for(size_t i = 0; i < 5; ++i){
		printf("element %zu is %g, \tits square is %g\n",
			i,
			A[i],
			A[i]*A[i]);
	}
	
	return EXIT_SUCCESS;
}