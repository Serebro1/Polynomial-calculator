#pragma once
#include "monom.h"
#include "iteratorTlist.h"

template<class T>
struct Node {
	T val;
	Node* pNext;
};

template<class T>
class TList {
protected:
	Node<T>* pFirst,* pPrev,* pCurr, * pLast;
	// указатели на: начало, предыдущий от текущего эл-та, текущий эл-т, конец списка.
	int sz;
public:
	typedef ListIterator<T> iterator;

	iterator begin() { return iterator(pFirst); }
	iterator end() { return iterator(pLast->pNext); }

	TList() : pFirst(nullptr), pPrev(nullptr), pCurr(nullptr), pLast(nullptr), sz(0) {}
	TList(const TList& copy);
	TList(TList&& queue);
	~TList();

	TList& operator=(const TList& copy);
	void clear();
	TList& operator=(TList&& queue);
	friend void swap(TList<T>& first, TList<T>& second) {
		std::swap(first.pFirst, second.pFirst);
		std::swap(first.pPrev, second.pPrev);
		std::swap(first.pCurr, second.pCurr);
		std::swap(first.pLast, second.pLast);
		std::swap(first.sz, second.sz);
	};

	bool operator==(const TList& right) const;
	bool operator!=(const TList& right) const;

	T& operator[](int pos);
	Node<T>* ToPos(int pos);
	bool isEnd() { return pCurr == pLast; };
	void reset() { pCurr = pFirst; pPrev = nullptr; };
	void goNext() { pPrev = pCurr;  pCurr = pCurr->pNext; };

	T getCurr() { return pCurr->val; }

	void insFirst(const T& value);
	void insLast(const T& value);

	void delFirst();
	void delCurr();
	void delLast();
	

	int size() { return sz; }
	bool isEmpty() { return sz == 0; }
	

};

template<class T>
TList<T>::TList(const TList& copy)
{
	if (copy.pFirst == nullptr) return;

	Node<T>* tmp = copy.pFirst;
	pFirst = new Node<T>();
	pFirst->pNext = nullptr;
	pFirst->val = copy.pFirst->val;
	Node<T>* prev = pFirst;

	tmp = tmp->pNext;
	while (tmp != nullptr) {
		Node<T>* node = new Node<T>();
		node->val = tmp->val;
		node->pNext = nullptr;
		prev->pNext = node;
		tmp = tmp->pNext;
		prev = prev->pNext;
	}

	pLast = prev;
	pPrev = copy.pPrev;
	pCurr = copy.pCurr;
	sz = copy.sz;
}


template<class T>
TList<T>::TList(TList&& queue)
{
	pFirst = nullptr;
	swap(*this, queue);
}


template<class T>
TList<T>::~TList()
{
	Node<T>* tmp;
	while (pFirst != nullptr) {
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

template<class T>
TList<T>& TList<T>::operator=(const TList& copy)
{
	if (this == &copy) return *this;
	clear();
	if (copy.pFirst == nullptr) {
		return *this;
	}
	sz = copy.sz;
	Node<T>* tmp = copy.pFirst;
	pFirst = new Node<T>();
	pFirst->pNext = nullptr;
	pFirst->val = copy.pFirst->val;
	Node<T>* prev = pFirst;
	tmp = tmp->pNext;
	while (tmp != nullptr) {
		Node<T>* node = new Node<T>();
		node->val = tmp->val;
		node->pNext = nullptr;
		prev->pNext = node;
		tmp = tmp->pNext;
		prev = prev->pNext;
	}
	pLast = prev;
	pPrev = copy.pPrev;
	pCurr = copy.pCurr;
	return *this;
}

template<class T>
void TList<T>::clear()
{
	while (pFirst != nullptr) {
		Node<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	pCurr = nullptr;
	pCurr = nullptr;
	pLast = nullptr;
	sz = 0;
}

template<class T>
TList<T>& TList<T>::operator=(TList&& queue)
{
	swap(*this, queue);
	return *this;
}

template<class T>
bool TList<T>::operator==(const TList& right) const
{
	if (sz != right.sz) return false;
	Node<T>* tmpFirst = pFirst;
	Node<T>* tmpSecond = right.pFirst;
	while (tmpFirst != nullptr)
	{
		if (tmpFirst->val != tmpSecond->val) return false;
		tmpFirst = tmpFirst->pNext;
		tmpSecond = tmpSecond->pNext;
	}
	return true;

}

template<class T>
bool TList<T>::operator!=(const TList& right) const
{
	return !(*this == right);
}

template<class T>
T& TList<T>::operator[](int pos)
{
	Node<T>* res = ToPos(pos);
	return res->val;
}

template<class T>
Node<T>* TList<T>::ToPos(int pos)
{
	Node<T>* tmp = pFirst;
	int count = 0;
	while (tmp != nullptr && count != pos) {
		tmp = tmp->pNext;
		count++;
	}
	if (tmp == nullptr) throw - 2; // Выход за список
	return tmp;
}

template<class T>
void TList<T>::insFirst(const T& value)
{
	Node<T>* node = new Node<T>{ value, pFirst };
	if (pFirst == nullptr) pLast = node;
	pFirst = node;
	sz++;
}

template<class T>
void TList<T>::insLast(const T& value)
{
	Node<T>* node = new Node<T>(value, nullptr);
	if (pFirst == nullptr) { pFirst = node; }
	else pLast->pNext = node;
	pLast = node;
	sz++;
}

template<class T>
void TList<T>::delFirst()
{
	if (pFirst == nullptr) return;
	Node<T>* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	if (pFirst == nullptr) pLast = nullptr; // если список состоял из 1 элемента
	sz--;
}
template<class T>
void TList<T>::delCurr()
{
	if (pCurr == pFirst) {
		delFirst();
	}
	else if (pCurr == pLast) {
		delLast();
	}
	else {
		pPrev->pNext = pCurr->pNext;
		delete pCurr;
		pCurr = pPrev->pNext;
	}
}
template<class T>
void TList<T>::delLast()
{
	if (pFirst == nullptr) return;
	Node<T>* tmp = pFirst;
	while (tmp->pNext != pLast) {
		tmp = tmp->pNext;
	}

	Node<T>* node = pLast;
	delete node;

	tmp->pNext = nullptr;
	pLast = tmp;
	sz--;
}
/*
Как реализовать доступ к элементам списка?
У нас в классе есть указатели на начало и конец списка.
1) Прогнать указатель на звенья от начало до конца
2) Заведём дополнительно указатель на текущий элемент

*/