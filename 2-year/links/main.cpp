#include <iostream>
#include <cmath>

using namespace std;

void rec(float a, float b, float c, float &p, float &s) {
	p = a+b+c;

	float tmp;
	tmp = (a+b+c)/2;

	s = sqrt(tmp*(tmp-a)*(tmp-b)*(tmp-c));
}

#define REC(a, b, c) \
	rec(a, b, c, p, s); \
	cout << "p = " << p << " s = " << s << endl; \

int main() {

	float p, s;

	cout << "Hello, World!" << endl;

	REC(6, 6, 6);
	REC(5, 5, 5);
	REC(4, 4, 4);

	return 0;
}