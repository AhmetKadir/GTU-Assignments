import srcAka.DifferenceOfTraversals;
import srcAka.Edge;
import srcAka.MyGraph;

public class test{
	public static void main(String[] args) {
		System.out.println("TESTING findDifference Method // 1\n");
		test1();
		System.out.println("\n\nTESTING findDifference Method // 2\n");
		test2();
	}

	public static void test1(){
		MyGraph g = new MyGraph(5);

		//Insert
		g.insert(new Edge(0, 1, 8));
		g.insert(new Edge(0, 2, 3));
		g.insert(new Edge(0, 3, 5));
		g.insert(new Edge(1, 4, 3));
		g.insert(new Edge(2, 4, 7));
		g.insert(new Edge(3, 4, 1));

		
		System.out.println("Difference of the traversals: " + DifferenceOfTraversals.findDifference(g));
	}

	public static void test2(){
		MyGraph g = new MyGraph(6);

		//Insert
		g.insert(new Edge(0, 1, 3));
		g.insert(new Edge(0, 2, 5));
		g.insert(new Edge(1, 3, 51));
		g.insert(new Edge(1, 4, 1));
		g.insert(new Edge(1, 5, 5));
		g.insert(new Edge(2, 3, 3));
		g.insert(new Edge(2, 4, 10));
		g.insert(new Edge(2, 5, 2));

		
		System.out.println("Difference of the traversals: " + DifferenceOfTraversals.findDifference(g));
	}
}