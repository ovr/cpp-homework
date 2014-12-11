#include <iostream>
#include <cmath>

using namespace std;

/**
 * Описать класс многочлен, с полями степень, аргумент и коэффициенты.
 * Создать метод вычисления значения многочлена от аргумента и вывода многочлена в общем виде на экран.
*/
class Polynomial {
public:
    /**
     * Степень
     */
    int order;

    /**
     * Коэфиценты
     */
    double *elements;

    /**
     * Аргумент
     */
    char arg = 'x';

    Polynomial(int order, double *elements, char arg = 'x') : order(order), elements(elements), arg(arg) {}

    int getOrder() {
        return this->order;
    }

    char getArg()
    {
        return this->arg;
    }

    double *getElements()
    {
        return this->elements;
    }

    // Сложение
    Polynomial * operator+(Polynomial &) {
        return this;
    }

    // Вычитание
    Polynomial *operator-(Polynomial &) {
        return this;
    }

    // Перемножение
    Polynomial *operator*(Polynomial &) {
        return this;
    }

    double calc(double number) {
        double result;

        int i;
        for (i = this->order; i >= 2; i-- ) {
            result += this->elements[i]*pow(number, i);
        }

        result += elements[i]*number;
        result += elements[--i];

        return result;
    }

    friend ostream &operator<<(ostream &fo, Polynomial &fp)
    {
        double *elements = fp.getElements();

        int i;
        for (i = fp.getOrder(); i >= 2; i-- ) {
            fo << elements[i] << fp.getArg() << "^" << i << " + ";
        }

        fo << elements[i] << fp.getArg() << " + ";
        fo << elements[--i] << " = 0";

        return fo;
    }
};

int main() {
    cout << "Hello, World!" << endl;

    double *tmp1X = new double[3]{6,3,8};
    Polynomial tmp1 = Polynomial(2, tmp1X);
    cout << tmp1 << endl;

    //32+6+6=44
    cout << "f(2)=" << tmp1.calc(2) << endl;

    return 0;
}