
#pragma once

namespace Ovr {
	using namespace std;

	class Date {
	protected:
		unsigned int d, m, y;

	public:
		static const int D_M_Y = 1;
		static const int Y_M_D = 2;

		string format(const int format);

		Date() {

		}
		Date(int y, int m, int d);
	};
}