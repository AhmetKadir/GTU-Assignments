/*Header file for GTUSet
Includes definitons and implementations*/

#ifndef GTUSET_H
#define GTUSET_H

#include <iostream>
#include "Iterable.h"

using std::shared_ptr;

namespace IterableAka{
template<class T>
class GTUSet : public Iterable<T>{
public:
	GTUSet(); /*Default Constructor with 20 T capacity*/

	GTUSet(const GTUSet<T>& otherSet); /*Copy constructor*/

	GTUSet(GTUSet<T>&& otherSet); /*Move Constructor*/

	GTUSet& operator=(const GTUSet<T>& otherSet); /*Assignment operator*/

	GTUSet& operator=(GTUSet<T>&& otherSet); /*Move assignment*/

	bool empty() const;/*Returns true if the Set is empty*/

	unsigned int size() const; /*Returns size of the Set*/

	void erase(GTUIterator<T> iter); /*Erases the element which pointed by the iterator*/

	void clear();/*Clears the set, deletes all element.*/

	GTUIterator<T> begin(); /*Return iterator to beginning*/

	GTUIterator<T> end(); /*Return iterator to end*/

	GTUIteratorConst<T> cbegin() const; /*Return a constant iterator to beginning*/

	GTUIteratorConst<T> cend()const; //Return a constant iterator to end

	void add(T value); /*Adds the value end of the Set*/

	GTUIterator<T> search(const int& el) const; /*Finds the element in the set and returns iterator
									If no such element is found, end iterator is returned.*/

	void deleteSet(GTUIterator<T> iter);/*Deletes the element which pointed by the iterator*/
	
	GTUSet<T> intersect(GTUSet<T>& set2);	/*returns intersection set of this set and set2*/

	GTUSet<T> unionSet(GTUSet<T>& set2); /*returns union set of this set and set2*/
private:
	unsigned int sizeSet;
	unsigned int capacity;
	shared_ptr<T[]> sPtr;
};

template <class T>
GTUSet<T>::GTUSet():										//Default constructor
sizeSet(0), capacity(20), sPtr(new T[capacity], std::default_delete<T[]>()) 
{}

template <class T>
GTUSet<T>::GTUSet(const GTUSet<T>& otherSet):				//Copy constructor
sizeSet(otherSet.size()), capacity(otherSet.capacity)
{	
	sPtr = otherSet.sPtr;
	for(unsigned int i=0; i<size() ; i++)
		sPtr[i] = otherSet.sPtr[i];
	std::cout << "Copy constructor worked succesfully" << std::endl;
}

template <class T>
GTUSet<T>::GTUSet(GTUSet<T>&& otherSet):					//Move constructor
sizeSet(std::move(otherSet.size())), capacity(std::move(otherSet.capacity))
{
	sPtr = otherSet.sPtr;
	otherSet.sPtr = NULL;
	otherSet.sizeSet = 0;
	std::cout << "Move constructor worked succesfully" << std::endl;
}

template <class T>
GTUSet<T>& GTUSet<T>::operator=(const GTUSet<T>& otherSet){				//Copy assignment
	capacity = otherSet.capacity;
	sizeSet = otherSet.size();
	sPtr = otherSet.sPtr;
	for (unsigned int i = 0; i < size(); i++)
		sPtr[i] = otherSet.sPtr[i];
	std::cout << "Copy assignment worked succesfully" << std::endl;
	return *this;
}

template <class T>
GTUSet<T>& GTUSet<T>::operator=(GTUSet<T>&& otherSet){     	//Move assignment
	capacity = otherSet.capacity;
	sizeSet = otherSet.size();
	for (unsigned int i = 0; i < sizeSet; i++)
		sPtr[i] = otherSet.sPtr[i];
	
	otherSet.sPtr = NULL;
	otherSet.sizeSet = 0;
	std::cout << "Move assignment worked succesfully" << std::endl;

	return *this;
}

template<class T>
bool GTUSet<T>::empty() const{
	return (sizeSet==0);
}

template<class T>
unsigned int GTUSet<T>::size() const{
	return sizeSet;
}

template<class T>
void GTUSet<T>::erase(GTUIterator<T> iter){
	unsigned int delIndex;
	bool found(false);
	for(unsigned int i=0; i<sizeSet; i++){
		if (sPtr[i] == *iter){
			delIndex = i;
			found = true;
		}
	}
	if(found){
		for(auto j=delIndex ; j+1 <sizeSet ; j++) sPtr[j] = sPtr[j+1];
		sizeSet--;
	}
}

template<class T>
void GTUSet<T>::clear(){
	sizeSet = 0;
}

template<class T>
GTUIterator<T> GTUSet<T>::begin(){
	GTUIterator<T> iter(sPtr[0]);
	return *iter;
}

template<class T>
GTUIterator<T> GTUSet<T>::end(){
	GTUIterator<T> iter(sPtr[size()]);
	return *iter;
}

template<class T>
GTUIteratorConst<T> GTUSet<T>::cbegin() const{
	GTUIteratorConst<T> iterC(sPtr[0]);
	return *iterC;
}

template<class T>
GTUIteratorConst<T> GTUSet<T>::cend() const{
	GTUIteratorConst<T> iterC(sPtr[size()]);
	return *iterC;
}

template<class T>
void GTUSet<T>::add(T value){
	GTUIterator<T> iter(search(value));
	if (iter != end()) return;
	/*If the element has already in the set, then it wont be added again.*/

	if(sizeSet >= capacity){
		capacity*= 2;
		shared_ptr<T[]> tempPtr(new T[capacity], std::default_delete<T[]>());
		for(unsigned int i=0; i<sizeSet; i++){
			tempPtr[i]=sPtr[i];
		}

		sPtr = tempPtr;
	}
	sPtr[sizeSet] = value;
	sizeSet+= 1;
}

template<class T>
GTUIterator<T> GTUSet<T>::search(const int& el) const{
	for(unsigned int i=0; i<sizeSet; i++){
		if (sPtr[i] == el) {
			GTUIterator<T> iter(sPtr[i]);
			return *iter;
		}
	}
	GTUIterator<T> iter(sPtr[sizeSet]);
	return *iter;
}

template<class T>
void GTUSet<T>::deleteSet(GTUIterator<T> iter){
	erase(*iter);
}

template<class T>	
GTUSet<T> GTUSet<T>::intersect(GTUSet<T>& set2){
	GTUSet<T> mySet;
	GTUIterator<T> iter1;
	GTUIterator<T> iter2;
	for(iter1 = begin(); iter1 != end(); ++iter1){
		for(iter2 = set2.begin(); iter2 != set2.end(); ++iter2){
			if (*iter1 == *iter2) {
				mySet.add(*iter1);
				break;
			}
		}
	}
	iter1 = set2.begin();
	return mySet;
}


template<class T>
GTUSet<T> GTUSet<T>::unionSet(GTUSet<T>& set2){
	GTUSet<T> newSet;
	GTUIterator<T> iter1;
	GTUIterator<T> iter2;

	for(iter1 = begin(); iter1 != end(); ++iter1)
		newSet.add(*iter1);

	for(iter2 = set2.begin(); iter2 != set2.end(); ++iter2)
		newSet.add(*iter2); //repetition is taken care by add function

	return newSet;
}


}//end namespace

#endif