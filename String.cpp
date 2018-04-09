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
String::String(const char word[]) 
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

// Methods
void String::resize(int newlenght, char& c )
{
	std::cout << c << std::endl; // Ok pour a 
	char *newword = new char [newlenght];
	if (newlenght < len_)
	{
		for (int i=0 ; i < newlenght ; ++i )
		{
			newword[i] = word_[i];
		}
		newword [newlenght + 1 ] = '\0'; // dernière case 	
		delete[] word_;
		word_ = newword;
		
	}
	else if (newlenght > len_)
	{
		for (int i=0 ; i<newlenght ; ++i)
		{	
			if (i <= len_)
			{	
			newword[i] = word_[i];
			}
			else
			{
				newword[i] = c;
			}
		}
		
		newword [newlenght + 1 ] = '\0';
		delete[] word_;
		word_ = newword;
	
	}
	
	len_ = newlenght;
	capacity_ = newlenght + 1;
}
// To do if newlength > Max sieze & paramètre optionnel ???
String::~String()
{

	// Add the delete [var] here when you make a new manual allocation in a function.
}

//void String::Resize(   , int n ) //  n taille voulue

String& String::operator=(char c)
{
	delete[] word_;
	this -> word_ = &c;
	this -> len_ = 1;
	this -> capacity_ = 2 ;
	return *this;
}
