import src_Aka.HashTableChain;
import src_Aka.HashTableComb;

public class test {
	public static void main(String[] args) {
		testHashTableChain();
		testHashTableComb();
	}

	public static void testHashTableChain(){
		System.out.println("\n\nTesting HashTable Chain method\n\n");
		HashTableChain<Integer, Integer> hashTable = 
			new HashTableChain<>();
		hashTable.put(3, 728);
		hashTable.put(12, 1010);
		hashTable.put(13, 531);
		hashTable.put(25, 285);
		hashTable.put(152, 518);
		hashTable.put(51, 255);
		hashTable.put(3, 728);
		System.out.println(hashTable.get(51));
		System.out.println(hashTable.isEmpty());
		System.out.println(hashTable.size());
		System.out.println(hashTable.toString());

		System.out.println("Item with key 25 is removed");
		hashTable.remove(25);
		System.out.println(hashTable.toString());
	}

	public static void testHashTableComb(){
		System.out.println("Testing HashTable Hybdrid(Combined) method");
		HashTableComb<Integer, Integer> hashTable = 	
		new HashTableComb<>();

			hashTable.put(3, 728);
			hashTable.put(12, 1010);
			hashTable.put(13, 531);
			hashTable.put(25, 285);
			hashTable.put(23, 518);
			hashTable.put(51, 255);
			System.out.println("\n");
			System.out.println(hashTable.get(51));
			System.out.println(hashTable.get(23));
			System.out.println("\nIndex, Key, Value, Next");
			System.out.println(hashTable.toString());
			System.out.println("Size of the hashTable is: "+ hashTable.size());
			if(hashTable.isEmpty()){
				System.out.println("Hash table is empty");
			}
			else {
				System.out.println("Hash table is not empty");
			}
	}
}



