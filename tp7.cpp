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

	
	cout << "Test de l'opérateur+ (char *)"<<endl;
	char c1[] = "Bien le ";
	String s1(c1);
	char c2[] = "bonjour !";

	String s;
	s = s1 + c2;
	cout << s.word()<<endl;
	
	cout << "Test de l'opérateur (char *)+ String"<<endl;

	String s_othersens;
	s = c2 + s1;
	cout << s.word()<<endl;
	return 0;
}


