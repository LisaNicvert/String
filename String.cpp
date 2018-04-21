# include "String.h"
int String::MAX_LEN_=100;

// ####################################################################
//Constructors
// ####################################################################

/* Default constructor : 
Using this constructor users could initiante a new string, with a null length and a null capacity.
The pointer world_ is set to a nullptr.*/
String::String()
{
	len_=0;
	capacity_=0;
	word_=nullptr;
    p_word_ =nullptr;
}

/* Parameterized constructor :
Using this constructor users could build a new string passing as argument an array of chars. This constructor
uses the definition of a c-string to build a new string. That's it so say, while the algorithm doesn't reach the
null character a counter sum the number of occurence. At the end of this while loop the counter is equal to
the length. To calcul the capicity we add 1 to the current length. This allows to take into account the null character.
Finally to initialize the attribute word_ the algorithm allocates a block of memory to contain an array of char of size
equal to the current capacity_.
*/
String::String(const char *c_string) 
{

	int i=0 ; 
    // This while loop runs until to reach the last 
	while (c_string[i] != '\0')
	{
        
		++i;
	}
    // If the c_string exceed Max_LEN a warning message informs the user that this action is impossible.
    if ( i > MAX_LEN_)
    {
        std::cout << "Sorry the max length is exceeded !" << std::endl;
    }
    else
    {    
	len_ = i ; 
	capacity_ = len_ + 1; 
    // Allocation of memory
	word_ = new char [(capacity_)*sizeof(char)];
    // filling an array char
	for (i=0 ; i <= len_ ; i++)
	{
       // std::cout<<i<<std::endl;
		word_[i] = c_string[i];
	}
	word_[capacity_] = '\0'; 
    p_word_ = &word_[0];
    }
}

// ####################################################################
// Getters
// ####################################################################

/* These Getters allow to users to access to each attribute of the class String.*/
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


/* Resize :
The method resize allows to users to redefine the size of a string pssing as arguement the new length of string. If the lenghth choosen 
is infeiror to the string length the excedent characters are deleted otherwise memory is allocated. If any argument is passed to the 
mathod null characters will be add until to reach the newlength, otherwise the charecter choosen is used.
This method created a new array of size equal to the new capacity (new length + 1). The string is partially or fully copied according to the 
new length choosen. Finally the array of char of the former size is deleted, and the new length and the new capacity are updated.
Becareful if the new size exceeds the max size, a warning message warns user.  

Pre-conditions : String of size define by its attribute len_ is modified
Post-conditions : if newlength < len_ exceedent char are deleted,
                  if  len_< newlength < max_size memory is allocated if any argument has been passed '\0' are added at the end of the string, otherwise
                  the string is extended with the char choosen,
                  if newlength > max_size any action is possible a warnning message appears.*/

void String::resize(int newlength, const char& c ) 
{
	// Allocation of memory
    char *newword = new char [newlength + 1];
    // Case n°1 : 
	if (newlength < len_)
	{
        // Filling the new array
		for (int i=0 ; i < newlength ; ++i )
		{
			newword[i] = word_[i];
		}
	    newword [newlength + 1 ] = '\0'; 
        // Free memory
		delete[] word_;
        // Redefinition of the attribute word_
		word_ = newword;
		
	}
    // Case n°2:
	else if (newlength > len_)
	{
		for (int i=0 ; i<=newlength ; ++i)
		{	
            // Filling the new array until to reach the end of the string
			if (i < len_)
			{	
			newword[i] = word_[i];
			}
            // Complete the string with a nullchar or a choosen char 
			else
			{	
			newword[i] = c;
			}
		}
		newword [newlength + 1 ] = '\0';
        // free memory
		delete[]  word_;
        // Redefinition of the attribute word_
		word_ = newword;
	
	}
    // Case n°3 : Impossible !
    else
    {
        std::cout << "Sorry the max size is excedeed." <<std::endl;
    }
	
	len_ = newlength  ;
	capacity_ = newlength + 1;
}

