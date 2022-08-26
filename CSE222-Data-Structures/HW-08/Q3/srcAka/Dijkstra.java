package srcAka;

import java.util.*;

/**
 * Dijkstra Algorithm With Boost
 */
public class Dijkstra {
	/**
	 * Dijkstra's Shortest Path algorithm
	 * pre: graph to be searched is a weighted directed graph with only positive weights
	 * 		pred and dist are arrays of size V
	 * @param graph The weighted graph to be searched
	 * @param start The start vertex
	 * @param pred Output array to contain the predecessors in the shortest path
	 * @param dist Output array to contain the distance in the shortest path
	 */
	public static void dijkstrasAlgorithm(MyGraph graph,
										  int start,
										  int[] pred,
										  double[] dist){
		int numV = graph.getNumV();
		HashSet<Integer> vMinusS = new HashSet<Integer>(numV);
		double[] boost = getBoosts(graph);

		//Initialize V - S
		for(int i = 0; i < numV; i++){
			if(i != start)
				vMinusS.add(i);
		}
		// Initialize pred and dist
		for(int v : vMinusS){
			pred[v] = start;
			if(graph.getEdge(start, v) !=null)
				dist[v] = graph.getEdge(start, v).getWeight();
			else dist[v] = Double.POSITIVE_INFINITY;

		}
		//Main loop
		while(vMinusS.size() != 0){
			//Find the value u in V - S with the smallest dist[u]
			double minDist = Double.POSITIVE_INFINITY;
			int u = -1;
			for(int v : vMinusS){
				if(dist[v] < minDist){
					minDist = dist[v];
					u = v;
				}
			}
			// Remove u from vMinusS
			vMinusS.remove(u);
			//Update the distances
			Iterator<Edge> edgeIter = graph.edgeIterator(u);
			while(edgeIter.hasNext()){
				Edge edge = edgeIter.next();
				int v = edge.getDest();
				if(vMinusS.contains(v)){
					double weight = edge.getWeight();

					if(dist[u] + weight -boost[u]  < dist[v]){
						dist[v] = dist[u] + weight - boost[u];
						pred[v] = u;
					}
				}
			}
		}
	}

	private static double[] getBoosts(MyGraph gr){
		double[] arr = new double[gr.getNumV()];
		arr = gr.getBoosts();
		return arr;
	}
}

