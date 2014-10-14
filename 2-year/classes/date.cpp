#include <string>
#include <iostream>
#include <sstream>
#include "date.h"

namespace Ovr {
	using namespace std;

	string Date::format(const int format) {
		stringstream result;

		switch (format) {
			case Date::D_M_Y:
				result << this->d << "-" << this->m << "-" << this->y;
				break;
		}

		return result.str();
	}

	Date::Date(int y, int m, int d) {
		this->y = y;
		this->m = m;
		this->d = d;
	}
};