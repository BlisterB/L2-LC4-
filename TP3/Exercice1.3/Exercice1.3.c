#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aaa (char *s){
  while (*s) *(s++) = 'A';
}

main(){
  int *t = malloc(3*sizeof(int));
  printf("&t : %p\n", &t);
  printf("&(t[0]) : %p\n", &(t[0]));
  printf("&(t[1]) : %p\n", &(t[1]));
  printf("t : %p\n", t);
  printf("t+1 : %p\n", t+1);
  
  char *s = malloc(10*sizeof(char));
  strcpy(s, "hello");
  aaa(s);
  printf("%s", s);
  
}
