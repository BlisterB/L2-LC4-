#include <stdio.h>

void affiche_tableau(int length, int t[]);
int est_identite(int n, int f[]);
int nombreInversion(int n, int t[]);
int main();
void compose_permutations(int n, int perm1[], int perm2[], int perm_composee[]);
void inverse_directe(int n, int perm[], int perm_inverse[]);
int rang(int n, int perm[]);
void inverse_ordre(int n, int perm[], int inverse[]);

void affiche_tableau(int length, int t[]){
  int i;
  printf("{ ");
  for(i = 0; i < length; i++){
    printf("%d", t[i]);
    if(i<length-1)
      printf(", ");
  }
  printf(" }\n");
}

int est_identite(int n, int f[]){
  int estIdentite = 1;
  int i;
  for(i = 0; i < n; i++){
    if(f[i] != i){
      estIdentite = 0;
    }
  }
  return estIdentite;
}

int nombreInversion(int n, int t[]){
  int compteur = 0;
  int i;
  int j;
  for(i=0; i < n - 1; i++){
    for(j=i+1; j <n; j++){
      if(t[i] > t[j])
	compteur++;
    }
  }
  return compteur;
}

void compose_permutations(int n, int perm1[], int perm2[], int perm_composee[]){
  int i;
  for(i=0; i < n; i++){
    perm_composee[i] = perm1[perm2[i]];
  }
}

void inverse_directe(int n, int perm[], int perm_inverse[]){
  int i;
  for(i=0; i < n; i++){
    perm_inverse[perm[i]] = i;
  }
}

void copie_permutation(int n, int permACopier[], int permVide[]){
  int i;
  for(i=0; i<n; i++){
    permVide[i] = permACopier[i];
  }
}

int rang(int n, int perm[]){
  int compteur = 0;
  int permPrecedente[n];
  int permTransitoire[n];
  //On copie la permutation dans un tableau
  copie_permutation(n, perm, permPrecedente);

  //On effectue les permutations successives
  while(!est_identite(n, permPrecedente)){
    compose_permutations(n, perm, permPrecedente, permTransitoire);
    //On copie permTransitoire dans permPrecedente
    int j;
    copie_permutation(n, permTransitoire, permPrecedente);
    //On incrémente le compteur
    affiche_tableau(n, permPrecedente);
    compteur++;
  }
  return compteur;
}

void inverse_ordre(int n, int perm[], int inverse[]){

}

int main(){
  printf("{ 0, 1, 2, 3 }\n");
  int t[] = {1, 3, 0, 2};
  int tInverse[] = {0, 0, 0, 0};
  inverse_directe(4, t, tInverse);
  affiche_tableau(4, t);
  affiche_tableau(4, tInverse);
  int tCompose[] = {0, 0, 0, 0};
  compose_permutations(4, t, tInverse, tCompose);
  printf("La composée est :\n");
  affiche_tableau(4, tCompose);

  printf("Composons la permutation sur elle même :\n");
  int compteur = rang(4, t);
  printf("On a mis %d tour de boucle pour effectuer l'opération.\n", compteur);
}
