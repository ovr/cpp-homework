#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Vector {
	private:
public:
	float getBeginX() const {
		return beginX;
	}

	float getBeginY() const {
		return beginY;
	}

	float getEndX() const {
		return endX;
	}

	float getEndY() const {
		return endY;
	}

private:
	float beginX;
		float beginY;
		float endX;
		float endY;
	public:
		Vector() : beginX(0), beginY(0), endX(0), endY(0) {}
		
		Vector(float beginX, float beginY, float endX, float endY) {
			this->beginX = beginX;
			this->beginY = beginY;
			this->endX = endX;
			this->endY = endY;
		}
		
		void printInfo() {
			cout << "X: " << beginX << "," << beginY << "; ";
			cout << "Y: " << endX << "," << endY << ";";
		}
		
		float length() {
			float X = this->getX();
			float Y = this->getY();
			
			float length = sqrt(X*X + Y*Y);
			
			return length;
		}
		
		void paintMe() {
			int length = abs(this->length());
			float X = this->getX();
			float Y = this->getY();
			
			cout << X;
			for (int i = 0; i < length; ++i) {
				cout << "-";
			}
			cout << ">" << Y;
		}

		void plus(const Vector a) {
			this->beginY += a.getBeginY();
			this->beginX += a.getBeginX();

			this->endY += a.getEndY();
			this->endX += a.getEndX();
		}

		Vector& operator+(const Vector a) {
			Vector* temp = new Vector(this->beginX, this->beginY, this->endX, this->endY);
			temp->plus(a);

			return (Vector&) *this;
		}
		
		private:
			float getX() {
				return endX - beginX;
			}
			
			float getY() {
				return endY - beginY;
			}
};

int main() {
	Vector vector = Vector(1, 2, 5, 9);
	vector.printInfo();
	vector.paintMe();
	cout << "\nLength vect 1= " << vector.length() << endl;

	cout << endl << endl;

	Vector vector2 = Vector(4, 8, 1, -20);
	vector2.printInfo();
	vector2.paintMe();
	cout << "\nLength vect2 = " << vector2.length() << endl;

	cout << endl << endl;

	Vector summ;
	summ = vector + vector2;
	summ.printInfo();
	summ.paintMe();
	cout << "\n Length Summ = " << summ.length() << endl;
}