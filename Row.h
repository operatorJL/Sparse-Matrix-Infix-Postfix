 #include "node.h"


class Row
{
	public:
	
		
		node* newEntry;
		node* headNode;
		Row* nextRow;
		int nodeCount;
		int rowIndex;
		
		
		
		Row();
		Row(int,int,double);
		void addNode();


};