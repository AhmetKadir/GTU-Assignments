import srcAka.BinarySearchTree;
import srcAka.ConvertToAvl;

public class Driver {
	public static void main(String[] args) {
        System.out.println("\n\n************************************************");
        System.out.println("Testing the bstToAvl method that takes a"
            +" binary search tree (BST) as a parameter"
            +" and prints the AVL tree obtained by rearranging the BST.");
        System.out.println("************************************************\n");


        test1();

        System.out.println("______________________________________________________________________\n");

        test2();
	}

    // Testing the bstToAvl method.
    public static void test1(){
        System.out.println("\nFIRST EXAMPLE:\n");
        var bsTree = new BinarySearchTree<Integer>();
        for (int i =15; i > 1; i--){
			bsTree.add(i);
		}

		System.out.println("Binary Search Tree: ");
		System.out.println(bsTree.toString());

        System.out.println("\t\t\tRESULT");
		System.out.println("Converted to Avl Tree");
		ConvertToAvl.bstToAvl(bsTree);
    }
        
    // Testing the bstToAvl method.
    public static void test2(){
        System.out.println("\nSECOND EXAMPLE:\n");
        var bsTree = new BinarySearchTree<Integer>();
        bsTree.add( 12); 
        bsTree.add( 87); 
        bsTree.add( 82); 
        bsTree.add( 71); 
        bsTree.add( 54); 
        bsTree.add( 3); 
        bsTree.add( 45); 
        bsTree.add( 53); 
        bsTree.add( 25); 
        bsTree.add( 31); 
        bsTree.add( 14); 
        bsTree.add( 66); 
        bsTree.add( 41); 
        bsTree.add( 29); 
        bsTree.add( 45); 
        bsTree.add( 72); 
        bsTree.add( 17); 
        bsTree.add( 71); 
        bsTree.add( 54); 
        bsTree.add( 73);


		System.out.println("Binary Search Tree: ");
		System.out.println(bsTree.toString());

        System.out.println("\t\t\tRESULT");

		System.out.println("Converted to Avl Tree");
		ConvertToAvl.bstToAvl(bsTree);
    }


}
