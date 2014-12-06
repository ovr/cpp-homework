#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

/**
* Вычислить сумму произведений первого элемента одномерного мас-сива
* с последним, второго – с предпоследним и т.д.
* Использовать функцию для каждой строки матрицы Т (5, 6).
*/

#define ROWS 5
#define COLUMNS 6

int mulElements(int* row, int index) {
    return row[index]*row[ROWS-index];
}

int main() {
    srand((unsigned int) time(nullptr));


    int **m = new int *[ROWS];
    for (int i = 0; i < ROWS; i++) {
        m[i] = new int[COLUMNS];
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << (m[i][j] = rand() % 10) << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    int summ = 0;
    int tmp;

    for (int i = 0; i < round((float) ROWS/2); i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cout << m[i][j] << " ";
        }

        tmp = mulElements(m[i], i);
        summ += tmp;
        cout << " = " << tmp;
        cout << endl;
    }

    cout << endl;
    cout << "Hello, World! summ = " << summ << endl;
    return 0;
}