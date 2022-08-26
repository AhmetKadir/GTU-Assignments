package aka.src;
import java.util.LinkedList;
import java.util.Scanner;
/**
 * City planning software that will be used for designing a small one street town
 * In this software user can:
 *  -add new buildings to the street
 *  -delete existing buildings on the street
 *  -list the buildings in the street
 *  -display playground ratio in the street
 *  -display the skyline silhoutte of the street
 *   
 */

@SuppressWarnings("resource")
public class Street{

	private LinkedList <Building> front;
	private LinkedList <Building> back;
	private int length;
	
	/**
	 * Default constructor
	 */
	public Street() throws Exception{
		length = 100;
		new Street(100);
	}
	
	/**
	 * Constructor
	 * @param l length of the street
	 */
	public Street(int l) throws Exception{
		if(l<5){
			throw new Exception("Length of the street can not be smaller than 5");
		}
		length = l;
		front = new LinkedList<Building>();
		back = new LinkedList<Building>();
	}

	/**
	 * add method adds a new building to the street
	 * First it checks the location, 
	 * if it is out of bounds of the street it does not add the building
	 * Then it checks if the location is empty
	 * for the side parameter "Front" or "front" and "Back" or "back" is acceptable
	 * 
	 * @param bui building 
	 * @param side side, front or back (String)
	 */
	public void add(Building bui, String side) throws Exception{
		if (bui.getStartingPoint() + bui.getLength() > length){
			throw new Exception("Building is out of bounds of the street");
		}
		if(isSuitable(bui.getStartingPoint(), bui.getLength(), side)
												 == false) 
			throw new Exception("There is no available spaces for the building");
	
		if (side == "front" || side == "Front"){
			front.add(bui);
		}
		else if (side == "back" || side == "Back") {
			back.add(bui);
		}
		else throw new Exception("Side input is wrong");
	}

	/**
	 * Deletes a building on the street.
	 * If two building are same on the street, 
	 * (Everything is same except the side of the building(front or back))
	 * it deletes both
	 * @param bui building
	 */	
	public void delete(Building bui){
		front.remove(bui);
		back.remove(bui);
	}

	/**
	 * Another delete method.
	 * Takes starting point and the side of the building on the street,
	 * then deletes it.
	 * @param startingPoint starting location of the building
	 * @param side side of the building on the street (front or back) (String)
	 */	
	public void delete(int startingPoint, String side) throws Exception{
		if(startingPoint < 0 || startingPoint > length)
			throw new Exception("starting point is out of bounds.");

		if(side == "front" || side == "Front"){
			for(int i = 0; i<front.size(); i++){
				if(front.get(i).getStartingPoint() == startingPoint)						
					front.remove(i);
			}
		}	

		else if (side == "back" || side == "Back"){
			for(int i = 0; i < back.size(); i++){
				if(back.get(i).getStartingPoint() == startingPoint)
					back.remove(i);
			}
		}

		else throw new Exception("Side input is wrong");
	}

	private boolean isSuitable(int start, int buildLength, String side) {		
		if (side == "Front" || side == "front"){
			for(int i = 0; i < front.size(); i++){
				if (front.get(i).getStartingPoint() == start)
					return false;
				else if (front.get(i).getStartingPoint() > start	
						&& start + buildLength > front.get(i).getStartingPoint())
					return false;
				else {
					if(front.get(i).getStartingPoint() <  start 
						&& front.get(i).getStartingPoint() + front.get(i).getLength() > start)
						return false; 
				}
			}
		}
		else if (side == "Back" || side == "back"){
			for(int i = 0; i < back.size(); i++){
				if (back.get(i).getStartingPoint() == start){
					return false;
				}
				else if (back.get(i).getStartingPoint() > start	
						&& start + buildLength > back.get(i).getStartingPoint()){
							System.out.println(start + " + " + buildLength 
											+ " > " + back.get(i).getStartingPoint());
							return false;

				}
				else {
					if(back.get(i).getStartingPoint() < start
						&& back.get(i).getStartingPoint() + back.get(i).getLength() > start)
						return false; 
				}
			}
		}
		return true;
	}

