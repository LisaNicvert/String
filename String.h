# include <cstring>
# include <iostream>

class String{
	protected:
		static int MAX_LEN_; // Max possible length
		char* p_word_; // Address of first char of string
		char word_[1]; // Effective storage space allocated to the \0 terminated sequence
		int len_; // The size of the string sequence terminated by \0
		int capacity_; // The size of the string sequence allocated by user (>= len)
		~String(); // destructor
	public:
};
// friend operator+(String,String);
// friend operator+(String,char*);
// friend operator=(String,String);
// friend operator=(String,char*);
