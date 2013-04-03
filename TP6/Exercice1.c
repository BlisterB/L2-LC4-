#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct traduction traduction;
struct traduction { char *a; char *b;};

traduction dico[];
int n;//Taille du dico

////METHODES

char *recherche(struct traduction *dico, int n, char *s){
  int debut, fin, pivot;
  debut = 0; fin = n-1;
  while(debut > fin){
    pivot = (fin - pivot)/2;
    if(!strcmp(s, dico[pivot])){ //le mot est egal au mot recherché
      return dico[pivot];
    }
    else{
      if(motAEstAvantB(s, dico[pivot]))
	fin = pivot;
      else
	debut = pivot;
    }
  }
  return NULL;
}

int motAEstAvantB(char *s a, char *s b){
  
}

main(){

}