	/**
	 * Prints buildings as a list.
	 * First, it prints the buildings on the front side of the street,
	 * then prints the buildings on the back side of the street.
	 */
	public void listBuildings(){
		//will be updated
		int counter = 0; 
		System.out.println("\nBuildings in the street:");
		System.out.println("\nFront : ");
		for(int i = 0; i < front.size(); i++){
			if (front.get(i) != null){
				counter++;
				System.out.println(counter+ "-" + front.get(i).toString());
			}
		}
		System.out.println("\nBack : ");
		for(int i = 0; i < back.size(); i++){
			if (back.get(i) != null){
				counter++;
				System.out.println(counter + "-" + back.get(i).toString());
			}
		}
		System.out.println("-----------------------------");
	}

	/**
	 * 
	 * @return number of playgrounds in the street
	 */	
	public int numberOfPlaygrounds(){
		int counter = 0;
		for(int i = 0; i < front.size(); i++)
			if(front.get(i) instanceof Playground)
				counter++;
		
		for(int i = 0; i < back.size(); i++){
			if(back.get(i) instanceof Playground)
				counter++;
		}
		return counter;
	}
	
	/**
	 * calculates the ratio of length of playgrounds on the street 
	 * @return a double between 0-1 
	 * (0 means there is no playground on the street)
	 * (1 means the street is full of playgrounds)
	 */
	public double playgroundRatio(){
		int totalPlaygroundLength = 0;
		for(int i = 0; i < front.size(); i++){
			if(front.get(i) instanceof Playground)
				totalPlaygroundLength += front.get(i).getLength(); 
		}

		for(int i = 0; i < back.size(); i++){
			if(back.get(i) instanceof Playground)
				totalPlaygroundLength += back.get(i).getLength();
		}

		return (double)totalPlaygroundLength / length;
	}

	/**
	 * Calculates empty areas on the front side of the street
	 * @return int, total remaining length of lands on the front side of the street 
	 */	
	public int totalRemainingLandsLengthAtFront(){
		int counter = 0;

		for(int j = 0; j< front.size(); j++){
			counter += front.get(j).getLength();
		}
		return length - counter;
	}

	/**
	 * Calculates empty areas on the back side of the street
	 * @return int, total remaining length of lands on the back side of the street 
	 */	
	public int totalRemainingLandsLengthAtBack(){
		int counter = 0;

		for(int j = 0; j< back.size(); j++){
			counter += back.get(j).getLength();
		}

		return length - counter;
	}

	/**
	 * 
	 * @return int total length of houses
	 */
	public int totalLengthHouse(){
		int lengthCounter = 0;
		for(int i = 0; i < front.size(); i++){
			if(front.get(i) instanceof House)
				lengthCounter += front.get(i).getLength();
		}

		for(int i = 0; i < back.size(); i++){
			if(back.get(i) instanceof House)
				lengthCounter += back.get(i).getLength();
		}

		return lengthCounter;
	}

	/**
	 * 
	 * @return int total length of markets
	 */

	public int totalLengthMarket(){
		int lengthCounter = 0;
		for(int i = 0; i < front.size(); i++){
			if(front.get(i) instanceof Market)
				lengthCounter += front.get(i).getLength();
		}

		for(int i = 0; i < back.size(); i++){
			if(back.get(i) instanceof Market)
				lengthCounter += back.get(i).getLength();
		}

		return lengthCounter;
	}

	/**
	 * 
	 * @return int total length of offices
	 */
	public int totalLengthOffice(){
		int lengthCounter = 0;
		for(int i = 0; i < front.size(); i++){
			if(front.get(i) instanceof Office)
				lengthCounter += front.get(i).getLength();
		}

		for(int i = 0; i < back.size(); i++){
			if(back.get(i) instanceof Office)
				lengthCounter += back.get(i).getLength();
		}

		return lengthCounter;
	}

