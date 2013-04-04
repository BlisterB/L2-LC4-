struct fraction{
  int numerateur;
  int denominateur;
};

typedef union valeur valeur;
union valeur{
  long long l;
  float f;
  struct fraction;
};

typedef struct num num;
struct num{
  valeur val;
  int t;
};
