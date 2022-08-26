public class testHW4{

	public static void main(String Args[]){
		
		//first Algorithm
		String str = "askxymxynxysjkahxykasbhxy ";
		String str2 = "xy";
		System.out.println("\n\nFirst problem: Returns index of i th occurence of " + str2);
		System.out.println("The string we will search is " + str);
		
		for(int i = 0; i<= 5 ; i++){
			System.out.println("i = " + i);
			System.out.println("Answer = " + findString(str, str2, i));
		}

		//algorithm 2
		System.out.println("\n\nSecond problem: Returns the number of"
						+" items between two number");
		System.out.println("(It includes the borders)");
		int[] myArr = {1, 2, 5, 8, 15, 16, 19, 23, 32, 35};
		System.out.print("The array : ");
		for(int x : myArr){
			System.out.printf(" %d ", x);
		}
		System.out.print("\n\nnumbers of items between 8 and 23 in the Array = ");
		System.out.println(numberOfItemsBetween(myArr, 8, 23));
		System.out.print("\n\n");
		int l = 0 ,r;
		for(int i = 1; i<38; i++){
			r = i;
			System.out.printf("Number of items between %d - %d", l, r);
			System.out.println(" = " + numberOfItemsBetween(myArr, l, r));
		}

		//algorithm 3
		System.out.println("\n\nThird problem: find contiguous subarray/s that" 
		+" the sum of its/theirs items is equal to a given integer value.");
		int[] myArr2 = {8, 25, 7, 13, 15, 10, 19, 12, 4, 9};
		System.out.print("The array : ");
		for(int x: myArr2){
			System.out.printf(" %d ", x);
		}
		System.out.println("\n\nFind subarrays that their sum equals to 35 ");
		findSubArrays(myArr2, 35);

		System.out.println("\nFind subarrays that their sum equals to 53 ");
		findSubArrays(myArr2, 53);

		System.out.println("\nFind subarrays that their sum equals to 64 ");
		findSubArrays(myArr2, 64);

		System.out.println("\nFind subarrays that their sum equals to 105 ");
		findSubArrays(myArr2, 105);

		System.out.println("\nFind subarrays that their sum equals to 122 ");
		findSubArrays(myArr2, 122);

		System.out.println("\nFind subarrays that their sum equals to 51 ");
		findSubArrays(myArr2, 51);

		//algorithm 5
		System.out.println("\n\nfifth problem: calculates all the possible " +
			"configurations to fill the array with colored-blocks " +
			"with length at least 3");
		System.out.println("C represents colored blocks");
		System.out.println("0 represent non-colored blocks");
		char[] blocks = new char[10];
		System.out.println("(WARNING THE ALGORITHM HAS MISSING PARTS)");
		System.out.print("The array: ");
		for(int i = 0; i< blocks.length; i++){
			blocks[i] = '0';
			System.out.print(blocks[i]);
		}
		System.out.printf("\nlength is %d \n", blocks.length);
		colorBlocks(blocks);
	} 
	static int findString(String str, String queryStr, int i){
		if(!str.contains(queryStr) || i == 0){
			return -1;
		}

		else {
			return str.indexOf(queryStr) + 1 +
				findString(str.substring(str.indexOf(queryStr)+1), queryStr, i-1);
		}
	}

	static int numberOfItemsBetween(int arr[], int first, int second){
		if(first > second) return -1;
		int firstIndex = binarySearchLower(arr, 0, arr.length-1, first);
		int lastIndex = binarySearchUpper(arr, 0, arr.length-1, second);
		if(firstIndex == -1 || lastIndex == -1) 
			return -1;
		return lastIndex - firstIndex + 1;

	}

	private static int binarySearchLower(int arr[], int l, int r, int num){
		if(r >= 1 )
		{
			int mid = (l+r)/2;
			if(num == arr[mid]){
				return mid;
			}
			else if(r-l == 1){
				if (num == 0) return l;
				return r;
			}
			else if(num < arr[mid]){
				return binarySearchLower(arr, l, mid , num);
			}

			else{
				return binarySearchLower(arr, mid, r, num);
			}
		}
		return -1;
	}

	private static int binarySearchUpper(int arr[], int l, int r, int num){
		if(r >= 1 )
		{
			int mid = (l+r)/2;

			if(num == arr[mid]){
				return mid;
			}
			else if(r-l == 1){
				if(num >= arr[arr.length - 1]) return r;
				return l;
			}
			else if(num < arr[mid]){
				return binarySearchUpper(arr, l, mid , num);
			}

			else{
				return binarySearchUpper(arr, mid, r, num);
			}
		}
		return -1;
	}

	static void findSubArrays(int[] arr, int sum){
		findSum(arr, sum, 0, 0, 0, "", false);
	}

	private static void findSum(int[] arr, int sum, int begin,
					int last, int result, String str, boolean found){
			
		if(last >= arr.length){
			if (found == false){
				System.out.println("No subArray found!");
			}
			return;
		}
						
		result += arr[last];
						
		if(result == sum){
			str += arr[last] + " ";
			System.out.println(str);
			str = "";
			result = 0;
			last = begin + 1;
			found = true;
			findSum(arr, sum, begin + 1, last, result, str, found);
		}
		else if(result < sum){
			str += arr[last] + " ";
			findSum(arr, sum, begin, last + 1 , result, str, found);
		}
		else if(result > sum){
			str = "";
			result = 0;
			last = begin + 1;
			findSum(arr, sum, begin + 1, last, result, str, found);
		}
	}	

	static void colorBlocks(char[] blocks){
		colorBlocks(blocks, 0, 3, 0, 1, 1, 0);
	}
	
	/**
	 * It does not work properly
	 * If there are more than one repeat in the sequence,
	 * it does not include the possibilites which 
	 * there are more space than 1 between the colored blocks.
	 * 'C' represents colored blocks
	 * while '0' represents non-colored blocks
	 * @param blocks array of blocks
	 * @param index index of the current block
	 * @param coloredLength length of the coloredBlocks
	 * @param consecutive Current length counter of the coloredBlocks
	 * @param next next keeps the next start of the array
	 * @param repeat repeat keeps number of repeat will be occur for the colored block in the sequence
	 * @param repeatCounter	keeps current repeat time in a sequence
	 */
	private static void colorBlocks(char[] blocks, int index,
	int coloredLength, int consecutive, int next, int repeat, int repeatCounter){
		
		if(coloredLength > blocks.length ) {
			return;
		}
		
		else if(blocks.length / coloredLength < repeat
					&& coloredLength*repeat != blocks.length){
			colorBlocks(blocks, 0, coloredLength+1, 0, 1, 1, 0);
		}

		else if(index == blocks.length){
			System.out.print("\n");
			if(blocks[index-1] == 'C'){
				repeat++;
				colorBlocks(blocks, 0, coloredLength, 0, 1, repeat, 0);
			}
			else{
				colorBlocks(blocks, 0, coloredLength, 0, next+1, repeat, 0);
			}
		}

		else if(consecutive == coloredLength){
			blocks[index] = '0';
			System.out.print(blocks[index]);
			repeatCounter++;
			if(repeatCounter >= repeat)
				colorBlocks(blocks, index+1, coloredLength, consecutive, next,
							repeat, repeatCounter);
			else
				colorBlocks(blocks, index+1, coloredLength, 0, next,
				 			repeat, repeatCounter);
		}
		else {
			if(index + 1 >= next){
				blocks[index] = 'C';
				System.out.print(blocks[index]);
				colorBlocks(blocks, index+1, coloredLength, consecutive+1, next,
							repeat, repeatCounter);
			}
			else{
				blocks[index] = '0';
				System.out.print(blocks[index]);
				colorBlocks(blocks, index+1, coloredLength, 0,
				 			next, repeat, repeatCounter);
			}
		}
	}
}
