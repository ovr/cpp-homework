#include "date.h"

namespace Ovr {
	class DayOfWeek : public Date {

	protected:
		string names[7] = {
			"Воск",
			"Пон",
			"Вто",
			"Сре",
			"Чет",
			"Пят",
			"Суб"
		};
		int dayOfWeek = -1;

	public:
		DayOfWeek(int y, int m, int d) : Date(y, m, d) {}

		string getDayOfWeek();
	};
}