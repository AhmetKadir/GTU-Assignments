using namespace std;

namespace ns1{

class DayofYearSet{
public:
	class DayofYear{
	public:
		DayofYear(int dayVal, int monthVal);
		DayofYear();
		int getDay() const;
		int getMonth() const;
	private:
		int day;
		int month;
	};
	DayofYearSet(vector <DayofYear> datesVal);
	
	DayofYearSet(); /*Default constructor*/
	
	DayofYearSet(const DayofYearSet& Set2); /*Copy Constructor*/

	DayofYearSet& operator =(const DayofYearSet& rSet);
	
	void add(int newDay, int newMonth); /*Adds new element to set*/
	void remove(); 						/*Removes last element*/

	int size() const;					/*Returns size*/

	friend bool checkDaysinMonths(int day, int month);
	/*Checks the date,
	Month value should be between 1-12 
	Day value should be appropriate by its month
	Returns true if the values are appropriate*/

	friend ostream& operator <<(ostream& outs,
								const DayofYearSet& date);							
	friend bool operator ==(const DayofYearSet& set1,
							const DayofYearSet& set2) ;
	friend bool operator !=(const DayofYearSet& set1,
							const DayofYearSet& set2) ;					
	friend const DayofYearSet operator +(const DayofYearSet& set1,
										const DayofYearSet& set2);	
		/*Union Operator*/

	friend const DayofYearSet operator -(const DayofYearSet& set1,
										const DayofYearSet& set2);
		/*Difference operator*/

	friend const DayofYearSet operator ^(const DayofYearSet& set1,
										const DayofYearSet& set2);
		/*Intersection Operator*/

	DayofYearSet operator !() const;
		/*Complement operator
		Returns a set includes the days
		which our set does not include in 365 days*/

	DayofYear& operator[](int index);

	DayofYear* getDates() const;
		/*returns dates array*/

	int getCapacity() const;

	int getUsed() const;

	static int totalNumberofDayofYearObjects();
		/*increases totalNumberofDates value by one.
		And returns totalNumberofDates value.*/

	~DayofYearSet();
	/*Destructor*/
	
private:
	int capacity;
	int used;
	DayofYear* dates;
	static int totalNumberofDates;
};

}