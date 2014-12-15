
class BasePolynomial {
protected:
    /**
    * Степень
    */
    int order;
    \
    /**
    * Коэфиценты
    */
    double *elements;

    /**
    * Аргумент
    */
    char arg = 'x';
public:
    /**
    * Чистый абстрактный виртуальный метод
    */
    virtual double calc(double number) = 0;

    BasePolynomial() {}

    BasePolynomial(int order, double *elements, char arg) : order(order), elements(elements), arg(arg) {}
};