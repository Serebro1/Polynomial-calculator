#pragma once
template<class T>
struct Node {
	T val;
	Node* pNext;
};

template<class T>
class TList {
	Node<T>* pFirst;
public:
	int size();
	void PushFront(const T& val);
};

template<class T>
int TList<T>::size()
{
	int count = 0;
	Node<T>* next = pFirst;
	while (next != nullptr) {
		next = next->pNext;
		count++;
	}
	return count;
}

template<class T>
void TList<T>::PushFront(const T& val)
{
	Node<T>* node = new Node<T>{ val, pFirst };
	pFirst = node;
}
