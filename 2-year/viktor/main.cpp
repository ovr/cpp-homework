#include <iostream>

using namespace std;

class Pole {
protected:
    int *elements;

    /**
     * Размер поле
     */
    int size = 0;
public:
    int *getElements() const {
        return this->elements;
    }

    int getSize() const {
        return this->size;
    }

    Pole() {
        this->size = 0;
    }

    Pole(int *elements, const int size) {
        this->elements = elements;
        this->size = size;
    }

    Pole &operator++(int a) {
        std::cout << "operator++" << std::endl;

        for (int i = 0; i < this->size; i++) {
            this->elements[i]++;
        }

        return *this;
    }

    Pole &operator--(int a) {
        std::cout << "operator--" << std::endl;

        for (int i = 0; i < this->size; i++) {
            this->elements[i]--;
        }

        return *this;
    }

    /**
    * Метод для сложения двух полей
    */
    inline void plus(const Pole expr) {
        realloc(this->elements, (size_t) (this->size + expr.getSize()));

        int *tmp1 = expr.getElements();

        for (int i = 0; i < expr.getSize(); i++) {
            this->elements[this->size+i] = tmp1[i];
        }

        this->size = this->size + expr.getSize();
    }

    Pole &operator+(const Pole exp) {
        Pole tmp = Pole(this->elements, this->size);
        tmp.plus(exp);

        return tmp;
    }

    Pole &operator-=(const int expSize) {
        this->size -= expSize;
        realloc(this->elements, (size_t) this->size);

        return *this;
    }

    void inputValues() {
        cout << endl << "Please input pole's size: ";
        cin >> this->size;

        elements = new int[this->size];

        for (int i = 0; i < this->size; i++) {
            std::cout << "\n" << i + 1 << ") ";
            std::cin >> elements[i];
        }
    }

    void print() {
        cout << "Elements: " << elements[0];

        for (int i = 1; i < this->size; i++) {
            cout << ", " << elements[i];
        }

        cout << endl;
    }

};

int main() {
//    setlocale(LC_ALL, "rus");

    int *elements1 = new int[5]{1, 2, 3, 4, 5};
    Pole pole1 = Pole(elements1, 5);

    int *elements2 = new int[5]{1, 2, 3, 4, 5};
    Pole pole2 = Pole(elements2, 5);

    pole1.print();
    cout << endl;

    pole1++;
    pole1.print();
    cout << endl;


    pole1--;
    pole1.print();
    cout << endl;

    pole2.print();
    cout << endl;

    Pole summPole = pole1 + pole2;
    cout << "Summ pole size: " << summPole.getSize() << endl;
    summPole.print();

    cout << endl;

    summPole -= 5;
    cout << "Pole -= 5 int size : " << summPole.getSize() << endl;
    summPole.print();
}
