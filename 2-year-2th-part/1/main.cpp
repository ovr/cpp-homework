#include <iostream>

using namespace std;

bool checkPoint(float x, float y) {
    if (x >= 0) {
        return (y*y+x*x) < 1;
    }

    //вверх      −1x+2y−2=0
    if (y > 0) {
        return (-x+2*y-2) < 0;
    }

    //нижняя 1x+2y+2=0
    return (x+2*y+2) > 0;
}

#define BOOL_STR(a) \
    (a ? "yes" : "no")

#define CHECK(X, Y, need) \
    cout << "check(" << X << ", " \
         << Y << ", " << BOOL_STR(need) << ") : " \
         << BOOL_STR(checkPoint(X, Y)) << endl;

int main() {
    cout << "11111" << endl;
    CHECK(0, 0, true)
    CHECK(1, 1, false)
    CHECK(0.60, 0.60, true)
    CHECK(1.1, 0, false)

    cout << endl << endl << "4444" << endl;

    CHECK(1, -1, false)
    CHECK(-1, -1, false)
    CHECK(-0.6, -0.6, true)

    cout << endl << endl << "2222" << endl;

    //2
    CHECK(-4, 4, false)
    CHECK(-4, 2, false)
    CHECK(-1, 0.25, true)

    cout << endl << endl << "33333" << endl;

    //3
    CHECK(-4, -4, false)
    CHECK(-0.5, -0.5, true)
    CHECK(-2, -2, false)
    CHECK(-2, -1, false)

    return 0;
}