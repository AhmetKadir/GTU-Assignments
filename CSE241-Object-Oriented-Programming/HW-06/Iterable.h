#ifndef ITERABLE_H
#define ITERABLE_H

#include <iostream>
#include <memory>
#include "Iterators.h"

namespace IterableAka{
template<class T>
class Iterable{
public:
	virtual bool empty()const = 0;

	virtual unsigned int size()const = 0;

	virtual void erase(GTUIterator<T> iter)= 0;

	virtual void clear()= 0;

	virtual GTUIterator<T> begin()=0;

	virtual GTUIterator<T> end()= 0;

	/*virtual T& cbegin()const = 0;

	virtual T& cend()const = 0;*/

	virtual ~Iterable<T>() = default;
};

}//end namespace
#endif