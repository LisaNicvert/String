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
    /*
    String mystr(Hello);
    */
    
    /*
	cout << "Test de constructeur " <<endl;	
	String mystr(Hello);
	std::cout<< "length de Bonjour : "<<mystr.len() << std::endl;
	std::cout<<"Mot en mémoire : " << mystr.word() << std::endl;
	std::cout<< "Cpacité = mémoire allouée : "<<mystr.capacity() << std::endl;
    mystr.display();
    */
    
    /*------------------------
    * resize test
    ------------------------*/
    /*
	cout << "Test de resize argument plus court" <<endl;	
	mystr.resize(3);
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;


	cout << "Test de RESIZE  avec argument c= +" <<endl;
	mystr.resize(8, '+');
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;


	cout << "Test de RESIZE  avec argulent c par défaut " <<endl;
	mystr.resize(15);
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;
    */
    
    /*------------------------
    * operator=(char) test
    ------------------------*/
    /*
	cout << "Test de l'opérateur=(char)"<<endl;
	mystr = "A";
	std::cout<< mystr.len() << std::endl;
	std::cout<< mystr.word() << std::endl;
	std::cout<< mystr.capacity() << std::endl;
	cout << "Eh ça marche :)"<<endl;
    mystr.display();
    */
    
	/*------------------------
    * operator+(char *) test
    ------------------------*/
    
    //###################################### WORKS
    char Hello2[]="cou";
    String mystr2(Hello2);
    
	cout << "Test de l'opérateur String + (char *)"<<endl;
	
    // Len okay
    char c1[] = "cou";
	String s1(c1);
	char c2[] = "ABC";

	String s = s1 + c2;
	cout << "s : " << s.word()<<endl;
    s.display();
    cout << s.len()<<endl;
    cout << s.capacity()<<endl;
    
    
    
    // Too long
    /*
    //###################################### WORKS
    char c1[] = "cou";
	String s1(c1);
	char c2[] = "ABCsdfgfdsfghjgfdqghjkhgfdsqhjkljhgdfsqlkjhgfdsqjklhgfdsqSDFGHJKGFDSQsdfghjkhgfdsqsdfghjkgfdsqdfghjkgfdsqdfghjgfdsqdfghjkgfdsqDFGHJFDSQDFGHJKGFDSQFGHJKGFDSQFGH";

	String s = s1 + c2;
	cout << "s : " << s.word()<<endl;
    s.display();
    cout << s.len()<<endl;
    cout << s.capacity()<<endl;
    */
    
    
	cout << "Test de l'opérateur (char *)+ String"<<endl;
    

    // Len okay
    /*
    //###################################### PB WITH DESTRUCTOR AND MEMORY LEAK
    char c1[] = "cou";
	String s1(c1);
	char c2[] = "ABC";
    
	String s_othersens;
	s_othersens = c2 + s1;
	cout << s_othersens.word()<<endl;
	// len accessor test
    cout<< "othersens len :" << s_othersens.len() << endl;
    s_othersens.display();
    */
    
    
    // Too long
    /*
    //###################################### PB WITH DESTRUCTOR AND MEMORY LEAK
    char c1[] = "cou";
	String s1(c1);
	char c2[] = "ABCsdfgfdsfghjgfdqghjkhgfdsqhjkljhgdfsqlkjhgfdsqjklhgfdsqSDFGHJKGFDSQsdfghjkhgfdsqsdfghjkgfdsqdfghjkgfdsqdfghjgfdsqdfghjkgfdsqDFGHJFDSQDFGHJKGFDSQFGHJKGFDSQFGH";

    String s_othersens;
	s_othersens = c2 + s1;
	cout << s_othersens.word()<<endl;
	// len accessor test
    cout<< "sother len :" << s_othersens.len() << endl;
    s_othersens.display();
    */
    
    /*------------------------
    * capacity getter test
    ------------------------*/
    /*
	cout<< "Capacity: " << mystr.capacity() << endl;
	*/
    
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
    String mystr(Hello);
    cout<< "mystr capacity: " << mystr.capacity() << endl;
    
    // equal capacity
    cout<< "equal capacity:" << endl;
    mystr.reserve(8);
    //mystr.display();
    cout<< "------------------------------------------" << endl;
    
    // greater capacity
    cout<< "greater capacity:" << endl;
	mystr.reserve(10);
	cout<< "mystr capacity: " << mystr.capacity() << endl;
	//mystr.display();
    cout<< "------------------------------------------" << endl;
    
    // lesser capacity
    cout<< "lesser capacity:" << endl;
	mystr.reserve(2);
	cout<< "mystr capacity: " << mystr.capacity() << endl;
    cout<< "mystr len: " << mystr.len() << endl;
    mystr.display();
    cout<< "------------------------------------------" << endl;
    */
    
    /*
    // empty string
    cout<< "empty string" << endl;
    char empty[]="";
	String emptystr(empty);
    cout<< "emptystr capacity: " << emptystr.capacity() << endl;
    cout<< "emptystr len: " << emptystr.len() << endl;
	emptystr.reserve(2);
	cout<< "emptystr capacity: " << emptystr.capacity() << endl;
    cout<< "emptystr len: " << emptystr.len() << endl;
    emptystr.display();
    cout<< "------------------------------------------" << endl;
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
    
    
    // String greater cap
    /*
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
    
    

    // String smaller cap
    
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
    
    
    // Original str is longer
    /*
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
    
    /*------------------------
    * operator+(string) test
    ------------------------*/
    /*
    String mystr(Hello);
    cout << mystr.word() << endl;    
    cout<< "mystr len: " << mystr.len() << endl;
    */
    
    /*
    // If new word is too long
    //###################################### WORKS
    char secondChar[]="AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaaaaa";
    String rhs(secondChar);
    String newstring=mystr+rhs;
    cout<< newstring.word() << endl;
    */
    
    /*
    // If newword is ok
    //###################################### WORKS
    char secondChar[]=", ca va ?"; // problem il I use ç, it tells me rhs has length 10... (instead of 9)
    String rhs(secondChar);
    cout<< "rhs len: " << rhs.len() << endl;
    String newstring=mystr+rhs;
    cout<< newstring.word() << endl;
    cout<< "newstring capacity: " << newstring.capacity() << endl;
    cout<< "newstring len: " << newstring.len() << endl;
    newstring.display();
    */
    
    /*
    // If newword is empty
    //###################################### WORKS
    char secondChar[]="";
    String rhs(secondChar);
    cout<< "rhs len: " << rhs.len() << endl;
    String newstring=mystr+rhs;
    cout<< newstring.word() << endl;
    cout<< "newstring capacity: " << newstring.capacity() << endl;
    cout<< "newstring len: " << newstring.len() << endl;
    newstring.display();
    */
    
	return 0;
}


