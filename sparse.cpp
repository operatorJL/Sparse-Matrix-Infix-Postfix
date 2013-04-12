//Joel Loucks
//1033681
#include <iostream>
#include <fstream>
#include <string>
#include <stack.h>
#include "clp.h"
#include "MatrixArray.h"
#include "List.h"
#include "ArrayStack.h"
using namespace std; 

ifstream scin;


int main(int argc,char** argv)
{	
	CommandLineParser clp(argv[1],';');  
	
	char *v1 = clp.extract("storage");
	char *v2 = clp.extract("script");
	
	string storage = v1;

	if(v1 == NULL ) {
		cout<<"There is no file1 name!\n";
	}
	if(v2 ==NULL){
		cout<<"There is no file2 name!\n";
	}
	//declare variables
	int fileCount=0;
	int outputCount=0;
	int numExpres;
	string input;
	string input2;
	string check;
	int openDelim;
	int closeDelim;
	
	if(storage=="array")
	{
		//declare objects
		MatrixArray *arrays = new MatrixArray[15];
		MatrixArray tempA;
		MatrixArray tempB;
		MatrixArray result;
		ArrayStack arrayStack;
		stack<MatrixArray> matStack;
	
		scin.open(v2);
		while(!scin.eof())
		{
			getline(scin,input);
		
			if(input[0]=='#')
				continue;
				
			if(input[0]==' ')
				continue;
	
			if(!input.find("read"))
			{	
				openDelim=input.find_first_of('"');
				closeDelim=input.find_last_of('"');
	
				input2=input.substr((openDelim+1), ((closeDelim-openDelim)-1));

			
				int var =input2.find_first_of('.');
				string variable = input2.substr(0,var);
			
				arrays[fileCount].readFile(input2);

				fileCount++;
			}
			else if(!input.find("write"))
			{
				openDelim=input.find_first_of('(');
				closeDelim=input.find_last_of(')');
				
				if(openDelim<closeDelim)
				{
					input2=input.substr((openDelim+1), ((closeDelim-openDelim)-1));
			
					for(int j=0; j<fileCount; j++)	
					{
						if(input2==arrays[j].variable)
						{
							//arrays[j].printScreen();
							input2+=".txt";
							arrays[j].printMatrix(input2);
						}
					}
				}
				else
				{
					input2=input.substr((closeDelim+1), ((openDelim-closeDelim)-1));
			
					for(int j=0; j<fileCount; j++)	
					{
						if(input2==arrays[j].variable)
						{
							//arrays[j].printScreen();
								input2+=".txt";
							arrays[j].printMatrix(input2);
						}
					}
					
				}
				
					
				outputCount++;
			}
			else
			{	
				string infix;
				string posfix;
				string write;
			
				//parsing the write file and expression
				openDelim=input.find_first_of('=');
				write=input.substr(0,openDelim);
				infix=input.substr(openDelim+1);
				
				posfix=arrayStack.evaluateInFix(infix);
			
				cout<<posfix<<endl;
				
				for(int j=0; j<abs(posfix.length()); j++)
				{
					check=posfix[j];
					string op1="";
					string op2="";
					bool opA=true;
					bool opB=true;
					
					if(check=="*")
					{	
						if(!matStack.empty())
						{	
							tempB=matStack.top();
							matStack.pop();
						}
						else
						{	opB=false;
							cout<<"not enough operands!\n";
						}
					
						if(!matStack.empty())
						{	
							tempA=matStack.top();
							matStack.pop();
						}
						else
						{
							opA=false;
							cout<<"not enough operands!\n";
						}
						
						if(opA && opB)
						{						
							result=tempA*tempB;
							matStack.push(result);
							continue;
							
						}
						else
						{
							cout<<"cannot multiply\n";
							continue;
						}
						
						
					}	
					if(check=="+")
					{	
						if(!matStack.empty())
						{	
							tempB=matStack.top();
							matStack.pop();
						}
						else
						{	
							opB=false;
							cout<<"not enough operands!\n";
						}
				
						if(!matStack.empty())
						{	
							tempA=matStack.top();
							matStack.pop();
						}
						else
						{
							opA=false;
							cout<<"not enough operands!\n";
						}
						
						if(opA && opB)
						{
							tempA.arrayAdd(tempA,tempB,result,1,1);
						
							matStack.push(result);
							continue;
						}
						else
						{
							cout<<"cannot add\n";
							continue;
						}
					}	
					else
					{	
						for(int k=0; k<fileCount; k++)
						{
							if(arrays[k].variable==check)
							{	
								tempA=arrays[k];
								matStack.push(tempA);
							}
						}
					}
				}
			
				if(!matStack.empty())
				{	
					result=matStack.top();
					matStack.pop();
					
					result.variable=write;
					arrays[fileCount]=result;
					fileCount++;
					numExpres++;
				}
			}
		}
		
		if(!matStack.empty())
		{
			result=matStack.top();
			result.printScreen();
		}
	}
	else if(storage=="linkedlist")
	{
		//declare objects
		List *lists = new List[10];
		List result;
		ArrayStack arrayStack;
		stack<List> listStack;
		
		fileCount=0;
		
	
		scin.open(v2);
		while(!scin.eof())
		{		
			getline(scin,input);
		
			if(input[0]=='#')
				continue;
				
			if(input[0]==' ')
				continue;
	
			if(!input.find("read"))
			{	
				openDelim=input.find_first_of('"');
				closeDelim=input.find_last_of('"');
	
				input2=input.substr((openDelim+1), ((closeDelim-openDelim)-1));

			
				//int var =input2.find_first_of('.');
				//string variable = input2.substr(0,var);
			
				lists[fileCount].readFile(input2);

				fileCount++;
			}
			else if(!input.find("write"))
			{			
				openDelim=input.find_first_of('(');
				closeDelim=input.find_last_of(')');
				
				if(openDelim<closeDelim)
				{
					input2=input.substr((openDelim+1), ((closeDelim-openDelim)-1));
			
					for(int j=0; j<fileCount; j++)	
					{
						if(input2==lists[j].variable)
						{
							//lists[j].printScreen();
							input2+=".txt";
							lists[j].printFile(input2);
						}
					}
				}
				else
				{
					input2=input.substr((closeDelim+1), ((openDelim-closeDelim)-1));
			
					for(int j=0; j<fileCount; j++)	
					{
						if(input2==lists[j].variable)
						{
							//lists[j].printScreen();
								input2+=".txt";
							lists[j].printFile(input2);
						}
					}
					
				}
					
				outputCount++;
			}
			else
			{	
				string infix;
				string posfix;
				string write;
			
				//parsing the write file and expression
				openDelim=input.find_first_of('=');
				write=input.substr(0,openDelim);
				infix=input.substr(openDelim+1);
				
				posfix=arrayStack.evaluateInFix(infix);
			
				cout<<posfix<<endl;
			
				for(int j=0; j<abs(posfix.length()); j++)
				{
					check=posfix[j];
					string op1="";
					string op2="";
					bool opA=true;
					bool opB=true;
					
					if(check=="*")
					{	
						List tempA;
						List tempB;
						
						if(!listStack.empty())
						{	
							tempB=listStack.top();
							listStack.pop();
						}
						else
						{	opB=false;
							cout<<" * not enough operands!\n";
						}
			
						if(!listStack.empty())
						{
							tempA=listStack.top();
							listStack.pop();
						}
						else
						{
							opA=false;
							cout<<" * not enough operands!\n";
						}
						
						if(opA && opB)
						{	
							List result1;
							
							tempA.multiply(tempB,result1);
							listStack.push(result1);
						
							continue;
							
						}
						else
						{
							cout<<"cannot multiply\n";
							continue;
						}	
					}	
					if(check=="+")
					{
						List tempA;
						List tempB;
						
						if(!listStack.empty())
						{
							tempB=listStack.top();
							listStack.pop();
						}
						else
						{	
							opB=false;
							cout<<" + not enough operands!\n";
						}
					
						if(!listStack.empty())
						{	
							tempA=listStack.top();
							
							listStack.pop();
						}
						else
						{
							opA=false;
							cout<<" + not enough operands!\n";
						}
						
						if(opA && opB)
						{	
							List result1;
							
							tempA.addMatx(tempA,tempB,result1,1,1);
							
							listStack.push(result1);
							continue;
						}
						else
						{
							cout<<"cannot add\n";
							continue;
						}
					}	
					else
					{	
						List tempA;
						
						for(int k=0; k<fileCount; k++)
						{
							if(lists[k].variable==check)
							{	
								tempA=lists[k];
								listStack.push(tempA);
							}
						}
					}
				}
			
				if(!listStack.empty())
				{	
					List result1;
					
					result1=listStack.top();
					listStack.pop();
					
					result1.variable=write;
					lists[fileCount]=result1;
					fileCount++;
				}
			}	
			
		}
		
		if(!listStack.empty())
		{	
			List result1;
			result1=listStack.top();
			result1.printScreen();
		}
	}
		
		
	cout<<"\n*Thank you for using the sparse matrix multiplier/adder!*\n";
	cout<<"\t*Now with arrayStacks for crazier expressions!*\n";

	return 0;
}




