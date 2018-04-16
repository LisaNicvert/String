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
		char* word_; // Effective stor
		int len_; // The size of the string sequence terminated by \0
		int capacity_; // The size of the string sequence allocated by user (>= len)
	
		
	public:

		/*------------------------
    	* Constructors
   		 ------------------------*/

		/* Default constructor : 
		Using this constructor users could initialize a new string, with a null length and a null capacity.
		The pointer to world_ is set to a nullptr.*/
		String();

		/* Parameterized constructor :
		Using this constructor users could build a new string passing as argument an array of chars. This constructor
		uses the definition of a c-string to build a new string. That's it so say, while the algorithm doesn't reach the
		null character a counter sum the number of occurence. At the end of this while loop the counter is equal to
		the length. To calcul the capicity we add 1 to the current length. This allows to take into account the null character.
		Finally to initialize the attribute word_ the algorithm allocates a block of memory to contain an array of char of size
		equal to the current capacity_.
		Pre-conditions : The argument passe to this constructor is a c_string
		Post-conditions : If the c_string's size exceeds the maximal length authorize a warning message prevents this action.
						 Otherwize a literal string is built.
		*/
		String(const char word[]);

		/*------------------------
    	* Destructor
   		 ------------------------*/

		~String(); 

		/*------------------------
    	* Getters
   		 ------------------------*/
		/* Those three getters allow to acces to the private attributes.*/
		int len();
		char* word();
		int capacity();



		/*------------------------
    	* Methods
   		 ------------------------*/

		/* Display :
		The method display allows to print each char contained in the attribute word_ up to capacity_.*/
		void display(); 

		/* reserve:
		The method reserve allows to forecast a changement of size, like this the user could choose the future size of his string. 
		If the size choosen is upper than the current capacity_ a array of the planed size is created and this one is filled by the
		current word_. Otherwise this algorithm allows to optimize the capacity by building a new array of size equal to the current 
		len_ more one. Finally if the newsize exceed the capacity a warning message appears.
		In order to optimize the optimize the capacity a tempory array is created, then this one is filled with the word. The memory the 
		older word is free. Then the attribute word_ is updated using the temppory array. Then this tempory array is delete and the capacity 
		is updated.
		Post-condition : In any case, the string and its length are modified only the capacity of the array containing the string could be changed.
                If the forecasted size (newsier setted by user) is lower than MAX_LEN_ and if this one is lower than the current capacity_ a new array 
                of the wanted sized is created an the former one is delete.
                If the forecasted size is lower than MAX_LEN_ but this one s lower than the current capacoty_, a new array of char is created
                its size is adjusted to optimize the memory occupied by the string. Like this this size is set to the current len_ more one.
                If the capacity is ever eaqual to the current capacity_ nothing is done.
                Else if the forcast size exceed the capacity a warning messaga appears*/
		void reserve(int newsize);

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
		void resize(int newlenght, const char& c= 0);
		

		/* Empty :	
		The function empty allows to know if a string is empty or not returning a boolean. To do this the algorithm tests
		if the attribute len_ is superior to one or not.
		Pre_condition : A string
		Post-condition : The boolean returned is TRUE is len_ <=1 (?????) else this one is False
		*/
        bool empty();
        
        
        
		/*------------------------
    	* Operators
   		 ------------------------*/
        /* Operator = (char) 
		This operator allow to replace a string by a single char choosen.
		The array of char containing the string is deleted and a new string is initialized.
		Pre-conditions : A string 
		Post-conditions : A string containing a simple character choosen by the user.
		*/
		String& operator=(char c);

		/* operator = (char*)
		This operator allows to user to replace the current strign by a c-string.
		Firstly the algorithm counts the number of characters contained in the arrayof char. As a counter is associated to the number of turns executed by 
		a while loop, at the end of  the process the counter is equal to the length of the string. If the this length more 1 (the new capacity) exceeds the 
		MAX_LEN_ authorized, a warning message prevents yhis action. Othewise if the current capacity_ is equal to 
		the future capacity_, the algorithm just replaces the content of world_ attribte. If the current capacity_ is upper than the new one  
		the algorithm  copy the content of th e new word in p_word_, redefine len_ attribute and then use "reserve" to build a new sring. Calling 
		resreve method with the argument new capacity allow optimize the capacity_ of the buildig srting. If the current capacity_ is lower than 
		the new the method reserve is called one more time. Since the current capacity_ is inferior to the new one reserve create a new array  which will be
		an intermediate between the current word_ and the new one. Finaly the attribute p_word_ is initialized with a for loop and the new length is update.
		Pre-conditions : A current string is setted equal to  c_string
		Post conditions : If the capacity of the building string (length of the c-string more 1) is equal to the atual string, only the content of te attribute
						  word_ is updated,
						If the current capacity is upper that the new one, the attribute p_word_ is updated and resize method is used to optimize memory allocated 
						to the string and to update the attribute word_. 
						If the current capacity is lower than the new one, resize method is call to allocate memory in consequence and to update the attribute word.
						Else if the new capacity exceeds the MAX_LEN_ a  warnng message prevents this action.
		*/

        String& operator=(const char* c); 

        // sets the word to the content of specified char*
        // Output : pointer on the string + if too long, message "ERROR: PARAMETER OVERSTEPS MAXIMAL LEGAL LENGTH"
        // If char is shorter, capacity is resized


        /* operator + (char*) : String + char*
        This oeprator allows to concatenate a string with a c-string. Firstly the algorithm build a string usin g the parameterized constructor. It calculates the resulting
        length addieng the two lengths. Then it initializes a empty string (res), if the total length is lower than MAX_LENGTH a new array of size equal to the total length 
        more one is created. This array is filled with the two string. After the attributes word_, len_ and capacity_ of the resulting word are updated. If the total length 
        more one exceeds the MAX_LEN_, a warning message prevents this ation.
        Pre-conditions :  A String and a c-string
		Post-conditions : A new string is built by concatenation of these two element by building a new array of char. Any element are delete. So at the and of execution user 
						still have in memory the former string the c-string and the new string resulting of concatenation. However if the resulting capacity exceeds the MAX_LEN_
						a warning message prevets this action.

        */
		friend String operator+(const String& s, const char* c );

		/* operator + (char*) :  char* + string 
		This operator does exactly the same operation than the previous one, but allow to concatenate a c-string with a string. */
        friend String operator+(const char* c ,const String& s );


        /* operator + (String) : String + String
		This operator allows to concatenate two string. Firstly the lgorithm sums the to lengths in order to find the new one. Then it build a empty String using the default
		constructor. A new aray of char of size equal to the new capacity is build. This one is filled by char contained in the left string and then by those in the rigth string.
		At the end of this operation the attributes words_, len_ and capacity_ are update.
		Pre-conditions : To use this operator two strings are required.
		Post-conditions : A new string is built by contenations of these two string. This operation is allowed only if the resulting capacity doesn't exceed the MAX_LEN. 
        */
        friend String operator+(const String& lhs, const String& rhs);

};

#endif