/* Empty :
The function empty allows to know if a string is empty or not returning a boolean. To do this the algorithm tests
if the attribute len_ is superior to one or not.
Pre_condition : A string
Post-condition : The boolean returned is TRUE is len_ <=1 (?????) else this one is False
*/
bool String::empty(){
	bool res;
	if(len_<=1) // Pourquoi 1 et pas 0 ???????? 
    {  
		res=true;
	}
	else
    {
		res=false;
	}
	return res;
}

/* reserve:
The method reserve allows to forecast a changement of size, like this the user could choose the future size of his string. 
If the size choosen is upper than the current capacity_ a array of the planed size is created and this one is filled by the
current word_. Otherwise this algorithm allows to optimize the capacity by building a new array of size equal to the current 
len_ more one. Finally if the newsize exceed the capacity a warning message appears.
In order to optimize the optimize the capacity a tempory array is created, then this one is filled with the word. The memory the 
older word is free. Then the attribute word_ is updated using the temppory array. Then this tempory array is delete and the capacity 
is updated.
Post-condition : In any case, the string and its length are modified only the capacity of the array containing the string could be changed.
                If the forecasted size (newsier setted by user) is lower than MAX_LEN_ and if this one is lower than the current capacity_ a new array of the wanted
                sized is created an the former one is delete.
                If the forecasted size is lower than MAX_LEN_ but this one s lower than the current capacoty_, a new array of char is created
                its size is adjusted to optimize the memory occupied by the string. Like this this size is set to the current len_ more one.
                If the capacity is ever eaqual to the current capacity_ nothing is done.
                Else if the forcast size exceed the capacity a warning messaga appears.
*/

void String::reserve(int newsize)
{
    if(newsize <=  MAX_LEN_){
        if(newsize >capacity_) // Case capacity enhanced
        {
            char * temp = new char[len_ + 1];
        
            for(int i=0 ; i<=len_+1 ; i++){ // to copy the word
                temp[i]=word_[i];
            }
        
            delete[] word_; // del previous
        
            word_ = new char[(newsize+1)*sizeof(char)]; // new storage space
            p_word_ = &word_[0]; // change pointer
        
            for(int i=0 ; i<len_+1 ; i++){ // to copy the word
                word_[i]=temp[i];
            }
            delete[] temp;
            capacity_=newsize;
        }
        else if(newsize < capacity_) // case capacity diminushed
        { 
            // we choose to optimize capacity
            char * temp = new char[this->len()+1]; // new capacity
            for(int i=0 ; i<len_+1 ; i++)// to copy the word
            { 
                temp[i]=word_[i];
            }
        
            delete[] word_;
        
            word_ = new char[(this->len()+1)*sizeof(char)]; // new storage space
            p_word_ = &word_[0]; // change pointer
        
            for(int i=0 ; i<len_+1 ; i++){ // to copy the word
                word_[i]=temp[i];
            }
        
            word_[capacity_] = '\0';
    
            delete[] temp;
            capacity_=this->len()+1;
        }
        else if(newsize==capacity_) // case capacity is the same
        {
            std::cout << "The size is already this one!" << std::endl;
        }
    }
    else if(newsize >  MAX_LEN_)
    {
        std::cout << "ERROR: RESULT OF CAPACITY " << newsize << " WOULD OVERSTEPS MAXIMAL LEGAL LENGTH"<<std::endl; 
    }
}

/* Display :
The method display allows to print each char containing in the attribute word_.*/
void String::display()
{
    if(capacity_<=1){
        std::cout <<"Empty string" << std::endl;;
    }
    else{
        int i=0;
        while(i < capacity_)
        {
            std::cout <<"Char in position " << i << " : " << p_word_[i]<< std::endl;;
            ++i;
        }
    }
    
}

// ####################################################################
// Operators
// ####################################################################

/* operator = c
This operator allows to user to replace the current strign by a c-string.
... (J continueRAI)
*/
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
        }
        else if (this->capacity() < charSize){ // if char is longer
            this->reserve(charSize);
            for(int i=0 ; i <= charSize ; ++i)
            {
            p_word_[i]=*(c+i);
            }
            // Update word
            len_=charSize-1;
        }
    }
    else if(charSize >  MAX_LEN_)
    {
        std::cout << "ERROR: PARAMETER OVERSTEPS MAXIMAL LEGAL LENGTH"<<std::endl;
    }
    return *this;
}

