#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

static int a[7] = {0, 1, 2, 3, 4, 5, 6};

float p(int x) {
	float result = 0;
	
	for(int i = 1; i < 6; i++) {
		result += a[i]*pow(x, i);
	}	
	
	return result;
}

float algoritm(int x) {
	cout << "p(" << x << "+1)-p(" << x << ") = " << ((p(x+1))-(p(x))) << endl;
}

int main(int argc, char *argv[])
{         	
	algoritm(1);
	algoritm(3);
	algoritm(4);
	
    return EXIT_SUCCESS;
}
