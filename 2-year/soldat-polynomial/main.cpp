#include <iostream>
#include <cmath>

using namespace std;

class BasePolynomial {
    /**
     * Чистый абстрактный виртуальный метод
     */
    virtual double calc(double number) = 0;
};

/**
 * Описать класс многочлен, с полями степень, аргумент и коэффициенты.
 * Создать метод вычисления значения многочлена от аргумента и вывода многочлена в общем виде на экран.
*/
class Polynomial : public BasePolynomial {
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
    Polynomial *operator += (Polynomial input) {
        if (input.getArg() != this->getArg()) {
            exit(10);
        }

        double *elementsTmp = input.getElements();
        for (int i = 0; i < this->getOrder()+1; i++) {
            this->elements[i] += elementsTmp[i];
        }

        return this;
    }


    // Перемножение
    Polynomial *operator*=(const int number) {
        int i;

        for (i = this->getOrder(); i >= 2; i-- ) {
            this->elements[i] *= number;
        }

        elements[i] *= number;
        elements[i-1] *= number;

        return this;
    }

    virtual double calc(double number) {
        double result = 0;

        int i;
        for (i = this->order; i >= 2; i-- ) {
            result += this->elements[i]*pow(number, i);
        }

        result += elements[i]*number;
        result += elements[--i];

        return result;
    }

    friend ostream &operator << (ostream &fo, Polynomial &fp)
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

    //8+3+6=17
    cout << "f(1)=" << tmp1.calc(1) << endl;

    //32+6+6=44
    cout << "f(2)=" << tmp1.calc(2) << endl;

    cout << endl;

    double *tmp2X = new double[3]{1,2,3};
    Polynomial tmp2 = Polynomial(2, tmp2X);
    cout << tmp2 << endl;

    cout << endl;

    tmp1 += tmp2;
    cout << tmp1 << endl;

    cout << endl;

    tmp1 *= 2;
    cout << tmp1;

    return 0;
}