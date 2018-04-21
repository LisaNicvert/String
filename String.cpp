# include "String.h"
int String::MAX_LEN_=100;

// ####################################################################
//Constructors
// ####################################################################


String::String()
{
	len_=0;
	capacity_=0;
    word_ = new char [(1)*sizeof(char)];
	word_[0]='\0';
    p_word_ =&word_[0];
}

/* Parametrized constructor:
 This constructor uses the definition 
        of a c-string to build a new string. 
        That's it so say, while the algorithm doesn't reach the
		null character, a counter sums the number of occurences. 
        At the end of this while loop, the counter is equal to
		the length. To calculate the capicity, we add 1 to the current 
        length. This allows to take into account the null character.
		Finally to initialize the attribute word_, the algorithm 
        allocates a block of memory to contain an array of char of size
		equal to the current capacity_.*/
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
	capacity_ = len_ +1 ; 
    // Allocation of memory
	word_ = new char [(capacity_)*sizeof(char)];
    // filling an array char
	for (i=0 ; i <= len_ ; i++)
	{
		word_[i] = c_string[i];
	}
	word_[len_] = '\0'; 
    p_word_ = &word_[0];
    }
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



/* resize: 
    If the choosen length is smaller than the string length,
            the excedent characters are deleted, otherwise memory 
            is allocated. If no argument is passed to the method, 
            null characters will be added up to the newlength, 
            otherwise the charecter choosen is used.
            This method creates a new array of size equal to the new 
            capacity (new length + 1). The string is partially or 
            fully copied according to the new choosen length. 
            Finally the array of char of the former size is deleted, 
            and the new length and the new capacity are updated.
            Be careful: if the new size exceeds the max size, 
            a warning message is displayed. */
            
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
	    newword [newlength] = '\0'; 
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
		newword [newlength] = '\0';
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

/* Method reserve:
 If the choosen size is greater than the current capacity_, an array of 
    the planned size is created and this one is filled by the
    current word_. Otherwise, this algorithm allows to optimize 
    the capacity by building a new array which size is equal to the current 
    len_ plus one. Finally, if the newsize exceeds the capacity a warning 
    message appears.
    In order to optimize the capacity, a tempory array is created, then 
    this one is filled with the word. The memory of the older word is freed. 
    Then the attribute word_ is updated using the temporary array. 
    Then this temporary array is deleted and the capacity is updated.*/
