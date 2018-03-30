# include <iostream>
# include "String.h"
using namespace std;

int main(){
	char Hello[]="Bonjour";
	//char*  greeting = Hello[0]; 
	String mystr(Hello);
	std::cout<< mystr.len() << std::endl;
	return 0;
}
