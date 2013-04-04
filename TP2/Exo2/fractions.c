#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fractions.h"


void affiche_fraction(struct fraction f){
  printf("La fonction est : %d/%d = %f\n", f.numerateur, f.denominateur, (float)f.numerateur/f.denominateur);
}

int pgcd(int a, int b){
  int r, tmp;//Le reste de la division et une variable temporaire
  a = fabs(a); b = fabs(b); //On convertit a et b en valeurs absolues
  if(b>a){
    tmp = a;
    a = b;
    b = tmp;
  }
  while(b != 0){
    r = a%b;
    a = b;
    b = r;
  }
  return a;
}

struct fraction reduit(struct fraction f){
  int p = pgcd(f.numerateur, f.denominateur);
  struct fraction f2 = {f.numerateur/p, f.denominateur/p};
  return f2;
}

struct fraction add_frac(struct fraction f1, struct fraction f2){
  struct fraction f3 = {f1.numerateur*f2.denominateur + f2.numerateur*f1.denominateur, f1.denominateur*f2.denominateur};
  return reduit(f3);
}

struct fraction sub_frac(struct fraction f1, struct fraction f2){
  struct fraction f3 = {f1.numerateur*f2.denominateur - f2.numerateur*f1.denominateur, f1.denominateur*f2.denominateur};
  return reduit(f3);
}

struct fraction mult_frac(struct fraction f1, struct fraction f2){
 struct fraction f3 = {f1.numerateur*f2.numerateur, f1.denominateur*f2.denominateur};
  return reduit(f3);
}

struct fraction div_frac(struct fraction f1, struct fraction f2){
 struct fraction f3 = {f1.numerateur*f2.denominateur, f1.denominateur*f2.numerateur};
  return reduit(f3);
}

int frac_eq(struct fraction f1, struct fraction f2){
  //Je suis conscient que ça posera soucis si les fractions on des signes différent pour le combo numerateur/denominateur
  f1 = reduit(f1);
  f2 = reduit(f2);
  return (f1.numerateur == f2.numerateur) && (f1.denominateur == f2.denominateur);
}

float to_float(struct fraction f){
  return (float)f.numerateur/f.denominateur;
}

struct fraction of_int(int i){
  struct fraction f = {i, 1};
  return f;
}
