#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

#define checkWord(startPosition, endPosition, string) \
{ \
	if (*(string+startPosition) == *(string+endPosition)) { \
		while(startPosition <= endPosition) { \
			cout << *(string+(startPosition++)); \
		} \
		\
		cout << endl; \
	} \
}

int main(int argc, char *argv[])
{         
	char* inputString;
	inputString = (char*) malloc(100*sizeof(char));
	int wordStartPosition = 0;
	int inputStringLenght;
	bool inWord = true;
	
	cin.getline(inputString, 100);
	
	inputStringLenght = strlen(inputString); 
	cout << "Input string: " << inputString  << " lenght " << inputStringLenght << endl;
		
	for (int i= 0; i <= inputStringLenght; i++) {
		if ((*(inputString+i) == ' ' || *(inputString+i) == ',' || *(inputString+i) == '.' || *(inputString+i) == '\0')) {
			checkWord(wordStartPosition, i-1, inputString);
			inWord = false;
		} else {
			if (!inWord) {
				wordStartPosition = i;
			}
			
			inWord = true;
		}
    }
	
	delete(	inputString);
	
    return EXIT_SUCCESS;
}
