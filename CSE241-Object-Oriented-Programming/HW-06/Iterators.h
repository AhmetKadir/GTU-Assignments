/*This file includes GTUIterator and GTUIteratorConst classes.*/

#ifndef ITERATORS_H
#define ITERATORS_H

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstddef>

namespace IterableAka{

template<class T>
class GTUIterator{
	using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;  // or also value_type*
    using reference         = T&;  // or also value_type&
public:
	GTUIterator():ptr(NULL){} /*Default constructor*/

	GTUIterator(T* mptr) : ptr(ptr) {}

	GTUIterator(T& val): ptr(&val){}

	T& operator *() {return *ptr;}

	T operator ->() {return ptr;}

	GTUIterator& operator ++(){++ptr; return *this;}

	GTUIterator& operator++(int) {GTUIterator<T> tmp = *this; ++(*this); return tmp; }

	GTUIterator& operator --(){--ptr; return *this;}
	
	GTUIterator& operator--(int) {GTUIterator<T> tmp = *this; --(*this); return tmp; }

	bool operator ==(const GTUIterator& other)const {return ptr == other.ptr;}

	bool operator !=(const GTUIterator& other)const {if(ptr == other.ptr) return false;
													 return true;}

	GTUIterator& operator =(const GTUIterator<T>& other){
		ptr = other.ptr;
		return *this;
	}

	~GTUIterator(){}
private:
	T *ptr;
};

template<class T>
class GTUIteratorConst{
	using iterator_category = std::bidirectional_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;  // or also value_type*
    using reference         = T&;  // or also value_type&
public:
	GTUIteratorConst():ptr(NULL){} /*Default constructor*/

	GTUIteratorConst(T* mptr) : ptr(ptr) {}

	GTUIteratorConst(T& val): ptr(&val){}

	T& operator *()const {return *ptr;}

	T operator ->() {return ptr;}

	const GTUIteratorConst& operator ++(){++ptr; return *this;}

	const GTUIteratorConst& operator++(int) {GTUIteratorConst<T> tmp = *this; ++(*this); return tmp; }

	const GTUIteratorConst& operator --(){--ptr; return *this;}
	
	const GTUIteratorConst& operator--(int) {GTUIteratorConst<T> tmp = *this; --(*this); return tmp; }

	bool operator ==(const GTUIteratorConst& other)const {return ptr == other.ptr;}

	bool operator !=(const GTUIteratorConst& other)const {if(ptr == other.ptr) return false;
													 return true;}

	const GTUIteratorConst& operator =(const GTUIteratorConst<T>& other){
		ptr = other.ptr;
		return *this;
	}

	~GTUIteratorConst(){}
private:
	T *ptr;
};


}
#endif