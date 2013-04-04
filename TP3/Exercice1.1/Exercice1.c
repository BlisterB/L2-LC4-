#include <stdio.h>
#include <stdlib.h>

#define affiche_nbr(a) printf("p (%lu)\n", a, (unsigned long)a)

char gc1 = '1',gc2 = '2';
int gi1 = 1, gi2 = 2;
int *gp1 = NULL, *gp2 = NULL;

void f1(int *p){
  int i1 = 7;
  char c1 = 'A';

  printf("\nFonction void f1(int*p) :\nContenu de l'adresse pointee par le parametre p : %d\nValeur de p : %p\nAdresse de p : %p\n", *p, p, &p);
  printf("\nModifions la valeur de l'entier pointé par p (mettons la a 5)");
  *p = 5;
  printf("\nContenu de l'adresse pointee par le parametre p : %d\nValeur de p : %p\nAdresse de p : %p\n", *p, p, &p);
  p = NULL;
  static int n = 9;
  printf("Adresse de n (qui est static) : %p", &n);
  n++;
}

void f2(int *p){
  int i1, i2;

  printf("\nFonction f2 :\nAdresse du parametre *p : %p\nAdresse de i1 : %p\nAdresse de i2 : %p\nContenu de i1 : %d\nContenu de i2 : %d\n", &p, &i1, &i2, i1, i2);

  f1(p);
}

main(){
  char lc1 = 'c', lc2 = 'c';
  int li1 = 1, li2 = 2;
  int *lp1 = NULL, *lp2 = NULL;

  printf("\n");
  printf("Variables Globales :\ngc1 : %p \ngc2 : %p \ngi1 : %p \ngi2 : %p \ngp1 : %p \ngp2 : %p\n", &gc1, &gc2, &gi1, &gi2, &gp1, &gp2);
  printf("Variables Locales :\nlc1 : %p \nlc2 : %p \nli1 : %p \nli2 : %p \nlp1 : %p \nlp2 : %p\n", &lc1, &lc2, &li1, &li2, &lp1, &lp2);

  //Question 3
  printf("\nsizeof(int) : %lu, sizeof(char) : %lu, sizeof(int *) : %lu\n", sizeof(int), sizeof(char), sizeof(int *));

  //Question 5
  lp1 = &li1;
  printf("%p", &lp1);
  f1(lp1);

  //Question 6
  f2(lp1);
}
