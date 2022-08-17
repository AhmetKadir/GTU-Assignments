/*Header file for GTUVector
Includes definitons and implementations*/

#ifndef GTUVECTOR_H
#define GTUVECTOR_H

#include <iostream>
#include "Iterable.h"
#include <exception>

using std::shared_ptr;

namespace IterableAka{
template<class T>
class GTUVector : public Iterable<T>{
public:
	GTUVector(); /*Default Constructor with 20 T capacity*/

	GTUVector(int sizeVal); /*Constructor with given size. Values initialized with 0*/

	GTUVector(const GTUVector<T>& otherVect); /*Copy constructor*/

	GTUVector(GTUVector<T>&& otherVect); /*Move Constructor*/

	GTUVector& operator=(const GTUVector<T>& otherVect); /*Assignment operator*/

	GTUVector& operator=(GTUVector<T>&& otherVect); /*Move assignment*/
	
	bool empty() const;/*Returns true if the vector is empty*/

	unsigned int size() const; /*Returns size of the vector*/

	void erase(GTUIterator<T> iter); /*Erases the element which pointed by the iterator*/

	void clear();/*Clears the vector, deletes all element.*/

	GTUIterator<T> begin(); /*Return iterator to beginning*/

	GTUIterator<T> end(); /*Return iterator to end*/

	GTUIteratorConst<T> cbegin() const; /*Return a constant iterator to beginning*/

	GTUIteratorConst<T> cend() const; /*Return a constant iterator to end*/

	void add(T value); /*Adds the value end of the vector*/

	T& operator[](unsigned int index); /*Array operator*/
private:
	unsigned int sizeVector;
	unsigned int capacity;
	shared_ptr<T[]> sPtr;
};

template<class T>
GTUVector<T>::GTUVector():												//default constructor
sizeVector(0), capacity(20), sPtr(new T[capacity], std::default_delete<T[]>()) 
{}										


template<class T>
GTUVector<T>::GTUVector(int sizeVal):								//Constructor with given size
sizeVector(sizeVal), capacity(sizeVal*2), sPtr(new T[capacity], std::default_delete<T[]>()){
	for(unsigned int i=0 ; i<sizeVal; i++)
		sPtr.get()[i] = 0;
}

template <class T>
GTUVector<T>::GTUVector(const GTUVector<T>& otherVect):						//Copy constructor
sizeVector(otherVect.size()), capacity(otherVect.capacity)
{	
	sPtr = otherVect.sPtr;
	for(unsigned int i=0; i<size() ; i++)
		sPtr[i] = otherVect.sPtr[i];
	std::cout << "Copy constructor worked succesfully" << std::endl;
}

template <class T>
GTUVector<T>::GTUVector(GTUVector<T>&& otherVect):							//Move constructor
sizeVector(std::move(otherVect.size())), capacity(std::move(otherVect.capacity))
{
	sPtr = otherVect.sPtr;
	otherVect.sPtr = NULL;
	otherVect.sizeVector = 0;
	std::cout << "Move constructor worked succesfully" << std::endl;
}

template <class T>
GTUVector<T>& GTUVector<T>::operator=(const GTUVector<T>& otherVect){				//Copy assignment
	capacity = otherVect.capacity;
	sizeVector = otherVect.size();
	sPtr = otherVect.sPtr;
	for (unsigned int i = 0; i < size(); i++)
		sPtr[i] = otherVect.sPtr[i];
	std::cout << "Copy assignment worked succesfully" << std::endl;
	return *this;
}

template <class T>
GTUVector<T>& GTUVector<T>::operator=(GTUVector<T>&& otherVect){     	//Move assignment
	capacity = otherVect.capacity;
	sizeVector = otherVect.size();
	for (unsigned int i = 0; i < size(); i++)
		sPtr[i] = otherVect.sPtr[i];
	
	otherVect.sPtr = NULL;
	otherVect.sizeVector = 0;
	std::cout << "Move assignment worked succesfully" << std::endl;

	return *this;
}

template<class T>
bool GTUVector<T>::empty() const{
	return (sizeVector==0);
}

template<class T>
unsigned int GTUVector<T>::size() const{
	return sizeVector;
}

template<class T>
void GTUVector<T>::erase(GTUIterator<T> iter){
	unsigned int delIndex;
	bool found(false);
	for(unsigned int i=0; i<sizeVector; i++){
		if (sPtr.get()[i] == *iter){
			delIndex = i;
			found = true;
		}
	}
	if(found){
		for(auto j=delIndex ; j+1 <sizeVector ; j++) sPtr.get()[j] = sPtr.get()[j+1];
		sizeVector--;
	}
}

template<class T>
void GTUVector<T>::clear(){
	sizeVector = 0;
}

template<class T>
GTUIterator<T> GTUVector<T>::begin(){
	GTUIterator<T> iter(sPtr[0]);
	return *iter;
}

template<class T>
GTUIterator<T> GTUVector<T>::end(){
	GTUIterator<T> iter(sPtr[sizeVector]);
	return *iter;
}

template<class T>
GTUIteratorConst<T> GTUVector<T>::cbegin() const{
	GTUIteratorConst<T> iterC(sPtr[0]);
	return *iterC;
}

template<class T>
GTUIteratorConst<T> GTUVector<T>::cend() const{
	GTUIteratorConst<T> iterC(sPtr[sizeVector]);
	return *iterC;
}

template<class T>
void GTUVector<T>::add(T value){
	if(sizeVector >= capacity){
		capacity*= 2;
		shared_ptr<T[]> tempPtr(new T[capacity], std::default_delete<T[]>());
		for(unsigned int i=0; i<size(); i++){
			tempPtr[i]=sPtr[i];
		}

		sPtr = tempPtr;
	}
	sPtr[size()] = value;
	sizeVector+= 1;
}

template<class T>
T& GTUVector<T>::operator[](unsigned int index){
	//exception
	if (index >= size())
		throw "Wrong index value !";
	return sPtr.get()[index];
}

}//end namespace

#endif