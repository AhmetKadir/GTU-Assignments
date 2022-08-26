package srcAka;

/**
 * boostedDijkstra
 */
public class BoostedDijkstra {
	public static void DijkstraWithBoost(MyGraph gr){
		int[] pred = new int[gr.getNumV()];
		double[] dist = new double[gr.getNumV()];
		Dijkstra.dijkstrasAlgorithm(gr, 0, pred, dist);


		System.out.println("Node, Predecessor, and Distance:");
		for(int i = 1; i < pred.length; i++){
			System.out.println(i + ":\t" + pred[i] + "\t\t" + dist[i]);
		}
		System.out.print("\n");
	}
}