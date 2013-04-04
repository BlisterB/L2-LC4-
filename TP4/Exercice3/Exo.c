#include <stdio.h>
#include <stdlib.h>

char *recherche(char *s, char c){
  while(*s){
    if(*s == c)
      return s;
    else
      s++;
  }
  return NULL;
}

int compte(char *s, char c){
  int compteur = 0;
  while(*s){
    if(*s == c) compteur++;
    s++;
  }
  return compteur;
}

main(){
  char chaine[] = "Il était une fois\n";
  printf("%s", chaine);

  //Question 1
  char *pchar = chaine;
  printf("%p %p\n", &chaine, pchar);
  char *pOccurenceC = recherche(pchar, 'o');
  printf("%p\n", pOccurenceC);
  printf("Il y a %d occurrence(s) de t dans la chaine\n", compte(pchar, 't'));
}
