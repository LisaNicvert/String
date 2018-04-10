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
	len_ = i ; // Car on commence on prend en compte le bite = 0
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

void String::resize(int newlenght, const char& c ) // A finir !!!!!
{
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
		for (int i=0 ; i<=newlenght ; ++i)
		{	
			if (i < len_)
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
	
	len_ = newlenght  ;
	capacity_ = newlenght + 1;
}
// To do if newlength > Max sieze & paramètre optionnel ???
String::~String()
{

}

//void String::Resize(   , int n ) //  n taille voulue

String& String::operator=(char c)
{
	delete[] this -> word_;
	this -> word_ = &c;
	this -> len_ = 1;
	this -> capacity_ = 2 ;
	return *this;
}




/*
String String::operator+(const char* lhs , const String& rhs)
{
	int newlenght = this -> len_ + 1;
	char *newword = new char [newlenght];

	newword[newlenght] = lhs;	
	for (int i=1 ; i<=  rhs.len_ ; ++i)
	{
		newword[i] = rhs.word_[i];
	}
	newword[newlenght + 1] = '\0';
	delete[] word_;
	this -> word_ = newword;
	this -> len_ = newlenght;
	this -> capacity_ = newlenght + 1;
	return *this;
}


*/


