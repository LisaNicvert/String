# include <cstring>
# include <iostream>
#ifndef STRING_H
#define STRING_H

class String{
	protected:
		static int MAX_LEN_; // Max possible length
		//char* p_word_; // Address of first char of string
		char* word_; // Effective storage space allocated to the \0 terminated sequence
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

		// Operator
		String& operator=(char c);
};
// friend operator+(String,String);
// friend operator+(String,char*);
// friend operator=(String,String);

	
#endif