	/**
	 * displays the skyline silhouette of the street
	 */

	public void displaySkylineSilhouette(){
		boolean fullFront = false;
		boolean fullBack = false;
		boolean[] fullVertical = new boolean[length];
		int buildingCount;
		for(int i = maxHeight() ; i >= 0 ; i--){
			for(int j = 0; j < length; j++){
				if(i == 0){
					//Bottom
					System.out.print("x");
				}
				//if the position is full vertically, do not print anything
				else if(fullVertical[j] == false){
					fullFront = false;
					//front side
					buildingCount = 0;
					for(int k = 0; k < front.size(); k++){
						//left side of the building
						if(front.get(k).getStartingPoint() == j
							&& front.get(k).getHeight() > i){
							buildingCount++;
						}
						//right side of the building
						else if(front.get(k).getEndingPoint() == j
								&& front.get(k).getHeight() > i){
							buildingCount++;
						}
						//roof of the building
						else if(front.get(k).getStartingPoint() < j
								&& front.get(k).getEndingPoint() > j
								&& front.get(k).getHeight() == i){
									System.out.print("-");
									fullFront = true;
									fullVertical[j] = true;
									break;
								}
					}
					//if there are 2 building in the same position, dont print the wall.
					if(buildingCount == 1){
						System.out.print("|");
						fullFront = true;
					}
					else if(buildingCount == 2){
						System.out.print(" ");
						fullFront = true;
					}

					//back side
					fullBack = false;
					buildingCount = 0;
					for(int k = 0; k < back.size() ; k++){
						//left side of the building
						if(back.get(k).getStartingPoint() == j
							&& back.get(k).getHeight() > i){
							buildingCount++;
						}
						//right side of the building
						else if (back.get(k).getEndingPoint() == j
									&&back.get(k).getHeight() > i){
							buildingCount++;
						}
						//roof of the building
						else if(back.get(k).getStartingPoint() < j
							&& back.get(k).getEndingPoint() > j
							&& back.get(k).getHeight() == i){
								fullBack = true;
								fullVertical[j] = true;
								if(!fullFront)
									System.out.print("-");
								break;
							}
					}
					//if there are 2 building in the same position, dont print the wall.
					if(buildingCount == 1 && !fullFront){
						System.out.print("|");
						fullBack = true;
					}
					else if(buildingCount == 2 && !fullFront){
						System.out.print(" ");
						fullBack = true;
					}
					//If there is no building in the position, print whitespace
					if (!fullFront && !fullBack)
						System.out.print(" ");

				}
				else
					System.out.print(" ");
			}
			System.out.print("\n");
		}
	}
	/**
	 * Calculates the max height on the street
	 * @return
	 */
	private int maxHeight(){
		int maxHeight = 0;
		for(int i = 0; i < front.size(); i++){
			if(front.get(i).getHeight() > maxHeight)	
				maxHeight = front.get(i).getHeight();
		}

		for(int i = 0; i < back.size(); i++){
			if(back.get(i).getHeight() >  maxHeight)
				maxHeight = back.get(i).getHeight();
		}
		return maxHeight;
	}

	/**
	 * menu for an interactive system
	 */
	public void menu(){
		System.out.println("-----------------------------------------");
		System.out.println("Welcome to the City Planning Software");
		System.out.println("-----------------------------------------");
		boolean running = true;
		Scanner sc = new Scanner(System.in);
		while(running){
			System.out.println("\n\nPlease choose the mode you want to use");
			System.out.println("1-Editing mode");
			System.out.println("2-Viewing mode");
			System.out.printf("\n0- Exit\n\n");
			System.out.printf("Your choice: ");
			int choice = sc.nextInt();
			switch(choice){
				case 1:
					editingMode();
					break;
				case 2:
					viewingMode();
					break;
				case 0:
					running = false;
					break;
				default:
					System.out.println("Wrong Input !!");
			}
		}
		sc.close();
	}

