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

		String();

		// Methods
		void resize(int newlenght, const char& c= 0);
		~String(); // destructor
		int capacity();

		// Operator
		String& operator=(char c);
		
	  friend String operator+(const String& s, const char* c )
	   {
	
		String s2(c);
		std::cout << s2.word_<<std::endl;	
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

};

//String operator+(const String& s, const char* c )
//;
// friend operator+(String,String);
 //
// friend operator=(String,String);
	
#endif