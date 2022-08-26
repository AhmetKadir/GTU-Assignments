package srcAka;

public class DifferenceOfTraversals{
	public static int findDifference(MyGraph gr){
		//calculate Breadth First Search distance
		var bfsDistance = BreadthFirstSearch.breadthFirstSearch(gr, 0);
		System.out.println("Bfs distance: " + bfsDistance);

		//calculate Depth First Search distance
		var dfsDistance = new DepthFirstSearch(gr).getDistance();
		System.out.println("Dfs distance: " + dfsDistance);

		var result = bfsDistance - dfsDistance;
		if(result < 0)  result = result * (-1);
		return result;
	}
}