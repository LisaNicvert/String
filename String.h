# include <cstring>
# include <iostream>
#ifndef STRING_H
#define STRING_H

class String{
	protected:
		static int MAX_LEN_; // Max possible length
		char* p_word_; // Address of first char of string
		char* word_; // Effective storage space allocated to the \0 terminated sequence
        
        // ####################################################################
        // J'ai remis p_word car j'ai besoin de word_[] pour la méthode reserve
        // ####################################################################
        
		int len_; // The size of the string sequence terminated by \0
		int capacity_; // The size of the string sequence allocated by user (>= len)
	public:
		//Constructors
		String(const char word[]);
		int len();
		char* word();

		// Methods
		void resize(int newlenght, char& c);
		~String(); // destructor
		int capacity();
        bool empty();
        void display(); // displays the content of all the bytes allocated (up to capacity)
        void reserve(int newsize);
        
		// Operator
		String& operator=(char c);
        String& operator=(const char* c); // sets the word to the content of specified char*
        // Output : pointer on the string + if too long, message "ERROR: PARAMETER OVERSTEPS MAXIMAL LEGAL LENGTH"
        // If char is shorter, capacity is resized
};
// friend operator+(String,String);
// friend operator+(String,char*);
// friend operator=(String,String);

	
#endif
