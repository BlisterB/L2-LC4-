#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct traduction traduction;
struct traduction{
  char *a; 
  char *b;
};

char *recherche(traduction *dico, int n, char *s){
  int debut = 0, fin = n-1, pivot, test;
  while(debut<=fin){
    pivot = (debut+fin)/2;
    test = strcmp(dico[pivot].a, s);
    //Le pivot contient le mot
    if(test == 0){
      return dico[pivot].b;
    }
    //Le pivot est superieur au mot
    else if(test > 0){
      fin = (pivot-1);
    }
    //Le pivot est inferieur au mot
    else if(test < 0){
      debut = (pivot+1);
    }
  }
  return NULL;
}

int nombre_espace(char *s){
  int compteur = 0;
  while(*s){
    if(*s == ' '){
      compteur++;
    }
    s++;
  }
  return compteur;
}

int nombre_caracteres_avant_espace(char *s){
  int compteur = 0;
  while(*s && *s!= ' ' && *s != '\0'){
    compteur++;
    *s++;
  }
  return compteur;
}

char** decoupe(char *s){
  int taille = nombre_espace(s) + 2;
  char** tab = malloc(taille*sizeof(char*));
  int i;
  for(i = 0; i < taille; i++){
    int tailleSousChaine = nombre_caracteres_avant_espace(s);
    tab[i] = malloc(taille*sizeof(char*));
    strncpy(tab[i], s, tailleSousChaine);
    s+=tailleSousChaine + 1;
  }
  tab[taille - 1] = NULL;
  return tab;
}

char * reconstruit(char **tab){
  //On va definir le nombre de lettre que contient tab (il finit par un NULL)
  int len = 0, i = 0;
  while (tab[i] != NULL){
    len += strlen(tab[i]);
    i++;
  }
  
  //On construit la nouvelle chaine de caractère
  char* chaine = malloc(len*sizeof(char));
  i = 0;
  while(tab[i] != NULL){
    chaine = strcat(chaine, tab[i]);
    i++;
  }
  printf("La chaine obtenue par concatenation est : \"%s\"\n", chaine);
  
}

main(){
  int n = 3;
  traduction* dico = malloc(n*sizeof(traduction));
  dico->a = "mot1"; dico->b = "trad1";
  (dico+1)->a = "mot2"; (dico+1)->b = "trad2";
  (dico+2)->a = "mot3"; (dico+2)->b = "trad3";

  //Q1
  char* mot = "mot1";
  printf("Le dictionnaire contient-il \"%s\" ? ... \n", mot);
  char * trad = recherche(dico, n, mot);
  if(trad != NULL){
    printf("La valeur trouvée est : %s\n", trad);
  }
  else{
    printf("Rien trouvé\n");
  }
 
  //Q2
  char* chaine = "Il etait une fois";
  int nbEspace = nombre_espace(chaine);
  printf("Il y a %d espaces dans : \"%s\"\n", nbEspace, chaine);

  //Q3
  char* chaine3 = "ba bu zo meu";
  char** tabChar3 = decoupe(chaine3);
  int i3 = 0;
  for(i3 = 0; i3 < 5; i3++){
    printf("%s.\n", tabChar3[i3]);
  }

  //Q4
  reconstruit(tabChar3);
}
