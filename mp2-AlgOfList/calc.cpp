#include "calc.h"
#include <string>
TCalc::TCalc()
{ // зачем если по умолчанию стек создаётся с этой константой?
	StIndex = Stack<int>();
	StChar = Stack<char>();
	StOpers = Stack<Opers>();
	StPolinoms = Stack<Polinom>();
}

int TCalc::Prior(const char* op)
{
	switch (*op)
	{
	case '+':
		return 1;
	case '-':
		if (*(op - 1) == '(')
			return 4;
		return 1;
	case '*':
		return 2;
	default:
		return 0;
	}
}

int TCalc::Prior(const Opers& op)
{
	switch (op)
	{
	case pls: case mns:
		return 1;
	case mlt:
		return 2;
	case unarMns:
		return 4;
	default:
		return 0;
	}
}
Opers TCalc::transform(const char* c)
{
	switch (*c)
	{
	case '+':
		return pls;
	case '-':
		if (*(c - 1) == '(')
			return unarMns;
		return mns;
	case '*':
		return mlt;
	default:
		throw std::invalid_argument("No operator found.");
	}
}

Polinom TCalc::Calcul()
{
	StIndex.Clear();
	StOpers.Clear();
	std::string str = '(' + infix + ')';
	std::vector<Polinom> polinoms = Model::getInstance().getPolinoms();
	for (int i = 0; i < str.size(); i++)
	{
		char tmp = str[i];
		if (tmp == '(') StOpers.Push(openbr);
		else if (tmp >= '0' && tmp <= '9') {
			size_t idx;
			int num = std::stoi(&str[i], &idx);
			StPolinoms.Push(polinoms[num]);
			i += idx - 1;
		}
		else if (tmp == '+' || tmp == '-' || tmp == '*') {
			while (Prior(StOpers.Top()) >= Prior(&str[i])) {
				Polinom leftPoly, rightPoly;
				switch (StOpers.Pop())
				{
				case pls:
					leftPoly = StPolinoms.Pop(), rightPoly = StPolinoms.Pop();
					StPolinoms.Push(leftPoly + rightPoly);
					break;
				case mns:
					leftPoly = StPolinoms.Pop(), rightPoly = StPolinoms.Pop();
					StPolinoms.Push(leftPoly - rightPoly);
					break;
				case mlt:
					leftPoly = StPolinoms.Pop(), rightPoly = StPolinoms.Pop();
					StPolinoms.Push(leftPoly * rightPoly);
					break;
				case unarMns:
					StPolinoms.Push(-StPolinoms.Pop());
					break;
				}
			}
			StOpers.Push(transform(&str[i]));
		}
		else if (tmp == ')') {
			Opers top = StOpers.Pop();
			while (top != openbr) {
				Polinom leftPoly, rightPoly;
				switch (top)
				{
				case pls:
					leftPoly = StPolinoms.Pop(), rightPoly = StPolinoms.Pop();
					StPolinoms.Push(leftPoly + rightPoly);
					break;
				case mns:
					leftPoly = StPolinoms.Pop(), rightPoly = StPolinoms.Pop();
					StPolinoms.Push(leftPoly - rightPoly);
					break;
				case mlt:
					leftPoly = StPolinoms.Pop(), rightPoly = StPolinoms.Pop();
					StPolinoms.Push(leftPoly * rightPoly);
					break;
				case unarMns:
					StPolinoms.Push(-StPolinoms.Pop());
					break;
				}
				top = StOpers.Pop();
			}
		}
	}
	if (!StOpers.IsEmpty()) throw std::invalid_argument("Invalid expression format!");
	if (StPolinoms.IsEmpty()) throw std::invalid_argument("Invalid expression format!");
	Polinom res = StPolinoms.Pop();
	if (!StPolinoms.IsEmpty()) throw std::invalid_argument("Invalid expression format!");
	return res;
}

void TCalc::Check(std::string str)
{
	Stack<char> stack;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') stack.Push('(');
		if (str[i] == ')')
			if (stack.IsEmpty()) throw std::invalid_argument("Invalid expression format!");
			else stack.Pop();
	}
	if (!stack.IsEmpty()) throw std::invalid_argument("Invalid expression format!");
}
