#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "hw4.h"

using namespace std;
using namespace ns1;

void writeFile(DayofYearSet set1,string fileName);
int DayofYearSet::totalNumberofDates = 0;

int main(){
	DayofYearSet::DayofYear date1(7,7);
	DayofYearSet::DayofYear date2(8,12);
	DayofYearSet::DayofYear date3(7,7);
	DayofYearSet::DayofYear date4(5,10);
	vector <DayofYearSet::DayofYear> mydates, mydates2;
	mydates.push_back(date1);
	mydates.push_back(date2);
	mydates2.push_back(date3);
	mydates2.push_back(date4);
	DayofYearSet set1(mydates);
	DayofYearSet set2(mydates2);
	DayofYearSet set3;
	
	writeFile(set1, "dates/set1Dates.txt");
	writeFile(set2, "dates/set2Dates.txt");

	cout << "\nset1 : \n" << set1 << endl;
	cout << "size of set1 : " << set1.size() << endl << endl;
	cout << "set2 : \n" << set2 << endl;
	cout << "size of set2 : " << set2.size() << endl << endl;
	cout << "set3\n" << set3 << endl;
	cout << "size of set3 : " << set3.size() << endl <<endl;

	/*TEST ASSIGNMENT*/

	/*cout << endl << "*************************" << endl;
	cout << "TESTING ASSIGNMENT FUNCTION"   << endl;
	cout << "*************************" << endl;
	set1 = set2;

	cout << "set1" << set1 << endl;
	cout << "set2" << set2 << endl;
	cout << "set3" << set3 << endl;*/	
	
	cout << endl << "*************************" << endl;
	cout << "TESTING Equal and not Equal OPERATORS"   << endl;
	cout << "*************************" << endl;
	cout << "\nComparing set1 and set2\n";
	if (set1 != set2) cout << "These sets are not equal" << endl;
	else cout << "These sets are equal" << endl;

	if (set1 == set2) cout << "These sets are equal" << endl;
	else cout << "These sets are not equal" << endl;
	
	cout << endl << "*************************" << endl;
	cout << "TESTING ADD FUNCTION"   << endl;
	cout << "*************************" << endl;
	set2.add(3,9);
	cout << "3,9 added to set2" << endl;
	cout << "set2 :\n" << set2 << endl; 
	cout << "size of set2 is " << set2.size() << endl;

	cout << endl << "*************************" << endl;
	cout << "TESTING INDEX OPERATOR"   << endl;
	cout << "*************************" << endl;
	cout << "day of set2[2] = " << set2[2].getDay()<< endl; 


	/*TEST remove*/
	set3 = set1;
	cout << endl << "*************************" << endl;
	cout << "TESTING REMOVE FUNCTION"   << endl;
	cout << "*************************" << endl;
	cout << "set3 :\n" << set3 << endl;
	set3.remove();
	cout << "last element of set3 is removed" << endl;
	cout << "set3 : \n" << set3 << endl;
	set3.remove();
	cout << "last element of set3 is removed" << endl;
	cout << "set3 : \n" << set3 << endl;
	set3.remove();
	cout << "last element of set3 is removed" << endl;
	cout << "set3 : \n" << set3 << endl;

	cout << endl << "*************************" << endl;
	cout << "TESTING INTERSECTION OPERATOR"   << endl;
	cout << "*************************" << endl;
	set3 = set1 ^ set2;
	cout << "Set1 : \n" << set1 << endl;
	cout << "Set2 : \n" << set2 << endl;
	cout << "INTERSECTION SET1 AND SET2: " << set3 << endl;


	cout << endl << "*************************" << endl;
	cout << "TESTING UNION OPERATOR"   << endl;
	cout << "*************************" << endl;
	set3 = set1 + set2;
	cout << "Set1 :\n" << set1 << endl; 
	cout << "Set2 :\n" << set2 << endl;	
	cout << "UNION SET1 + SET2 :\n" << set3 << endl;

	
	cout << endl << "*************************" << endl;
	cout << "TESTING DIFFERENCE OPERATOR"   << endl;
	cout << "*************************" << endl;
	set3 = set1 - set2;
	cout << "Set1 :\n" << set1 << endl; 
	cout << "Set2 :\n" << set2 << endl;
	cout << "SET1 - SET2 :\n" << set3 << endl;


	cout << endl << "*************************" << endl;
	cout << "TESTING DE MORGAN RULE"   << endl;
	cout << "*************************" << endl;

	cout<< "\nDe Morgan rule for set and set2\n";
	if ((!(set1 + set2)) == (!set1 ^ !set2)) 
		cout << "CHECK DE MORGAN : TRUE" << endl;
	else 
		cout << "CHECK DE MORGAN : FALSE" << endl;	

	DayofYearSet set4, set5, set6, set7, set8, set9, set10, set11;

	set4.add(3,7);
	set4.add(5,11);
	set5.add(30,7);
	set5.add(25,6);
	set5.add(13,10);
	set6.add(12,1);
	set6.add(21,2);
	set7.add(22,1);
	set7.add(30,3);
	set7.add(15,5);
	set7.add(13,2);
	set8.add(11,11);
	set8.add(8,12);
	set8.add(19,9);
	set8.add(27,3);
	set8.add(30,8);
	set9.add(11,8);
	set9.add(18,7);
	set10.add(2,1);
	set11.add(22,6);
	set11.add(26,4);
	cout << "Set4 :\n" << set4 << endl; 
	cout << "Set5 :\n" << set5 << endl;
	if ((!(set4 + set5)) == (!set4 ^ !set5)) 
		cout << "CHECK DE MORGAN : TRUE" << endl;
	else 
		cout << "CHECK DE MORGAN : FALSE" << endl;	
	cout << "*************************\n" << endl;

	cout << "Set6 :\n" << set6<< endl; 
	cout << "Set7 :\n" << set7 << endl;
	if ((!(set6 + set7)) == (!set6 ^ !set7)) 
		cout << "CHECK DE MORGAN : TRUE" << endl;
	else 
		cout << "CHECK DE MORGAN : FALSE" << endl;
	cout << "*************************\n" << endl;	

	cout << "Set8 :\n" << set8 << endl; 
	cout << "Set9 :\n" << set9 << endl;
	if ((!(set8 + set9)) == (!set8 ^ !set9)) 
		cout << "CHECK DE MORGAN : TRUE" << endl;
	else 
		cout << "CHECK DE MORGAN : FALSE" << endl;
	cout << "*************************\n" << endl;	

	cout << "Set10 :\n" << set10 << endl; 
	cout << "Set11 :\n" << set11<< endl;
	if ((!(set10 + set11)) == (!set10 ^ !set11))
		cout << "CHECK DE MORGAN : TRUE" << endl;
	else 
		cout << "CHECK DE MORGAN : FALSE" << endl;		
	cout << "*************************\n" << endl;

	/*TEST COMPLEMENT*/
	cout << endl << "*************************" << endl;
	cout << "TESTING COMPLEMENT OPERATOR"   << endl;
	cout << "*************************" << endl;
	cout << "Set1 :\n" << set1;
	set3 = !set1;
	cout << "\nComplement of set1: ";
	cout << set3;

	return 0;
}

void writeFile(DayofYearSet set1,string fileName){
	ofstream myFile;
    myFile.open(fileName);
	if(myFile.is_open()){
		myFile << set1;
		myFile.close();
		cout << "\n\nWriting to file is successful\n";
	}


}