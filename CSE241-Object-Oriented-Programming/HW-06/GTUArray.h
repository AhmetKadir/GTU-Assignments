/*Header file for GTUArray
Includes definitons and implementations*/

#ifndef GTUARRAY_H
#define GTUARRAY_H

#include <iostream>
#include "Iterable.h"

namespace IterableAka{
template<class T, int SIZE>
class GTUArray : public Iterable<T>{
public:
	GTUArray(); /*Default Constructor with 50 T capacity*/
	
	GTUArray(const GTUArray<T, SIZE>& otherArray); /*Copy constructor*/

	GTUArray(GTUArray<T, SIZE>&& otherArray); /*Move Constructor*/

	GTUArray& operator=(const GTUArray<T, SIZE>& otherArray); /*Assignment operator*/

	GTUArray& operator=(GTUArray<T, SIZE>&& otherArray); /*Move assignment*/

	bool empty() const;/*Returns true if the array is empty*/

	unsigned int size() const; /*Returns size of the array*/

	void erase(GTUIterator<T> iter); /*Erases the element which pointed by the iterator*/

	void clear();/*Clears the array, deletes all element.*/

	GTUIterator<T> begin(); /*Return iterator to beginning*/

	GTUIterator<T> end(); /*Return iterator to end*/

	GTUIteratorConst<T> cbegin() const; /*Return a constant iterator to beginning*/

	GTUIteratorConst<T> cend() const; /*Return a constant iterator to end*/

	T& operator[](int index); /*Array operator*/
private:
	unsigned int sizeArray;
	unsigned int capacity;
	shared_ptr<T[]> sPtr;
};


template<class T, int SIZE>
GTUArray<T, SIZE>::GTUArray(): 											//default constructor
sizeArray(SIZE), capacity(SIZE*2), sPtr(new T[capacity], std::default_delete<T[]>())
{
	for(unsigned int i=0; i<size(); i++){
		sPtr[i] = 0;						//Initializes the array with 0s.
	}
}

template <class T, int SIZE>
GTUArray<T, SIZE>::GTUArray(const GTUArray<T, SIZE>& otherArray):						//Copy constructor
sizeArray(otherArray.size()), capacity(otherArray.capacity)
{	
	sPtr = otherArray.sPtr;
	for(unsigned int i=0; i<size() ; i++)
		sPtr[i] = otherArray.sPtr[i];
	std::cout << "Copy constructor worked succesfully" << std::endl;
}

template <class T, int SIZE>
GTUArray<T, SIZE>::GTUArray(GTUArray<T, SIZE>&& otherArray):								//Move constructor
sizeArray(std::move(otherArray.size())), capacity(std::move(otherArray.capacity))
{
	sPtr = otherArray.sPtr;
	otherArray.sPtr = NULL;
	otherArray.sizeArray = 0;
	std::cout << "Move constructor worked succesfully" << std::endl;
}

template <class T, int SIZE>
GTUArray<T, SIZE>& GTUArray<T, SIZE>::operator=(const GTUArray<T, SIZE>& otherArray){				//Copy assignment
	capacity = otherArray.capacity;
	sizeArray = otherArray.size();
	sPtr = otherArray.sPtr;
	for (unsigned int i = 0; i < size(); i++)
		sPtr[i] = otherArray.sPtr[i];
	std::cout << "Copy assignment worked succesfully" << std::endl;
	return *this;
}

template <class T, int SIZE>
GTUArray<T, SIZE>& GTUArray<T, SIZE>::operator=(GTUArray<T, SIZE>&& otherArray){     				//Move assignment
	capacity = otherArray.capacity;
	sizeArray = otherArray.size();
	for (unsigned int i = 0; i < sizeArray; i++)
		sPtr[i] = otherArray.sPtr[i];
	
	otherArray.sPtr = NULL;
	otherArray.sizeArray = 0;
	std::cout << "Move assignment worked succesfully" << std::endl;

	return *this;
}

template<class T, int SIZE>			
bool GTUArray<T, SIZE>::empty() const{								
	return (sizeArray==0);
}

template<class T, int SIZE>
unsigned int GTUArray<T, SIZE>::size() const{
	return sizeArray;
}

template<class T, int SIZE>
void GTUArray<T, SIZE>::erase(GTUIterator<T> iter){
	for(unsigned int i=0; i<sizeArray; i++)
		if (sPtr[i] == *iter)
			sPtr[i] =0;					//Replaces the erased element with 0.
}
template<class T, int SIZE>
void GTUArray<T, SIZE>::clear(){
	sizeArray = 0;
}

template<class T, int SIZE>
GTUIterator<T> GTUArray<T,SIZE>::begin(){
	GTUIterator<T> iter(sPtr[0]);
	return *iter;
}

template<class T, int SIZE>
GTUIterator<T> GTUArray<T,SIZE>::end(){
	GTUIterator<T> iter(sPtr[sizeArray]);
	return *iter;
}

template<class T, int SIZE>
GTUIteratorConst<T> GTUArray<T, SIZE>::cbegin() const{
	GTUIteratorConst<T> iterC(sPtr[0]);
	return *iterC;
}

template<class T, int SIZE>
GTUIteratorConst<T> GTUArray<T, SIZE>::cend() const{
	GTUIteratorConst<T> iterC(sPtr[size()]);
	return *iterC;
}

template<class T, int SIZE>
T& GTUArray<T, SIZE>::operator[](int index){
	//need exception
	return sPtr[index];
}


}//end namespace

#endif