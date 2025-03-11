#pragma once

#include "ListStack.h"
#include "../TasksList/polinom.h"


enum Opers {
	openbr, unarMns, pls, mns, mlt, dv, pw, sn, cs, tn
};

class TCalc
{
	std::string infix;
	std::string postfix;

	std::vector<Polinom> polinoms;
	Stack<Polinom> StPolinoms;
	Stack<char> StChar;
	Stack<Opers> StOpers;
public:
	TCalc();
	// set, get для тестов
	void SetInfix(std::string _infix) { infix = _infix; }
	void SetPostfix(std::string _postfix) { postfix = _postfix; }
	void SetPolinoms(std::vector<Polinom> pol) { polinoms = pol; }
	std::string GetInfix() { return infix; }
	std::string GetPostfix() { return postfix; }

	int Prior(const char* op);
	int Prior(const Opers& op);

	Polinom Calcul();
	void Check(std::string str);
	Opers transform(const char* c);

};
