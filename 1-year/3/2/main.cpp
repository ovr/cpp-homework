#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;

void func(char txt[], const char *str)
{
    char const* pstr = str;
    char* ptxt = txt;
	
    for(pstr = str; *pstr; ++pstr)
    {
        for(ptxt = txt; *ptxt; )
        {
            if(*pstr == *ptxt)
                memmove(ptxt, ptxt + 1, strlen(ptxt));
            else
                ++ptxt;
        }
    }
}
 
int main()
{
	char txt[] = "Hello man";
	const char *str = "Hllod";
	
	func(txt, str);
	cout << txt << endl;
	
	return EXIT_SUCCESS;
}
