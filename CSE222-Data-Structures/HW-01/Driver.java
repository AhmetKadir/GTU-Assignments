import java.util.Scanner;

import src.aka.*;

@SuppressWarnings("unused")
public class Driver{
	public static void main(String[] args){
		try{
		System.out.println("\n\n");
		System.out.println("*********************************************");
		System.out.println("\nTESTING CITY PLANNING SOFTWARE\n");
		System.out.println("*********************************************\n");


		Street myStreet = new Street(60);
		House house1 = new House(8, 10, 6, 10, "Blue", "Hans");
		Market market1 = new Market(12, 7, 45, "Kahn", 10, 19);
		House house2 = new House(10, 15, 20, 4, "Black", "Osman");
		House house3 = new House(8, 10, 6, 10, "Blue", "Hans");

		System.out.println("\nChecking if house1 and house2 are equal: ");
		System.out.println(house1.equals(house2));

		System.out.println("\nChecking if house1 and house1 are equal");
		System.out.println(house1.equals(house1));

		System.out.println("\nChecking if house1 and house3 are equal");
		System.out.println(house1.equals(house3));
	
		System.out.println("\n\nAdding a house at the front side of the street");
		myStreet.add(house1, "Front");
		System.out.println("\nAdding a market at the back side of the street");
		myStreet.add(market1, "Back");
		System.out.println("\nAdding a playground at the front side of the street.");
		myStreet.add(new Playground(7, 14), "Front");
		System.out.println("\nAdding an office at the front side of the street.");
		myStreet.add(new Office(10, 15, 25, "Software", "Aka Software"), "Front");
		System.out.println("\nAdding a house at the back side of the street");
		myStreet.add(new House(8, 10, 30, 5, "Black", "John"), "Back");
		
		myStreet.listBuildings();

		myStreet.displaySkylineSilhouette();

		System.out.println("\n\nDeleting the playground building");

		myStreet.delete(14, "Front");

		myStreet.listBuildings();

		myStreet.displaySkylineSilhouette();

		System.out.println("\nTotal remaining length of lands");
		System.out.println("At Front: "+ myStreet.totalRemainingLandsLengthAtFront());
		System.out.println("At Back: "+ myStreet.totalRemainingLandsLengthAtBack());

		myStreet.listBuildings();

		System.out.println("There are " + myStreet.numberOfPlaygrounds()
								+ " playgrounds on the street");
		System.out.println("Ratio is " + myStreet.playgroundRatio());

		System.out.println("Total length of the markets: "
								+ myStreet.totalLengthMarket());
		System.out.println("Total length of the houses: "
								+ myStreet.totalLengthHouse());
		System.out.println("Total length of the offices: "
								+ myStreet.totalLengthOffice());
		System.out.println("\n\n");
		myStreet.displaySkylineSilhouette();
		} catch (Exception e){
		System.out.println(e);
		}	

		//Exceptions
		System.out.println("\n\n-----------------------------");
		System.out.println("TRYING EXCEPTIONS");
		System.out.println("-----------------------------\n");

		try{
			System.out.println("\nTrying to create a street with negative length");
			var myStreet2 = new Street(-1);
		}catch (Exception e){
			System.out.println(e);
		}

		try{
			System.out.println("\nTrying to add a building which is longer than the street");
			var myStreet3 = new Street(10);
			myStreet3.add(new House(15, 20, 5, 3, "Blue", "Hasan"), "Front");
		} catch(Exception e){
			System.out.println(e);
		}

		try{
			System.out.println("\nTrying to delete a building with wrong input");
			var myStreet4 = new Street(50);
			myStreet4.add(new Office(20, 15, 10, "Coffee shop", "Osman"), "Front");
			myStreet4.delete(60, "Back");
		} catch(Exception e){
			System.out.println(e);
		}

		try{
			System.out.println("\nTrying to create a building with negative length");
			var Market = new Market(-5, 15, 5, "Johnson", 9, 12);
		} catch (Exception e){
			System.out.println(e);
		}

		try{
			System.out.println("\nTrying to create a market with wrong opening hour");
			var Market = new Market(15, 15, 5, "Johnson", 25, 26);
		} catch (Exception e){
			System.out.println(e);
		}

		//Menu part
		try{
			System.out.print("\n\nEnter the length of the street: ");
			Scanner sc = new Scanner(System.in);
			int len = sc.nextInt();	
			var yourStreet = new Street(len);
			yourStreet.menu();
			sc.close();
		} catch(Exception e){
			System.out.println(e);
		}
		
	}
}