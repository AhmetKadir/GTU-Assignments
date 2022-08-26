package aka.src;
public class Playground extends Building{
	
	/**
	 * Default constructor
	 */
	public Playground() throws Exception{
		super(3,2,0);
	}

	/**
	 * Constructor
	 * @param l length of the building
	 * @param startingPoint	starting location in the street (horizontal axis)
	 */	
	public Playground(int l, int startingPoint) throws Exception{
		super(l, 2, startingPoint);
	}

	@Override
	public String toString(){
		String str = new String();
		str = "Playground";
		return str;
	}

	@Override
	public boolean equals(Object o){
		return super.equals(o);
	}

	/**
	 * Presented to the user
	 */
	public int focus(){
		return getLength();
	}
}