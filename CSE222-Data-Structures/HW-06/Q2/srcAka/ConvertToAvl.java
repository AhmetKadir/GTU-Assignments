package srcAka;

import srcAka.BinaryTree.Node;

public class ConvertToAvl<E extends Comparable<E>> {	
	
	/**
	 * The method that takes a binary search tree (BST) as a parameter
	 * and prints the AVL tree obtained by rearranging the BST.
	 * @param <T> Type
	 * @param bsTree binary Search Tree 
	 */
	public static <T extends Comparable<T>> void bstToAvl(BinarySearchTree<T> bsTree){
		bsTree.root = bstToAvl(bsTree.root);
		bsTree.root = bstToAvl2(bsTree.root);
		System.out.println(bsTree.toString());
	}

	/**
	 * Recursive method that rotates nodes of binary search tree in order to convert it into a AVL Tree.
	 * @param <T> Type
	 * @param root root of the Tree.
	 * @return root of the Tree.
	 */
	private static <T> Node<T> bstToAvl(Node<T> root) {
		if(root.left != null){
			root.left = bstToAvl(root.left);
		}
		if(root.right != null){
			root.right = bstToAvl(root.right);
		}
		int lHeight = heightOf(root.left);
		int rHeight = heightOf(root.right);

		// if left is heavy
		if(lHeight - rHeight > 1){
			Node<T> leftChild = root.left;

			//left right unbalance
			if(root.left.left == null){
				root.left = rotateLeft(leftChild);
			}

			root = rotateRight(root);		

			lHeight = heightOf(root.left);
			rHeight = heightOf(root.right);
		}
		// if right is heavy
		if (rHeight - lHeight > 1){
			Node<T> rightChild = root.right;

			//right left unbalance
			if(root.right.right == null){
				root.right = rotateRight(rightChild);
			}

			root = rotateLeft(root);

		}

		return root;
	}

	/**
	 * Recursive method that rotates nodes of binary search tree in order to convert it into a AVL Tree.
	 * It is a similar method the first one but difference is this traverses right side first.
	 * @param <T> Type
	 * @param root root of the Tree
	 * @return root of the Tree.
	 */
	private static <T> Node<T> bstToAvl2(Node<T> root) {

		if(root.right != null){
			root.right = bstToAvl(root.right);
		}
		if(root.left != null){
			root.left = bstToAvl(root.left);
		}
		int lHeight = heightOf(root.left);
		int rHeight = heightOf(root.right);

		// if left is heavy
		if(lHeight - rHeight > 1){
			Node<T> leftChild = root.left;

			//left right unbalance
			if(root.left.left == null){
				root.left = rotateLeft(leftChild);
			}

			root = rotateRight(root);		
			lHeight = heightOf(root.left);
			rHeight = heightOf(root.right);
		}
		// if right is heavy
		if (rHeight - lHeight > 1){
			Node<T> rightChild = root.right;

			//right left unbalance
			if(root.right.right == null){
				root.right = rotateRight(rightChild);
			}

			root = rotateLeft(root);

		}

		return root;
	}

	/**
	 * Rotates the node right.
	 * @param <T> Type.
	 * @param root node.
	 * @return new root.
	 */
	protected static <T> Node<T> rotateRight(Node<T> root){
		Node<T> temp = root.left;
		root.left = temp.right;
		temp.right = root;
		return temp;
	}
	
	/**
	 * Rotates the node right.
	 * @param <T> Type
	 * @param root node.
	 * @return new root.
	 */
	protected static <T> Node<T> rotateLeft(Node<T> root){
		Node<T> temp = root.right;
		root.right = temp.left;
		temp.left = root;
		return temp;
	}

	/**
	 * Calculates the height of the tree recursively with helper method.
	 * @param <T> Type.
	 * @param root Root of the tree.
	 * @return The height of the tree.
	 */
	private static <T> int heightOf(Node<T> root){
		int[] arr = new int[2];
		arr[0] = 0;
		arr[1] = 0;
		heightOf(root, arr);
		if(arr[0] > arr[1]) return arr[0];
		else return arr[1];
	}

	/**
	 * Helper method calculates the height of the tree recursively.
	 * @param <T> Type
	 * @param root Root of the tree.
	 * @param arr arr[0] = Height of left subtree, arr[1] = Height of the Right subtree.
	 * @return Array of Heights of left and right subtree.
	 */
	private static <T> int[] heightOf(Node<T> root, int[] arr){
		if(root == null){
			arr[0] = -1;
			arr[1] = -1;
		}
		else{
			if(root.left != null){
				arr = heightOf(root.left, arr);
				arr[0]++;
			}
			if(root.right != null){
				arr = heightOf(root.right, arr);
				arr[1]++;
			}
		}
		return arr;
	}
}
