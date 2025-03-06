#pragma once
#include "TList.h"
class Polinom : public TList<Monom> {
	
public:
	Polinom() {};
	Polinom(Monom* p, unsigned int size);
	
	void operator*=(double c);
	void operator+=(const Monom m);
	void operator*=(const Monom m);
	void operator-=(const Monom m);
	void operator+=(Polinom& p);
	void operator*=(Polinom& p);
	void operator-=(Polinom& p);

	Polinom operator+(const Monom& m);
	Polinom operator*(const Monom& m);
	Polinom operator-(const Monom& m);
	Polinom operator+(Polinom& p);
	Polinom operator*(Polinom& p);
	Polinom operator-(Polinom& p);
	Polinom operator-();

	friend std::ostream& operator<<(std::ostream& out, const Polinom& p);
};
/*
* Тесты добавления монома.
* Создали полином из трёх звеньев
Все возможные сложения
Обнуление звена в середине, обнуление с концов.

Сложение полиномов:
пусть есть полиномы res, p
3 варианта степеней
Степени равны => складываем коэффициенты, если результат не равен 0, то записывам результат,двигаем оба указателя,
иначе удаляем через delCurr и продвигаем только указатель pCurr у p

Степени полинома складываемого полинома больше результирующего
Тогда мы должны добавить моном перед мономом результирующего и двигаем указатель pCurr у p.
Если наоборот то двигаем pCurr у res

Если один из них закончится, то всё зависит от степеней.
Ситуация в любом случае может произойти:
один из полиномов кончился а у другого остался хвост у p. Необходимо переписать хвост результирующему полиному
Если же дошли до конца у res, то мы ничего не делаем.
*/