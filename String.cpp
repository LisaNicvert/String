# include "String.h"
int String::MAX_LEN_;

String::~String(){
	// Add the delete [var] here when you make a new manual allocation in a function.
}

int String::capacity(){
	return capacity_;
}

bool String::empty(){
	bool res;
	if(len_<=1){
		res=true;
	}
	else{
		res=false;
	}
	return res;
}

void String::reserve(int newsize){
	if(newsize >=)
}
