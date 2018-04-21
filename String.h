# include <cstring>
# include <iostream>
#ifndef STRING_H
#define STRING_H

class String{
	protected:
		static int MAX_LEN_; // Max possible length
		char* p_word_; // Address of first char of string
		char* word_; // Effective storage space allocated to the \0 terminated sequence
		int len_; // The size of the string sequence terminated by \0
		int capacity_; // The size of the string sequence allocated by user (>= len)
	
		
	public:
		//Constructors
		String(const char word[]);
		String();

        // Getters / setters
        int len();
		char* word();
        int capacity(); /* getter for the capacity of the String
        Returns the capacity, ie the size of the string sequence allocated by user */
        
		// Methods
		void resize(int newlenght, const char& c= 0);
		~String(); // destructor
        bool empty(); /* returns a boolean to check if the string is empty
        returns 1 (true) if empty,
        0 (false) if non-empty */
        void display(); /* displays the content of all the bytes allocated (up to capacity)
        This method is suited for tests, to see if the capacity chosen by the user has been granted.
        Postconditions: if the string is empty, displays "Empty string" */
        void reserve(int newsize); /* Allows the user to manually reserve storage space for the string.
        Postconditions: if the size is greater than 100, a message is displayed : 
            "ERROR: RESULT OF CAPACITY [user chosen capacity] WOULD OVERSTEPS MAXIMAL LEGAL LENGTH" 
            and the capacity doesn't change.
        if the capacity is the same, a message is displayed: "The size is already this one!" 
            and the capacity doesn't change.
        if the capacity is smaller than the current capacity (or negative), the capacity is reduced 
            to be the exact capacity needed to contain the word. 
        else the capacity is adjusted to the one demanded. */
        
		// Operators
		String& operator=(char c); 
        String& operator=(const char* c); /* sets the word to the content of specified char* 
        and returns pointer on the string.
        Postconditions:  if the char c is too long, 
            a message "ERROR: PARAMETER OVERSTEPS MAXIMAL LEGAL LENGTH" is displayed and the string doesn't change.
        If the char c is shorter, capacity is resized. */
		friend String operator+(const String& s, const char* c );
        friend String operator+(const char* c ,const String& s );
        friend String operator+(const String& lhs, const String& rhs); /* allows to concatenate two strings.
        Postconditions: if the resulting size is greater than 100, a message is displayed : 
            "ERROR: RESULT OF LENGTH [resulting length] WOULD OVERSTEPS MAXIMAL LEGAL LENGTH" 
        and the capacity doesn't change. */

};

#endif
