#include <string>
 class ArrayStack
 {
	public:
	
		int stackTop;
		int max;
		std::string expres[20];
		
		
		ArrayStack();
		void createArrayObs();
		std::string evaluateInFix(std::string&);
		//void evaluatePosFix(std::string&);
		void initializeStack();
		bool isEmptyStack();
		bool isFullStack();
		void push(std::string&);
		void pop();
		std::string top();
		
		
		
 
 
 
 
 
 };