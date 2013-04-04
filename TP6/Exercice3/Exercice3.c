#include <stdio.h>
#include <stdlib.h>
#include "Exercice3.h"
#include <math.h>

//Q8
double valeur_polynome(int n, polynome *P){
  int i, somme = 0;
  for(i=0; i < P->degre;i++){
    somme +=  (P->coefficients[i]) * pow(n, (double)i);
  }
  return somme;
}


main(){
  double coefP[5] = {1, 2, 3, 4, 5};
  polynome P = {5, coefP};


  double coefQ[5] = {2, 3, 4, 5, 6};
  polynome Q = {5, coefQ};

  //Q8
  printf("%f", valeur_polynome(5, &P));
}
