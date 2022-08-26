package src_Aka;

import interface_Aka.IKWHashMap;

@SuppressWarnings("unchecked")
public class HashTableComb<K extends Comparable<K>, V> implements IKWHashMap<K, V>{
	private static class Entry<K extends Comparable<K>, V> implements Comparable<Entry<K, V>>
{
		private final K key;
		private V value;
		private int nextIndex;
		protected Entry<K, V> next;
 		
		/**
		 * @param key The key
		 * @param value The value
		 */
		public Entry(K key, V value){
			this.key = key;
			this.value = value;
			this.next = null;
			this.nextIndex = -1;
		}
 
		public K getKey(){
			return key;
		}

		public V getValue(){
			return value;
		}

		public Entry<K, V> next(){
			return next;
		}

		public V setValue(V _val){
			value = _val;
			return value;
		}

		public void setNextIndex(int index){
			nextIndex = index;
		}

		public int getNextIndex(){
			return nextIndex;
		}

		public int compareTo(Entry<K, V> o) {
			return key.compareTo(o.getKey());
		}

		public String toString(){
			String str = "";
			str += key + ", " + value + ", ";
			if(nextIndex != -1) str += nextIndex;
			else str += "null";
			return str;
		}

	}
		/**The table */
		private Entry<K, V>[] table;
		/**The number of keys */
		private int numKeys;
		/**The capacity */
		private int CAPACITY = 10;
		/**The maximum load factor */
		private static final double LOAD_THRESHOLD= 3.0;
		private int Prime_number;

		public HashTableComb(){
			table = new Entry[CAPACITY];
			numKeys = 0;
			Prime_number = 7 /* findPrime()*/;
		}

		private int findPrime(){
			int num = (int) (CAPACITY * 0.8);
			while(isPrime(num) == false){
				num -= 1;
			}
			return num;
		}

		private boolean isPrime(int num){
			for(int i = 2; i < num; i++){
				if(num % i == 0){
					return false;
				}
			}
			return true;
		}

		@Override
		public V get(Object key) {
			int probe = 1;
			int ind = hash((K) key, probe);

			if(ind < 0){
				ind += table.length;
			}

			if(table[ind] == null){
				return null;
			}

			var temp = table[ind];
			while (temp.next != null){
				if(temp.getKey().equals(key)){
					return temp.getValue();
				}
				temp = temp.next;
				probe++;
			}

			if(temp.getKey().equals(key)){
				return temp.getValue();
			}

			return null;
		}
		
		private int hash(K key, int probe){
			int hash1 = key.hashCode() % table.length;
			int hash2 = Prime_number - (key.hashCode() % Prime_number);
			return (hash1 + (probe*hash2)) % table.length;			
		}

		@Override
		public V put(K key, V value) {
			int probe = 1;
			int ind = hash(key, probe);

			if(ind < 0){
				ind += table.length;
			}

			if (table[ind] == null){
				table[ind] = new Entry<K, V>(key, value);
				numKeys++;
				return null;
			}

			probe++;
			while (table[ind].next() != null){
				table[ind] = table[ind].next();
				probe++;
			}

			int newIndex = hash(key, probe);

			table[newIndex] = new Entry<K, V>(key, value);
			table[ind].next = table[newIndex];
			table[ind].setNextIndex(newIndex);


			numKeys++;

			if((numKeys / table.length) > LOAD_THRESHOLD){
				rehash();
			}

			return null;
		}

		private void rehash(){
			System.out.println("Not implemented");
		}

		@Override
		public V remove(Object key) {
			System.out.println("It is too complicated," + 
				 " I could not figure it out");
			return null;
		}
		@Override
		public int size() {
			return numKeys;
		}
		@Override
		public boolean isEmpty() {
			return numKeys == 0;
		}

		public String toString(){
			String str = "";
			int i = 0;
			while(i < CAPACITY ){
				if(table[i] != null){
					str += i + " -> ";
					str += table[i].toString();
				}
				else{
					str += i + " null ";
				}
				
				str += "\n";
				i++;
			}
			return str;
		}

		

}
