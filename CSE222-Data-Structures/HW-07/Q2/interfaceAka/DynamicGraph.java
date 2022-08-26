package interfaceAka;

import srcAka.MyGraph;
import srcAka.MyGraph.Vertex;

public interface DynamicGraph extends Graph {
	
	/**
	 * Generate a new vertex.
	 * @param label label of a vertex.
	 * @param weight weight of a vertex.
	 */
	Vertex newVertex(String label, double weight);

	/**
	 * Add the given vertex to the graph.
	 * @param new_vertex vertex to be added.
	 */
	void addVertex(Vertex new_vertex);

	/**
	 * Add an edge between the given two vertices in the graph.
	 * @param VertexID1 vertex1
	 * @param vertexID2	vertex2
	 */
	void addEdge(int VertexID1, int vertexID2, double _weight);

	/**
	 * Remove the edge between the given two vertices.
	 * @param VertexID1 vertex1
	 * @param vertexID2 vertex2
	 */
	void removeEdge(int VertexID1, int vertexID2);

	/**
	 * Remove the vertex from the graph with respect to the given vertex id
	 * @param vertexID vertex to be deleted.
	 */
	void removeVertex(int vertexID);

	/**
	 * Remove the verticez that have given label from the graph.
	 * @param label label of the vertex to be deleted.
	 */
	void removeVertex(String label);

	/**
	 * Filter the vertices by the given user-defined property and returns a subgraph of the graph.
	 * @param key key of a vertex
	 * @param filter
	 */ 
	MyGraph filterVertices(String key, String filter);

	/**
	 * Generate the adjacency matrix representtation of the graph and returns the matrix.
	 */
	int[][] exportMatrix();

	/**
	 * Print the graph in adjacency list format 
	 */
	void printGraph();
}
