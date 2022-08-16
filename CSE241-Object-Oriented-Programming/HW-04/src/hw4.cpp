#include <iostream>
#include <vector>
#include <fstream>
#include "hw4.h"

using namespace std;
namespace ns1{

bool checkDaysinMonths(int dayInput, int monthInput){
	int DaysinMonths[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (monthInput > 12 || monthInput < 1) return false;
	if (dayInput > DaysinMonths[monthInput] || 
		dayInput < 1) return false;
	return true;
}

DayofYearSet::DayofYearSet (vector <DayofYearSet::DayofYear> datesVal)
:capacity(50)
{
	used = 0;
	dates = new DayofYear[capacity]; 	/*Dates array created dynamically*/
	int vectorSize = datesVal.size();
	for(int i =0; i< vectorSize; i++){
		add(datesVal[i].getDay(), datesVal[i].getMonth());
	}
}

DayofYearSet::DayofYearSet()
:capacity(50),used(0),dates()
{
	/*Default constructor*/
	dates = new DayofYear[capacity];
}

DayofYearSet::DayofYearSet(const DayofYearSet& set2)
:capacity(set2.getCapacity()), used(set2.getUsed())
{
	/*Copy Constructor*/
	dates = new DayofYear[capacity];
	for (int i = 0; i < used; i++)
		dates[i] = set2.dates[i];
}

DayofYearSet::DayofYear::DayofYear(int dayVal, int monthVal)
:day(dayVal), month(monthVal){
	if (checkDaysinMonths(day, month) == false){
		cerr << "Illegal date !" << endl;
		exit(1);
	}
	totalNumberofDayofYearObjects();
}

DayofYearSet::DayofYear::DayofYear()
:day(1), month(1){
	/*Default constructor for DayofYear Class*/
	totalNumberofDayofYearObjects();
}

DayofYearSet& DayofYearSet::operator =(const DayofYearSet& rSet)
{
	/*If capacities are not same, deletes the array 
	and creates a new one*/
	if (capacity != rSet.capacity)
	{
		delete [] dates;
		dates = new DayofYear[rSet.getCapacity()];
	}
	capacity = rSet.getCapacity();
	used = rSet.getUsed();
	for (auto i = 0; i < used; i++)
		dates[i] = rSet.dates[i];
	return *this;
}

void DayofYearSet::add(int newDay, int newMonth){
	if (checkDaysinMonths(newDay, newMonth) ==  false){
		cerr << "Wrong input for date" << endl;
		return;
	} 
	/*Checks if the set already has the date*/
	for (int i = 0 ; i< size(); i++){
		if (getDates()[i].getDay() == newDay && getDates()[i].getMonth() == newMonth){
			/*cerr << "This set already has " << newDay << " " << newMonth << endl;*/
			return;
		}
	}	
	/*Increases capacity if needed*/
	if(used >= capacity){
		capacity*= 2;
		DayofYear *temp = new DayofYear[capacity];
		for(int i=0 ; i<used ; i++)
			temp[i]  = dates[i];
		delete [] dates;
		dates = temp;
	}
	DayofYearSet::DayofYear newDate(newDay, newMonth);
	dates[used]= newDate;
	used++;
	/*cout << newDay << " and " << newMonth << " added succesfully " << endl;*/
	totalNumberofDayofYearObjects();
}

void DayofYearSet::remove(){
	/*Deletes last element*/
	if(used > 0) used--;
}

int DayofYearSet::size() const{
	return used;
}

ostream& operator <<(ostream& outs,
					const DayofYearSet& date)
{
	if (date.size() == 0) outs << "This set is empty" << endl;
	else
		for(int i =0 ;i < date.size(); i++){
			outs << date.dates[i].getDay() << "/" << date.dates[i].getMonth();
			outs << endl;
	}
	return outs;
}

bool operator ==(const DayofYearSet& set1, const DayofYearSet& set2) {
	int control = 0;
	if (set1.size() == set2.size()){
		for(int i=0 ; i<set1.size() ; i++){
			control = 0;
			for(int j=0 ; j<set1.size() ; j++){
				if (set1.getDates()[i].getDay() == set2.getDates()[j].getDay()
					&& set1.getDates()[i].getMonth() == set2.getDates()[j].getMonth()){
					control = 1;
					break;
				} 		
			}
			if (control == 0) return false;
		}
	}
	return true;
}

bool operator !=(const DayofYearSet& set1,
							const DayofYearSet& set2){
	return !(set1 == set2);
}	

const DayofYearSet operator +(const DayofYearSet& set1,
							  const DayofYearSet& set2) {
	int newDay, newMonth;
	DayofYearSet set3;
	set3 = set1;
	for(int i=0 ; i<set2.size(); i++){
		for(int j=0 ; j<set1.size(); j++){
			newDay = set2.getDates()[i].getDay();
			newMonth = set2.getDates()[i].getMonth();
			set3.add(newDay, newMonth); 
		}
	}
	return set3;
}

const DayofYearSet operator -(const DayofYearSet& set1,
							  const DayofYearSet& set2) {
	DayofYearSet set3;
	int newDay, newMonth, control;
	for (int i=0 ; i<set1.size(); i++){
		for (decltype(i) j = 0 ; j< set2.size() ; j++){
		control = 0;
			if (set1.getDates()[i].getDay() == set2.getDates()[j].getDay()&&
				set1.getDates()[i].getMonth() == set2.getDates()[j].getMonth()){
				control = 1;
				break;
			}
		}
		if (control == 0){
			newDay = set1.getDates()[i].getDay();
			newMonth = set1.getDates()[i].getMonth();
			set3.add(newDay, newMonth);
		}
	}
	return set3;						  
}

const DayofYearSet operator ^(const DayofYearSet& set1,
								const DayofYearSet& set2)
{
	DayofYearSet set3;
	int newDay, newMonth;
	for (int i=0 ; i<set1.size(); i++){
		for (decltype(i) j = 0 ; j< set2.size() ; j++){
			if (set1.getDates()[i].getDay() == set2.getDates()[j].getDay()&&
				set1.getDates()[i].getMonth() == set2.getDates()[j].getMonth()){
				newDay = set1.getDates()[i].getDay();
				newMonth = set1.getDates()[i].getMonth();
				set3.add(newDay, newMonth);
				break;
			}
		}
	}
	return set3;
}

DayofYearSet DayofYearSet::operator !() const{
	DayofYearSet set3;
	int DaysinMonths[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int control;
	for(int i=1 ; i<=12 ; i++){
		for (int j=1 ; j<=DaysinMonths[i]; j++){
			control = 0;
			for (int k=0; k<size(); k++){
				/*cout << j << "  " << getDates()[k].getDay() << endl << endl;
				cout << i << "  "<< getDates()[k].getMonth() << endl << endl;*/
				if (getDates()[k].getDay() == j && getDates()[k].getMonth() == i)
				{	
					control = 1;
					break;
				}
			}
			if (control == 0){
				set3.add(j,i);	
				/*cout << i << " and " << j << " added to set3" << endl << endl;*/
			}
		}
		
	}
	return set3;
}

DayofYearSet::DayofYear& DayofYearSet::operator[](int index){
	return getDates()[index];
}

int DayofYearSet::DayofYear::getDay() const{
	return day;
}

int DayofYearSet::DayofYear::getMonth() const{
	return month;
}

DayofYearSet::DayofYear* DayofYearSet::getDates() const{
	return dates;
}

int DayofYearSet::getCapacity() const{
	return capacity;
}

int DayofYearSet::getUsed() const{
	return used;
}

int DayofYearSet::totalNumberofDayofYearObjects(){
	totalNumberofDates++ ;
	/*cout << "Total number of dates: " <<totalNumberofDates << endl;*/
	return totalNumberofDates;
}

DayofYearSet::~DayofYearSet()
{
delete [] dates;
}

}