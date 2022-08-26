package srcAka;

import java.util.*;

/**
 * Class to implement a breadth-first search algorithm
 *
 */
public class BreadthFirstSearch {
	/**
	 * Perform a breadth-first search of a graph
	 * post: The array parent will contain the predecessor of each vertex in the breadth first search tree
	 * @param graph The graph to be searched
	 * @param start The start vertex
	 * @return The array of parents
	 */
	public static int breadthFirstSearch(MyGraph graph, int start){
		Queue<Integer> theQueue = new LinkedList<Integer>();
		//Declare array parent and initialize its elements to -1
		int[] parent = new int[graph.getNumV()];
		int counter = 0;
		for(int i = 0; i < graph.getNumV(); i++){
			parent[i] = -1;
		}

		//array keeps shortest ways to destinations
		double[] shortestRoads = findShortestRoads(graph);

		//Declare array identified and initialize its elements to false
		boolean[] identified = new boolean[graph.getNumV()];
		/* Mark the start vertex as identified and insert it into the queue */
		identified[start] = true;
		theQueue.offer(start);
		
		/* Perform breadth-first search until done */
		while(!theQueue.isEmpty()){
			/* Take a vertex, current, out of the queue. Begin visiting current */
			
			int current = theQueue.remove();
			/* Examine each vertex, neighbor, adjacent to current. */
			Iterator<Edge> itr = graph.edgeIterator(current);
			while(itr.hasNext()){
				Edge edge = itr.next();

				if(edge.getWeight() == shortestRoads[edge.getDest()]){

					int neighbor = edge.getDest();
					//If neighbor has not been identified
					if(!identified[neighbor]){
						//Mark it identified
						identified[neighbor] = true;
						//Place it into the queue
						theQueue.offer(neighbor);
						/* Insert the edge (current, neighbor) into the tree */
						parent[neighbor] = current;

						//keep distance
						counter += edge.getWeight();
					}
				}
			}

			//Finished visiting current
		}
		return counter;
	}

	/**
	 * It takes a graph and returns an array of the shortest roads from the first vertex to all other
	 * vertices
	 * 
	 * @param gr The graph to find the shortest roads in.
	 * @return The shortest road from each city to the next.
	 */

	private static double[] findShortestRoads(MyGraph gr){
		int cur = 0;
		double[] arr = new double[gr.getNumV()];
		for(int i = 0; i < arr.length; i++){
			arr[i] = -1;
		}

		while(cur < gr.getNumV()){
			var iter = gr.edgeIterator(cur);
			while(iter.hasNext()){
				var curEdge = iter.next();
				if(arr[curEdge.getDest()] == -1){
					arr[curEdge.getDest()] = curEdge.getWeight();
				}

				else {
					if(arr[curEdge.getDest()] > curEdge.getWeight()){
						arr[curEdge.getDest()] = curEdge.getWeight();
					}
				}
			}
			cur++;
		}
		return arr;
	}
}
