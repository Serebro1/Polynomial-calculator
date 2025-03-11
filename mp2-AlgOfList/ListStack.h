#pragma once
#include <iostream>
template<class T>
class Stack {
	struct Node {
	T val;
	Node* pNext;
};
	Node* pFirst;

public:
	Stack();
	Stack(const Stack<T>& st);
	~Stack();
	
	void Push(T elem);
	T Pop();
	T Top() const;
	void Clear();
	bool IsFull();
	bool IsEmpty();

	Stack<T>& operator=(const Stack<T>& st);
	bool operator==(const Stack<T>& s) const;
	bool operator!=(const Stack<T>& s) const;
};

template<class T>
Stack<T>::Stack()
{
	pFirst = nullptr;
}

template<class T>
Stack<T>::Stack(const Stack<T>& st)
{
	if (st.pFirst == nullptr) return;
	Node* tmp = st.pFirst;
	pFirst = new Node();
	pFirst->pNext = nullptr;
	pFirst->val = st.pFirst->val;
	Node* prev = pFirst;
	tmp = tmp->pNext;
	while (tmp != nullptr) {
		Node* node = new Node();
		node->val = tmp->val;
		node->pNext = nullptr;
		prev->pNext = node;
		tmp = tmp->pNext;
		prev = prev->pNext;
	}
}

template<class T>
Stack<T>::~Stack()
{
	while (pFirst != nullptr) {
		Node* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}

}

template<class T>
void Stack<T>::Push(T elem)
{
	if (IsFull()) throw - 2;
	Node* tmp = new Node();
	tmp->val = elem;
	tmp->pNext = pFirst;
	pFirst = tmp;
}

template<class T>
T Stack<T>::Pop()
{
	if (pFirst == nullptr) throw - 1;
	T res = pFirst->val;
	Node* tmp = pFirst;
	pFirst = pFirst->pNext;
	delete tmp;
	return res;
}

template<class T>
T Stack<T>::Top() const
{
	if (pFirst == nullptr) throw - 1;
	return pFirst->val;
}

template<class T>
void Stack<T>::Clear()
{
	while (pFirst != nullptr) {
		Node* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

template<class T>
bool Stack<T>::IsFull()
{
	try {
		Node* node = new Node();
		delete node;
		return false;
	}
	catch (std::bad_alloc) {
		return true;
	}
	
}

template<class T>
bool Stack<T>::IsEmpty()
{
	return pFirst==nullptr;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st)
{
	if (this == &st) return *this;
	Clear();
	if (st.pFirst == nullptr) {
		return *this;
	}
	Node* tmp = st.pFirst;
	pFirst = new Node();
	pFirst->pNext = nullptr;
	pFirst->val = st.pFirst->val;
	Node* prev = pFirst;
	tmp = tmp->pNext;
	while (tmp != nullptr) {
		Node* node = new Node();
		node->val = tmp->val;
		node->pNext = nullptr;
		prev->pNext = node;
		tmp = tmp->pNext;
		prev = prev->pNext;
	}
	return *this;
}

template<class T>
bool Stack<T>::operator==(const Stack<T>& s) const
{
	Node* tmpFirst = pFirst;
	Node* tmpSecond = s.pFirst;
	while (tmpFirst != nullptr && tmpSecond != nullptr)
	{
		if (tmpFirst->val != tmpSecond->val) return false;
		tmpFirst = tmpFirst->pNext;
		tmpSecond = tmpSecond->pNext;
	}
	if (tmpFirst == tmpSecond) return true;
	return false;
}

template<class T>
bool Stack<T>::operator!=(const Stack<T>& s) const
{
	return !(*this == s);
}

