package srcAka;

import java.util.Arrays;

public class BSTBuilder<E extends Comparable<E>> {
	// index of the array.
	public static int index=0;
	
	/** 
	 * A method that takes a binary tree and an array of E type and returns a binary search tree.
	 * @param bTree `bTree` is a binary tree.
	 * @param arr `arr` is an array of E type.
	 * @return BinaryTree<E> has the structure that its elements can be accessed by binary search
	 */

	public BinaryTree<E> build(BinaryTree<E> bTree, E[] arr){
		//sort array
		Arrays.sort(arr);
		//convert to set
		builder(bTree, arr);
		index = 0;
		return bTree;
	}


	/**
	 * A recursive method that traverses the tree in order and assigns the values of the array to the
	 * nodes of the tree.
	 * @param bTree `bTree` is a binary tree.
	 * @param arr arr is E array
	 */

	private void builder(BinaryTree<E> bTree, E[] arr){
		if(bTree.root == null){
			//do nothing
		}
		else{
			builder(bTree.getLeftSubtree(), arr);
			bTree.root.data = arr[index];
			index++;
			builder(bTree.getRightSubtree(), arr);
		}
	}
}

	
