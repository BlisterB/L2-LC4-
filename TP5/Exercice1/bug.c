#include <stdio.h>

void init_tab(int tab[], int taille, int val)
{
  int i;

  for(i = 0; i < taille; i++)
    tab[i] = val;
}

void affiche_tab(int tab[], int taille)
{
  int i;

  for(i = 0; i < taille; i++)
    printf("%d ", tab[i]);

  printf("\n");
}

int main()
{
  int n = 10;
  int tab[10];

  init_tab(tab, n, 1);
  affiche_tab(tab, n);

  return 0;
}