//void String::Resize(   , int n ) //  n taille voulue -> ça fait quoi ici ?

/* Operator = char c
This operator allow to replace a string by a single char choosen.
The array of char containing the string is deleted and a new string is initialized.
Pre-conditions : A string 
Post-conditions : A string containing a simple character choosen by the user.
*/
String& String::operator=(char c)
{
    // Step n°1 : deletion
	delete[] word_;
    //Step n°2 : Initialization of a new word
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
	int newlength = len1 + len2;
    
    String res;
    
    if(newlength+1 <= String::MAX_LEN_)
    {
        char *newword = new char [newlength + 1];
        for (int i=0 ; i<=len1 ; ++i)
        {	
            newword[i] = s.word_[i];	
        }
        for (int i=0 ; i<=len2 ; ++i)
        {	
            newword[len1+i] = s2.word_[i];	
        }
        newword [len1 + len2 + 1 ] = '\0';
        res.word_ = newword;
        res.len_ = len1 + len2 ;
        res.capacity_ = len1 + len2 + 1;
	}	
    else if(newlength+1 > String:: MAX_LEN_)
    {
        std::cout << "ERROR: RESULT OF LENGTH " << newlength << " WOULD OVERSTEPS MAXIMAL LEGAL LENGTH"<<std::endl;
        char* temp = new char[0];
        String res(temp);
        delete[] temp;
    }
    return res;
}

String operator+(const char* c ,const String& s )	
{
	String s1(c);
	int len1 = s1.len_;
	int len2 = s.len_;
	int newlength = len1 + len2;
    
    String res;
    
    if(newlength+1 <= String::MAX_LEN_)
    {
        char *newword = new char [newlength + 1];
        for (int i=0 ; i<=len1 ; ++i)
        {	
            newword[i] = s1.word_[i];	
        }
        for (int i=0 ; i<=len2 ; ++i)
        {	
            newword[len1+i] = s.word_[i];	
        }
        newword [len1 + len2 + 1 ] = '\0';
        res.word_ = newword;
        res.len_ = len1 + len2 ;
        res.capacity_ = len1 + len2 + 1;
    }
    else if(newlength+1 > String:: MAX_LEN_)
    {
        std::cout << "ERROR: RESULT OF LENGTH " << newlength << " WOULD OVERSTEPS MAXIMAL LEGAL LENGTH"<<std::endl;
        char* temp = new char[0];
        String res(temp);
        delete[] temp;
    }
    return res;
}

String operator+(const String& lhs, const String& rhs)
{
    int len1 = lhs.len_;
	int len2 = rhs.len_;
    int newlength= len1+ len2;
    
    String res;
    
    if(newlength+1 <= String::MAX_LEN_)
    {
        char *newword = new char [newlength + 1];
        for (int i=0 ; i<=len1 ; ++i)
        {	
            newword[i] = lhs.word_[i];	
        }
            for (int i=0 ; i<=len2 ; ++i)
        {	
            newword[len1+i] = rhs.word_[i];	
        }
        newword [newlength + 1 ] = '\0';
        res.word_ = newword;
        res.len_ = len1 + len2 ;
        res.capacity_ = len1 + len2 + 1;
    
    }
    else if(newlength+1 > String:: MAX_LEN_)
    {
        std::cout << "ERROR: RESULT OF LENGTH " << newlength << " WOULD OVERSTEPS MAXIMAL LEGAL LENGTH"<<std::endl;
        char* temp = new char[0];
        String res(temp);
        delete[] temp;
    }
    return res;
}


// ####################################################################
// Destructor
// ####################################################################
String::~String()
{
	// Add the delete [var] here when you make a new manual allocation in a function.
    if(capacity_>1){ // because else the pointer was never allocated
        delete [] word_ ; 
    }
}
