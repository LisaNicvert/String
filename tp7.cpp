# include <iostream>
# include "String.h"

int main(){
	char Hello[]="Bonjour";
	//char*  greeting = Hello[0]; 
	String mystr(Hello);
	std::cout<< mystr.len() << std::endl;
	return 0;
}