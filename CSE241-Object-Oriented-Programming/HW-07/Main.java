/**
 * Driver program to test DayofYearSet class methods.
 */

import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
	public static void main(String[] args) {
		System.out.println("\n\nPROGRAM TO TEST DayofYearSet CLASS METHODS\n\n");
		test1();
		System.out.println("\n");
		test2();
		testInvalidInputs();
		writeToFile();
	}
	public static void test1(){
		var day1 = new DayofYearSet.DayofYear(3,5);
		var day2 = new DayofYearSet.DayofYear(6,10);
		var day3 = new DayofYearSet.DayofYear(25,10);
		var myDays = new ArrayList<DayofYearSet.DayofYear>();
		myDays.add(day1);
		myDays.add(day2);
		myDays.add(day3);

		DayofYearSet setA;
		setA = new DayofYearSet(myDays);
		System.out.println("(3,5) (6,10) and (25,10) added to setA");
		System.out.println("size of setA is " + setA.size());
		System.out.println("\nset A");
		System.out.println(setA.toString());

		System.out.print("Total number of alive DayofYear objects: ");
		System.out.println(DayofYearSet.totalNumberofDayofYears());

		//Using default constructor
		DayofYearSet setB = new DayofYearSet();		
		setB = setA.complement();
		System.out.println("\nset B is complement of set A\nset B");
		System.out.println(setB.toString());

		var setC = new DayofYearSet();
		setC.add(11,11);
		setC.add(6,10);
		setC.add(19,3);
		setC.add(13,1);
		System.out.println("setC\n" + setC.toString());

		System.out.print("Total number of alive DayofYear objects: ");
		System.out.println(DayofYearSet.totalNumberofDayofYears());

		System.out.println("\nCheck if setA and SetC are equal with using the method equal()");
		if(setA.equals(setC)) System.out.println("SetA equals setC.");
		else 			 System.out.println("SetA and SetC are not equal.");
		
		System.out.println("\nIntersection set of setA and setC is");
		var intersectSet = new DayofYearSet();
		intersectSet = setA.intersection(setC);
		System.out.println(intersectSet.toString());

		System.out.println("The difference of setA from setC is");
		var differenceSet1 = new DayofYearSet();
		differenceSet1 = setA.difference(setC);
		System.out.println(differenceSet1.toString());

		System.out.println("The difference of setC from setA is");
		var differenceSet2 = new DayofYearSet();
		differenceSet2 = setC.difference(setA);
		System.out.println(differenceSet2.toString());

		System.out.println("Union set of setA and setC is");
		var unionSet = new DayofYearSet();
		unionSet = setA.union(setC);
		System.out.println(unionSet.toString());

		System.out.println("set A");
		System.out.println(setA.toString());

		setA.remove(6,10);
		System.out.println("After removing (6,10)");

		System.out.println("\nset A");
		System.out.println(setA.toString());
		System.out.println("Size of set A is " + setA.size());

		setA.union(setC);

		System.out.print("Total number of alive DayofYear objects: ");
		System.out.println(DayofYearSet.totalNumberofDayofYears());

		/**
		 * Test de morgan rule
		 */

		/*System.out.println("\nLeftSide is: " + (setA.union(setC).complement()).toString());
		System.out.println("\nRightSide is: " + (setA.complement().intersection(setC.complement())).toString());*/

		if((setA.union(setC).complement()).equals((setA.complement().intersection(setC.complement()))))
		 	System.out.println("\nDe morgan rule works fine.");
		else 
			System.out.println("\nSomething is wrong with De Morgan rule !");

	}
	public static void test2(){
		/**
		 * Similar to the test1.
		 * There are sets equal to each other end of the method.
		 * No de morgan(de morgan test is in test1)
		 * No test for complement method(There is in test1, though)
		 * No test for static totalaliveobjectnumber method(There is in test1, though)
		 */
		System.out.println("Test2 method\n (Similar things to test1)\n");
		
		var day1 = new DayofYearSet.DayofYear(11,12);
		var day2 = new DayofYearSet.DayofYear(3,3);
		var day3 = new DayofYearSet.DayofYear(1,10);
		var day4 = new DayofYearSet.DayofYear(1,1);
		var day5 = new DayofYearSet.DayofYear(31,5);
		var myDays = new ArrayList<DayofYearSet.DayofYear>();
		myDays.add(day1);
		myDays.add(day2);
		myDays.add(day3);
		myDays.add(day4);
		myDays.add(day5);

		DayofYearSet setX;
		setX = new DayofYearSet(myDays);
		System.out.println("(11,12), (3,3), (1,10), (1, 1), (31, 5) added to setX");
		System.out.println("size of setX is " + setX.size());
		System.out.println("\nset X");
		System.out.println(setX.toString());

		var setZ = new DayofYearSet();
		setZ.add(3,3);
		setZ.add(31,5);
		setZ.add(12,12);
		setZ.add(29,10);
		setZ.add(15,11);
		System.out.println("setZ\n" + setZ.toString());

		System.out.println("Check if setX and SetZ are equal with using the method equal()");
		if(setX.equals(setZ)) System.out.println("setX equals setZ.");
		else 			 System.out.println("setX and setZ are not equal.");
		
		System.out.println("\nIntersection set of setX and setZ is");
		var intersectSet = new DayofYearSet();
		intersectSet = setX.intersection(setZ);
		System.out.println(intersectSet.toString());

		System.out.println("The difference of setX from setZ is");
		var differenceSet1 = new DayofYearSet();
		differenceSet1 = setX.difference(setZ);
		System.out.println(differenceSet1.toString());

		System.out.println("The difference of setZ from setX is");
		var differenceSet2 = new DayofYearSet();
		differenceSet2 = setZ.difference(setX);
		System.out.println(differenceSet2.toString());

		System.out.println("Union set of setX and setZ is");
		var unionSet = new DayofYearSet();
		unionSet = setX.union(setZ);
		System.out.println(unionSet.toString());

		System.out.println("set A");
		System.out.println(setX.toString());

		setX.remove(1,10);
		System.out.println("After removing (1,10)");

		System.out.println("\nset A");
		System.out.println(setX.toString());
		System.out.println("Size of set A is " + setX.size());

		var setM = new DayofYearSet();
		setM.add(1,2);
		setM.add(1,3);
		var setK = new DayofYearSet();
		setK.add(1,2);
		setK.add(1,3);
		System.out.println("\nsetK\n" + setK.toString());
		System.out.println("setM\n" + setM.toString());

		System.out.println("Check if setK and SetM are equal with using the method equal()");
		if(setK.equals(setM)) System.out.println("setK equals setM.");
		else 			 System.out.println("setM and setK are not equal.");

	}
	public static void testInvalidInputs(){
		/**
		 * Test different invalid inputs.
		 */
		System.out.println("Testing Invalid Inputs\n");
		
		var day1 = new DayofYearSet.DayofYear(30,50);	//invalid
		var day2 = new DayofYearSet.DayofYear(31,30);	//invalid 
		var day3 = new DayofYearSet.DayofYear(30,2) ;	//invalid
		var day4 = new DayofYearSet.DayofYear(32,1) ;	//invalid
		var day5 = new DayofYearSet.DayofYear(31,11);	//invalid
		var day6 = new DayofYearSet.DayofYear(0,8)  ; 	//invalid
		var day7 = new DayofYearSet.DayofYear(8,0)  ; 	//invalid		
		
		var day8 = new DayofYearSet.DayofYear(28,2); 	
		//valid, only this will be added to the set
		
		var myDays = new ArrayList<DayofYearSet.DayofYear>();
		myDays.add(day1);
		myDays.add(day2);
		myDays.add(day3);
		myDays.add(day4);
		myDays.add(day5);
		myDays.add(day6);
		myDays.add(day7);
		myDays.add(day8);

		System.out.println("After trying to add: (30,50)(31,30)(30,2)"
		+ "(32,1)"
		+ "(31,11)"
		+ "(0,8)" 
		+ "(8,0)"
		+ "(28,2)");

		DayofYearSet set1;
		set1 = new DayofYearSet(myDays);
		System.out.println("size of set1 is " + set1.size());
		
		System.out.println("set1\n" + set1.toString());
		/**
		 * This will print (28,2), since it is the only valid date. 
		 */
	}
	public static void writeToFile(){
		var day1 = new DayofYearSet.DayofYear(3,5);
		var day2 = new DayofYearSet.DayofYear(6,10);
		var day3 = new DayofYearSet.DayofYear(25,10);
		var myDays = new ArrayList<DayofYearSet.DayofYear>();
		myDays.add(day1);
		myDays.add(day2);
		myDays.add(day3);
		DayofYearSet setA;
		setA = new DayofYearSet(myDays);

		var setC = new DayofYearSet();
		setC.add(11,11);
		setC.add(6,10);
		setC.add(19,3);
		setC.add(13,1);

		var unionSet = new DayofYearSet();
		unionSet = setA.union(setC);
		/**
		 * These sets are same with the sets in test1 method.
		 */
		try {
			var writeSets = new FileWriter("setExs.txt");
			
			writeSets.write(setA.toString() + "\n");
			writeSets.write(setC.toString() + "\n");
			writeSets.write(unionSet.toString()+ "\n");
			writeSets.close();
			System.out.println("\nWriting to the file is successful");
		} catch (IOException exc) {
			System.out.println("ERROR");
			exc.printStackTrace();
		}
	}
		  
}
