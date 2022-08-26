import java.util.Random;

import src_Aka.*;

public class driver {
	public static void main(String[] args) {
		System.out.println("Calculating the time (ms)");
		System.out.println("\n\n");
		testSmalls();
		System.out.println("\n\n");
		testMed();
		System.out.println("\n\n");
		testLarge();
		System.out.println("\n\n");
		
	}

	public static void resetArr(Integer[] arr1, Integer[] arr2){
		for(int i = 0; i < arr1.length; i++){
			arr1[i]= arr2[i];
		}
	}
	
	public static void testSmalls(){
		Random ran = new Random();
		int s_size = 100;
		int numArrays = 1000;
		Integer[][] randSArray = new Integer[numArrays][s_size];
		Integer[][] temp = new Integer[numArrays][s_size];
		for(int i = 0 ; i < numArrays; i++){
			for(int j = 0; j < s_size; j++){
				randSArray[i][j] = (int) ran.nextInt(s_size);
				temp[i][j] = randSArray[i][j];
			}
		}
		
		long startTime = System.currentTimeMillis();
		for(int i =0; i < numArrays; i++){
			New_sort.sort(randSArray[i]);			
		}
		long elapsedTime = System.currentTimeMillis() - startTime;
        System.out.println("NewSort 100: " + elapsedTime);
		
		//reset arrays
		for(int i = 0; i < numArrays; i++){
			resetArr(randSArray[i], temp[i]);
		}

		//Quick Sort
		startTime = System.currentTimeMillis();
		for(int i =0; i < numArrays; i++){
			QuickSort.sort(randSArray[i]);
		}
		elapsedTime = System.currentTimeMillis() - startTime;
        System.out.println("Quick Sort 100: " + elapsedTime);
		
		//reset arrays
		for(int i = 0; i < numArrays; i++){
			resetArr(randSArray[i], temp[i]);
		}

		//Merge Sort
		startTime = System.currentTimeMillis();
		for(int i =0; i < numArrays; i++){
			MergeSort.sort(randSArray[i]);
		}
		elapsedTime = System.currentTimeMillis() - startTime;
        System.out.println("MergeSort 100: " + elapsedTime);
		
		//reset arrays
		for(int i = 0; i < numArrays; i++){
			resetArr(randSArray[i], temp[i]);
		}

	}
	
	public static void testMed(){
		Random ran = new Random();
		int s_size = 1000;
		int numArrays = 1000;
		Integer[][] randSArray = new Integer[numArrays][s_size];
		Integer[][] temp = new Integer[numArrays][s_size];
		for(int i = 0 ; i < numArrays; i++){
			for(int j = 0; j < s_size; j++){
				randSArray[i][j] = (int) ran.nextInt(s_size);
				temp[i][j] = randSArray[i][j];
			}
		}
		
		long startTime = System.currentTimeMillis();
		for(int i =0; i < numArrays; i++){
			New_sort.sort(randSArray[i]);			
		}
		long elapsedTime = System.currentTimeMillis() - startTime;
        System.out.println("NewSort 1000: " + elapsedTime);
		
		//reset arrays
		for(int i = 0; i < numArrays; i++){
			resetArr(randSArray[i], temp[i]);
		}

		//Quick Sort
		startTime = System.currentTimeMillis();
		for(int i =0; i < numArrays; i++){
			QuickSort.sort(randSArray[i]);
		}
		elapsedTime = System.currentTimeMillis() - startTime;
        System.out.println("Quick Sort 1000: " + elapsedTime);
		
		//reset arrays
		for(int i = 0; i < numArrays; i++){
			resetArr(randSArray[i], temp[i]);
		}

		//Merge Sort
		startTime = System.currentTimeMillis();
		for(int i =0; i < numArrays; i++){
			MergeSort.sort(randSArray[i]);
		}
		elapsedTime = System.currentTimeMillis() - startTime;
        System.out.println("MergeSort 1000: " + elapsedTime);
		
		//reset arrays
		for(int i = 0; i < numArrays; i++){
			resetArr(randSArray[i], temp[i]);
		}

	}

	public static void testLarge(){
		Random ran = new Random();
		int s_size = 10000;
		int numArrays = 1000;
		Integer[][] randSArray = new Integer[numArrays][s_size];
		Integer[][] temp = new Integer[numArrays][s_size];
		for(int i = 0 ; i < numArrays; i++){
			for(int j = 0; j < s_size; j++){
				randSArray[i][j] = (int) ran.nextInt(s_size);
				temp[i][j] = randSArray[i][j];
			}
		}
		
		long startTime = System.currentTimeMillis();
		for(int i =0; i < numArrays; i++){
			New_sort.sort(randSArray[i]);			
		}
		long elapsedTime = System.currentTimeMillis() - startTime;
        System.out.println("NewSort 10000: " + elapsedTime);
		
		//reset arrays
		for(int i = 0; i < numArrays; i++){
			resetArr(randSArray[i], temp[i]);
		}

		//Quick Sort
		startTime = System.currentTimeMillis();
		for(int i =0; i < numArrays; i++){
			QuickSort.sort(randSArray[i]);
		}
		elapsedTime = System.currentTimeMillis() - startTime;
        System.out.println("Quick Sort 10000: " + elapsedTime);
		
		//reset arrays
		for(int i = 0; i < numArrays; i++){
			resetArr(randSArray[i], temp[i]);
		}

		//Merge Sort
		startTime = System.currentTimeMillis();
		for(int i =0; i < numArrays; i++){
			MergeSort.sort(randSArray[i]);
		}
		elapsedTime = System.currentTimeMillis() - startTime;
        System.out.println("MergeSort 10000: " + elapsedTime);
		
		//reset arrays
		for(int i = 0; i < numArrays; i++){
			resetArr(randSArray[i], temp[i]);
		}
	}
}
