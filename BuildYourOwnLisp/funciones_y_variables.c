#include <stdio.h>

int suma_enteros(int a, int b){
  return a + b;
}

int main(int argc, char** argv){
  int ent1 = 5;
  int ent2 = 7;

  int res = suma_enteros(ent1, ent2);
  printf("El resultado es: %d",res);

  return 0;
}
