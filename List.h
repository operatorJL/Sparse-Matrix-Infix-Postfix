#include "Row.h"
#include <string>
#include <iostream>

class List
{	
	public:
		
		Row *head;
		Row *newRow;
		node *newNode;
		Row *currentRow;
		node *currentNode;
		node *cHead;
		int maxI;
		int maxJ;
		int i;
		int j;
		int rowcount;
		double tempVal;
		std::string input;
		std::string variable;
		
		List();
		~List();
		List(const List&);
		void destroyList();
		void readFile(std::string&);
		void addEntry(int,int,double);
		double search(int,int);
		void printScreen();
		void printFile(std::string&);
		void setNodes();
		void multiply(List&,List&);
		void addMatx(List&,List&,List&,int,int);
		const List& operator =(const List& B);
};