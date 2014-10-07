#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
using namespace std;

#define IN_NAME "STUDENT.DAT"
#define OUT_NAME "STUDENT.OUT.DAT"

int main()
{
	srand(time(0));
	
    fstream inputFile(IN_NAME, ios::in | ios::out);
    fstream dublicateSearchInputFile;
    ofstream(OUT_NAME);
    fstream outFile(OUT_NAME, ios::in | ios::out);
	
    int n = 10;
 
    if (!inputFile.is_open() || !outFile.is_open()) {
		cerr << "ERROR! File can't opened. \n";
        exit(EXIT_FAILURE);
    }
	
	while(n > 0) {
		inputFile << rand()%10;
		if (n > 1) {
			inputFile << "\r\n";
		}
		cout << n << endl;
		n--;
	}
	
	inputFile.close();
	inputFile.clear();
	inputFile.open(IN_NAME);
	
	streampos position;
	bool needWrite;
	int currentNumber, currentNumberBuffer;
	
	while (!inputFile.eof()) {
		currentNumber = 0;
		needWrite = true;
		inputFile >> currentNumber;
		position = inputFile.tellg();
		
		cout << currentNumber << " pos " << position << endl;
		
		dublicateSearchInputFile.open(OUT_NAME, ios::in);

		while(!dublicateSearchInputFile.eof()) {
			cout << dublicateSearchInputFile.tellg() << " = " << position << endl;
			dublicateSearchInputFile >> currentNumberBuffer;

			if (currentNumber == currentNumberBuffer && dublicateSearchInputFile.tellg() != position) {
				needWrite = false;
				break;
			}
		}

		dublicateSearchInputFile.close();
		dublicateSearchInputFile.clear();
		
		if (needWrite) {
			outFile << currentNumber << endl;
		}
	}
	
	
    return 0;
}