#pragma once
#include <iterator>

template<typename ValueType> class TList;
template<typename ValueType> struct Node;

template<typename ValueType>
class ListIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
	friend class TList<ValueType>;

public:
	ListIterator(const ListIterator& it);

	bool operator!=(const ListIterator& other) const;
	bool operator==(const ListIterator& other) const;
	typename ListIterator<ValueType>::reference operator*() const;
	typename ListIterator<ValueType>::pointer operator->() const;
	ListIterator& operator++();
private:
	ListIterator(Node<ValueType>* p);
	Node<ValueType>* pCurr;
};

template<typename ValueType>
ListIterator<ValueType>::ListIterator(Node<ValueType>* p) : pCurr(p)
{

}
template<typename ValueType>
ListIterator<ValueType>::ListIterator(const ListIterator& it) : pCurr(it.pCurr)
{

}

template<typename ValueType>
bool ListIterator<ValueType>::operator!=(const ListIterator& other) const
{
	return pCurr != other.pCurr;
}
template<typename ValueType>
bool ListIterator<ValueType>::operator==(const ListIterator& other) const
{
	return pCurr == other.pCurr;
}

template<typename ValueType>
typename ListIterator<ValueType>::reference ListIterator<ValueType>::operator*() const
{
	return pCurr->val;
}

template<typename ValueType>
typename ListIterator<ValueType>::pointer ListIterator<ValueType>::operator->() const
{
	return &(pCurr->val);
}

template<typename ValueType>
ListIterator<ValueType>& ListIterator<ValueType>::operator++()
{
	pCurr = pCurr->pNext;
	return *this;
}