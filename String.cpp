# include "String.h"
int String::MAX_LEN_=100;
using namespace std;


//Constructor
String::String(const char word[]) 
{
	
	int i=0 ; 
	while (word[i] != '\0')
	{
		++i;
	}
	len_ = i;
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

// Getters
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

// Methods
void String::resize(int newlenght, char& c )
{
	std::cout << c << std::endl; // Ok pour a 
	char *newword = new char [newlenght];
	if (newlenght < len_)
	{
		for (int i=0 ; i < newlenght ; ++i )
		{
			newword[i] = p_word_[i];
		}
		newword [newlenght + 1 ] = '\0'; // dernière case 	
		delete[] p_word_;
		p_word_ = newword;
		
	}
	else if (newlenght > len_)
	{
		for (int i=0 ; i<newlenght ; ++i)
		{	
			if (i <= len_)
			{	
			newword[i] = p_word_[i];
			}
			else
			{
				newword[i] = c;
			}
		}
		
		newword [newlenght + 1 ] = '\0';
		delete[] p_word_;
		p_word_ = newword;
	
	}
	
	len_ = newlenght;
	capacity_ = newlenght + 1;
}
// To do if newlength > Max sieze & paramètre optionnel ???

String& String::operator=(const char* c){
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
        cout << "ERROR: PARAMETER OVERSTEPS MAXIMAL LEGAL LENGTH"<<endl;
        return *this;
    }
}

String& String::operator=(char c)
{
	delete[] word_;
	this -> p_word_ = &c;
	this -> len_ = 1;
	this -> capacity_ = 2 ;
	return *this;
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
        cout << "The size is already this one!" <<endl;
    }
}

void String::display()
{
    int i=0;
    while(i < capacity_)
    {
        cout <<"Char in position " << i << " : " << p_word_[i]<< endl;;
        ++i;
    }
}

// Destructor
String::~String()
{
	// Add the delete [var] here when you make a new manual allocation in a function.
    delete word_; 
}
