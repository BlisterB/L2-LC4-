#include <stdio.h>
#include <stdlib.h>

main(){
  printf("Adresse renvoyee par malloc(1)  : %p\n", malloc(1));
  printf("Adresse renvoyee par malloc(2)  : %p\n", malloc(2));
  printf("Adresse renvoyee par malloc(12) : %p\n", malloc(12));
  printf("Adresse renvoyee par malloc(13) : %p\n", malloc(13));
}
