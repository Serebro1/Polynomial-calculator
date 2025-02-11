#pragma once
#include "monom.h"

template<class T>
struct Node {
	T val;
	Node* pNext;
};

template<class T>
class TList {
protected:
	Node<T> *pFirst, *pLast;
	int sz;
public:
	TList() : pFirst(nullptr), pLast(nullptr), sz(0) {}
	TList(const TList& copy);
	~TList();
	TList& operator=(const TList& copy);
	void clear();

	void insFirst(const T& value);
	void insLast(const T& value);

	void delFirst();
	void delLast();


	int size() { return sz; }
	bool isEmpty() { return sz == 0; }
	
};

template<class T>
TList<T>::TList(const TList& copy)
{
	if (st.pFirst == nullptr) return;
	Node<T>* tmp = st.pFirst;
	pFirst = new Node<T>();
	pFirst->pNext = nullptr;
	pFirst->val = st.pFirst->val;
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
	pLast = nullptr;
}

template<class T>
void TList<T>::insFirst(const T& value)
{
	Node<T>* node = new Node<T>(value, pFirst);
	if (pFirst == nullptr) pLast = node;
	pFirst = node;
	sz++;
}

template<class T>
void TList<T>::insLast(const T& value)
{
	Node<T>* node = new Node<T>(value, nullptr);
	if (pFirst == nullptr) {pFirst = node;}
	else pLast->pNext = node;
	pLast = node
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
void TList<T>::delLast()
{
	if (pLast == nullptr) return;
	

}
template<class T>
class Polinom : public TList {
	/*
		Список с конкретным типом данных
		Реализует специфические методы, такие как:
		хранение по порядку, добавление по порядку, сложение, вычитание
	*/
};