# include <iostream>
# include "String.h"
#include <string>
using namespace std;

int main(){
    // Ctor test
	char Hello[]="Bonjour";
	
    /*------------------------
    * Ctor test
    ------------------------*/
	cout << "Test de constructeur " <<endl;	
	String mystr(Hello);
	std::cout<< "length de Bonjour "<<mystr.len() << std::endl;
	std::cout<<"Mot en mémoire " << mystr.word() << std::endl;
	std::cout<< "Cpacité = mémoire allouée  "<<mystr.capacity() << std::endl;
	char plus = 'a';

    /*------------------------
    * resize test
    ------------------------*/
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

    /*------------------------
    * operator=(char) test
    ------------------------*/
	cout << "Test de l'opérateur=(char)"<<endl;
	mystr = "A";
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;
	cout << "Eh ça marche :)"<<endl;

	/*------------------------
    * operator+(char *) test
    ------------------------*/
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
	// len accessor test
    cout<< "mystr len :" << mystr.len() << endl;
    mystr.display();
	
    
    /*------------------------
    * capacity getter test
    ------------------------*/
	cout<< "Capacity: " << mystr.capacity() << endl;
	
	/*------------------------
    * empty test
    ------------------------*/
    /*
	cout<< "mystr is empty: " << mystr.empty() << endl;
	char empty[]="";
	String emptystr(empty);
	cout<< "emptystr is empty: " << emptystr.empty() << endl;
	emptystr.display();
    */
    
	/*------------------------
    * reserve test
    ------------------------*/
    /*
    cout<< "mystr capacity: " << mystr.capacity() << endl;
    
    // equal capacity
    mystr.reserve(8);
    mystr.display();
    

    // greater capacity
	mystr.reserve(40);
	cout<< "mystr capacity: " << mystr.capacity() << endl;
	mystr.display();
    
    
    // lesser capacity
	mystr.reserve(2);
	cout<< "mystr capacity: " << mystr.capacity() << endl;
    cout<< "mystr len: " << mystr.len() << endl;
    mystr.display();
    */
    
    /*------------------------
    * Display tests
    ------------------------*/
    /*
    mystr.display();
    mystr.reserve(40);
    mystr.display();
    char empty[]="";
	String emptystr(empty);
    emptystr.display();
    */
    
    
    /*------------------------
    * Operator=(char *) tests
    ------------------------*/
    /*
    char secondChar[]="AFRESdt";
    // Equal capacity
    char* ptr= &secondChar[0];
    
    mystr=ptr;
    
    cout<< mystr.word() << endl;
    cout<< "mystr display: "  << endl;
    mystr.display();
    */
    
    /*
    // String greater cap
    char secondChar[]="AFRESdt";
    mystr.reserve(40);
    cout<< "mystr display before: "  << endl;
    mystr.display();
    
    char* ptr= &secondChar[0];
    mystr=ptr;
    cout<< mystr.word() << endl;
    cout<< "mystr capacity: " << mystr.capacity() << endl;
    cout<< "mystr display after: "  << endl;
    mystr.display();
    */
    
    
    // String lesser cap
    /*
    char secondChar[]="AFRESdfdvqfdbdfbt";
    char* ptr= &secondChar[0];
    
    cout<< "mystr display before: "  << endl;
    mystr.display();
    
    mystr=ptr;
    
    cout<< "mystr display after: "  << endl;
    mystr.display();
    
    cout<< mystr.word() << endl;
    cout<< "mystr capacity: " << mystr.capacity() << endl;
    */
    
    /*
    // Original str is longer
    char secondChar[]="AFR";
    char* ptr= &secondChar[0];
    mystr=ptr;
    
    cout<< "mystr display after: "  << endl;
    mystr.display();
    
    cout<< mystr.word() << endl;
    cout<< "mystr capacity: " << mystr.capacity() << endl;
    */
    
    
    // Too long char
    /*
    char secondChar[]="AFRdqgfdfbfdgnfegnhreghfsgdfgrgfhrefghngrezgfregfrghfezfghdfdfdqsfgdqfghfdghdqsfghydscvfghredqsfghredqsvfghrtedqsfghtedqscvb";
    char* ptr= &secondChar[0];
    
    mystr=ptr;
    
    cout<< mystr.word() << endl;
    
    mystr.display();
    
    cout<< "mystr capacity: " << mystr.capacity() << endl;
    */
    
	return 0;
}


