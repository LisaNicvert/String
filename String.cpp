# include "String.h"
int String::MAX_LEN_;

// 
int String::len()
{
	return len_;
} 
int String::capacity(){
	return capacity_;
}
char* String::word()
{
	return word_;
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
	word_ = new char[len_];


	for (i=0 ; i < capacity_ ; i++)
	{
		word_[i] = word[i];
	}
	word_[capacity_] = '\0';
	//strcpy (word_,word);
	
}
String::~String()
{
	// Add the delete [var] here when you make a new manual allocation in a function.
}


