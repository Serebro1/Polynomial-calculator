#pragma once
#include <vector>
#include "polinomParser.h"
class Model {
	Model(const Model&) = delete;
	Model& operator=(const Model&) = delete;
	Model();
	std::vector<Polinom> polinoms;
	Monom currMonom;
public:
	PolinomParser parser;
	
	static Model& getInstance();

	std::string getStrPoly(const Polinom& poly);
	std::vector<std::string> getStrPolinoms();

	void addPolinom(const Polinom& p) { polinoms.push_back(p); }
	void setMonom(const Monom& m) { currMonom = m; }
	Monom getMonom() { return currMonom; }
	std::vector<Polinom> getPolinoms() { return polinoms; }
	void setPolinoms(std::vector<Polinom> _polinoms) { polinoms = _polinoms; }
	void removePolinom(int index);
	void clearPolinoms();
};