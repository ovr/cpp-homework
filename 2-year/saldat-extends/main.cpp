#include <iostream>
#include <cmath>
#include "Polynomial.h"

using namespace std;

/**
 * Описать класс многочлен, с полями степень, аргумент и коэффициенты.
 * Создать метод вычисления значения многочлена от аргумента и вывода многочлена в общем виде на экран.
*/
class Polynomial : public BasePolynomial {
public:
    Polynomial(int order, double *elements, char arg = 'x') : BasePolynomial(order, elements, arg) {}

    ~Polynomial() {
        delete[] this->elements;
    }

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

};

int main() {
    cout << "Hello, World!" << endl;

    double *tmp1X = new double[3]{6,3,8};
    Polynomial tmp1 = Polynomial(2, tmp1X);

    //8+3+6=17
    cout << "f(1)=" << tmp1.calc(1) << endl;

    return 0;
}