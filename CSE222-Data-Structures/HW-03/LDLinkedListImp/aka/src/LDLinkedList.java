package aka.src;
import java.util.AbstractList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

@SuppressWarnings("all")
public class LDLinkedList<E>
	extends AbstractList<E>
	implements List<E> {
	
	private HelperLinkedList<E> list;
	private HelperLinkedList<E> deletedElementsList;


	/**
	 * Constructor to create an empty list.
	 */
	public LDLinkedList() {
		list = new HelperLinkedList<E>();
		deletedElementsList = new HelperLinkedList<E>();
	}

	/**
	 * Adds an item at the specified position
	 * @param index index at which the specified item is to be instered
	 * @param item item to be inserted
	 */
	public void add(int index, E item){		// 	O(n)
		boolean itemDeletedBefore = false;
		var iter = deletedElementsList.listIterator(); 
		while(iter.hasNext()) 		//O(n)
			if(iter.next() == item){
				itemDeletedBefore = true;
				list.listIterator(index).add(item); //	O(1)
				break;
			}
		if(!itemDeletedBefore){
			list.add(index, item);
		}
		
	}

	
	/**
	 * Adds the item at the beginning of the list.
	 * 
	 * @param item the item which will be added
	 */
	public void addFirst(E item){
		list.addFirst(item);
	}

	public void addLast(E item){
		list.addLast(item);
	}
	
	/**
	 * Removes and returns the first element from the list.
	 * @return
	 */
	public E removeFirst(){
		return list.removeFirst();
	}

	public E removeLast(){
		return list.removeLast();
	}

	/**
	 * Returns the item at the specified position.
	 * 
	 * @param index index of the item to return
	 * @return the item at the specified position in the list
	 */
	@Override
	public E get(int index) {
		return list.get(index); //O(n)
	}

	public E getFirst(){
		return list.getFirst();
	}

	public E getLast(){
		return list.getLast();
	}

    public E remove(int index){
		E removed = list.remove(index); //O(1)
		deletedElementsList.add(removed); //O(1)


		return removed;
	}

	@Override
	public int size() {
		return list.size();
	}

	@Override
	public String toString() {
		return list.toString();
	}

	public Iterator<E> iterator() { 
		return list.iterator();  
	}
	public ListIterator<E> listIterator() {
		 return list.listIterator();  
		}
	public ListIterator<E> listIterator(int index){
		return list.listIterator(index);
	}
	public ListIterator<E> listIterator(ListIterator<E> iter){
		return list.listIterator(iter);  
	}
}