void String::reserve(int newsize)
{
    if(newsize <=  MAX_LEN_){
        if(newsize >capacity_) // Case capacity enhanced
        {
            char * temp = new char[len_ + 1];
        
            for(int i=0 ; i<=len_ ; i++){ // to copy the word  
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
        
            word_[len_] = '\0'; // Attention j'ai changé cette ligne anciennement == word_[capacity]
    
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

// displays the content of all the bytes allocated (up to capacity)
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

/* operator=(char*):
First, the algorithm counts the number of characters contained in the 
array of char. 
    As the counter is associated to the number of loops executed by 
    a while, at the end of the process the counter is equal to the 
    length of the string. 
    
    If the this length plus 1 (the new capacity) exceeds the MAX_LEN_ 
    authorized, a warning message prevents this action. 

    Othewise if the current capacity_ is equal to the future capacity_, 
    the algorithm just replaces the content of world_ attribute. 
    
    If the current capacity_ is greater than the new one, the algorithm 
    copies the content of th e new word in p_word_, redefine len_ 
    attribute and then use "reserve" to build a new sring. Calling 
    resreve method with the argument new capacity allow optimize the 
    capacity_ of the build string. 
    
    If the current capacity_ is smaller than the new one,
    the method reserve is called one more time. 
    Since the current capacity_ is inferior to the new one,
    reserve creates a new array which will be an intermediate between 
    the current word_ and the new one. 
    Finaly the attribute p_word_ is initialized with a for loop 
    and the new length is updated.*/
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
            for(int i=0 ; i <= charSize  - 1 ; ++i) 
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

/* Operator=(char):
    The array of char containing the string is deleted,
    and a new string is initialized. */
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

String operator+(const String& s1, const char* c )
{
    bool possible=1; // this operation is necessary to say wether s2 can be constructed or not (if char is not too long)
    
    int i=0;
    while (c[i] != '\0' && i<String::MAX_LEN_)
	{
        
		++i;
	}
    if ( i == String::MAX_LEN_)
    {
        possible=0;
    }
	
    String res;
    
    if(possible){
        String s2(c); // Build a new string
        int len2 = s2.len_;
        int len1 = s1.len_;
        int newlength = len1 + len2;

        char *newword = new char [newlength+1];
        for (int i=0 ; i<len1 ; ++i) // We ommit the '\0'
        {   
            newword[i] = s1.word_[i];
            //std::cout <<"first part newword     " <<newword[i] << "    pos   :"<< i<< std::endl;
        }
    
        for (int i=0 ; i<=len2 ; ++i)
        {	
            newword[i+len1] = s2.word_[i];
            //std::cout <<"Second part     " <<newword[i + len1] << "    pos   :"<< i <<"    Second part Index    " <<i + len1 <<  std::endl;
        }
    
        res.reserve(newlength+1); // to allocate space to copy the word then
        //res.display();
        //std::cout<<"res cap : "<<res.capacity()<<std::endl;
    
        std::cout <<"copied:"<<std::endl;
        for(int i=0 ; i<newlength+1 ; i++){ // to copy the word
            res.word_[i]=newword[i];
            //std::cout <<res.word_[i];
        }
        newword [len1 + len2 ] = '\0';
        //std::cout<<std::endl;
    
        res.len_ = len1 + len2 ;
        res.capacity_ = len1 + len2 + 1;
    
        delete[] newword;
    }
    else if(!possible)
    {
        std::cout << "ERROR: RESULT WOULD OVERSTEPS MAXIMAL LEGAL LENGTH"<<std::endl;
        /*char* temp = new char[0];
        String res(temp);
        delete[] temp;
        return res;*/
    }
    return res;
    //################################################
    // Problème : on retourne une variable locale !!
    //################################################
}

/* operator + (char*) : String + char*
        This operator allows to concatenate a string with a c-string. 
        Firstly the algorithm builds a string using the parameterized 
        constructor. It calculates the resulting
        length adding the two lengths. Then it initializes a empty 
        string (res), if the total length is smaller than MAX_LENGTH;
        a new array of size equal to the total length 
        more one is created. This array is filled with the two strings. 
        Then, the attributes word_, len_ and capacity_ of the resulting 
        word are updated. If the total length more one exceeds the 
        MAX_LEN_, a warning message prevents this ation.*/
        
String operator+(const char* c ,const String& s2 )	
{
    
    bool possible=1; // this operation is necessary to say wether s2 can be constructed or not (if char is not too long)
    
    int i=0;
    while (c[i] != '\0' && i<String::MAX_LEN_)
	{
        
		++i;
	}
    if ( i == String::MAX_LEN_)
    {
        possible=0;
    }
	
    String res;
    String s1(c);
    int len1 = s1.len_;
    int len2 = s2.len_;
    int newlength = len1 + len2;

    
    if(possible)
    {
        String s1(c);
        int len1 = s1.len_;
        int len2 = s2.len_;
        int newlength = len1 + len2;

        char *newword = new char [newlength +1];
        for (int i=0 ; i<len1 ; ++i)
        {	
            newword[i] = s1.word_[i];
        }
        for (int i=0 ; i<= len2 ; ++i)
        {	
            newword[len1+i] = s2.word_[i];
        }
        
        res.reserve(newlength+1); // to allocate space to copy the word then
       
        for(int i=0 ; i<newlength+1 ; i++){ // to copy the word
            res.word_[i]=newword[i];
        }
            
        
        res.len_ = len1 + len2 ;
        res.capacity_ = len1 + len2 + 1;
                
        delete[] newword;
        
        //################################################
        // Memory leak !!
        //################################################
    }
    else if(!possible)
    {
        std::cout << "ERROR: RESULT WOULD OVERSTEPS MAXIMAL LEGAL LENGTH"<<std::endl;
        //################################################
        // Memory leak !!
        //################################################
    }
    return res;
    //################################################
    // Problème : on retourne une variable locale !!
    //################################################
}

/* operator + (String) : String + String
    This operator allows to concatenate two string. 
    First, the algorithm sums the two lengths in order to find the 
    new one. Then it builds a empty String using the default
    constructor. A new aray of char of size equal 
    to the new capacity is build. This one is filled by char 
    contained in the left string and then by those in the rigth string.
    At the end of this operation the attributes words_, 
    len_ and capacity_ are updated.*/

String operator+(const String& lhs, const String& rhs)
{
    bool possible=1; // this operation is necessary to say wether s2 can be constructed or not (if char is not too long)
    
    int len1 = lhs.len_;
    int len2 = rhs.len_;
    int newlength= len1+ len2;
        
    if ( newlength >= String::MAX_LEN_)
    {
        possible=0;
    }
	
    String res;
    
    if(possible)
    {
        char *newword = new char [newlength+1];
        for (int i=0 ; i<=len1 ; ++i)
        {	
            newword[i] = lhs.word_[i];	
            std::cout <<"first part newword     " <<newword[i] << "    pos   :"<<  i<< std::endl;
        }
            for (int i=0 ; i<=len2 ; ++i)
        {	
            newword[len1+i] = rhs.word_[i];	
        }
        
        res.reserve(newlength+1); // to allocate space to copy the word then
        
        for(int i=0 ; i<newlength+1 ; i++){ // to copy the word
                res.word_[i]=newword[i];
            }
            
        res.len_ = len1 + len2 ;
        res.capacity_ = len1 + len2 + 1;
        
        delete[] newword;    
    }
    else if(!possible)
    {
        std::cout << "ERROR: RESULT OF LENGTH " << newlength << " WOULD OVERSTEPS MAXIMAL LEGAL LENGTH"<<std::endl;
    }
    return res;
    //################################################
    // Problème : on retourne une variable locale !!
    //################################################
}


// ####################################################################
// Destructor
// ####################################################################
String::~String()
{
	// Add the delete [var] here when you make a new manual allocation in a function.
    //if(capacity_>1){ // because else the pointer was never allocated
        delete [] word_ ; 
    //}
}
