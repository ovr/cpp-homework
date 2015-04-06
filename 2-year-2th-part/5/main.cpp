#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define ELEMENTS_COUNT 100

int main() {
	srand ((unsigned int) time(NULL));

	auto *tmpNumbers = new stack<int>();
	tmpNumbers->reserve(ELEMENTS_COUNT);		tmpNumbers->push_back(tmp);


	for (int i = 0; i < ELEMENTS_COUNT; i++) {
		int tmp = (rand() % 100) + 50;

//		cout << tmp << endl;
	}

	cout << "Hello, World!" << endl;
	cout << "Max " << *max_element(tmpNumbers, tmpNumbers->end()) << endl;
	cout << "Min " << *min_element(tmpNumbers->begin(), tmpNumbers->end()) << endl;

	return 0;
}