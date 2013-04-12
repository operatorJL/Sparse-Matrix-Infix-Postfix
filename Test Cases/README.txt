**********************
* Joel Loucks
* 
* October 26, 2012
**********************



Sparse Matrix Program!

using the Borland C++ compiler
make sure your path in the command line is set to the folder that the project is in and compile.

bcc32 sparse.cpp clp.cpp List.cpp Row.cpp node.cpp MatrixArray.cpp ArrayStack.cpp


once that has compiled run the program with the following statement
making sure the files to be run are in the same directory

sparse storage<linkedlist|array>;script<file>

when the program runs, any errors in the file will send a message to the screen notifying the user

the estimated time complexity for both my array and linked list are O(n^2)