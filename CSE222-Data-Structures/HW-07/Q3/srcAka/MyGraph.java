package srcAka;

import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;

import interfaceAka.DynamicGraph;

/**
 * Graph class that uses a HashMap to store vertices and a LinkedList to store edges
 */

public class MyGraph implements DynamicGraph {
	public class Vertex{
		private int ID;
		private String label;
		@SuppressWarnings("unused")
		private double weight;
		private HashMap<String, String> properties;

		protected Vertex(){
			ID = nextID;
			nextID++;
			label = " ";
			weight = 1;
			properties = new HashMap<>();
		}
		private Vertex(int id){
			ID = id;
			label = " ";
			weight = 1;	
			properties = new HashMap<>();
		}
		
		protected Vertex(String _label){
			ID = nextID;
			nextID++;
			label = _label;
			weight = 1;
			properties = new HashMap<>();

		}

		protected Vertex(String _label, double _weight){
			ID = nextID;
			nextID++;
			label = _label;
			weight = _weight;
			properties = new HashMap<>();
		}

		protected Vertex(String key, String value){
			ID = nextID;
			nextID++;
			label = " ";
			weight = 1;
			properties = new HashMap<>();
			properties.put(key, value);
		}

		protected Vertex(int id, String _label, double _weight, String key, String value){
			ID = id;
			label = _label;
			weight = _weight;
			properties = new HashMap<>();
			properties.put(key, value);
		}

		@Override
		public int hashCode() {
			return Integer.hashCode(ID);
		}

		public boolean equals(Object obj){
			return obj.hashCode() == this.hashCode();
		}
	
	}

	private HashMap<Vertex, LinkedList<Edge>> graph;
	
	private int nextID;
	/**
	 * Number of vertices
	 */
	private int numV;
	/**
	 * Flag to indicate whether this is a directed graph
	 */
	private boolean directed;

	//Constructors 
	public MyGraph(){
		nextID = 0;
		numV = 0;
		directed = true;
		graph = new HashMap<>();
	} 

	public MyGraph(int vertices){
		numV = 0;
		nextID = 0;
		directed = true;
		graph = new HashMap<>();
		for(int i = 0; i < vertices; i++){
			addVertex(new Vertex());
		}
		
	}

	@Override
	public int getNumV() {
		return numV;
	}

	@Override
	public boolean isDirected() {
		return directed;
	}

	@Override
	public void insert(Edge e) {
		// Checking if the graph contains the key, if it does not, it adds it.
		// if(!(graph.containsKey(new Vertex(e.getSource())))){
		// 	addVertex(new Vertex(e.getSource()));
		// }		
		graph.get(new Vertex(e.getSource())).add(e);
	}

	@Override
	public boolean isEdge(int source, int dest) {
		return graph.get(new Vertex(source)).contains(new Edge(source, dest));
	}

	@Override
	public Edge getEdge(int source, int dest) {
		var iter = edgeIterator(source);
		while(iter.hasNext())
		{
			Edge cur = iter.next();
			if(cur.getDest() == dest){
				return cur;
			}
		}
		return null;
	}

	@Override
	public Iterator<Edge> edgeIterator(int source) {
		return graph.get(new Vertex(source)).listIterator();
	}

	@Override
	public Vertex newVertex(String label, double weight) {
		return new Vertex(label, weight);
	}

	@Override
	public void addVertex(Vertex new_vertex) {
		graph.put(new_vertex, new LinkedList<>());
		numV++;
	}

	@Override
	public void addEdge(int vertexID1, int vertexID2, double _weight) {
		graph.get(new Vertex(vertexID1)).add(new Edge(vertexID1, vertexID2, _weight));
	}

	@Override
	public void removeEdge(int vertexID1, int vertexID2) {
		graph.get(new Vertex(vertexID1)).remove(new Edge(vertexID1, vertexID2));
	}

	@Override
	public void removeVertex(int vertexID) {
		graph.remove(new Vertex(vertexID));
		numV--;
	}

	@Override
	public void removeVertex(String _label) {
		var iter = graph.keySet().iterator();

		while(iter.hasNext()){
			var cur = iter.next();
			if(cur.label.equals(_label)){
				iter.remove();
				numV--;
			}
		}
	}

	public Vertex newVertex(String key, String value){
		return new Vertex(key, value);
	}

	public double[] getBoosts(){
		double[] boost = new double[numV];
		var iter = graph.keySet().iterator();
		while(iter.hasNext()){
			var cur = iter.next();
			double d = 0;
			String s = cur.properties.get("Boosting");
			if(s != null){
				d = Double.parseDouble(s);
			}
			boost[cur.ID] = d;
		}
		return boost;
	}

	@Override
	public MyGraph filterVertices(String key, String filter) {
		var filteredMyGraph = new MyGraph();
		
		var iterThis = graph.keySet().iterator();

		while(iterThis.hasNext()){
			var cur = iterThis.next();
			
			if(cur.properties.get(key) !=  null & key != null){
				if(cur.properties.get(key).equals(filter)){
					Vertex ver = new Vertex(cur.ID, cur.label, cur.weight, key, filter);
					filteredMyGraph.addVertex(ver);
					
					var listiter = edgeIterator(cur.ID);

					while(listiter.hasNext()){
						var listCur = listiter.next();
						filteredMyGraph.addEdge(cur.ID, listCur.getDest(), listCur.getWeight());
					}
				}
			}
		}
		return filteredMyGraph;
	}

	@Override
	public int[][] exportMatrix() {
		var arr = new int[numV][numV];
		var iter = graph.keySet().iterator();

		while (iter.hasNext()){
			var cur = iter.next();
			var listiter = graph.get(cur).listIterator();
			while(listiter.hasNext()){
				var listCur = listiter.next();
				arr[listCur.getSource()][listCur.getDest()] = 1;
			}
		
		}
		return arr;
	}

	@Override
	public void printGraph() {
		var iter = graph.keySet().iterator();
		System.out.println("Graph: ");
		while(iter.hasNext()){
			var cur = iter.next();
			System.out.printf("%d: \"%s\" {", cur.ID, cur.label);

			var listiter = edgeIterator(cur.ID);

			while(listiter.hasNext()){
				var listCur = listiter.next();
				System.out.printf(" [(%d,%d) : (%.2f)] " ,  listCur.getSource(), listCur.getDest(), listCur.getWeight());
				if (listiter.hasNext()) System.out.printf("--> ");
			}
			System.out.print("}");
			System.out.println("");
		}
		System.out.println();
	}
}
