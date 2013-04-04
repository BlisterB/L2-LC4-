#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  printf("Vous avez entré %d arguments\n", argc - 1);
  printf("Les arguments que vous avez entré son :\n");

  if(argc > 0){
    int i;
    for(i = 1; i < argc; i++){
      printf("%s\t", argv[i]);
    }
  }
  printf("\n");
}
