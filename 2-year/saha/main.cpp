#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void swap(int *elements, const int first, const int last) {
	int tmpNumber;

	double j = (double)(last-first)/2;

	for (int i = 0; i < round(j); i++) {
//		cout << "i = " << i+first << endl;

		tmpNumber = elements[i+first];
 		elements[i+first] = elements[last-i];
		elements[last-i] = tmpNumber;
	}
}


#define DEBUG true

int main() {
	srand((unsigned int) time(nullptr));


	int **m = new int *[9];
	for (int i = 0; i < 9; i++) {
		m[i] = new int[10];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			m[i][j] = rand() % 10;
		}
	}

	cout << endl << endl;

	if (DEBUG) {
		for (int i = 0; i < 9; i += 3) {
			for (int j = 2; j < 7; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
	}

	cout << endl << endl;

	for (int i = 0; i < 9; i += 3) {
		/**
		* 0 1 2 3 4 5 6 7
		* c 2 до 7
		*/
		swap(m[i], 2, 6);
	}


	cout << endl << endl;

	if (DEBUG) {
		for (int i = 0; i < 9; i += 3) {
			for (int j = 2; j < 7; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}