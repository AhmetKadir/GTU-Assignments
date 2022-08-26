package src_Aka;

import interface_Aka.IKWHashMap;

@SuppressWarnings("unchecked")
public class HashTableChain<K extends Comparable<K> , V extends Comparable<V> > implements IKWHashMap<K, V>{
	private static class Entry< K extends Comparable<K> , V extends Comparable<V> > implements Comparable<Entry<K, V> >
	{
		private final K key;
		private V value;
		
		/**
		 * @param key The key
		 * @param value The value
		 */
		public Entry(K key, V value){
			this.key = key;
			this.value = value;
		}
 
		public K getKey(){
			return key;
		}

		public V getValue(){
			return value;
		}

		public V setValue(V _val){
			value = _val;
			return value;
		}

		public int compareTo(Entry<K, V> o) {
			return key.compareTo(o.getKey());
		}

		public String toString(){
			String str = "";
			str += key + ", " + value;
			return str;
		}

	}

	/**The table */
	private BinarySearchTree<Entry<K, V> > [] table;
	/**The number of keys */
	private int numKeys;
	/**The capacity */
	private int CAPACITY = 101;
	/**The maximum load factor */
	private static final double LOAD_THRESHOLD= 3.0;
	
	public HashTableChain(){
		table = new BinarySearchTree[CAPACITY];
		numKeys = 0;
	}

	
	/** 
	 * @param key The key is being sought
	 * @return V is the value of the key if found.
	 * 			Otherwise null.
	 */
	@Override
	public V get(Object _key){
		int index = _key.hashCode() % table.length;
		if(index < 0){
			index += table.length;
		}
		if (table[index] == null){
			return null;
		}
		
		var iter = table[index].BSTIterator();

		while (iter.hasNext()) {
			var node = iter.next();
			if(node.getKey().equals(_key)){
				return node.getValue();
			}
		}
		return null;
	}
	
	/** 
	 * @param key The key of the item
	 * @param Value	The value of the item
	 * @return V The old value of the key if it exists,
	 * 			otherwise, null;
	 */
	@Override
	public V put(K key, V value) {
		int index = key.hashCode() % table.length;
		if (index <  0){
			index += table.length;
		}
		if(table[index] == null){
			table[index] = new BinarySearchTree<Entry<K, V>>();
		}

		var iter = table[index].BSTIterator();
		while(iter.hasNext()){
			var node = iter.next();
			if(node.getKey().equals(key)){
				V oldValue = node.getValue();
				node.setValue(value);
				return oldValue;
			}
		}

		table[index].add(new Entry<K, V>(key, value));
		numKeys++;
		if((numKeys / table.length) > LOAD_THRESHOLD){
			rehash();
		}
		return null;
	}

	
	/** 
	 * @param key key of the item is wanted to be deleted.
	 * @return V value which is just removed.
	 */
	@Override
	public V remove(Object key) {
		int index = key.hashCode() % table.length;
		if (index < 0){
			index += table.length;
		}
		if (table[index] == null){
			//Key is not in the table
			return null;
		}

		var iter = table[index].BSTIterator();

		while(iter.hasNext()){
			if(iter.next().equals(key)){
				V lastValue = iter.next().getValue();
				table[index].remove(iter.next());
				numKeys--;
				return lastValue;
			}
		}

		return null;
	}

	
	/** 
	 * @return int
	 */
	@Override
	public int size() {
		return numKeys;
	}
	
	private void rehash(){
		CAPACITY = 2*CAPACITY + 1;
		while(isPrime(CAPACITY) == false){
			CAPACITY += 2;
			if(CAPACITY % 5 == 0){
				CAPACITY += 2;
			}
		}
		BinarySearchTree<Entry<K, V> > [] newTable; 
		newTable = new BinarySearchTree[CAPACITY];

		int i = 0;
		while(i < CAPACITY ){
			if(table[i] != null){
				var iter = table[i].BSTIterator();
				while(iter.hasNext()){
					newTable[i].add(iter.next());
				}
			}
			i++;
		}

		table = newTable;
	}

	private boolean isPrime(int num){
		for(int i = 2; i < num/2 ; i++){
			if(num % i == 0){
				return false;
			}
		}
		return true;
	}

	@Override
	public boolean isEmpty() {
		return numKeys == 0;
	}

	public String toString(){
		String str= "";
		int i = 0;
		while(i < CAPACITY ){
			if(table[i] != null){
				str += i + " -> ";
				var iter = table[i].BSTIterator();
				while(iter.hasNext()){
					str += iter.next().toString();
					if(iter.hasNext() == true) str += " -> ";
				}
				str += "\n";
			}
			i++;
		}
		return str;
	}
}