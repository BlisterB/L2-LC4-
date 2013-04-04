#include "nums.h"

affiche_num(num n){
  switch(n.t){
  case 0: 
    //long long
    prinf("%ul", num.val.l);
  case 1 :
    //float
    printf("%f", num.val.f);
  case 2 :
    //struct fraction
    affiche_fraction(num.n.fraction)
  }
}

struct num retype(struct num n){
  
}
