# include <iostream>
# include "String.h"
#include <string>
using namespace std;

int main(){
	char Hello[]="Bonjour";
	

	cout << "Test de constructeur " <<endl;	
	String mystr(Hello);
	std::cout<< "length de Bonjour "<<mystr.len() << std::endl;
	std::cout<<"Mot en mémoire " << mystr.word() << std::endl;
	std::cout<< "Cpacité = mémoire allouée  "<<mystr.capacity() << std::endl;
	char plus = 'a';

	cout << "Test de resize argument plus court" <<endl;	
	mystr.resize(3);
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;


	cout << "Test de RESIZE  avec argulent c= +" <<endl;
	mystr.resize(8, '+');
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;


	cout << "Test de RESIZE  avec argulent c par défaut " <<endl;
	mystr.resize(15);
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;


	cout << "Test de l'opérateur=(char)"<<endl;
	mystr = "A";
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;
	cout << "Eh ça marche :)"<<endl;

	
	string h = "hello";
	cout << h.length() << endl;
	cout << h.size() << endl;
	cout << h.capacity() << endl; // Allocation non égale à la longueur du string
	h.resize(8, '+');
	cout << h << endl;


	char suite[] = "a";
 	char* mynewword = new char [12];
	for (int  i = 0 ;  i<= 12 ; ++i)
	{
		if (i <= 7){
			mynewword[i] = Hello[i];
		}
		else {
			mynewword[i] = suite[0];
		}
	}
	cout << mynewword << endl;

	return 0;
}


