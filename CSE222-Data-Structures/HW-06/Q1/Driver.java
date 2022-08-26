import srcAka.*;

public class Driver {
	public static void main(String[] args) {
		System.out.println("\n****************************************************************");
		System.out.println("\nTesting a method that takes an array and a binary tree and build a"
							+" binary search tree with structure of binary tree and items from the array\n\n");
		System.out.println("****************************************************************");
		test1();
		System.out.println("_________________________________________________________________");
		test2();
	}

	// A test case that is used to test the BSTBuilder class.
	public static void test1(){
		System.out.println("FIRST EXAMPLE:");
		// Create an array
		Integer[] arr = {13, 5, 26, 53, 12, 27, 3};
		
		/*Binary Tree Structure: 

				11
				----15
				--------3
				------------null
				------------7
				----------------null
				----------------null
				--------41
				------------null
				------------null
				----29
				--------null
				--------5
				------------null
				------------null
		*/
		var aTree = new BinaryTree<>(11,
						new BinaryTree<>(15, 
							new BinaryTree<>(3, null, 
								new BinaryTree<>(7, null, null)),
							new BinaryTree<>(41, null, null)),
						new BinaryTree<>(29, null,
							new BinaryTree<>(5, null, null)));

		System.out.println("\n\n");
		System.out.println("Binary Tree Structure: \n");
		System.out.println(aTree.toString());

		System.out.print("\nMy array : ");

		for(int i = 0; i < arr.length; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.println("\n\n**********************RESULT*****************************");
		System.out.println("\n\nBinary Search Tree: \n");

		BSTBuilder<Integer> test = new BSTBuilder<>();
		System.out.println(test.build(aTree, arr).toString());
	}

	public static void test2(){
		System.out.println("SECOND EXAMPLE:");
		// Create an array
		Integer[] arr = {7, 12, 23, 10, 39};
		
		/*
		Binary Tree Structure: 

			11
			----15
			--------3
			------------null
			------------null
			--------41
			------------null
			------------null
			----29
			--------null
			--------null


		 */
		var aTree = new BinaryTree<>(11,
						new BinaryTree<>(15, 
							new BinaryTree<>(3, null, null),
							new BinaryTree<>(41, null, null)),
						new BinaryTree<>(29, null, null));

		System.out.println("\n\n");
		System.out.println("Binary Tree Structure: \n");
		System.out.println(aTree.toString());

		System.out.print("\nMy array : ");

		for(int i = 0; i < arr.length; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.println("\n\n*********************RESULT*****************************");
		System.out.println("\n\nBinary Search Tree: \n");

		BSTBuilder<Integer> test = new BSTBuilder<>();
		System.out.println(test.build(aTree, arr).toString());
	}
}
