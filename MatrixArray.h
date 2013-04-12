/***********************************
Header file for matrix class

************************************/
#include <string>
#include <iostream>
#include <map>
class MatrixArray
{
	public:
		
		double matrix[101][101];
		int maxI;
		int maxJ;
		std::string variable;
		std::map<std::string,MatrixArray>;
	
	
	MatrixArray();
	MatrixArray(double newMatrix[][101], int,int);
	MatrixArray(const MatrixArray&);
	
	void readFile(std::string&);
	void printMatrix(std::string&);
	void setValue(int,int,double);
	double getValue(int,int);
	void setMaxI(int);
	int getMaxI();
	void setMaxJ(int);
	int getMaxJ();
	const MatrixArray operator *(const MatrixArray& B);
	const MatrixArray& operator =(const MatrixArray& B);
	void arrayAdd(MatrixArray&,MatrixArray&,MatrixArray&,int, int);
	void printScreen();

};

