package src.aka;
public class Market extends Building{
	
	private String owner;
	private int openingTime;
	private int closingTime;
	
	/**
	 * Default constructor
	 */
	public Market(){
		super();
		owner = "Hasan";
		openingTime = 9;
		closingTime = 20;
	}

	/**
	 * Constructor
	 * @param len length of the building
	 * @param hei height of the building
	 * @param startingPoint	starting location in the street (horizontal axis)
	 * @param ownedBy	owner of the building (person name)
	 * @param openT		opening time of the market (hour)
	 * @param closeT	closing time of the market (hour)
	 */
	public Market(int len, int hei, int startingPoint, String ownedBy, int openT,
									 int closeT)throws Exception{
		super(len, hei, startingPoint);
		owner = ownedBy;
		if(openT < 0 || openT > 23 || closeT < 0 || closeT > 23)
			throw new Exception("Invalid time information");
		openingTime = openT;
		closingTime = closeT;
	}

	/**
	 * Presented to the user
	 */
	public int focus(){
		return closingTime;
	}
	
	@Override
	public String toString(){
		String str = new String();
		str = "Market";
		return str;
	}

	@Override
	public boolean equals(Object o){
		if (super.equals(o) == false)
			return false;

		Market otherM = (Market) o;

		return (this.owner == otherM.owner
				&& this.openingTime == otherM.openingTime
				&& this.closingTime == otherM.closingTime);
	}
}