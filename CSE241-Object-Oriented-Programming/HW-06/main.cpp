/*Driver program to test the all the classes and all of their functions.*/
#include <iostream>
#include <algorithm>
#include "Iterable.h"
#include "GTUVector.h"
#include "GTUSet.h"
#include "GTUArray.h"

using std::cout;
using std::cin;
using std::endl;

using namespace IterableAka;


void testGtuVector();
void testGtuSet();
void testGtuArray();

int main(){
	cout << "**************************************************" << endl;
	cout << "**************************************************" << endl;
	cout << "WELCOME TO THE GTU ITERABLES DEMONSTRATION PROGRAM" << endl;
	cout << "**************************************************" << endl;
	cout << "**************************************************" << endl << endl << endl;

	testGtuVector();
	testGtuSet();
	testGtuArray();

	return 0;
}

void testGtuVector(){
	/*Test For GtuVector Class*/
	cout << "__________________________________________________" << endl;
	cout << "_______________TESTING GTUVector__________________" << endl;
	cout << "__________________________________________________" << endl << endl;
	GTUIterator<int> iter;
	GTUIterator<int> it;
	GTUVector<int> myvect;
	GTUVector<char>charVect; //Creates a char vector
	GTUVector<double> charDoubles; //Creates doubles vector
	
	/*TESTING std::fill*/
	GTUVector<int> vec;
	vec.add(5);
	vec.add(12);
	vec.add(8);
	cout << "3 is filling to vec with std::fill" << endl << "Now vec is : ";
	std::fill(vec.begin(), vec.end(), 3);
	for(it = vec.begin() ; it != vec.end(); ++it){
		cout << *it << " ";
	}
	cout << endl << endl;

	/*TESTING std::find*/
	/*GTUVector<int> vec2;
	vec2.add(19);
	vec2.add(12);
	vec2.add(3);
	cout << "Test to find 12 in the vec2 with std::find" << endl << "Now vec is : ";
	for(it = vec2.begin() ; it != vec2.end(); ++it){
		cout << *it << " ";
	}
	cout << endl ;
	auto result1 = std::find(vec2.begin(), vec2.end(), 12);
	if(result1 != std::end(vec2)) cout << "vec2 contains " << 12 << endl;
	else cout << "vec2 does not contain " << 12 << endl;
	cout << endl << endl;*/
	
	/*TESTING std::for_each*/
	GTUVector<int> vec3;
	auto print = [](const int& n) {cout << " " << n; };
	vec3.add(19);
	vec3.add(15);
	vec3.add(24);
	vec3.add(41);
	cout << "using std::for_each my vec3: ";
	std::for_each(vec3.begin(), vec3.end(), print);
	cout << endl << "vec3 is : ";
	for(it = vec3.begin() ; it != vec3.end(); ++it){
		cout << *it << " ";
	}
	cout << endl << endl;

	/*TESTING std::sort*/
	/*GTUVector<int> vec4;
	vec4.add(25);
	vec4.add(10);
	vec4.add(33);
	cout << endl << "vec4 is : ";
	for(it = vec4.begin() ; it != vec4.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	std::sort(vec4.begin(), vec4.end());
	cout << endl << "after sorted with std::sort, vec4 is : ";
	for(it = vec4.begin() ; it != vec4.end(); ++it){
		cout << *it << " ";
	}
	cout << endl << endl;*/



	if (myvect.empty()) cout << "My vector is empty" << endl;
	else cout << "My vector is not empty" << endl;

	cout << "Size of my vector is " << myvect.size() << endl;

	myvect.add(3);
	myvect.add(11);
	myvect.add(8);

	cout << endl << "After added 3 11 and 8 to the vector: ";
	for(iter = myvect.begin() ; iter != myvect.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;

	//Exception handling
	try {
    	cout << "index value is 15" << endl;
		cout << "value is " << myvect[15] << endl;

    } catch (const char* msg) {
    	std::cerr << msg << endl;
    }

	try {
		cout << "index value is 2" << endl;
    	cout << "value is " << myvect[2] << endl;
    } catch (const char* msg) {
    	std::cerr << msg << endl;
    }
	cout << endl;
	
	cout << "Size of my vector is " << myvect.size() << endl;
	if (myvect.empty()) cout << "My vector is empty" << endl;
	else cout << "My vector is not empty" << endl << endl;
	
	for(iter = myvect.begin() ; iter != myvect.end(); ++iter){
		if(*iter == 11){
			cout << *iter << " is erased from the vector" << endl;
			myvect.erase(*iter);
			break;
		}
	}
	cout << "Size of my vector is: " << myvect.size();
	cout << endl << endl;

	myvect.add(25);
	cout << "25 is added to the vector" << endl;
	cout << "Now my vector is : ";
	for(iter = myvect.begin() ; iter != myvect.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;
	cout << "Size of my vector is: " << myvect.size();
	cout << endl << endl;

	/*Using array operator*/
	cout << "Testing array operator..." << endl;
	cout << "vector[1] = " << myvect[1] << endl;

	myvect.clear();
	cout << endl << "My vector is cleared" << endl;
	cout << "Size of my vector is " << myvect.size() << endl;
	
}//end testGTUVector


void testGtuSet(){
	cout << "__________________________________________________" << endl;
	cout << "_______________TESTING GTUSet_____________________" << endl;
	cout << "__________________________________________________" << endl << endl;
	/*Test For GtuSet Class*/
	
	GTUIterator<int> iter;
	/*GTUIteratorConst const_iterSet;*/
	GTUSet<char> CharSet;	//Creates char set
	GTUSet<double> DoubleSet; //creates doubles set
	GTUSet<int> testSet;

	for(iter = testSet.begin() ; iter != testSet.end(); ++iter){
		cout << *iter << " ";
	}

	/*GTUSet<int> mySet;
	mySet.add(5);
	mySet.add(12);
	mySet.add(8);
	std::sort(mySet.begin(), mySet.end());
	for(it = mySet.begin() ; it != mySet.end(); ++it){
		cout << *it << " ";
	}	*/

	if (testSet.empty()) cout << "testSet is empty" << endl;
	else cout << "testSet is not empty" << endl;

	cout << "Size of testSet is " << testSet.size() << endl;

	testSet.add(13);
	testSet.add(21);
	testSet.add(68);
	testSet.add(99);

	cout << endl << "After added 13 21 68 and 99 to the Set: ";
	for(iter = testSet.begin() ; iter != testSet.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl << endl;

	/*Testing copy constructor*/
	GTUSet<int> copiedSet(testSet);
	cout << "Copied set is: ";
	for(iter = copiedSet.begin() ; iter != copiedSet.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl << "testSet(original set) is: ";
	for(iter = testSet.begin() ; iter != testSet.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl << endl;

	/*Testing copy assigment*/
	GTUSet<int> copiedSet2;
	copiedSet2 = testSet;
	cout << "Copied set is: ";
	for(iter = copiedSet2.begin() ; iter != copiedSet2.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl << "testSet(original set) is: ";
	for(iter = testSet.begin() ; iter != testSet.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl << endl;


	cout << "Testing search function to find 68 in the set" << endl;
	cout << 68 << " = " <<*(testSet.search(68)) << endl;
	if (*(testSet.search(68)) == 68) cout << "SUCCESSFUL" << endl << endl;
	else cout << "Could not find the number." << endl << endl;

	cout << "Size of testSet is " << testSet.size() << endl;
	if (testSet.empty()) cout << "testSet is empty" << endl;
	else cout << "testSet is not empty" << endl << endl;

	iter= testSet.search(21);
	if(iter != testSet.end()) {
		cout << *iter << " is erased from the Set" << endl;
		testSet.erase(*iter);
	}

	iter= testSet.search(13);
	if(iter != testSet.end()) {
		cout << *iter << " is deleted from the Set" << endl;
		testSet.deleteSet(*iter);
	}

	cout << "Size of testSet is: " << testSet.size();
	cout << endl << endl;

	testSet.add(25);
	cout << "25 is added to the Set" << endl;
	cout << "adding lots of numbers..: " << endl;
	
	for(int i =0 ; i < 100 ; i+=3){
		testSet.add(i+1);
	}

	cout << "Now my Set is : ";
	for(iter = testSet.begin() ; iter != testSet.end(); ++iter){
		cout << *iter << " ";
	}

	cout << endl;
	cout << "Size of testSet is: " << testSet.size();
	cout << endl << endl;

	GTUSet<int> testSet2;
	testSet2.add(1);
	testSet2.add(11);
	testSet2.add(87);
	testSet2.add(99);

	cout << "set 2 is : ";
	for(iter = testSet2.begin(); iter != testSet2.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;

	/*Testing move assignment*/
	GTUSet<int> newSet;
	newSet = std::move(testSet2);
	cout << "set2 is moved to newSet" << endl;
	cout << "newSet is : ";
	for(iter = newSet.begin(); iter != newSet.end(); ++iter)
		cout << *iter << " "; 
	cout << endl;
	cout << "set 2 is : ";
	for(iter = testSet2.begin(); iter != testSet2.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl << endl;
	
	/*Testing move constructor*/
	GTUSet<int> newSet2(std::move(testSet));
	cout << "testSet is moved to newSet2" << endl;

	cout << "newSet2 is : ";
	for(iter = newSet2.begin(); iter != newSet2.end(); ++iter)
		cout << *iter << " "; 
	cout << endl;

	cout << "testSet is : ";
	for(iter = testSet.begin(); iter != testSet.end(); ++iter)
		cout << *iter << " "; 
	cout << endl << endl;

	/*Testing intersection function*/
	GTUSet<int> intersectSet = newSet.intersect(newSet2); //Copy assignment
	cout << "Intersection set of newSet1 and newSet2: ";
	for(iter = intersectSet.begin(); iter != intersectSet.end(); ++iter)
		cout << *iter << " "; 
	cout << endl << endl;

	/*Testing union function*/
	
	GTUSet<int> unionSet1 = newSet.unionSet(newSet2);
	cout << "Union set of newset1 and newset2: ";
	for(iter = unionSet1.begin(); iter != unionSet1.end(); ++iter)
		cout << *iter << " "; 
	cout << endl << endl;

	unionSet1.clear();
	cout << "unionSet is cleared" << endl;
	cout << "Size of unionSet is " << unionSet1.size() << endl;
}//end testGtuSet

void testGtuArray(){
	cout << "__________________________________________________" << endl;
	cout << "_______________TESTING GTUArray__________________" << endl;
	cout << "__________________________________________________" << endl << endl;
	
	/*Test For GtuArray Class*/
	
	GTUArray<char, 15> CharArray;	  //Creates char Array
	GTUArray<double, 20> DoubleArray; //Creates doubles Array
	GTUIterator<int> iter;
	/*GTUIteratorConst const_iterArray;*/
	GTUArray<int,10> testArray;

	cout << "my array is : ";
	for(iter = testArray.begin() ; iter != testArray.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;

	testArray[0]= 1;
	testArray[1]= 4;
	testArray[2]= 14;
	testArray[3]= 24;
	testArray[4]= 35;

	cout << "1 4 14 24 and 35 is added to my array" << endl;
	cout << "my array is : ";
	for(iter = testArray.begin() ; iter != testArray.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;

	/*GTUArray<int> myArray;
	myArray.add(5);
	myArray.add(12);
	myArray.add(8);
	std::sort(myArray.begin(), myArray.end());
	for(it = myArray.begin() ; it != myArray.end(); ++it){
		cout << *it << " ";
	}	*/

	if (testArray.empty()) cout << "My Array is empty" << endl;
	else cout << "My Array is not empty" << endl;

	cout << "Size of my Array is " << testArray.size() << endl << endl;

	auto testArray2(testArray); //using copy constructor
	cout << "Testing copy constructor" << endl;
	cout << "TEST ARRAY2 IS : ";
	for(iter = testArray2.begin() ; iter != testArray2.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;
	cout << "Size of testArray2 is " << testArray2.size() << endl;
	cout << endl;

	cout << "Size of my Array is " << testArray.size() << endl;
	if (testArray.empty()) cout << "My Array is empty" << endl;
	else cout << "My Array is not empty" << endl;
	 
	for(iter = testArray.begin(); iter != testArray.end(); ++iter){
		if(*iter == 24){
			cout << *iter << " is erased" << endl;
			testArray.erase(*iter);
			break;
		}
	}
	cout << "Size of my Array is: " << testArray.size() << endl << endl;
	for(iter = testArray.begin() ; iter != testArray.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;

	testArray.clear();
	cout << endl << "My Array is cleared" << endl;
	cout << "Size of my Array is " << testArray.size() << endl;
	cout << "Checking if my array is empty..." << endl;
	if (testArray.empty()) cout << "My Array is empty" << endl;
	else cout << "My Array is not empty" << endl;
}//end testGTUArray