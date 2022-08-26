package aka.src;
public class Office extends Building{
	
	private String jobType;
	private String owner;

	/**
	 * Default constructor
	 */
	public Office(){
		super();
		jobType = "Paper Company";
		owner = "Michael";
	}

	/**
	 * Constructor
	 * @param len length of the building
	 * @param hei height of the building
	 * @param startingPoint starting location in the street (horizontal axis)
	 * @param job job type	
	 * @param ownedBy owner of the building (person name)
	 */	
	public Office(int len, int hei, int startingPoint, String job, String ownedBy)throws Exception{
		super(len, hei, startingPoint);
		jobType = job;
		owner = ownedBy;
	}

	/**
	 * presented to the user
	 * @return jobType job type
	 */	
	public String focus(){
		return jobType;
	}

	@Override
	public String toString(){
		String str = new String();
		str = "Office";
		return str;
	}

	@Override
	public boolean equals(Object o){
		if (super.equals(o) == false) return false;

		Office otherO = (Office) o;
		
		return(this.jobType == otherO.jobType
				&& this.owner == otherO.owner);
	}
}