package src.aka;
public class Building{
	
	private int startingPoint;
	private int endingPoint;
	private int height;
	private int length;
	
	/**
	 * Default constructor
	 */
	public Building(){
		length = 3;
		height = 3;
		startingPoint = 0;
		endingPoint = startingPoint + length;
	}

	/**
	 * Constructor
	 * @param len length of the building
	 * @param hei height of the building 
	 * @param start starting location in the street (horizontal axis)
	 */	
	public Building(int len, int hei, int start)throws Exception{
		if(hei < 1 || len < 1 || start < 0)
			throw new Exception("Invalid input");
		height = hei;
		length = len;
		startingPoint = start;
		endingPoint = startingPoint + length;
	}

	public int getLength(){
		return length;
	}

	public int getStartingPoint(){
		return startingPoint;
	}

	public int getEndingPoint(){
		return endingPoint;
	}

	public int getHeight(){
		return height;
	}

	@Override
	public String toString(){
		String str = new String();
		str = String.format("%d %d", length, height);
		return str;
	}

	@Override
	public boolean equals(Object o){
		if(o == this)
			return true;

		if (!(o instanceof Building)) {
			return false;
		}
		
		Building obj = (Building) o;
		return (this.startingPoint == obj.startingPoint
			&& this.endingPoint == obj.endingPoint
			&& this.height == obj.height
			&& this.length == obj.length
			);
	}
}