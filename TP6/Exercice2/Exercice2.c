#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_tab(int *tab, int n, int val){
  int i;
  int* ptr = malloc(n*sizeof(int));
  for(i = 0; i < n; i++){
    ptr[i] = val;
  }
  memcpy(tab, ptr, n*sizeof(int));}

main(){
  int tab[10];
  init_tab(tab, 10, 5);
}
