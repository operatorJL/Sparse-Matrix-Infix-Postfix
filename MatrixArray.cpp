/***********************************
matrix class 
************************************/
#include <iostream>
#include <map>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <string>
#include "MatrixArray.h"
using namespace std;

ifstream in;
ofstream fout;

/***********************************
	default constructor to initialize 
	matrix values
************************************/
MatrixArray::MatrixArray()
{
	//map<std::string,MatrixArray>;
	for(int i=0; i<101; i++)
	{
		for(int j=0; j<101; j++)
			matrix[i][j]=0.0;
	}
	
	maxI=1;
	maxJ=1;
	variable="";
	
}

/***********************************
	constructor that is called
	after overloaded operator 
************************************/
MatrixArray::MatrixArray(double newMatrix[][101], int newI, int newJ)
{
	maxI=newI;
	maxJ=newJ;
	for(int r=1; r<=newI; r++)
	{
		for(int c=1; c<=newJ; c++)
			matrix[r][c]=newMatrix[r][c];
	}
	
}

//copy constructor
MatrixArray::MatrixArray(const MatrixArray& cpy)
{
	for(int i=1; i<=cpy.maxI; i++)
	{	
		for(int j=1; j<=cpy.maxJ; j++)
		{	
			matrix[i][j]=cpy.matrix[i][j];
		}
	}
	
	variable=cpy.variable;
	
	maxI=cpy.maxI;
	maxJ=cpy.maxJ;
}

/***********************************
	takes the input file that was
	parsed from clp.cpp, opens it
	and does error checking on inputs 
	and assigns them in the matrix
************************************/
void MatrixArray::readFile(string &file)
{
	string input=" ";
	int linenum=0;
	int i=1;
	int j=1;
	double value=0.0;
	
	in.open(file.c_str());
	
	if(in.fail())
	{
		cout<<"could not open the file\n";
		cout<<"please retry with a new file\n";
		return;
	
	}
	
	int var =file.find_first_of('.');
	variable = file.substr(0,var);
	
	//arMap.insert(std::pair<string, MatrixArray>(input2,arrays[fileCount])
	
	
	
	while(!in.eof())
	{
			++linenum;
				
			getline(in,input);
			
			if(input[0]=='#')
				continue;
			else	
			{
				istringstream lineparse(input);
				
			
				if(!(lineparse>> i >> j >> value))
				{
					//cout<<"\nError line "<<linenum<<endl;
					continue;
				}
				
				lineparse>> i >> j >> value;					
					
				if(i<0)
				{
					cout<<"\nline "<<linenum<< " has negative i entry \n";
					continue;
				}
				
				if(j<0)
				{
					cout<<"\nline "<<linenum<< " has negative j entry \n";
					continue;
				}
				
				if(maxI<=i)
					maxI=i;
					
				
				if(maxJ<=j)
					maxJ=j;
								
				matrix[i][j]=value;	
			}
	
	}
	
	in.close();
	
	
}

//seting the value
void MatrixArray::setValue(int i, int j, double value)
{
	matrix[i][j]=value;
}

//retrieving the value
double MatrixArray::getValue(int i, int j)
{

	return matrix[i][j];
	
}

//setting the max I
void MatrixArray::setMaxI(int newMaxI)
{
	maxI=newMaxI;
}
//retrieving the max I
int MatrixArray::getMaxI()
{
	return maxI;
}

//setting the max J
void MatrixArray::setMaxJ(int newMaxJ)
{
	maxJ=newMaxJ;
}

//retrieving the max J
int MatrixArray::getMaxJ()
{
	return maxJ;
}

/*************************************
	printing the result matrix in
	sparse list form.  finds a value
	in matrix < or > 0 and prints
	the i and j values then the value

*************************************/
void MatrixArray::printMatrix(string &file)
{	
	fout.open(file.c_str());
	
	fout<<"#Matrix C\n";
	fout<<"#Array\n";
	
	for(int i=1; i<=maxI; i++)
	{	
		for(int j=1; j<=maxJ; j++)
		{
			if((matrix[i][j]<0) || (matrix[i][j]>0))
			{
				fout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
					
			}	
				
		}
	}		
	
	if(matrix[maxI][maxJ]==0)
	{
		fout<<maxI<<" "<<maxJ<<" 0\n";

	}
	fout<<endl;	
	
	fout.close();
	
	
}
/*************************************
overloaded operator to do matrix
multiplication.  returns an anonymous
object 
**************************************/

const MatrixArray MatrixArray::operator *(const MatrixArray& matxB)
{
	double cMatrix[101][101]= {0.0};
	
	if(maxJ != matxB.maxI)
		{
			cout<<"Invalid matrix dimensions\n";
			cout<<"cannot multiply matrices\n";
		}
	else
	{
		for (int i=1 ; i<=maxI; i++)
		{	
			for (int j=1;  j<=matxB.maxJ; j++)
			{	
				for (int k=1; k<=matxB.maxI; k++)
				{	
					cMatrix[i][j] += matrix[i][k] * matxB.matrix[k][j];
				}
			}
		}
		return MatrixArray(cMatrix, maxI, matxB.maxJ);	
	}

	return MatrixArray();
}

const MatrixArray& MatrixArray::operator =(const MatrixArray& B)
{
	
	for(int i=1; i<=B.maxI; i++)
	{	
		for(int j=1; j<=B.maxJ; j++)
		{
			matrix[i][j]=B.matrix[i][j];
		}
	}
	
	maxI=B.maxI;
	maxJ=B.maxJ;
	
	variable=B.variable;
	
	return *this;
}

/************************************************
	function to add matrices recursively
	checks if the dimensions are the same
	if not it returns and does not perform any operations
	also returns if the i or j is larger than the maximum indexes

**************************************************/
void MatrixArray::arrayAdd(MatrixArray& A,MatrixArray& B, MatrixArray &C, int i, int j)
{
	double sum;
	
	
	if((A.maxI!=B.maxI) || (A.maxJ!=B.maxJ))
	{
		cout<<"\nCan not add matrices of different size\n";
		return;
	}
	else if(((i>A.maxI) && (i>B.maxI)) || ((j>A.maxJ) && (j>B.maxJ)))
	{	
		C.maxI=A.maxI;
		C.maxJ=B.maxJ;
		return;
	}
	else
	{	
		sum = A.matrix[i][j] + B.matrix[i][j];
		
		if(sum!=0)
		{
			C.matrix[i][j]=sum;
			
			if(j==maxJ)
			{
				j=1;
				arrayAdd(A,B,C,(i+1),(j));
			}
			else
			{
				arrayAdd(A,B,C,(i),(j+1));
			}
		}
		else
		{
			if(j==A.maxJ)
			{
				j=1;
				arrayAdd(A,B,C,(i+1),(j));
			}
			else
			{
				arrayAdd(A,B,C,(i),(j+1));	
			}
		}	
	}
}
/*******************************
	printing to the screen 
	for error checking
********************************/
void MatrixArray::printScreen()
{	
	cout<<"Matrix: "<<variable<<endl;

	for(int i=1; i<=maxI; i++)
	{	
		for(int j=1; j<=maxJ; j++)
		{
			if(matrix[i][j]<0 || matrix[i][j]>0)
				{
					cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
					
				}
		}
	}
}	