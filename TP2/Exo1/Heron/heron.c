#include "fractions.c"

struct fraction heron(int a, int n){
  struct fraction f = {1, 1};
  if (n == 0)
    return f;
  else{
    int i;
    for(i = 1; i <=n; i++){
      f = div_frac(add_frac(f, div_frac(of_int(a), f)), of_int(2));
    }
    return f;
  }
}

main(){
  int a, n;
  printf("Entrez un a :\n");
  scanf("%d", &a);
  printf("Entrez un n :\n");
  scanf("%d", &n);
  int i;
  for(i = 0; i <=n; i++){
    printf("Rang %d :\n", i);
    affiche_fraction(heron(a, i));
  }
}