	private void editingMode(){
		boolean runningEdit = true;
		while(runningEdit){
			Scanner sc = new Scanner(System.in);
			System.out.println("\n\n1-add");
			System.out.println("2-delete");
			System.out.printf("\n0-Back\n\n");
			System.out.printf("Your choice: ");
			int option = sc.nextInt();
			switch(option){
				case 1: 
					userAdd();
					break;
				case 2:
					userDelete();
					break;
				case 0:
					runningEdit = false;
					break;
				default:
					System.out.println("Wrong Input !!");
			}
		}
	}

	private void viewingMode(){
		boolean runningView = true;
		Scanner sc = new Scanner(System.in);
		int option;
		while(runningView){
			System.out.println("\n\n1 - Display the remaining length of lands " 
															+"on the street");
			System.out.println("2 - Display the list of building "
															+"on the street");
			System.out.println("3 - Display the number and ratio of "
									+"lenth of playgrounds in the street");
			System.out.println("4 - Total length of street occupied by "
													+"any building");
			System.out.println("5 - Display the silhouette of the street");
			System.out.printf("\n0 - Back\n\n");
			System.out.printf("Your choice: ");
			option = sc.nextInt();
			switch(option){
				case 1:
					System.out.println("Total remaining length of lands");
					System.out.println("At Front: "+ totalRemainingLandsLengthAtFront());
					System.out.println("At Back: "+ totalRemainingLandsLengthAtBack());
					break;
				case 2:
					listBuildings();
					break;
				case 3:
					System.out.println("There are " +numberOfPlaygrounds()
											+ " playgrounds on the street");
					System.out.println("Ratio is " + playgroundRatio());
					break;
				case 4:
					System.out.println("Total length of the markets: "
											+ totalLengthMarket());
					System.out.println("Total length of the houses: "
											+ totalLengthHouse());
					System.out.println("Total length of the offices: "
											+ totalLengthOffice());
					break;
				case 5:
					displaySkylineSilhouette();
					break;
				case 0:
					runningView = false;
					break;
				default: 
					System.out.println("Wrong input");
			}
		}
	}	

