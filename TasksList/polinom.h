#pragma once
#include "monom.h"
#include "TList.h"

class Polinom : public TList<Monom> {
	
public:
	Polinom(Monom* p, unsigned int size);
	
	void operator+=(Monom m);
	
	
};
