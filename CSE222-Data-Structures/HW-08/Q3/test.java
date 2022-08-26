import srcAka.Edge;
import srcAka.MyGraph;
import srcAka.BoostedDijkstra;

public class test {
	public static void main(String[] args) {
		System.out.println("\n\nTESTING Dijkstra With Boost\n\n");
		System.out.println("TESTING example 1:\n");
		test1();
		System.out.println("\n\nTESTING example 2:\n");
		test2();
	}

	public static void test1(){
		MyGraph g = new MyGraph();

		g.addVertex(g.newVertex("Boosting", "2"));
		g.addVertex(g.newVertex("Boosting", "3"));
		g.addVertex(g.newVertex("Boosting", "0"));

		g.insert(new Edge(0, 1, 4));
		g.insert(new Edge(0, 2, 8));
		g.insert(new Edge(1, 2, 6));

		BoostedDijkstra.DijkstraWithBoost(g);

	}

	public static void test2(){
		MyGraph g = new MyGraph();

		g.addVertex(g.newVertex(" ", 1));
		g.addVertex(g.newVertex("Boosting", "20.0"));
		g.addVertex(g.newVertex(" ", 1));
		g.addVertex(g.newVertex(" ", 1));
		g.addVertex(g.newVertex(" ", 1));

		//Insert
		g.insert(new Edge(0, 1, 10));
		g.insert(new Edge(0, 3, 30));
		g.insert(new Edge(0, 4, 100));
		g.insert(new Edge(1, 2, 50));
		g.insert(new Edge(2, 4, 10));
		g.insert(new Edge(3, 2, 20));
		g.insert(new Edge(3, 4, 60));

		BoostedDijkstra.DijkstraWithBoost(g);

	}
}
