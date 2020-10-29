#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Usage : ./assign3 <fileName>" << endl;
        return -1;
    }
    
    ifstream fin;
    fin.open(argv[1], ios::in);
    
    if(!fin.is_open())
    {
        cout << "File not found." << endl;
        return -1;
    }
    char c;
    int lineNo = 1;
    bool syntaxErrorFound = false;
    GenStack<char> genStack;
    
	while (fin.get(c)) {

    	if(c == '\n')
    	{
    	    lineNo++;
    	    continue;
    	}
    	
		if(c == '{' || c == '(' || c == '[')
		{
		    genStack.push(c);
		    continue;
		}
		if(c == '}' || c == ')' || c == ']')
		{
		    if(genStack.isEmpty())
		    {
		        cout << "Line " << lineNo << ": Unexpected symbol " << c << "found." << endl;
		        syntaxErrorFound = true;
		        break;
		    }
		    char openC = genStack.pop();
		    if((openC == '{' && c != '}') || (openC == '(' && c != ')') || (openC == '[' && c != ']'))
		    {
		        cout << "Line " << lineNo << ": expected " << openC << " and found " << c << endl;
		        syntaxErrorFound = true;
		    }
		}
	}
	
	while(!genStack.isEmpty())
    {
        char openC = genStack.pop();
        char closeC = '}';
        if(openC == '[')
            closeC = ']';
        else if(openC == '(')
            closeC = ')';
        cout << "Reached end of file: missing " << closeC << endl;
        syntaxErrorFound = true;
    }
    
    if(!syntaxErrorFound)
    {
        cout << "No Syntax error found." << endl;
    }
    
    return 0;
}
