using ull=long long;

ull expMod(ull x, ull puis, ull mod);

ull pgcd(ull a, ull b);

bool estPremier(ull n);

ull invMod(ull a, ull b);

ull randPremier();

void genGroupe(ull *p, ull *q, ull *g);

void genCle(ull q, ull g, ull *h, ull *x, ull p);

void encrypt(ull p, ull g, ull m, ull h,  ull *c1, ull *c2, ull q);

ull decrypt(ull p, ull x, ull c1, ull c2);
