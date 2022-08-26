import srcAka.Edge;
import srcAka.MyGraph;

public class test {
	public static void main(String[] args) {
		System.out.println("\nTEST MyGraph CLASS\n");

		MyGraph g = new MyGraph(5);

		//Insert
		g.insert(new Edge(0, 3, 5));
		g.insert(new Edge(0, 1, 5));
		g.insert(new Edge(1, 4, 3));
		g.insert(new Edge(4, 3, 7));


		g.printGraph();

		System.out.println("isDirected : " + g.isDirected());
		System.out.println();

		g.addVertex(g.newVertex(" ", 1));
		g.addVertex(g.newVertex("Color", "Orange"));
		g.addVertex(g.newVertex("Color", "Blue"));
		g.addVertex(g.newVertex("Color", "Blue"));
		g.addVertex(g.newVertex("Capacity", "Full"));



		g.printGraph();


		g.addEdge(4, 5, 5);
		g.printGraph();

		System.out.println("Number of vertices in the graph: " + g.getNumV());
		System.out.println();

		System.out.println("edge(1,4): " + g.getEdge(1, 4).toString());
		System.out.println();
		
		//isEdge
		System.out.println("isEdge(4,5) : " + g.isEdge(4, 5));
		System.out.println();

		//Remove an edge
		g.removeEdge(4, 5);
		g.printGraph();

		//isEdge
		System.out.println("isEdge(4,5) : " + g.isEdge(4, 5));
		System.out.println();
		
		//Remove a Vertex
		g.removeVertex(5);
		g.printGraph();

		g.removeVertex("deleteThis");
		g.printGraph();

		//Add an edge
		g.addEdge(7, 3, 4.0);
		g.printGraph();

		System.out.println("Number of vertices in the graph: " + g.getNumV());
		System.out.println();

		//Test filter method
		System.out.println("filtered :Color = Blue : ");
		g.filterVertices("Color", "Blue").printGraph();

		System.out.println("filtered :Capacity = Full : ");
		g.filterVertices("Capacity", "Full").printGraph();

		System.out.println("filtered :Color = Blue : ");
		g.filterVertices("Color", "Blue").printGraph();

		g.printGraph();

		//Test exportMatrix
		var arr = g.exportMatrix();

		for(int i = 0; i < arr.length; i++){
			for(int j = 0; j < arr[i].length; j++){
				if(arr[i][j] == 1)
					System.out.printf("[%d][%d]\n" ,i, j);
			}
		}

		

	}
}
