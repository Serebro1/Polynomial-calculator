#pragma once
#include <iostream>
#include <regex>
struct Monom {
	double coeff;
	int x, y, z;

	
	Monom() : coeff(0), x(0), y(0), z(0) {};
	Monom(double _coeff, int _x, int _y, int _z) :coeff(_coeff), x(_x), y(_y), z(_z) {};
	Monom operator*(const Monom& m) const {
		Monom res;
		res.coeff = coeff * m.coeff;
		res.x = x + m.x;
		res.y = y + m.y;
		res.z = z + m.z;
		return res;
	}
	Monom operator-() const {
		return(Monom(-coeff, x, y, z));
	}
	void operator *=(const Monom& m) {
		coeff *= m.coeff;
		x += m.x;
		y += m.y;
		z += m.z;
	}
	bool operator<(const Monom& m) const {
		unsigned int left = x * 100 + y * 10 + z;
		unsigned int right = m.x * 100 + m.y * 10 + m.z;
		if (left < right) return true;
		return false;
	};
	bool operator>(const Monom& m) const {
		unsigned int left = x * 100 + y * 10 + z;
		unsigned int right = m.x * 100 + m.y * 10 + m.z;
		if (left > right) return true;
		return false;
	}
	bool operator==(const Monom& m) const {
		unsigned int left = x * 100 + y * 10 + z;
		unsigned int right = m.x * 100 + m.y * 10 + m.z;
		if (left == right) return true;
		return false;
	}
	bool operator!=(const Monom& m) const {
		return !(*this == m);
	}
	friend std::ostream& operator<<(std::ostream& out, const Monom& m) {
		out << m.coeff;
		if (m.x != 0){ 
			out << "*x";
			if (m.x != 1) {
				out << "^" << m.x;
			}
		}
		if (m.y != 0) {
			out << "*y";
			if (m.y != 1) {
				out << "^" << m.y;
			}
		}
		if (m.z != 0) {
			out << "*z";
			if (m.z != 1) {
				out << "^" << m.z;
			}
		}

		return out;
	};
	friend std::istream& operator>>(std::istream& in, Monom& m) {
		in >> m.coeff >> m.x >> m.y >> m.z;
		return in;
	};

};