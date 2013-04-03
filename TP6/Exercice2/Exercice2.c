#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Q6
void init_tab(int *tab, int n, int val){
  int* ptr = malloc(n*sizeof(int));
  int i;
  for(i = 0; i < n; i++){
    ptr[i] = val;
  }
  memcpy(tab, ptr, n*sizeof(int));
}

//Q7
void init_tab_bis(int *tab, int n, int val){
  //En fait la fonction remplie bien le tableau mais pas avec la valeur entiere correspondante (elle le met en char)

  //Peut on vraiment la coder avec memset ?
  memset(tab, val, n*sizeof(int));
  int i = 0;
  for(i = 0; i < n; i++){
    printf("%d\n", tab[i]);
  }
}

void caddoc_bis(int *tab, int n){
  memset(tab, 0, n*sizeof(int));
}


///MAIN
main(){
  //Q6
  int tab[10];
  init_tab(tab, 10, 5);

  //Q6
  init_tab_bis(tab, 10, 0);
}
