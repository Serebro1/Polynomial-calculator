#pragma once
#include <vector>
#include "polinomParser.h"
class Model {
	Model(const Model&) = delete;
	Model& operator=(const Model&) = delete;
	Model();
	std::vector<Polinom> polinoms;
	
public:
	PolinomParser parser;
	
	static Model& getInstance();

	std::vector<std::string> getStrPolinoms();

	void addPolinom(const Polinom& p);
	std::vector<Polinom> getPolinoms() { return polinoms; }
	void setPolinoms(std::vector<Polinom> _polinoms) { polinoms = _polinoms; }
	void removePolinom(int index);
	void clearPolinoms();
};