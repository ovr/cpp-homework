#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{         
	char* inputString;
	inputString = (char*) malloc(100*sizeof(char));
	int spaceCount = 0;
	
	cin.getline(inputString, 100);
	
	for (int i=0; i < strlen(inputString); i++)
    {
		if (*(inputString+i) == ' ') {
			spaceCount++;
		}
    }
	
	cout << "Input string: " << inputString << endl;
	cout << "Space count " << spaceCount << endl;
	
	delete(inputString);
	
    return EXIT_SUCCESS;
}
