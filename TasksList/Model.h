#pragma once
#include <vector>
#include "polinomParser.h"
#include "../mp2-AlgOfList/calc.h"
class Model {
	Model(const Model&) = delete;
	Model& operator=(const Model&) = delete;
	Model();
	std::vector<Polinom> polinoms;
	Monom currMonom;
	TCalc calculator;
public:
	PolinomParser parser;
	
	static Model& getInstance();

	std::string convertPolyToStr(const Polinom& poly);
	std::vector<std::string> getStrPolinoms();

	void addPolinom(const Polinom& p) { polinoms.push_back(p); }
	void setMonom(const Monom& m) { currMonom = m; }
	Monom getMonom() { return currMonom; }
	std::vector<Polinom> getPolinoms() { return polinoms; }
	void setPolinoms(std::vector<Polinom> _polinoms) { polinoms = _polinoms; }
	void removePolinom(int index);
	void clearPolinoms();
	Polinom parsePolinom(const std::string& polynomialStr);
	Polinom calcPolinom(const std::string& expression);
};