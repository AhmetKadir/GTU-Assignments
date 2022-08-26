package interface_Aka;

public interface IKWHashMap<K, V>{
	V get(Object key);

	boolean isEmpty();

	V put(K key, V Value);

	V remove (Object key);

	int size();
}