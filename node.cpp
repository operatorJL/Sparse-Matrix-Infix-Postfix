#include "node.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


node::node()
{
	iValue=0;
	jValue=0;
	value=0;
	nodeLink=NULL;

}

node::node(int i,int j,double newValue)
{
	iValue=i;
	jValue=j;
	value=newValue;
	nodeLink=NULL;

}
 
  
  
//~node();









