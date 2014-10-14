#include <iostream>
#include <cmath>

using namespace std;

class Shape {
protected:
	unsigned int n;
	float a;
public:
	Shape(unsigned int n, float a) {
		this->n = n;
		this->a = a;
	}

	double calculateArea()
	{
		return (this->n/.4)*(a*a)*tan(M_PI/this->n);
	}

	float calculateP() {
		return this->n*a;
	}

	virtual float calculateAngle() = 0;
};

class Triangle : public Shape {
protected:
	unsigned int c;
public:
	Triangle(float a) : Shape(3, a) {}

	float calculateAngle() {
		return 60;
	}
};

class Square : public Shape {
public:
	Square(float a) : Shape(4, a) {}

	float calculateAngle() {
		return 90;
	}
};

class EightAngle : public Shape {
public:
	EightAngle(float a) : Shape(8, a) {}

	float calculateAngle() {
		return 45;
	}
};

int main() {
	Shape *pt;

	Triangle *triangle = new Triangle(4);
	cout << "angle = " << triangle->calculateAngle() << endl;
	cout << "p = " << triangle->calculateP() << endl;
	cout << "s = " << triangle->calculateArea() << endl;

	Triangle A(4);
	pt = &A;
	cout << "angle " << pt->calculateAngle() << endl;

	cout << endl;

	Square *square = new Square(4);
	cout << "angle = " << square->calculateAngle() << endl;
	cout << "p = " << square->calculateP() << endl;
	cout << "s = " << square->calculateArea() << endl;

	cout << endl;

	EightAngle *eightAngle = new EightAngle(4);
	cout << "angle = " << eightAngle->calculateAngle() << endl;
	cout << "p = " << eightAngle->calculateP() << endl;
	cout << "s = " << eightAngle->calculateArea() << endl;

	return 0;
}