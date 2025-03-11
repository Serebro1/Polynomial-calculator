#pragma once

#include "ListStack.h"
#include "../TasksList/Model.h"
//using namespace std;

enum Opers {
	openbr, unarMns, pls, mns, mlt, dv, pw, sn, cs, tn
};

class TCalc
{
	std::string infix;
	std::string postfix;
	Stack<int> StIndex;
	Stack<Polinom> StPolinoms;
	Stack<char> StChar;
	Stack<Opers> StOpers;
public:
	TCalc();
	// set, get для тестов
	void SetInfix(std::string _infix) { infix = _infix; }
	void SetPostfix(std::string _postfix) { postfix = _postfix; }
	std::string GetInfix() { return infix; }
	std::string GetPostfix() { return postfix; }

	int Prior(const char* op);
	int Prior(const Opers& op);

	Polinom Calcul();
	void Check(std::string str);
	Opers transform(const char* c);

};
