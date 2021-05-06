#include<iostream>
#include<numeric>
#include"fonctions.h"
#include <ctime>

using ull=long long;
using namespace std;

int main(int argc, char *argv[]){

	ull p, q, g, h, x; //déclaration des variables utlisées (p-ê à remplacer par une classe)


	srand((int) time(0));
	genGroupe(&p, &q, &g);
	genCle(q, g, &h, &x, p); //on définit x et h, composants des clés

	string m;

	cout<<"On travaille dans le sous-groupe d'ordre "<<q<<" du groupe Z/"<<p<<"Z. Le générateur utilisé est "<<g<<endl<<endl;
	cout<<"Les clés sont"<<endl<<"x = "<<x<<endl<<"h = "<<h<<endl<<endl;

	cout<<"Entrez le message à chiffrer : ";
	getline(cin,m);

	ull Tab[m.length()][2];

	cout<<endl<<"Les chiffrés sont :"<<endl;

	//on décompose le string en caractères qu'on chiffre un à un
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
	cout<<"Le message déchiffré est : "<<dec<<endl;


	return 0;
}

