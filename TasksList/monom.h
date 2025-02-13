#pragma once
#include <iostream>
struct Monom {
	double coeff;
	int x, y, z;

	
	Monom() : coeff(0), x(0), y(0), z(0) {};
	Monom(double _coeff, int _x, int _y, int _z) :coeff(_coeff), x(_x), y(_y), z(_z) {};
	bool operator<=(const Monom& m) {
		unsigned int left = x * 100 + y * 10 + z;
		unsigned int right = m.x * 100 + m.y * 10 + m.z;
		if (left < right) return true;
		if (left > right) return false;
		if (coeff <= m.coeff) return true;
		return false;
	};
	friend std::ostream& operator<<(std::ostream& out, const Monom& m) {
		out << m.coeff;
		if (m.x != 0) out << "*x^" << m.x;
		if (m.y != 0) out << "*y^" << m.y;
		if (m.z != 0) out << "*z^" << m.z;

		return out;
	};
	friend std::istream& operator>>(std::istream& in, Monom& m) {
		in >> m.coeff >> m.x >> m.y >> m.z;
		return in;
	};
};