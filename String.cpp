# include "String.h"
int String::MAX_LEN_;

// 
int String::len()
{
	return len_;
} 

//Constructor
String::String(char word[]) 
{
	//p_word_ = word;
	int i=0 ; 
	while (word[i] != '\0')
	{
		++i;
	}
	len_ = i;
	capacity_ = len_ + 1; // on compte \0
	word_ = new char[len_ + 1];
	strcpy (word,word_);

}
String::~String()
{
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
