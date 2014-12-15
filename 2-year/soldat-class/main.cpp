#include <iostream>
#include <cmath>

using namespace std;

/**
 * Описать класс многочлен, с полями степень, аргумент и коэффициенты.
 * Создать метод вычисления значения многочлена от аргумента и вывода многочлена в общем виде на экран.
*/
class Polynomial {
protected:
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
public:
    Polynomial(int order, double *elements) : order(order), elements(elements), arg('x') {}

    Polynomial(int order, double *elements, char arg) : order(order), elements(elements), arg(arg) {}

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

    double calc(double number) {
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
    cout << "Polynomial(2, tmp1X)" << endl;
    double *tmp1X = new double[3]{6,3,8};
    Polynomial tmp1 = Polynomial(2, tmp1X);
    cout << tmp1 << endl;

    //8+3+6=17
    cout << "f1(1)=" << tmp1.calc(1) << endl;

    cout << endl << "Polynomial(2, tmp2X, 'y')" << endl;
    double *tmp2X = new double[3]{5,4,1};
    Polynomial tmp2 = Polynomial(2, tmp2X, 'y');
    cout << tmp2 << endl;

    //8+3+6=17
    cout << "f2(1)=" << tmp1.calc(1) << endl;

    return 0;
}