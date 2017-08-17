// Elaborado por Adrian Alvarado Ramirez.

#include <stdlib.h>
#include <stdio.h>

// Recibe un puntero de enteros, la cantidad de elementos que lo componen, 
// y los imprime
void imprimir(int* arreglo, int cantidad){
	for(int i = 0; i < cantidad; i++){
		printf("[%i] -> = %i\n",i,arreglo[i]); 
	}	
}

// Un ejemplo de abrir un archivo con la modalidad append.
void guardar_en_archivo(int *arreglo, int cantidad){
	FILE* archivo = fopen("log.txt","a");	
	fputs("\nIniciando salida\n",archivo);
	if(archivo != NULL){
		for(int i = 0; i < cantidad; i++){
			char hilera[25];
			int res = sprintf(hilera, "[%i] -> = %i\n", i, arreglo[i]);
			if(res > 0){
				fputs(hilera,archivo);
			}
		}
	fputs("Salida finalizada",archivo);
	fclose(archivo); // Cierra el archivo.
	}
}

int main(int argc, char** argv){
	int* arreglo_enteros;	

	// Solicita memoria para almacenar 100 enteros.
	// para ello, multiplica 100 (bytes) por la cantidad de bytes
	// que usa un entero, esto mediante el operador sizeof
	arreglo_enteros = malloc(100 * sizeof(int));

	// Se llena con los numeros del 1 al 100
	for(int i = 1; i <= 100; i++){
		arreglo_enteros[i-1] = i;
	}	

	imprimir(arreglo_enteros, 100);

	// Otra manera de llenarlos, usando aritmetica de punteros.
	int* actual;

	actual = arreglo_enteros;

	// Se hace mediante la des-referencia
	for(int i = 100; i > 0; i--){
		*actual = i;
		actual++; // Con esto se incrementa el puntero a la siguiente posicion en memoria
		// del siguiente entero.
	}

	imprimir(arreglo_enteros, 100);
	guardar_en_archivo(arreglo_enteros, 100);


	// Se debe liberar la memoria
	free(arreglo_enteros);

	return EXIT_SUCCESS;
}
