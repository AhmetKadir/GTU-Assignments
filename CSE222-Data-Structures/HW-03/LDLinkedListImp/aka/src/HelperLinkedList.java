package aka.src;
import java.util.AbstractList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.NoSuchElementException;

/**
 * Linked list implementation of the {@code List} interface with lazy deletion
 * strategy.
 * Implements all optional list operations.
 * In lazy deletion strategy, the nodes containing removed
 * elements are moved to a separate Linked List for future use. When a new
 * element is added, a node is obtained from this second list if one available.
 * A new node should be created, otherwise.
 * 
 * @author Ahmet Kadir Aksu
 * @see List
 * @see AbstractList
 * @param <E> the type of elements held in this linked list
 */

@SuppressWarnings("all")
public class HelperLinkedList<E>
			extends AbstractList<E>
			implements List<E> {

	/**
	 * Pointer to the head.
	 */
	private Node<E> head = null;

	/**
	 * Pointer to the tail.
	 */
	private Node<E> tail = null;

	private int size = 0;

	/**
	 * Constructor to create an empty list.
	 */
	public HelperLinkedList() {
	}

	/**
	 * Adds an item at the specified position
	 * @param index index at which the specified item is to be instered
	 * @param item item to be inserted
	 */
	public void add(int index, E item){ //O(1)
		listIterator(index).add(item); //O(1)
		
	}

	
	/**
	 * Adds the item at the beginning of the list.
	 * 
	 * @param item the item which will be added
	 */
	public void addFirst(E item){
		add(0, item);
	}

	public void addLast(E item){
		add(size, item);
	}
	
	/**
	 * Removes and returns the first element from the list.
	 * @return
	 */
	protected E removeFirst(){
		// Node<E> temp = head;
		// if (head != null)
		// 	head = head.next;
		// if(temp != null){
		// 	size--;
		// 	return temp.item;
		// }
		// else	
		// 	return null;
		return remove(0);

	}

	protected E removeLast(){
		return remove(size);
	}

	/**
	 * Returns the item at the specified position.
	 * 
	 * @param index index of the item to return
	 * @return the item at the specified position in the list
	 */
	@Override
	public E get(int index) {
		return listIterator(index).next();
	}

	public E getFirst(){
		return head.item;
	}

	public E getLast(){
		return tail.item;
	}

	@Override
    public E remove(int index){ //O(1)
		E returnVal = null;
		var iter = listIterator(index); //O(1)
		if (iter.hasNext()){   //O(1)
			returnVal = iter.next(); //O(1)
			iter.remove(); //O(1)
			size--;
		}
		else {  throw new IndexOutOfBoundsException();  }
		return returnVal;
	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public String toString() {
		LDListIter iter = new LDListIter(0); 
		String str = "[";
		while(iter.hasNext()){
			str += iter.next().toString() + "->";
		}
		str += "]";
		return str;
	}

	public Iterator<E> iterator() { return new LDListIter(0);  }
	public ListIterator<E> listIterator() { return new LDListIter(0);  }
	public ListIterator<E> listIterator(int index){return new LDListIter(index);}
	public ListIterator<E> listIterator(ListIterator<E> iter)
	{     return new LDListIter( (LDListIter) iter);  }

	private class LDListIter implements ListIterator<E>{
		private Node<E> nextItem;
		private Node<E> lastItemReturned;
		private int index;
		
		/**
		 * Constructor
		 * @param ind index
		 */
		public LDListIter(int ind) { //O(n)
			if (ind < 0 || ind > size){
			    throw new IndexOutOfBoundsException("Invalid index " + ind); }
			lastItemReturned = null; 
		
			//for the last item
			if (ind == size){     
				index = size;     
				nextItem = null;
			}
			else{   
				nextItem = head;
				for (index = 0; index < ind; index++)  //O(n)
					nextItem = nextItem.next;   
			}
		}  
		
		public LDListIter(LDListIter other){
			nextItem = other.nextItem;
			index = other.index;
		}

		/**
		 * Checks if the next node exists.
		 * @return true if the next node exists.
		 */
		@Override
		public boolean hasNext() {
			return (nextItem != null);
		}

		/**
		 * Moves to the next node and returns its item.
		 * @return the next item.
		 */
		@Override
		public E next() {
			if(!hasNext())
				throw new NoSuchElementException();
			lastItemReturned = nextItem;
			nextItem = nextItem.next;
			index++;
			return lastItemReturned.item;

		}

		/**
		 * Checks if the previous node exist
		 * @return true if the previous node exist.
		 */
		@Override
		public boolean hasPrevious() {
			return (nextItem == null && size != 0)
					|| nextItem.prev != null;
		}

		/**
		 * Moves to the previous node and returns its item.
		 * @return previous item.
		 */
		@Override
		public E previous() {
			if(!hasPrevious()) 
				throw new NoSuchElementException();
			
			if(nextItem == null)
				nextItem = tail;
			else
				nextItem = nextItem.prev;
			lastItemReturned = nextItem;
			index--;
			return lastItemReturned.item;
		}

		@Override
		public int nextIndex() {
			return index;
		}

		@Override
		public int previousIndex() {
			return index - 1;
		}
		/*@Override
		public void remove() {
			if(lastItemReturned == null)
				throw new IllegalStateException();

			Node<E> lastNext = lastItemReturned.next;
			HelperLinkedList.this.remove(lastItemReturned);
			if(nextItem == lastItemReturned)
				nextItem = lastNext;
			else	
				index--;

			lastItemReturned = null;
			
		}*/

		@Override
		public void remove(){
            if(lastItemReturned != null)
            {
                lastItemReturned.next.prev = lastItemReturned.prev;
                lastItemReturned.prev.next = lastItemReturned.next;
                lastItemReturned = null;
            }
            else
                tail = tail.prev;
            index--;
        }

		@Override
		public void set(E el) {
			if(lastItemReturned ==  null)
				throw new IllegalStateException();
			lastItemReturned.item = el;
		}	

		@Override
		public void add(E el) { //O(1)
			//inserts to empty list
			if (head == null){
				head = new Node<E> (el);
				tail = head;
			}

			//inserts to head
			else if(nextItem == head){
				var newNode = new Node<E>(el);
				newNode.next = nextItem;
				nextItem.prev = newNode;
				head = newNode;
				lastItemReturned = null;
			}

			//inserts to tail
			else if(nextItem == null){
				var newNode = new Node<E>(el);
				tail.next = newNode;
				newNode.prev = tail;
				tail = newNode;
			}

			//inserts to middle of the list
			else{
				var newNode = new Node<E>(el);
				newNode.prev = nextItem.prev;
				nextItem.prev.next = newNode;
				newNode.next = nextItem;
				nextItem.prev = newNode;
			}

			size++;
			index++;
		}
	}//end of class LDListIter

	private static class Node<E> {
		private E item;
		private Node<E> next = null;
		private Node<E> prev = null;

		private Node(E item) {
			this.item = item;   
		}

		Node(Node<E> prev, E element, Node<E> next) {
			this.item = element;
			this.next = next;
			this.prev = prev;
		}
	}// end of inner class Node

}// end of class LDLinkedList