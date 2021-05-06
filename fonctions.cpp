#include "fonctions.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
using ull=long long;

/*********FONCTIONS MATHEMATIQUES*********/

//fonction d'exponentiation modulaire : x^puiss [mod]
ull expMod(ull x, ull puis, ull mod){
	ull res = 1;

	x = x % mod;

	if(!x){
		puis=0;
		res=0;
	}

	while(puis>0){
		if(puis&1)
			res = (res*x) % mod;

		puis=puis>>1;
		x = (x*x) % mod;
	}
	return res;
}


ull pgcd(ull a, ull b){
    while(a != b)
        if(a > b)
            a -= b;
        else
            b -= a;
    return a;
}

//fonction d'inversion modulaire
ull invMod(ull a, ull b){

	ull r1=a, r2=b, v1=0, v2=1, u1=1, u2=0;
		r1=b, r2=a;
		ull q, rs, vs, us;

	while(r2){
		q = (r1/r2);
	    rs = r1, us = u1, vs = v1,
	    r1 = r2, u1 = u2, v1 = v2,
	    r2 = (rs - (q*r2)), u2 = (us - (q*u2)), v2 = (vs - (q*v2));
	}
	return u1;
}

//test de primalit�
bool estPremier(ull n){
	bool res=1;
	if(n <= 2)
		res = (n==2);
	else if(!(n&1))
		res = 0;
	else{
		for(int i=3; i<=sqrt(n); i+=2){
			if(n%i==0)
				res=0;
		}
	}

	return res;
}

//fonction pour obtenir un ordre al�atoire pour le groupe
ull randPremier(){
	return 953;
}


/********************FONCTIONS ELGAMAL*************************/

//G�n�ration du groupe (seulement son ordre) et du g�n�rateur g
void genGroupe(ull *p, ull *q, ull *g){
	bool b=1;

	while(b){
		*q = randPremier();
		*p = (2*(*q) + 1);
		b = !estPremier(*p);
	}

	unsigned int temp;
	do{
	temp = (rand() % *q);
	}while  ((!(expMod(temp, 2, *p)!=1))&(temp!=0));

	if(expMod(temp, *q, *p)==1){
		*g=temp;
	}
	else *g=expMod(temp, 2, *p);


}

//g�n�ration des �l�ments x et h des cl�s, on peut trouver pk et sk avec ces deux nombres
void genCle(ull q, ull g, ull *h, ull *x, ull p){
	*x = (rand() % q) + 1;
	*h = expMod(g, *x, p);
}

//fonction de chiffrage
void encrypt(ull p, ull g, ull m, ull h,  ull *c1, ull *c2, ull q){
	ull y = (rand() % q) + 1;

	//std::cout<<"r = "<<y<<std::endl;
	*c1 = expMod (g, y, p);

	ull s = expMod(h, y ,p);
	*c2 = (m*s % p);
}

//fonction de d�chiffrage
ull decrypt(ull p, ull x, ull c1, ull c2){
	ull s = expMod(c1, x ,p);
	ull sInv = invMod(p, s) %p;
	if(sInv<0)
		sInv+=p;
	//std::cout<<"s = "<<s<<"  sInv = "<<sInv<<std::endl;

	return ((c2*sInv) % p);
}


