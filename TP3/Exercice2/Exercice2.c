#include <stdio.h>
#include <stdlib.h>

//STRUCTURES

struct st3 { 
  int a, b, c; 
};

//TYPEDEF
typedef struct st3 st3;
typedef struct st3 *pst3;

//METHODES
pst3 clone_st3(pst3 pst){
  //Affichage des adresse des champs du st3 pointé par pst
  int* pst2 = (int *) pst;//Pour parcourir les champs de st on doit faire un cast de pointeur sur INT
  //Car pst est un pointeur de structure st, donc pst +1 incremente de sizeof(ST3) et pas sizeof(st) !!
  printf("FONCTION CLONE_ST3\n&st.a = %p\n&st.b = %p\n&st.c = %p\n\nSORTIE DE CLONE_ST3\n", pst2, pst2 + 1, pst2 + 2);

  st3 stBis = {*pst2, *(pst2 + 1), *(pst2 +2)};
  st3* pstBis = &stBis;
  return pstBis;
}

main(){
  st3 st = {1, 2, 3};
  int *t = (int *) &st;

  printf("&st : %p\n&st.a : %p\n&st.b : %p\n&st.c : %p\n", &st, &st.a, &st.b, &st.c);

  //Question 19
  //Appel de clone_st3
  pst3 pst = &st;
  st3 stBis = *clone_st3(pst);
  printf("stBis.a = %d, stBis.b = %d, stBis.c = %d\n", stBis.a, stBis.b, stBis.c);

  //Question 20
  st3 tab[10];
  int i;
  for(i = 0; i < 10; i++){
    printf("Case numero %d :\na : %p\nb : %p\nc : %p\n", i, &(tab[i].a), &(tab[i].b), &(tab[i].c));
  }

  //Question 21
  pst3 tabp[10];
  //On affecte les cases du tableau
  for(i = 0; i < 10; i++){
    tabp[i] = malloc(sizeof(st3));
  }
  //On les affiche
  printf("\nAdresse du tableau de pst3 : %p\n", &tabp);
  for(i = 0; i < 10; i++){
    printf("Case numero %d à l'adresse %p :\na : %p\nb : %p\nc : %p\n", i, &tabp[i], tabp[i], ((int*)tabp[i]) +1, ((int*)tabp[i]) +2);
  }
}
