class CommandLineParser
{
private:
	char *input;
	char delimiter;
	char* data;  // to store input data
	int inputSize; //size of input data 

public:
        char* extract(char*); // Method to extract the variable value
        CommandLineParser(char*,char); //constructor
	 void read_inputData(char* fileName); // to read input data from file
};