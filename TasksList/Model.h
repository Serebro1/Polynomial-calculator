#pragma once
#include <vector>
#include "polinom.h"

class Model {
	Model(const Model&) = delete;
	Model& operator=(const Model&) = delete;
	Model();
	std::vector<Polinom> polinoms;
public:
	
	
	static Model& getInstance();

	std::vector<std::string> getStrPolinoms();

	void clearPolinoms();
};