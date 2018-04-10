# include <iostream>
# include "String.h"
using namespace std;

int main(){
    // Ctor test
	char Hello[]="Bonjour";
	//char*  greeting = Hello[0]; 
	String mystr(Hello);
	// len accessor test
	cout<< mystr.len() << endl;
	/*
	// Capacity accessor test
	cout<< "Capacity: " << mystr.capacity() << endl;
	
	// empty test
	cout<< "mystr is empty: " << mystr.empty() << endl;
	char empty[]="";
	String emptystr(empty);
	cout<< "emptystr is empty: " << emptystr.empty() << endl;
	*/
    
	// reserve test
    
    cout<< "mystr capacity: " << mystr.capacity() << endl;
    
    // equal capacity
    mystr.reserve(8);
    
    /*
    // greater capacity
	mystr.reserve(40);
	cout<< "mystr capacity: " << mystr.capacity() << endl;
	
    // lesser capacity
	mystr.reserve(2);
	cout<< "mystr capacity: " << mystr.capacity() << endl;
    cout<< "mystr len: " << mystr.len() << endl;
    */
	return 0;
}
