#include <iostream>
#include <math.h>

using namespace std;

class RegularPolyhedron {
protected:
    int edgeLength;
    int edgeNumber;

public:
    virtual double area() = 0;
    virtual double volume() = 0;
    virtual void printInfo() = 0;

    void setEdgeLength(int length) { edgeLength = length; }
    void setEdgeNumber(int number) { edgeNumber = number; }

    int getEdgeLength() const { return edgeLength; }
    int getEdgeNumber() const { return edgeNumber; }
};

class Tetrahedron : public RegularPolyhedron {

public:

    Tetrahedron() : RegularPolyhedron() {
        setEdgeLength(0);
        setEdgeNumber(6);
    }

    Tetrahedron(int length) : RegularPolyhedron() {
        setEdgeLength(length);
        setEdgeNumber(6);
    }

    double area() {
        return (pow(getEdgeLength(), 2) * sqrt(3));
    }

    double volume() {
        return (pow(getEdgeLength(), 3) * (sqrt(2) / 12) );
    }

    void printInfo() {
        cout << "Area = "   << area()   << endl
             << "Volume = " << volume() << endl;
    }
};


int main(int argc, const char * argv[]) {
    Tetrahedron Tetrahedron(4);
    Tetrahedron.printInfo();

    return 0;
}

