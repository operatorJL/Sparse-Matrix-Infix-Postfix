 #include "Row.h"
 #include <iostream>
using namespace std; 
		
		
		
Row::Row()
{
	nextRow = NULL;
	newEntry = new node;
	headNode = newEntry;
	nodeCount=1;
}

Row::Row(int i, int j, double newVal)
{
	nextRow = NULL;
	newEntry = new node(i,j,newVal);
	headNode = newEntry;
	nodeCount=1;
	rowIndex=i;

}

void Row::addNode()
{
	nodeCount++;

}