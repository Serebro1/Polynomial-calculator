#pragma once
#include <iostream>
struct Monom {
	double coeff;
	int x, y, z;

	
	Monom():coeff(0), x(0), y(0), z(0){}

	bool operator<=(const Monom& m);
	friend std::ostream& operator<<(std::ostream& out, const Monom& m);
	friend std::istream& operator>>(std::istream& in, Monom& m);
};
bool Monom::operator<=(const Monom& m)
{
	unsigned int left = x * 100 + y * 10 + z;
	unsigned int right = m.x * 100 + m.y * 10 + m.z;
	if (left <= right) return true;
	return false;
}
std::ostream& operator<<(std::ostream& out, const Monom& m)
{
	out << m.coeff << "x^" << m.x << "*y^" << m.y << "*z^ ";
	return out;
}
std::istream& operator>>(std::istream& in, Monom& m)
{
	in >> m.coeff >> m.x >> m.y >> m.z;
	return in;
}

