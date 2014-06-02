#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

inline int countWords(char *string)
{
	int count = 0, i = 0;
	bool inWord = false;
	
	for(i = 0; i <= strlen(string); i++) {
		if ((*(string+i) == ' ' || *(string+i) == ',' || *(string+i) == '.' || *(string+i) == '\0')) {
			count++;
			inWord = false;
		} else {
			inWord = true;
		}
	}
	
	return count;
}

 
int main()
{
    char *str = new char[1025];
    int count = 0;
	
    ifstream base("input");
	
    while (!base.eof())
    {
        base.getline(str, 1024, '\n');
		count += countWords(str);
        cout << count << endl;
    }
	
    base.close();
    delete str;
 
    return 0;
}
