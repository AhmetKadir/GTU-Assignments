package srcAka;

import java.util.*;

 /**
 * Class to implement the depth-first search algorithm
 *
 */
public class DepthFirstSearch {
	//Data Fields
	/**
	 * A reference to the graph being searched
	 */
	private MyGraph graph;
	/**
	 * Array of parents in the depth-first search tree
	 */
	private int[] parent;
	/**
	 * Flag to indicate whether this vertex has been visited
	 */
	private boolean[] visited;
	/**
	 * The array that contains each vertex in discovery order
	 */
	private int[] discoveryOrder;
	/**
	 * The array that contains each vertex in finish order
	 */
	private int[] finishOrder;
	/**
	 * The index that indicates the discovery order
	 */
	private int discoverIndex = 0;
	/**
	 * The index that indicates the finish order
	 */
	private int finishIndex = 0;

	private int distance = 0;
	
	//Constructors
	/**
	 * Construct the depth-first search of a Graph
	 * starting at vertex 0 and visiting the start vertices in ascending order
	 * @param graph The graph
	 */
	public DepthFirstSearch(MyGraph graph){
		this.graph = graph;
		int n = graph.getNumV();
		parent = new int[n];
		visited = new boolean[n];
		discoveryOrder = new int[n];
		finishOrder = new int[n];


		for(int i = 0; i < n; i++){
			parent[i] = -1; //Declare array parent and initialize its elements to -1
		}
		
		for(int i = 0; i < n; i++){
			if(!visited[i]){
				depthFirstSearch(i);
			}
		}
	}

	/**
	 * Recursively depth-first search the graph starting at vertex current
	 * @param current The start vertex
	 */
	public void depthFirstSearch(int current) {
		//array keeps shortest ways to destinations
		var edgeList = findShortestRoads(graph, current);

		/* Mark the current vertex visited */
		visited[current] = true;
		discoveryOrder[discoverIndex++] = current;
		/* Examine each vertex adjacent to the current vertex */

		int i = 0;
		while(i <  edgeList.size()){			
			var curEdge = edgeList.get(i);
			int neighbor = curEdge.getDest();
			/* Process a neighbor that has not been visited */
			if(!visited[neighbor]){
				/* Insert (current, neighbor) into the depth-first search tree */
				parent[neighbor] = current;
				/* Recursively apply the algorithm starting at neighbor */
				
				//keep distance
				distance += curEdge.getWeight();
				depthFirstSearch(neighbor);
			}
			i++;
		}
		/* Mark current index finished */
		finishOrder[finishIndex++] = current;
	}

	public int getDistance(){
		return distance;
	}

	/**
	 * It takes a graph and a vertex, and returns a list of edges that are connected to the vertex, sorted
	 * by weight
	 * 
	 * @param gr The graph we're working with
	 * @param cur the current node we're looking at
	 * @return The shortest roads from the current node.
	 */
	private static ArrayList<Edge> findShortestRoads(MyGraph gr, int cur){
		ArrayList<Edge> edgeList = new ArrayList<Edge>();

		var iter = gr.edgeIterator(cur);

		while(iter.hasNext()){
			edgeList.add(iter.next());
		}
		
		//Sort the edges according to their weights(ascending order)
		Collections.sort(edgeList, new EdgeComparator());

		return edgeList;
	}
	
	public int[] getDiscoveryOrder() {
		return discoveryOrder;
	}

	public int[] getFinishOrder() {
		return finishOrder;
	}

	public MyGraph getGraph() {
		return graph;
	}

	public int[] getParent() {
		return parent;
	}

	public boolean[] getVisited() {
		return visited;
	}

	public int getDiscoverIndex() {
		return discoverIndex;
	}

	public int getFinishIndex() {
		return finishIndex;
	}
}

class EdgeComparator implements Comparator<Edge> {
		
	// override the compare() method
	@Override
	public int compare(Edge o1, Edge o2) {
		if (o1.getWeight() == o2.getWeight())
			return 0;
		else if(o1.getWeight() > o2.getWeight())
			return 1;
		else 
			return -1;
	}
}
