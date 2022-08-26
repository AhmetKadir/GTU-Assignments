package src.aka;
public class House extends Building{
	
	private int rooms;
	private String color;
	private String owner;
	
	/**
	 * Default constructor
	 */
	public House(){
		super();
		rooms = 1;
		color = "Black";
		owner = "Sam";
	}

	/**
	 * Constructor
	 * @param len length of the building
	 * @param hei heigth of the building
	 * @param startingPoint starting location in the street (horizontal axis)
	 * @param roomsInput number of rooms in the house
	 * @param colorInput color of house
	 * @param ownedBy owner of the building (person name)
	 */	
	public House(int len, int hei, int startingPoint, int roomsInput,
							 String colorInput, String ownedBy)throws Exception{
		super(len, hei, startingPoint);
		if(rooms < 0)	
			throw new Exception("Number of rooms can not be negative.");
		rooms = roomsInput;
		color = colorInput;
		owner = ownedBy;
	}

	/**
	 * presented to the user
	 * @return owner owner of the building
	 */	
	public String focus(){
		return owner;
	}

	@Override
	public String toString(){
		String str = new String();
		str = "House";
		return str;
	}

	@Override
	public boolean equals(Object o){
		if (super.equals(o) == false) return false;
		House otherH = (House) o;
		return(this.rooms == otherH.rooms
				&& this.color == otherH.color
				&& this.owner == otherH.owner);
	}
}