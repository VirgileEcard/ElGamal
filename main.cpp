#include<iostream>
#include<numeric>
#include"fonctions.h"
#include <ctime>

using ull=long long;
using namespace std;

int main(int argc, char *argv[]){

	ull p, q, g, h, x; //d�claration des variables utlis�es (p-� � remplacer par une classe)


	srand((int) time(0));
	genGroupe(&p, &q, &g);
	genCle(q, g, &h, &x, p); //on d�finit x et h, composants des cl�s

	string m;

	cout<<"On travaille dans le sous-groupe d'ordre "<<q<<" du groupe Z/"<<p<<"Z. Le g�n�rateur utilis� est "<<g<<endl<<endl;
	cout<<"Les cl�s sont"<<endl<<"x = "<<x<<endl<<"h = "<<h<<endl<<endl;

	cout<<"Entrez le message � chiffrer : ";
	getline(cin,m);

	ull Tab[m.length()][2];

	cout<<endl<<"Les chiffr�s sont :"<<endl;

	//on d�compose le string en caract�res qu'on chiffre un � un
	for(int i=0; i<m.length(); i++){
		ull c1, c2;
		char c=m.at(i);
		encrypt(p, g, (ull)c, h, &c1, &c2, q);
		Tab[i][0]=c1;
		Tab[i][1]=c2;

		cout<<c1<<" ; "<<c2<<endl;
	}
	cout<<endl;


	string dec;
	for(int i=0; i<m.length(); i++){
		dec+=(char)decrypt(p, x, Tab[i][0], Tab[i][1]);
	}
	cout<<"Le message d�chiffr� est : "<<dec<<endl;


	return 0;
}

