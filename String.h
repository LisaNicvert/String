# include <cstring>
# include <iostream>

class String{
	protected:
		static int MAX_LEN_; // Max possible length
		//char* p_word_; // Address of first char of string
		char* word_; // Effective storage space allocated to the \0 terminated sequence
		int len_; // The size of the string sequence terminated by \0
		int capacity_; // The size of the string sequence allocated by user (>= len)
	public:
		//Constructors
		String(char word[]);
		int len();

		~String(); // destructor
		int capacity(); // returns capacity_
		bool empty(); // returns true if the string is empty
		void reserve(int newsize);
	
};
// friend operator+(String,String);
// friend operator+(String,char*);
// friend operator=(String,String);

//friend operator=(String,char*); // assign a new value to the String, changing its size (len_) and capacity_


