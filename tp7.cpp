# include <iostream>
# include "String.h"
using namespace std;

int main(){
    // Ctor test
	char Hello[]="Bonjour";
	//char*  greeting = Hello[0]; 
	String mystr(Hello);
    
    /*
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;
    mystr.display();
    
	char plus = 'a';
	mystr.resize(3, plus);
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;


	mystr.resize(8 , plus);
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;

	cout << "Test de l'opérateur=(char)"<<endl;
	mystr = "A";
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;
	cout << "Eh ça marche :)"<<endl;

	// len accessor test
    cout<< "mystr len :" << mystr.len() << endl;
    mystr.display();
	
    
	// Capacity accessor test
	cout<< "Capacity: " << mystr.capacity() << endl;
	
	// empty test
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
