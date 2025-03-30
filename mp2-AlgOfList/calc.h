#pragma once

#include "ListStack.h"
#include "../TasksList/polinom.h"


enum Opers {
	openbr, unarMns, pls, mns, mlt, dv, pw, sn, cs, tn
};

class TCalc
{
	std::string infix;
	std::vector<Polinom> polinoms;
	Stack<Polinom> StPolinoms;
	Stack<Opers> StOpers;
public:
	TCalc();

	void SetInfix(std::string _infix) { infix = _infix; }
	std::string GetInfix() { return infix; }

	void SetPolinoms(std::vector<Polinom> pol) { polinoms = pol; }

	int Prior(const char* op);
	int Prior(const Opers& op);
	Opers transform(const char* c);

	Polinom Calcul();
	void Check(std::string str);

};
