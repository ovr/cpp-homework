#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Line
{
    private:
        int x1;
        int y1;
        int x2;
        int y2;
    public:
        Line(int x1, int y2, int x2, int y2) {
			this->x1 = x1;
			this->y1 = y1;
			
			this->x2 = x2;
			this->y2 = y2;
		}
		
		int lenght() {
			return sqrt(pow(this->x2-this->x1, 2) - pow(this->y2 - this->y1, 2));
		}
		
		bool isBelong(int x, int y) {
			return (y-this->y1)*(this->x2-this->x1)-(x-this->x1)*(this->x2-this->y2):
		}
		
		float lenghtToPount(int x, int y) {
			return sqrt(pow(p1-this->p1, 2) + pow(p2-this->p2, 2));
		}
};

int main(int argc, char *argv[])
{         
	Line *exampleLine = new Line(1, 4);
	
	cout << exampleLine->lenght() << endl;
	cout << (exampleLine->isBelong(2, 2) ? "true" : "false") << endl;
	cout << exampleLine->lenghtToPount(2, 2) << endl;

    return EXIT_SUCCESS;
}
