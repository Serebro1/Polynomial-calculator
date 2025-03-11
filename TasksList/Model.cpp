#include "Model.h"
#include <sstream>
template <typename T>
std::string to_string(const T& obj) {
	std::ostringstream oss;
	oss << obj;
	return oss.str();
}
std::string Model::convertPolyToStr(const Polinom& poly)
{
	return to_string(poly);
}
Model::Model()
{
	Monom* monoms = new Monom[3];
	monoms[0] = Monom(3.0, 0, 0, 0);
	monoms[1] = Monom(2.0, 1, 1, 1);
	monoms[2] = Monom(5.0, 2, 1, 0);
	Polinom p1(monoms, 3);
	polinoms.push_back(p1);

	monoms[0] = Monom(2.5, 0, 1, 1);
	monoms[1] = Monom(-2.0, 1, 1, 1);
	monoms[2] = Monom(3.5, 2, 1, 0);
	Polinom p2(monoms, 3);
	polinoms.push_back(p2);
}

Model& Model::getInstance()
{
	static Model instance;
	return instance;
}

std::vector<std::string> Model::getStrPolinoms()
{
	std::vector<std::string> res;
	for (Polinom p : polinoms) {
		res.push_back(to_string(p));
	}

	return res;
}

void Model::removePolinom(int index)
{
	if (index >= 0 && index < polinoms.size()) {
		polinoms.erase(polinoms.begin() + index);
	}
}

void Model::clearPolinoms()
{
	polinoms.clear();
}

Polinom Model::calcPolinom(std::string expression)
{
	calculator.Check(expression);
	calculator.SetInfix(expression);
	return calculator.Calcul();
}
