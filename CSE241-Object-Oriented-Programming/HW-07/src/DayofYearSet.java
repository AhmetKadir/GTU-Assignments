import java.util.ArrayList;

public class DayofYearSet {
	public static class DayofYear{
		public DayofYear(){					//Default constructor
			day = 1;
			month = 1;
		}
		public DayofYear(int dayVal, int monthVal){		//Constructor with day and month input
			if(checkValidDate(dayVal, monthVal) == true){
				day = dayVal;
				month = monthVal;
			}
		}
		void setDay(int dayVal){
			day = dayVal;
		}
		void setMonth(int monthVal){
			month = monthVal;
		}
		final int getDay(){ 
			return day;
		}
		final int getMonth(){ 
			return month;
		}
		
			//private members
		private int day;
		private int month;
	}
	public DayofYearSet(){						//Default constructor
		//dates[] is empty
		size = 0;
		capacity = 50;
		dates = new DayofYear[50];
	} 						
	public DayofYearSet(ArrayList<DayofYear> days){			//Constructor with day of year arrays
		size = 0;
		dates = new DayofYear[(days.size())+50];
		int k=0;
		for(int i =0; i < days.size(); i++){
			if(checkValidDate(days.get(i).day, days.get(i).month)){
				dates[k] = days.get(i);
				size += 1;	
				k+= 1;
				addDayofYearobject();
			}
		}
		capacity = days.size()+50;
	}	

	public String toString(){		
		//Prints the details of the set
		String str = "";	
		for(int i = 0; i<size(); i++){
			String str2 = (dates[i].getDay() + "," + dates[i].getMonth() + "\n");
			str = str + str2;
		}
		str = str + "This set has " + size() + " dates\n";
		return str;
	}	

	public final boolean equals(DayofYearSet set2){			
		/**
		 * Compares two sets .
		 * If they are the same(regardless of the keeping order), returns true.
		 */
		int control = 0; 	//If there is a match, this will be 1, else 0.
		if (size() != set2.size()) return false;
		for(var i =0 ;i<size(); i++){
			control = 0;
			for(var j=0; j<size(); j++){

				if(dates[i].getDay() == set2.dates[j].getDay() &&
					dates[i].getMonth() == set2.dates[j].getMonth()){
						control = 1;
						break;
					}
			}
			if(control == 0) return false;
		}
		return true;
	}
	
	public boolean setHas(int theDay, int theMonth){	
		/**
		 * Returns true if the set already includes the given date.
		 */
		for(var i=0; i<this.size(); i++){
			if(this.dates[i].getDay() == theDay 
				&& this.dates[i].getMonth() == theMonth)
				return true;
		}
		return false;
	}

	public void add(int newDay, int newMonth){ 		//Adds new element to set
		if (setHas(newDay, newMonth) == true) return; 
		//If the date is already in the set, do not add it again.
		
		if(checkValidDate(newDay, newMonth) == false) return;
		//If the date is not valid return;
		
		var newDate = new DayofYear(newDay, newMonth);
		if(size >= capacity){
			capacity = capacity * 2;
			var tempDates = new DayofYear[capacity];
			for(var i =0; i< size(); i++){
				tempDates[i] = dates[i];
			}
			dates = tempDates;
			tempDates = null;
		}
		
		dates[size] = newDate;
		size += 1;
		addDayofYearobject();
	}

	public void remove(int rmDay, int rmMonth) {		//Removes an element
		var control = 0;
		for(var i = 0; i<size(); i++){
			if (dates[i].getDay() == rmDay 
				&& dates[i].getMonth() == rmMonth){
					control = 1;
				}
			if (control == 1 && i != size() - 1){
				dates[i] = dates[i+1];
			}	
		}
		if (control == 1){ 
			size -= 1;
			deleteDayofYearobject();
		}
	}
	
	public final int size() {		//Returns size
		return size;	
	}

	public final int getCapacity(){
		return capacity;
	}

	public DayofYearSet union(DayofYearSet set2){
		/**
		 * Returns the union set of two set.
		 */				
		DayofYearSet set3 = new DayofYearSet();
		for(var i = 0; i<size(); i++){
			set3.add(dates[i].getDay(), dates[i].getMonth());
		}
		int newDay, newMonth;
		/**
		 * No need to check repeats here, because add method already checks that.
		 */
		for(var i=0; i<set2.size(); i++){
			newDay = set2.dates[i].getDay();
			newMonth = set2.dates[i].getMonth();
			set3.add(newDay, newMonth);
		}
		return set3;
	}
	public DayofYearSet difference(DayofYearSet set2){
		/**
		 * Returns the difference set of two set.
		 */		
		DayofYearSet set3 = new DayofYearSet();
		int newDay, newMonth, control;
		for(var i=0; i<size(); i++){
			control = 0;
			for (var j=0; j<set2.size(); j++){
				if(dates[i].getDay() == set2.dates[j].getDay()
					&& dates[i].getMonth() == set2.dates[j].getMonth()){
						control = 1;
						break;
					}
			}
			if(control == 0){	
				newDay = dates[i].getDay();
				newMonth = dates[i].getMonth();
				set3.add(newDay, newMonth);
			}
		}
		return set3;
	}
	public DayofYearSet intersection(DayofYearSet set2){
		/**
		 * Returns the intersection set of two set
		 */		
		DayofYearSet set3 = new DayofYearSet();
		int newDay, newMonth;
		for(var i=0; i<size(); i++){
			for (var j=0; j<set2.size(); j++){
				if(dates[i].getDay() == set2.dates[j].getDay()
					&& dates[i].getMonth() == set2.dates[j].getMonth()){
						newDay = dates[i].getDay();
						newMonth = dates[i].getMonth();
						set3.add(newDay, newMonth);
						break;
					}
			}
		}
		return set3;
	}
	public DayofYearSet complement(){
		/**
		 * Returns the complement set of two set
		 */
		var set3 = new DayofYearSet();
		for(var i=1; i<=12; i++){
			for(var j=1; j<= 31; j++){
				if (setHas(j, i) == false){
					set3.add(j, i);
				}
			}
		}
		return set3;
	}

	public static boolean checkValidDate(int theDay, int theMonth){
		/**
		 * Checks if the date is valid.
		 */
		int DaysinMonths[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (theMonth > 12 || theMonth < 1) return false;
		if (theDay > DaysinMonths[theMonth] || 
			theDay < 1) return false;
		return true;
	}

	public static void addDayofYearobject(){
		totalObject += 1;
	}

	public static void deleteDayofYearobject(){
		totalObject -= 1;
	}

	public static int totalNumberofDayofYears(){
		return totalObject;
	}

	static int totalObject = 0;
	//privates
	private DayofYear[] dates; //data member
	private int capacity;
	private int size;
}