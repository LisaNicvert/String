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