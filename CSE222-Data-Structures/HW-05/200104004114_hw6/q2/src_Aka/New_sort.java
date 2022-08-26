package src_Aka;

public class New_sort {
	static int counter = 0;

	public static <T extends Comparable<T>> void sort(T[] table) {
		sort(table, 0, table.length - 1);
	}

	private static <T extends Comparable<T>> T[] sort(T[] table, int head, int tail){

		if(head > tail){
			return table;
		}

		else{
			int MIN_MAX[] = min_max_finder(table, head, tail);
			swap(table, head, MIN_MAX[0]);
			swap(table, tail, MIN_MAX[1]);

			return sort(table, head+1 , tail-1);
		}
	}

	private static <T extends Comparable<T>> int[] min_max_finder(T[] table,
	 	int head, int tail){
		return min_max_finder(table, head, tail, 0, 0);
	}

	private static <T extends Comparable<T>> int[] min_max_finder(T[] table,
		int head, int tail, int min, int max){
			if(head > tail){
				int[]min_max = {min, max};
				return min_max;
			}

			if(table[head].compareTo(table[min]) <= 0){
				min = head;
			}

			if(table[head].compareTo(table[max]) >= 0){
				max = head;
			}

			return min_max_finder(table, head+1, tail, min, max);
		}

	private static <T extends Comparable<T>> void swap(T[] table, int index1, int index2) 
	{
		T temp = table[index1]; 
		table[index1] = table[index2]; 
		table[index2] = temp; 
	}
}