	private void userAdd(){
		Scanner sc= new Scanner(System.in);
		boolean runningUserAdd = true;
		int option;
		int inputLength;
		int inputHeight;
		int inputStart;
		int inputRooms;
		String inputColor;
		String inputOwner;
		String inputJob;
		int inputOpenT;
		int inputCloseT;
		String inputSide;

		while(runningUserAdd){
			System.out.println("\n\nChoose the building type you want to add");
			System.out.println("1-House");
			System.out.println("2-Office");
			System.out.println("3-Playground");
			System.out.println("4-Market");
			System.out.printf("\n0-Back\n\n");
			System.out.printf("Your choice: ");
			option = sc.nextInt();
			switch(option){
				case 1:
					System.out.println("Enter the required informations about "
																+"the house.");
					System.out.printf("length: ");
					inputLength = sc.nextInt();
					System.out.printf("\nheight: ");
					inputHeight = sc.nextInt();
					System.out.printf("\nstarting point: ");
					inputStart = sc.nextInt();
					System.out.printf("\nrooms: ");
					inputRooms = sc.nextInt();
					sc.nextLine();
					System.out.printf("\ncolor: ");
					inputColor = sc.nextLine();
					System.out.printf("\nowner: ");
					inputOwner = sc.nextLine();
					System.out.printf("\nFront(1) or back(2): ");
					switch(sc.nextInt()){
						case 1:
							inputSide = "Front";
							break;
						case 2:
							inputSide = "Back";
							break;
						default:
							inputSide = "Front";
					}
					try{
					add(new House(inputLength, inputHeight, inputStart,
					 	inputRooms, inputColor, inputOwner), inputSide);
					} catch (Exception e){
						System.out.println(e);
					}

					break;
				case 2:
					System.out.println("Enter the required informations about "
																+"the office.");
					System.out.printf("length: ");
					inputLength = sc.nextInt();
					System.out.printf("\nheight: ");
					inputHeight = sc.nextInt();
					System.out.printf("\nstarting point: ");
					inputStart = sc.nextInt();
					sc.nextLine();
					System.out.printf("\njob: ");
					inputJob = sc.nextLine();
					System.out.printf("\nowner: ");
					inputOwner = sc.nextLine();
					System.out.printf("\nFront(1) or back(2): ");
					switch(sc.nextInt()){
						case 1:
							inputSide = "Front";
							break;
						case 2:
							inputSide = "Back";
							break;
						default:
							inputSide = "Front";
					}
					try{
					add(new Office(inputLength, inputHeight, inputStart
											, inputJob, inputOwner), inputSide);
					} catch(Exception e) {
						System.out.println(e);
					}
					break;
				case 3:
					System.out.println("Enter the required informations about "
															+"the playground.");
					System.out.printf("length: ");
					inputLength = sc.nextInt();
					System.out.printf("\nstarting point: ");
					inputStart = sc.nextInt();
					System.out.printf("\nFront(1) or back(2): ");
					switch(sc.nextInt()){
						case 1:
							inputSide = "Front";
							break;
						case 2:
							inputSide = "Back";
							break;
						default:
							inputSide = "Front";
					}
					try{
					add(new Playground(inputLength, inputStart), inputSide);
					} catch(Exception e) {
						System.out.println(e);
					}
					break;
				case 4:
					System.out.println("Enter the required informations about "
																+"the market.");
					System.out.printf("length: ");
					inputLength = sc.nextInt();
					System.out.printf("\nheight: ");
					inputHeight = sc.nextInt();
					System.out.printf("\nstarting point: ");
					inputStart = sc.nextInt();
					sc.nextLine();
					System.out.printf("\nowner: ");
					inputOwner = sc.nextLine();
					System.out.printf("\nopening time: ");
					inputOpenT = sc.nextInt();	
					System.out.printf("\nclosing time: ");
					inputCloseT = sc.nextInt();				
					System.out.printf("\nFront(1) or back(2): ");
					switch(sc.nextInt()){
						case 1:
							inputSide = "Front";
							break;
						case 2:
							inputSide = "Back";
							break;
						default:
							inputSide = "Front";
					}
					try{
					add(new Market(inputLength, inputHeight, inputStart
							, inputOwner, inputOpenT, inputCloseT), inputSide);
					} catch(Exception e){
						System.out.println(e);
					}
					break;
				case 0:
					runningUserAdd = false;
					break;
				default:
					System.out.println("Wrong Input !!");			
			}
			
		}
	}

	/**
	 * Delete option for menu
	 */	
	private void userDelete(){
		int option;
		listBuildings();
		System.out.println("Pick a building to delete");
		System.out.print("Your choice: ");
		Scanner sc = new Scanner(System.in);
		option = sc.nextInt();
		if(option > front.size())
			delete(back.get(option - front.size() - 1));
		else	
			delete(front.get(option - 1));
	}

	/**
	 * Overriden toString method,
	 * returns the list of the buildings in the street
	 */
	@Override
	public String toString(){
		String str = new String();
		str = "Front : ";
		for(int i = 0; i < front.size(); i++){
			if (front.get(i) != null){
				str= str + "\n" + front.get(i).toString();
			}
		}
		str = str + " \nBack : ";
		for(int i = 0; i < back.size(); i++){
			if (back.get(i) != null){
				str = str + "\n" + back.get(i).toString();
			}
		}
		return str;
	}

	/**
	 * Overriden equals method,
	 * returns true if the object o is the same as this.
	 */
	@Override
	public boolean equals(Object o){
		if(o == this)	
			return true;
		
		Street otherS = (Street) o;
		
		return(	   this.front.size() == otherS.front.size()
				&& this.back.size() == otherS.back.size()
				&& this.front == otherS.front
				&& this.back == otherS.back
				&& this.length == otherS.length
				);
	}
}