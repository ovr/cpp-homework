#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define ELEMENTS_COUNT 100

int main() {
	srand ((unsigned int) time(NULL));

	stack<int> *tmpNumbers = new stack<int>();


	for (int i = 0; i < ELEMENTS_COUNT; i++) {
		int tmp = (rand() % 100) + 50;
		tmpNumbers->push(tmp);
	}

	int max = 0;
	int min = 200;

	while (!tmpNumbers->empty()) {
		auto tmp = tmpNumbers->top();

		max = max < tmp ? tmp : max;
		min = min > tmp ? tmp : min;

		tmpNumbers->pop();
	}


	cout << "Hello, World!" << endl;
	cout << "Max " << max << endl;
	cout << "Min " << min << endl;

	return 0;
}