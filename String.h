# include <cstring>
# include <iostream>
#ifndef STRING_H
#define STRING_H

class String{
	protected:

		/*------------------------
    	* Attributes
   		 ------------------------*/
		static int MAX_LEN_; // Max possible length
		char* p_word_; // Address of first char of string
		char* word_; // Effective storage space allocated to the \0 terminated sequence
		int len_; // The size of the string sequence terminated by \0
		int capacity_; // The size of the string sequence allocated by user (>= len)
	
		
	public:

		/*------------------------
    	* Constructors
   		 ------------------------*/

		/* Default constructor : 
		Using this constructor, users may initialize a new string, 
        with a null length and a null capacity.
		The pointer to world_ is set to a nullptr.*/
		String();

		/* Parameterized constructor :
		Using this constructor, users may build a new string passing as 
        argument an array of chars.
		Post-conditions : If the c_string's size exceeds the maximal 
            length authorized, a warning message prevents this action.
            Otherwize a literal string is built.
		*/
		String(const char word[]);

        /*------------------------
    	* Getters
   		 ------------------------*/
        /* Those three getters allow to acces to the private attributes.*/
        int len();
		char* word();
        int capacity();

		/*------------------------
    	* Destructor
   		 ------------------------*/
		~String(); 
        
		/*------------------------
    	* Methods
   		 ------------------------*/

		/* Display :
		Displays the content of all the bytes allocated (up to capacity)
        This method is suited for tests, to see if the capacity chosen by the user has been granted.
        Postconditions: if the string is empty, displays "Empty string" */
		void display(); 
        
        /* Reserve:
        Allows the user to manually reserve storage space for the string.
        Postconditions: if the size is greater than 100, a message is displayed : 
            "ERROR: RESULT OF CAPACITY [user chosen capacity] WOULD OVERSTEPS MAXIMAL LEGAL LENGTH" 
            and the capacity doesn't change.
        if the capacity is the same, a message is displayed: "The size is already this one!" 
            and the capacity doesn't change.
        if the capacity is smaller than the current capacity (or negative), the capacity is reduced 
            to be the exact capacity needed to contain the word. 
        else the capacity is adjusted to the one demanded. */
        void reserve(int newsize); 


		/* Resize :
		The method resize allows to users to redefine the size of a 
        string passing as arguement the new length of string. 

		Post-conditions : if newlength < len_, exceedent char are 
            deleted,
            if  len_< newlength < max_size, memory is allocated 
            if no argument has been passed, '\0' is added at the end 
            of the string.
            Otherwise the string is extended with the choosen char.
            If newlength > max_size, no action is possible a warning 
            message : "Sorry the max size is excedeed." appears.*/

		void resize(int newlenght, const char& c= 0);
		

		/* Empty:
        returns a boolean to check if the string is empty
        returns 1 (true) if empty,
        0 (false) if non-empty */
        bool empty();
        
		/*------------------------
    	* Operators
   		 ------------------------*/
        /* Operator = (char) 
		This operator allows to replace a string by a choosen single 
        char.

		Post-conditions : A string containing a simple character 
            choosen by the user is returned.
		*/
		String& operator=(char c);

        /* Operator = (char*)
        sets the word to the content of specified char* 
        and returns pointer on the string.
        Postconditions:  if the char c is too long, 
            a message "ERROR: PARAMETER OVERSTEPS MAXIMAL LEGAL LENGTH" is displayed and the string doesn't change.
        If the char c is shorter, capacity is resized. */
        String& operator=(const char* c); 


        /* operator + (char*) : String + char*
        This operator allows to concatenate a string with a c-string. 

		Post-conditions : A new string is built by concatenation 
            of these two element by building a new array of char. 
            There are no elements deleted, so at the and of execution,
            the user still has in memory the former string, the c-string 
            and the new string resulting of concatenation. 
            If the resulting capacity exceeds the MAX_LEN_,
            a warning message : "ERROR: RESULT OF LENGTH 
            [resulting length] WOULD OVERSTEPS MAXIMAL LEGAL LENGTH" 
            is displayed and the string doesn't change.*/
		friend String operator+(const String& s, const char* c );
		/* operator + (char*) :  char* + string 
		This operator does exactly the same operation than the previous 
            one, but allow to concatenate a c-string with a string. */
        friend String operator+(const char* c ,const String& s );
        
        /* operator + (string)
            allows to concatenate two strings.
        Postconditions: if the resulting size is greater than 100, a message is displayed : 
            "ERROR: RESULT OF LENGTH [resulting length] WOULD OVERSTEPS MAXIMAL LEGAL LENGTH" 
        and the capacity doesn't change. */		
        friend String operator+(const String& lhs, const String& rhs);

};

#endif
