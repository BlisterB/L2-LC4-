#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]){
  float somme = 0;
  
  int i;
  for(i = 1; i < argc; i++){
    somme += atof(argv[i]);
  }
  printf("La somme des nombres entres en parametre est %f\n", somme);
}
