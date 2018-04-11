# include "String.h"
int String::MAX_LEN_=100;

// ####################################################################
//Constructors
// ####################################################################
String::String()
{
	len_=0;
	capacity_=0;
	word_=nullptr;
}


String::String(const char word[]) 
{
	int i=0 ; 
	while (word[i] != '\0')
	{
		++i;
	}
	len_ = i ; // Car on commence on prend en compte le bite = 0
	capacity_ = len_ + 1; // on compte \0
	word_ = new char[len_];
    
    p_word_ = &word_[0];


	for (i=0 ; i < capacity_ ; i++)
	{
		word_[i] = word[i];
	}
	word_[capacity_] = '\0';
    
	//strcpy (word_,word);
	
}

// ####################################################################
// Getters
// ####################################################################
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

// ####################################################################
// Methods
// ####################################################################
void String::resize(int newlenght, const char& c ) // A finir !!!!!
{
	char *newword = new char [newlenght + 1];
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
		delete[]  word_;
		word_ = newword;
	
	}
	
	len_ = newlenght  ;
	capacity_ = newlenght + 1;
}
// To do if newlength > Max sieze & paramètre optionnel ???


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

void String::reserve(int newsize)
{
	if(newsize >capacity_) // Case capacity enhanced
	{
        char * temp = new char[len_ + 1];
        
		for(int i=0 ; i<=len_+1 ; i++){ // to copy the word
			temp[i]=p_word_[i];
		}
        
        delete[] word_; // del previous
        //delete p_word_;
        
		word_ = new char[(newsize+1)*sizeof(char)]; // new storage space
        p_word_ = &word_[0]; // change pointer
        
        for(int i=0 ; i<len_+1 ; i++){ // to copy the word
			p_word_[i]=temp[i];
		}
        delete[] temp;
		capacity_=newsize;
    }
    else if(newsize < capacity_) // case capacity diminushed
    { 
        // we choose to optimize capacity
        char * temp = new char[this->len()+1]; // new capacity
		for(int i=0 ; i<len_+1 ; i++){ // to copy the word
			temp[i]=p_word_[i];
		}
        strcpy(p_word_,temp);
        delete[] temp;
        capacity_=this->len()+1;
    }
    else if(newsize==capacity_) // case capacity is the same
    {
        std::cout << "The size is already this one!" << std::endl;
    }
}

void String::display()
{
    int i=0;
    while(i < capacity_)
    {
        std::cout <<"Char in position " << i << " : " << p_word_[i]<< std::endl;;
        ++i;
    }
}

// ####################################################################
// Operators
// ####################################################################
String& String::operator=(const char* c)
{
    // Step 1: determine char[] size
    int charSize=1;
        
    while(*(c+charSize)  != '\0')
    {
        ++ charSize; 
    }
    ++charSize; // at the end, it is worth the length with '\0'
    
    if(charSize <=  MAX_LEN_){
        if(this->capacity() == charSize){ // if String capacity is equal to charSize
            for(int i=0 ; i <= charSize+1 ; ++i)
            {
            word_[i]=*(c+i);
            }
            return *this;
        }

        else if(this->capacity() > charSize) // if String is longer
        {
            int i;
            for(i=0 ; i <= charSize ; ++i) // up to the end of the new char, including '\0'
            {
                p_word_[i]=*(c+i);
            }
            int j=i;
            // Update word
            len_ = charSize-1;
            this->reserve(charSize);
            return *this;
        }
        else if (this->capacity() < charSize){ // if char is longer
            this->reserve(charSize);
            for(int i=0 ; i <= charSize ; ++i)
            {
            p_word_[i]=*(c+i);
            }
            // Update word
            len_=charSize-1;
            return *this;
        }
    }
    else //if(charSize >  MAX_LEN_)
    {
        std::cout << "ERROR: PARAMETER OVERSTEPS MAXIMAL LEGAL LENGTH"<<std::endl;
        return *this;
    }
}

//void String::Resize(   , int n ) //  n taille voulue

String& String::operator=(char c)
{
	delete[] word_;
	this -> p_word_ = &c;
	this -> len_ = 1;
	this -> capacity_ = 2 ;
	return *this;
}

String operator+(const String& s, const char* c )
{
	
	String s2(c);
	int len2 = s2.len_;
	int len1 = s.len_;
	int newlenght = len1 + len2;
	char *newword = new char [newlenght + 1];
	for (int i=0 ; i<=len1 ; ++i)
	{	
		newword[i] = s.word_[i];	
	}
	for (int i=0 ; i<=len2 ; ++i)
	{	
		newword[len1+i] = s2.word_[i];	
	}
	newword [len1 + len2 + 1 ] = '\0';
	String s3;
	s3.word_ = newword;
	s3.len_ = len1 + len2 ;
	s3.capacity_ = len1 + len2 + 1;
		
	return s3;
}

String operator+(const char* c ,const String& s )	
{
	String s1(c);
	int len1 = s1.len_;
	int len2 = s.len_;
	int newlenght = len1 + len2;
	char *newword = new char [newlenght + 1];
	for (int i=0 ; i<=len1 ; ++i)
	{	
		newword[i] = s1.word_[i];	
	}
	for (int i=0 ; i<=len2 ; ++i)
	{	
		newword[len1+i] = s.word_[i];	
	}
	newword [len1 + len2 + 1 ] = '\0';
	String s3;
	s3.word_ = newword;
	s3.len_ = len1 + len2 ;
	s3.capacity_ = len1 + len2 + 1;
		
	return s3;
}

// ####################################################################
// Destructor
// ####################################################################
String::~String()
{
	// Add the delete [var] here when you make a new manual allocation in a function.
    delete word_; 
}
