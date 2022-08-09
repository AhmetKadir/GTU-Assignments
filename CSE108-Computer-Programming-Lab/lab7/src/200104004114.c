#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int check_palindrome(int  a[], int i , int  n);
int search_element(int  arr[],  int  input_number, int size);
float calculate_cos(int n, float x );

int main (){
    int control , i, randnum, n, size = 0;
    float res,x;
    int my_array[20] = {0}, pArray[50]={0};
    srand(time(NULL));
    
    /*Palindrome function*/
    printf("\n********************************************************************************");
    printf("\n\tTest palindrome function");
    printf("\n********************************************************************************");

    printf("\n\nEnter the values for array(-1 to stop): ");
    for (i=0 ; i < 50 ; i++){
        scanf("%d", &pArray[i]);
        if(pArray[i] == -1){
            break;
        }
        size++;
        
    }
    if (check_palindrome(pArray, 0, size-2)== 1)
        printf("\nYour input is a palindrome.\n");
    else
        printf("\nYour input is not a palindrome.\n");

    
    /*test for search_element function*/
    /*Creates array with random numbers between 0-100.*/
    printf("\n********************************************************************************");
    printf("\n\tTest search element function");
    printf("\n********************************************************************************\n\n");
    
    for (i=0 ; i< 20 ; i++){
        randnum = (rand() %100) + 0;
        my_array[i]= randnum;
        printf("%d ",my_array[i]);
    }
    randnum = (rand() %100) + 0; 
    int input_number = randnum;
    control =search_element(my_array, input_number, 19);
    printf("\n\nnumber = %d\nresult = %d\n",input_number, control);
    if (control)
        printf("\nFound");
    else printf("\nNot Found");

    
    /*cos function*/
    printf("\n\n********************************************************************************");
    printf("\n\tTest cos function");
    printf("\n********************************************************************************\n\n");

    /*scanf("%d ", &n);
    scanf("%f ",&x);*/
    res = calculate_cos(1, 10);
    printf("%f\n", res);
    return 0 ;
}

int check_palindrome(int  a[], int i ,int  n){
    /*If it reaches middle of the array, stop.*/
    if (i == n || i > n )
        return 1;
    /*Check same values in array.*/
    else if (a[i] == a[n])
        check_palindrome(a, i+1, n-1);
    /*If compared values are not same return 0.*/
    else 
        return 0;

}

int search_element(int  arr[],  int input_number, int size){
    /*if the number is not in that index of array, look for previous index.*/
    if (size < 0)
        return 0;

    if (arr[size] == input_number)
        return 1;

    else
        search_element(arr , input_number, size-1);
}

float calculate_cos(int n, float x ){

    int a = 2*n -1;
    int b = 2*n ;
    if (n == MAX + 1)
        return 0;
    else 
        return 1-(((x*x)/(a*b))*calculate_cos(n + 1,x));
}