#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>
#include "ArrayStack.h"
using namespace std;

ArrayStack::ArrayStack()
{	
	
	stackTop=-1;
	max=50;
	
}



string ArrayStack::evaluateInFix(string &expression)
{
	string newExpres;
	string check;
	//cout<<"expression\n";
	//cout<<expression<<endl;
	
	for(int i=0; i<abs(expression.length()); i++)
	{	
		check=expression[i];
		
		if(check=="+")
		{	
			if(isEmptyStack())
			{	
				push(check);
			}
			else if (expres[stackTop]=="*")
			{
				newExpres+=expres[stackTop];
				pop();
				push(check);
			}
			else if(expres[stackTop]=="+")
			{	
				newExpres+=expres[stackTop];
				pop();
				push(check);
			}
			else
			{
				push(check);
			}
			
		}
		else if(check=="*")
		{
			if(isEmptyStack())
			{	
				push(check);
			}
			else if (expres[stackTop]=="*")
			{
				newExpres+=expres[stackTop];
				pop();
				push(check);
			}
			else if(expres[stackTop]=="+")
			{	
				push(check);
			}
			else
			{
				push(check);
			}				
		
		}
		else if(check=="(")
		{
			push(check);
		}
		else if(check==")")
		{	
			while((expres[stackTop]!="(") && (!isEmptyStack()))
			{	
				newExpres+=expres[stackTop];
				pop();
			}
	
			if(expres[stackTop]=="(")
			{	
				pop();
			}	
		}
		else
		{	
			newExpres+=check;
		}
		
		if(i==abs(expression.length()-1))
		{
			while(!isEmptyStack())
			{	
				string temp=expres[stackTop];
				newExpres+=temp;
				pop();
			}
		}
	}
	
	return newExpres;	
}

/*void ArrayStack::evaluatePosFix(string& expression)
{

}*/

void ArrayStack::initializeStack()
{
	stackTop=-1;
}

bool ArrayStack::isEmptyStack()
{
	return (stackTop==-1);
}

bool ArrayStack::isFullStack()
{
	return (stackTop==max);
}

void ArrayStack::push(string &opera)
{	
	//cout<<"pushing "<<opera<<endl;

	if(!isFullStack())
	{	
		stackTop++;
		expres[stackTop]=opera;
	}
}

void ArrayStack::pop()
{
	//cout<<"popping \n";
	if(!isEmptyStack())
	{	
		stackTop--;
	}
	else
	{
		cout<<"Empty Stack!\n";
	}

}

string ArrayStack::top()
{
	if(!isEmptyStack())
	{
		return expres[stackTop];
	}
	
	return " ";
}
