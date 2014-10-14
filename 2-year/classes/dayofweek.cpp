#include "dayofweek.h"

namespace Ovr {

	string DayOfWeek::getDayOfWeek() {
		if (dayOfWeek == -1) {
			int a = (14 - this->m) / 12;
			int y = this->y - a;
			int m = this->m + 12 * a - 2;
			this->dayOfWeek = (7000 + (this->d + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
		}

		return this->names[this->dayOfWeek];
	}
}