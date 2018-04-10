# include "String.h"
int String::MAX_LEN_;
using namespace std;

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
	strcpy (word_,word);

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

void String::reserve(int newsize)
{
	if(newsize >capacity_) // Case capacity enhanced
	{
		char * temp = new char[newsize + 1]; // new capacity
		for(int i=0 ; i<len_+1 ; i++){ // to copy the word
			temp[i]=word_[i];
		}
		strcpy(word_,temp);
        delete[] temp;
		capacity_=newsize;
    }
    else if(newsize < capacity_) // case capacity diminushed
    { 
        // we choose to optimize capacity
        char * temp = new char[this->len()+1]; // new capacity
		for(int i=0 ; i<len_+1 ; i++){ // to copy the word
			temp[i]=word_[i];
		}
        strcpy(word_,temp);
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
    while(word_[i] != '\0')
    {
        cout << word_[i];
        ++i;
    }
    if(i != 0) // to avoid displaying newline if String is empty
    {
        cout << endl;
    }
}

String::~String()
{
	// Add the delete [var] here when you make a new manual allocation in a function.
	delete word_;
}
/*
String& operator=(const char* c){
    // if sizes are equal
    // if String is longer
    // if char is longer
    
}
*/
